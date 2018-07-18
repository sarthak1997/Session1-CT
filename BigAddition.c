//Program to add two big numbers of size as big as 4096 bytes
/*

	the program takes two big integers as char array and to add them, follow the basic concept of addition by traversing both the char array aka big integers from reverse i.e from ones place and then 		it adds the places number, the check for carry is handled using /10 and then it is added to the respective next higher decimal place. Firstly, the loop runs for shorter length number to add it 	 with the bigger length number and then next loop for the remaining places of the bigger length number to reflect back to the result with proper carry handling.

	The integers are taken in char array as a string and the operated for arithmetic operations using the ascii code concept as '0'-48=0

*/

#include<stdio.h>

#define NUM_SIZE 4097
#define RESULT_SIZE 4098
#define ASCII_CONVERTER 48
#define MY_NULL '\0'

char result[RESULT_SIZE];

//length method to calculate length of char array
int length(char *var)
{
     int i=0;
     while(var[i]!=MY_NULL)
     {
	i++;
     }
     return i;
}

int add_big(char* bigNumber1,char *bigNumber2)
{
    int lengthBigNum1,lengthBigNum2;
    
    lengthBigNum1=length(bigNumber1);

    lengthBigNum2=length(bigNumber2);
   /*
	Determinig length of the shorter number
   */
    int minLength=(lengthBigNum1<lengthBigNum2?lengthBigNum1:lengthBigNum2);
    int j;
    /*
	Initializing the result char array with '0'
    */
    for(j=0;j<RESULT_SIZE;j++)
    {
        result[j]='0';
    }
    int k=NUM_SIZE,temp;
    /*
	loop runs the shorter integer length number of times to add the respective decimal places of both the numbers with carry handling.
    */
    while(minLength!=0)
    {
        temp=(bigNumber1[lengthBigNum1-1]-ASCII_CONVERTER)+(bigNumber2[lengthBigNum2-1]-ASCII_CONVERTER)+(result[k]-ASCII_CONVERTER);
        if(temp/10==0)
        {
            result[k]=temp+ASCII_CONVERTER;
        }
        else
        {
            result[k]=(temp%10)+ASCII_CONVERTER;
            result[k-1]=(temp/10)+ASCII_CONVERTER;
        }
        minLength--;
        lengthBigNum1--;
        lengthBigNum2--;
        k--;
    }
    /*
	condition checks if number 1 is the larger length number and then uses loop fill in the result in the remaining blocks of the result char array with carry handling.
    */
    if(lengthBigNum1>lengthBigNum2)
    {
    while(lengthBigNum1>0)
    {
        temp=((result[k]-ASCII_CONVERTER)+(bigNumber1[lengthBigNum1-1]-ASCII_CONVERTER));
        if(temp/10==0)
        {
            result[k]=temp+ASCII_CONVERTER;
        }
        else
        {
            result[k]=(temp%10)+ASCII_CONVERTER;
            result[k-1]=(temp/10)+ASCII_CONVERTER;
        }
        k--;
        lengthBigNum1--;
    }
    }
    /*
	condition checks if number 2 is the larger length number and then uses loop fill in the result in the remaining blocks of the result char array with carry handling.
    */
    else if(lengthBigNum2>lengthBigNum1)
    {
    while(lengthBigNum2>0)
    {
        temp=((result[k]-ASCII_CONVERTER)+(bigNumber2[lengthBigNum2-1]-ASCII_CONVERTER));
        if(temp/10==0)
        {
            result[k]=temp+ASCII_CONVERTER;
        }
        else
        {
            result[k]=(temp%10)+ASCII_CONVERTER;
            result[k-1]=(temp/10)+ASCII_CONVERTER;
        }
        k--;
        lengthBigNum2--;
    }
    }
    return k;
}
//Applying Validation to check for numeric characters only
int validate(char* var)
{
	int i=0;
	while(var[i]!='\0')
	{
		if(var[i]-ASCII_CONVERTER<0 || var[i]-ASCII_CONVERTER>9)
			return 0;
		i++;
	}
	return 1;
}

int main()
{
    char bigNumber1[NUM_SIZE],bigNumber2[NUM_SIZE];
    int i,k;
    printf("\nEnter First Big Number - ");
    scanf("%s",bigNumber1);
    if(!validate(bigNumber1))
	{
	    printf("\nWrong Input\n");
	    return 0;
	}
    printf("\nEnter Second Big Number - ");
    scanf("%s",bigNumber2);
    if(!validate(bigNumber2))
	{
	    printf("\nWrong Input\n");
	    return 0;
	}
    k=add_big(bigNumber1,bigNumber2);
    printf("\n%d\n",4098-k+1);
    printf("\nHere is the Addition of two Big Numbers - ");
    /*
	Loop start from the start index or 1 before the start index of the number depending upon the carry and prints the result.
	It checks for the carry in the if block by checking any updation in the initialized value.
    */
    for(i=k;i<RESULT_SIZE;i++)
    {
        if(i==k && result[i]=='0')
            continue;
        else
            printf("%c",result[i]);
    }
    printf("\n");
    return 0;

}
