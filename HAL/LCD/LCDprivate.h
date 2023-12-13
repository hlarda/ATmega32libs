#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H



#define _8_BIT_MODE           8
#define _4_BIT_MODE           4


#define LCD_8_BIT_MODE_CMD        0x38
#define LCD_DISPLAY_ON_CMD        0x0C
#define LCD_RETURN_HOME_CMD       0x02

#define LCD_4_BIT_MODE_CMD_1      0x33
#define LCD_4_BIT_MODE_CMD_2      0x32
#define LCD_4_BIT_MODE_CMD_3      0x28

#define LCD_CLR_CMD               0x01
#define LCD_ROW0_CMD              0x80
#define LCD_ROW1_CMD              0xC0

#define NULL                      '\0'
#define ASCII_DIGIT_OFFSET        48

#endif 
