/*
	the program contains the operation for encryption and decryption of the input string at every character level using bitwise xor operator.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define KEY_SIZE 6

char key[]="123321";
char encryptedVal[SIZE];
char decryptedVal[SIZE];

int getLength(char *string)
{
	int i=0;
	while(string[i]!='\0')
	{
		i++;
	}
	return i;
}

void encrypt_XOR(char *string,int size)
{
    int i=0,j;
/*
	loop performs xor of the respective index character of the key with the character of the string to encrypt and thus encrypt every character of the string accordingly.
*/
    while(string[i]!='\0')
    {
        encryptedVal[i]=(string[i]^key[i%KEY_SIZE]);
	i++;
    }
    printf("\nEncrypted Value :");
    for(i=0;i<size;i++)
	{
		printf("%c",encryptedVal[i]);
	}	
	printf("\n");
}

void decrypt_XOR(char *string,int size)
{
    int i=0,j=size;
/*
	loop performs xor of the respective index character of the key with the character of the encrypted string to decrypt every character of the string accordingly and generate the plain text again.
*/
    while(j)
    {
        decryptedVal[i]=string[i]^key[i%KEY_SIZE];
        i++;
	j--;
    }
    printf("\nDecrypted Value :");
    for(i=0;i<size;i++)
	{
		printf("%c",decryptedVal[i]);
	}
	printf("\n");
}

int main()
{
    char string[SIZE];
    printf("Enter plain text to encrypt - ");
    fgets(string,SIZE,stdin);
    int size=getLength(string);
    encrypt_XOR(string,size);
    printf("\nNow decrypting the value \n");
    decrypt_XOR(encryptedVal,size);
    return 0;
}
