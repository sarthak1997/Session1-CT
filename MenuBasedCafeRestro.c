
/*
	this program contains two methods i.e addToCart and generateBill which operates upon the menu data attributes.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define OFFSET 101

char items[]="TEA\0LATTE\0PEPSI\0SOUP\0COKE\0";
int itemid[]={101,102,103,104,105};
int price[]={25,50,50,40,50};
int cart[]={0,0,0,0,0};

//method that sustains the order with respective item id based on indexes and quantity of that item in the cart
void addToCart(int id,int qty)
{
    cart[id-OFFSET]+=qty;
}
//it calculates the total amount by using price data and quantity of the item and generates the bill accordingly.
void generateBill()
{
    printf("\n\t\t\t**Here is your bill**");
    printf("\n\n\tITEM_ID\t\tITEM\t\tPRICE\t\tQty\n");
    int i,j=0,totalAmt=0;
    for(i=0;i<SIZE;i++)
    {
       if(cart[i]!=0)
       {
           printf("\t%d\t\t",itemid[i]);
           while(items[j]!='\0')
           {
               printf("%c",items[j]);
               j++;
           }
           j++;
           printf("\t\t%d\t\t%d\n",price[i]*cart[i],cart[i]);
           totalAmt+=price[i]*cart[i];
       }
       else
       {
           while(items[j]!='\0')
           {
               j++;
           }
           j++;    
       }
    }
    printf("\n\n\t\t\t\t\t\t\tTOTAL:\t%d\n",totalAmt);
}

//validating the item id based on the data at present
int validate(int item_id)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(item_id==itemid[i])
			return 1;
	}
	return 0;
}

int main()
{
    printf("\t\tWELCOME TO CLEAR-TRAIL'S CAFETERIA\n");
    printf("\t\t\t**Here is the Menu**");
    printf("\n\n\tITEM_ID\t\tITEM\t\tPRICE\n");
    int i,j=0;
/*
	printing the menu
*/
    for(i=0;i<SIZE;i++)
    {
       printf("\t%d\t\t",itemid[i]);
       while(items[j]!='\0')
       {
           printf("%c",items[j]);
           j++;
       }
       j++;
       printf("\t\t%d\n",price[i]);
    }
    int check=1,check2=0;
    int item_id,qty;
/*
	loop for placing the order as many times as the user wants depending upon the input 1 and 0 to continue or stop placing the order.
*/
    do
    {
	if(check2>=10)
	{
		printf("\nAt once you can add only 10 items in your cart. Try in another transaction.\n");
		break;
	}
        printf("Enter item id to place your order -");
        scanf("%d",&item_id);
	if(!validate(item_id))
	{
		printf("\nWrong Input\n");
		return 0;
	}
        printf("Enter quantity of the item -");
        scanf("%d",&qty);
        addToCart(item_id,qty);
        printf("Do you want to add more items (y=1/n=0)");
	check2++;
        scanf("%d",&check);
    }while(check==1);
    generateBill();
    return 0;
}
