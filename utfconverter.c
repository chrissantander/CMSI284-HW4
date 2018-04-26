#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

static size_t code_to_utf8(const unsigned int code);
static void toHex(unsigned char *const d);
void emit_byte(int i);
void to_utf_8(int c);


int main() {
//    
//    int i;
//    
//    printf( "Enter a utf-32 code point:");
//    scanf("%d", &i);
//    
//    toHex(code_to_utf8(i));
    
    
    
    
    to_utf_8('%');
  
}

//static int* code_to_utf8(const unsigned int code) {
//    char *buffer = malloc(4);
//    
//    if (code <= 0x7F) {
//        buffer[0] = code;
//        return 1;
//    }
//    if (code <= 0x7FF) {
//        buffer[0] = 0xC0 | (code >> 6);            /* 110xxxxx */
//        buffer[1] = 0x80 | (code & 0x3F);          /* 10xxxxxx */
//        return 2;
//    }
//    if (code <= 0xFFFF) {
//        buffer[0] = 0xE0 | (code >> 12);           /* 1110xxxx */
//        buffer[1] = 0x80 | ((code >> 6) & 0x3F);   /* 10xxxxxx */
//        buffer[2] = 0x80 | (code & 0x3F);          /* 10xxxxxx */
//        return 3;
//    }
//    if (code <= 0x10FFFF) {
//        buffer[0] = 0xF0 | (code >> 18);           /* 11110xxx */
//        buffer[1] = 0x80 | ((code >> 12) & 0x3F);  /* 10xxxxxx */
//        buffer[2] = 0x80 | ((code >> 6) & 0x3F);   /* 10xxxxxx */
//        buffer[3] = 0x80 | (code & 0x3F);          /* 10xxxxxx */
//        return 4;
//    }
//    return 0;
//}

void toHex(unsigned char *const d) {
    long int binaryval, hexadecimalval = 0, i = 1, remainder;
    
    printf("Enter the binary number: ");
    scanf("%ld", &binaryval);
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("Equivalent hexadecimal value: %lX", hexadecimalval);
    return;
}



void emit_byte(int i) {
    
    printf("%d\n", i);
}

void to_utf_8(int c) {
    if (c > 0x10FFFF) {
        printf("Code point too large\n");
        return;
    } else if (c <= 0x7F) {
        emit_byte(c);
    } else if (c <= 0x7FF) {
        emit_byte(0xC0 | (c >> 6));
        emit_byte(0x80 | (c & 0x3F));
    } else if (c <= 0xFFFF) {
        emit_byte(0xE0 | (c >> 12));
        emit_byte(0x80 | (c >> 6 & 0x3F));
        emit_byte(0x80 | (c & 0x3F));
    } else {
        emit_byte(0xF0 | (c >> 18));
        emit_byte(0x80 | (c >> 12 & 0x3F));
        emit_byte(0x80 | (c >> 6 & 0x3F));
        emit_byte(0x80 | (c & 0x3F));
    }
}
