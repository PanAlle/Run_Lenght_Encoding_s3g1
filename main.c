#include <stdio.h>
#include <ctype.h>

void encode(const char *original, char *encoded){
    const char *po = &original[0];
    char *pc = &encoded[0];
    int counter = 0;
    while (*po++ != '\0'){
        counter++;
    }
        printf("Nuber of character in the string %d\n", counter);
    encoded[1] = counter;
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
