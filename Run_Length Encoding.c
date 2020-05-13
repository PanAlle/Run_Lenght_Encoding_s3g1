#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* encode(const char *original, char *encoded)
{
    int length = strlen(original);
    int count[100];  //the number of each letter
    char store[100];     //store repeated letter
    int start = 0;

    for(int i=0;i<=length;i++)
         count[i]=1;

    for(int i=0;i<=(length-2);i++)
    {
        if(original[i]==original[i+1])
        {
            count[start]++;
            store[start]=original[i];
        }
        else
        {
            store[++start]=original[i+1];
        }
    }

    encoded = malloc(start*sizeof(char));
	memset(encoded,0,start*sizeof(char));

    for(int i=0;i<=start;i++)
    {
		if (count[i]!=1)
        	sprintf(encoded,"%s%d", encoded,count[i]);
        sprintf(encoded,"%s%c", encoded,store[i]);
    }
	
	return encoded;
}

void decode(const char *encoded, char *decoded)
{

}

void main(void)
{
    const char original[100] = "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB";
    char encoded[100];
    char decode[100];

    printf("Original: %s \n", original);
    /*printf("%d %d\n", &encoded,&original);*/

    char *p = encode(original, encoded);
    printf("\nEncoded: %s \n", p);

    /*decode(encoded, decode);
    printf("Decoded: %s \n", decode);*/
}
