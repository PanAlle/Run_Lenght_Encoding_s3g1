#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* encode(const char *original)
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

    char * encoded = malloc(start*sizeof(char)+start*sizeof(unsigned char)); //create a piece of memory in the heap to keep the memory in the main function
	memset(encoded,0,start*sizeof(char)+start*sizeof(unsigned char)); //empty the created memory

    for(int i=0;i<=start;i++)
    {
		if (count[i]!=1)
        	sprintf(encoded,"%s%d", encoded,count[i]);
        sprintf(encoded,"%s%c", encoded,store[i]);
    }

	return encoded;
}

char* decode(const char *encoded)
{
    char *decoded = malloc(100*sizeof(char));
    memset(decoded,0,100*sizeof(char));

    char num[100];
    memset(num,0,sizeof(num));

    for(int i=0; encoded[i]!='\0'; i++)
    {
        if(isdigit(encoded[i]))
            sprintf(num,"%s%c",num,encoded[i]);

        else
        {
            for(int j=0;j < (atoi(num)-1);j++)
                sprintf(decoded,"%s%c",decoded,encoded[i]);

            sprintf(decoded,"%s%c",decoded,encoded[i]);
            memset(num,0,sizeof(num));
        }
    }

    return decoded;

}

void main(void)
{
    const char original[100] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
    printf("Original: %s \n", original);

    char *encoded = encode(original);
    printf("\nEncoded: %s \n", encoded);


    char* decoded = decode(encoded);
    printf("Decoded: %s \n", decoded);

    free(encoded);
    free(decoded);

}
