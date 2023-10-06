


#include <xc.h>
#include <pic16f887.h>
#include "fuses.h"



void main() {
    TRISA = 0;
    TRISB = 0;
    ANSEL = 0;

    int CONT3 = 3;
    int CONT4 = 4;
    unsigned char VARX = 64;
    unsigned char VARY = 3;
    unsigned char VARZ = 192;

    PORTB = 0x81;
    unsigned char TEMP = PORTB;
    __delay_ms(50);

    // LOOP6_1
    while (CONT3 != 0) {
        TEMP = TEMP ^ VARY;
        TEMP = TEMP | VARX;
        PORTB = TEMP;
        __delay_ms(50);
        VARX = VARX >> 1;
        VARY = VARY << 1;
        CONT3--;
    }

    // LIMPIAR
    CONT3 = 3;
    TEMP = VARY;
    PORTB = TEMP;
    __delay_ms(50);
    VARX = VARX >> 1;
    VARY = VARY << 1;

    // LOOP6_2
    while (CONT3 != 0) {
        TEMP = TEMP ^ VARY;
        TEMP = TEMP | VARX;
        PORTB = TEMP;
        __delay_ms(50);
        VARX = VARX >> 1;
        VARY = VARY << 1;
        CONT3--;
    }

    // FIN DEL LOOP 6
    CONT3 = 3;
    STATUSbits.C = 0;

    // LOOP8_1
    while (CONT3 != 0) {
        PORTB = VARZ;
        __delay_ms(50);
        VARZ = VARZ >> 1;
        VARZ = VARZ >> 1;
        CONT3--;
    }

    // LOOP8_2
    while (CONT4 != 0) {
        PORTB = VARZ;
        __delay_ms(50);
        VARZ = VARZ << 1;
        VARZ = VARZ << 1;
        CONT4--;
    }


}
