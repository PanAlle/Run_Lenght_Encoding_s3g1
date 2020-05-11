#include <stdio.h>
#include <ctype.h>

void encode(const char *original, char *encoded){
    //TO DO
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
    printf("Alessandro solution");
}
