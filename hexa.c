
#include <stdio.h>
#include <ctype.h>  
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    HEX_0,
    HEX_1,
    HEX_2,
    HEX_3,
    HEX_4,
    HEX_5,
    HEX_6,
    HEX_7,
    HEX_8,
    HEX_9,
    HEX_A,
    HEX_B,
    HEX_C,
    HEX_D,
    HEX_E,
    HEX_F
} Hexadecimal;

char hex_to_char(Hexadecimal hex) {
    switch (hex) {
        case HEX_0: return '0';
        case HEX_1: return '1';
        case HEX_2: return '2';
        case HEX_3: return '3';
        case HEX_4: return '4';
        case HEX_5: return '5';
        case HEX_6: return '6';
        case HEX_7: return '7';
        case HEX_8: return '8';
        case HEX_9: return '9';
        case HEX_A: return 'A';
        case HEX_B: return 'B';
        case HEX_C: return 'C';
        case HEX_D: return 'D';
        case HEX_E: return 'E';
        case HEX_F: return 'F';
        default: return '?';
    }
}

Hexadecimal char_to_hex(char input_char) {
    
    char c = toupper(input_char);

    switch (c) {
        case '0': return HEX_0;
        case '1': return HEX_1;
        case '2': return HEX_2;
        case '3': return HEX_3;
        case '4': return HEX_4;
        case '5': return HEX_5;
        case '6': return HEX_6;
        case '7': return HEX_7;
        case '8': return HEX_8;
        case '9': return HEX_9;
        case 'A': return HEX_A;
        case 'B': return HEX_B;
        case 'C': return HEX_C;
        case 'D': return HEX_D;
        case 'E': return HEX_E;
        case 'F': return HEX_F;
    }
}

#define DIGIT_CHARS "0123456789"
#define HEX_CHARS_UPPER "ABCDEF"
#define HEX_CHARS_LOWER "abcdef"

void generate_random_number_string(char *buffer, size_t length) {
    const char *digits = DIGIT_CHARS;
    size_t digits_len = strlen(digits);

    for (size_t i = 0; i < length; ++i) {
        buffer[i] = digits[rand() % digits_len];
    }
    buffer[length] = '\0';
}

void generate_random_hex_string(char *buffer, size_t length, int use_uppercase) {
    const char *hex_chars = use_uppercase ? HEX_CHARS_UPPER : HEX_CHARS_LOWER;
    size_t hex_len = strlen(hex_chars);

    for (size_t i = 0; i < length; ++i) {
        buffer[i] = hex_chars[rand() % hex_len];
    }
    buffer[length] = '\0'; 
}

int main() {
    Hexadecimal hex_val = HEX_A;
    printf("Hexadecimal value: %c\n", hex_to_char(hex_val));

    char c = 'b';
    Hexadecimal hex_from_char = char_to_hex(c);
    printf("Converted from char: %c\n", hex_to_char(hex_from_char));

    srand((unsigned int)time(NULL));

    size_t digit_length = 10000;
    size_t hex_length = 10000;

    
    char *digit_buffer = malloc(digit_buffer + 1);
    char *hex_buffer_upper = malloc(hex_length + 1);
    char *hex_buffer_lower = malloc(hex_length + 1);
    char *combined_buffer = malloc(digit_length + hex_length * 2 + 100);

    if (digit_buffer == NULL || hex_buffer_upper == NULL || hex_buffer_lower == NULL || combined_buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    generate_random_number_string(digit_buffer, digit_length);
    generate_random_hex_string(hex_buffer_upper, hex_length, 1);
    generate_random_hex_string(hex_buffer_lower, hex_length, 0);

    snprintf(combined_buffer, digit_length + hex_length * 2 + 100,
             "%s"
             "%s"
             "%s",
             digit_buffer,
             hex_buffer_upper,
             hex_buffer_lower
    );

    printf("%s\n", combined_buffer);

    printf("\n\n---------------\n\n");

    size_t combined_buffer_length = strlen(combined_buffer);

    for (size_t i = 0; i < combined_buffer_length; ++i) {
        char c = combined_buffer[i];
        Hexadecimal hex_from_char = char_to_hex(c);
        printf("Character: %c, Hex: %c\n", c, hex_to_char(hex_from_char));
    }

    free(digit_buffer);
    free(hex_buffer_upper);
    free(hex_buffer_lower);
    free(combined_buffer);

    return 0;
}