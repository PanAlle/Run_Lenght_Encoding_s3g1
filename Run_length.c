#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* encode(const char *original, char *encoded)
{
    int length = strlen(original);
    int count[100];  //the repeated number of each letter
    char store[100];     //store repeated letter
    int start = 0;    // the count number of different letters, count from 0.


    for(int i=0;i<=length;i++)
         count[i]=1;       // initial the content in array, each letter at least appear one time

    for(int i=0;i<=(length-1);i++) // The comparison is a pair. so the sum of the length is minus 1
    {
        if(original[i]==original[i+1]) //When the previous and next letters are the same, count number under index start increase and store this letter
        {
            count[start]++;
            store[start]=original[i];
        }
        else                       //When the previous and next letters are different, increase the start number and store the new letter
        {
            store[++start]=original[i+1];
        }
    }

	memset(encoded,0,sizeof(encoded)); //empty the created memory

    for(int i=0;i<=start;i++)   // put the number and letter together
    {
		if (count[i]!=1)        // if the corresponding number is 1, we omit it, and only record the letter
        	sprintf(encoded,"%s%d", encoded,count[i]);
        sprintf(encoded,"%s%c", encoded,store[i]);
    }
}

void decode(const char *encoded, char *decoded)
{
    memset(decoded,0,sizeof(decoded));     // clean up the space, avoid garbled

    char num[100];     // create a new char array for the number in the string
    memset(num,0,sizeof(num));

    for(int i=0; encoded[i]!='\0'; i++)
    {
        if(isdigit(encoded[i])) // store the number to num, if there is number before letter.
            sprintf(num,"%s%c",num,encoded[i]);

        else
        {
            for(int j=0;j < (atoi(num)-1);j++) //repeated put the letter to decoded with corresponding time
                sprintf(decoded,"%s%c",decoded,encoded[i]);

            sprintf(decoded,"%s%c",decoded,encoded[i]); // when there is no number before letter, just put the letter in the string
            memset(num,0,sizeof(num)); // initial num for next loop
        }
    }
}

void main(void)
{
    const char original[100] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
    char encoded [100];
    char decoded [100];

    printf("Original: %s \n", original);

    encode(original, encoded);
    printf("\nEncoded: %s \n", encoded);


    decode(encoded,decoded);
    printf("Decoded: %s \n", decoded);
}
