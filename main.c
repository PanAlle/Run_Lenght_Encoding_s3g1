#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void encode(const char *original, char *encoded) {
    //Pointer to the two array
    const char *po = &original[0];
    char *pe = &encoded[0];
    //Initialize counter to save the number of words equal to each other
    int counter = 1;
    //Compute the initial lenght of the pointer
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
                //Jump to the next not filled position in the encoded, jumping based on how many digits have been written in the encoded (es 12 -- jump 2 addresses)
                while (counter) {
                    pe++;
                    counter /= 10;
                }
            }
            //Update the previuos character
            *pe = previous_char;
            //Go the the next character
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
    for (int j = 0; j < strlen(encoded) - 2; ++j) {
        //If the the value of pe is a digit
        if (isdigit(*pe)) {
            char *end;
            //The function retur a pointer to the next non-digit char and the integer, based on the given base (in this case decimal = 10)
            long int integer = strtol(pe, &end, 10);
            //make pe point to the same address of pe
            pe = end;
            //iterate and insert the value of pe to the pd (decoded array) for a number of times equal to the value of integer
            for (int i = 1; i < integer; i++) {
                *pd = *pe;
                pd++;
            }
        }
            //If no number is find then just copy the character to the decoded string and continue to iterate
        else {
            *pd = *pe;
            pd++;
            pe++;
        }
    }
}

void main(void) {
    const char original[100] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
    char encoded[100];
    char decoded[100];
    printf("Original: %s\n", original);
    encode(original, encoded);
    printf("Encoded : %s\n", encoded);
    decode(encoded, decoded);
    printf("Decoded : %s\n", decoded);
}
