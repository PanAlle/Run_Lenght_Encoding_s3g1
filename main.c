#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void encode(const char *original, char *encoded){
    const char *po = &original[0];
    char *pc = &encoded[0];
    int counter = 1;
    while (*po != '\0') {
        char previous_char = *po;
        *po++;
        if (previous_char == *po) {
            counter++;}
        else {
            if (counter > 1){
            printf("The value of the counter is %d\n", counter);
            sprintf(pc, "%d", counter);

            while (counter){
                *pc++;
                counter /= 10;
            }
            }
            *pc = previous_char;
            *pc++;
            counter = 1;
        }
    }

}

void decode(const char *encoded, char *decoded){
    //TO DO
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
