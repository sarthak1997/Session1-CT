//Printing fibonacci numbers upto a number using recursion

/*
	program prints the fibonacci series i.e 0 1 1 2 3 5 8............. upto a limit specified by the user. It is implemented using recursion concept.
*/

#include<stdio.h>

int limit;
/*
	method is recursive calls itself in a manner such that formal parameters are updated according to the logic of next term of the fibonacci series.
*/
void fib_rec(long long int a,long long int b)
{
	//condition to break the recursion
	if(limit<=0)
		return;
	else
	{
		limit--;
		printf("%lld ",a);
		fib_rec(b,a+b);	
	}
}

long long int validate(long long int num)
{
	if(num<=0 || num>93)
		return 0;
	return 1;
}

int main()
{
	printf("Please enter number of terms you want to print - ");
	scanf("%d",&limit);
	printf("%d",limit);
	if(!validate(limit))
	{
		printf("\nWrong Input - You can enter number of terms from 1 to 93 only\n");
		return 0;
	}
	long long int n1=0,n2=1;
	fib_rec(n1,n2);
	return 0;
}
