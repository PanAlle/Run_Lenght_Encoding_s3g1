#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void encode(const char *original, char *encoded) {
    const char *po = &original[0];
    char *pe = &encoded[0];
    int counter = 1;
    unsigned int lengh_pe = strlen(pe);
    for (int i = 0; i < strlen(original); ++i) {
        //save the previous character and iterate to the next
        char previous_char = *po;
        *po++;
        // iterate through the string when to sequential character are the same
        if (previous_char == *po) {
            counter++;
        }
            //When the sequential character are not equal insert in the string the value of the counter and add the letter
        else {
            if (counter > 1) {
                int tmp = counter;
                // digits = 1 account for the fact that string end with a \0 character
                int digits = 1;
                // count the digit to better allocate the buffer max. size
                while (tmp) {
                    tmp /= 10;
                    digits++;
                }
                //insert the digits in the string
                snprintf(pe, digits, "%d", counter);

                while (counter) {
                    pe++;
                    counter /= 10;
                }
            }
            *pe = previous_char;
            pe++;
            counter = 1;
        }
        unsigned int new_lenght_of_pe = lengh_pe - strlen(pe);
        //printf("Lenght of pe at he end %d\n", new_lenght_of_pe);
        //Assign to the last number of the used digit the value \0 in order to terminate the string.
        *(pe + new_lenght_of_pe - 1) = '\0';
    }


}

void decode(const char *encoded, char *decoded) {
    const char *pe = &encoded[0];
    char *pd = &decoded[0];
    //unsigned int lengh_pd = strlen(pd);
    for (int j = 0; j < strlen(encoded)-2; ++j) {
        if (isdigit(*pe)) {
            char* end;
            long int integer = strtol(pe, &end, 10);
            pe = end;
            for (int i = 1; i < integer; i++) {
                *pd = *pe;
                pd++;
            }

        } else {
            *pd = *pe;
            pd++;
            pe++;
        }
    }
    //unsigned int new_lenght_of_pd = lengh_pd - strlen(pd);
    //*(pd + new_lenght_of_pd - 1) = '\0';
}

void main(void ) {
    const char original[100] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
    char encoded [100];
    char decoded [100];
    printf("Original: %s\n", original);
    encode(original , encoded);
    printf("Encoded : %s\n", encoded);
    decode(encoded, decoded);
    printf("Decoded : %s\n", decoded);
}
