#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void encode(const char *original, char *encoded) {
    const char *po = &original[0];
    char *pe = &encoded[0];
    int counter = 1;
    int string_lenght_counter = 0;
    while (*po != '\0') {
        char previous_char = *po;
        *po++;
        if (previous_char == *po) {
            counter++;
        } else {
            if (counter > 1) {
                //printf("The value of the counter is %d\n", counter);
                snprintf(pe,3,  "%d", counter);

                while (counter) {
                    *pe++;
                    counter /= 10;
                }
            }
            *pe = previous_char;
            *pe++;
            counter = 1;
        }
        //string_lenght_counter++;
    }

}

void decode(const char *encoded, char *decoded) {
    const char *pe = &encoded[0];
    char *pd = &decoded[0];
    long int integer = 0;
    char *end;
    while (*pe != '\0'){
    if (isdigit(*pe) != 0) {
        integer = strtol(encoded, &end, 10);
        printf("The value of the counter is %ld\n", integer);
    }
    pe = &end;
        while (integer){
            *pd = *pe;
            *pd++;
            integer --;
        }
    }
}

void main(void ) {
    const char original[100] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
    char encoded [100];
    char decoded [100];
    printf("Original: %s\n", original);
    encode(original , encoded);
    printf("Encoded: %s\n", encoded);
    decode(encoded, decoded);
    printf("Decoded: %s\n", decoded);
}
