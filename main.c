#include <REGX51.H>

void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 1275; j++);
}

// 7-segment codes for digits 0–9 (Common Cathode)
unsigned char seg_codes[10] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F   // 9
};

void main() {
    unsigned char digit = 0;

    P0 = 0xFF;   // Make P0 input (especially P0.0)
    P2 = 0x00;   // Initialize display output

    while (1) {
        P2 = seg_codes[digit];  // Show current digit

        if (P0_0 == 0) {        // Button pressed (active LOW)
            delay_ms(20);       // Debounce delay
            while (P0_0 == 0);  // Wait until button is released

            digit++;            // Increment digit
            if (digit > 9)
                digit = 0;      // Loop back to 0

            delay_ms(50);      // Delay to avoid multiple increments
        }
    }
}