#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "LCD/LCD.h"
#include"keyPad/keyPad.h"

#define STACK_SIZE      16
#define LCD_MAX_INDEX   16

typedef struct {
    int top;
    int capacity;
    int array[STACK_SIZE];
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = STACK_SIZE;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1;
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top];
    }
    return -1;
}

int operate(char op, int a, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return (int)pow(a, b);
        default:
            return 0;
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return 0;
}

int MathChallenge(char* str) {
    int len = strlen(str);

    Stack* values = createStack(len);
    Stack* operators = createStack(len);

    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            int num = 0;
            while (i < len && (isdigit(str[i]) || str[i] == ' ')) {
                if (isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                }
                i++;
            }
            i--; // Adjust index after the loop
            push(values, num);
        } else if (str[i] == '(') {
            push(operators, str[i]);
        } else if (str[i] == ')') {
            while (!isEmpty(operators) && peek(operators) != '(') {
                int b = pop(values);
                int a = pop(values);
                char op = (char)pop(operators);
                push(values, operate(op, a, b));
            }
            pop(operators); // Pop '('

            // Check if the next character is not an operator
            if (i + 1 < len && !isOperator(str[i + 1])) {
                // If so, insert a multiplication operator
                push(operators, '*');
            }
        } else if (isOperator(str[i])) {
            while (!isEmpty(operators) && precedence(peek(operators)) >= precedence(str[i])) {
                int b = pop(values);
                int a = pop(values);
                char op = (char)pop(operators);
                push(values, operate(op, a, b));
            }
            push(operators, str[i]);
        } else if (str[i] == ' ') {
            // Skip spaces
            continue;
        } else {
            // Handle implicit multiplication
            int num = 0;
            while (i < len && (isdigit(str[i]) || str[i] == ' ')) {
                if (isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                }
                i++;
            }
            i--; // Adjust index after the loop
            push(values, num);

            // Check if the next character is not an operator or a closing parenthesis
            if (i + 1 < len && !isOperator(str[i + 1]) && str[i + 1] != ')') {
                // If so, insert a multiplication operator
                push(operators, '*');
            }
        }
    }

    while (!isEmpty(operators)) {
        int b = pop(values);
        int a = pop(values);
        char op = (char)pop(operators);
        push(values, operate(op, a, b));
    }

    int result = pop(values);
    free(values->array);
    free(values);
    free(operators->array);
    free(operators);

    return result;
}

int main(void) {
    u8      keypadInput=0;
    char    inputArray[LCD_MAX_INDEX];
    u8      inputCounter=0;
    LCDinit     ();
    keyPadInit  ();

    while (1) {
        keypadInput=keyPadRead();
            if (keypadInput == '=' || inputCounter == LCD_MAX_INDEX){
                break;
            }
            else if(keypadInput != KEYPAD_NOT_PRESSED){
			    LCDwriteCharacter(keypadInput);
                inputArray[inputCounter++]=keypadInput;
		    }
        }
        LCDgoTo(1,0);
        int result = MathChallenge(inputArray);
        LCDwriteSignedNumber(result);
        _delay_ms(2000);
    return 0;
}