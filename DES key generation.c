#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char key[10],p10[10],p8[8];
int p10order[10],p8order[8],n;
void P10()
{
     int j;
     for(int i=0;i<10;i++)
     {
          j=p10order[i];
          p10[i]=key[j-1];
     }
     for(int i=0;i<10;i++)
	     printf("%c ",p10[i]);
	printf("\n\n");
}

void leftshift()
{
     int temp=p10[0];
     for(int i=0;i<9;i++)
     {
          p10[i]=p10[i+1];
     }
     p10[9]=temp;
     for(int i=0;i<10;i++)
	     printf("%c ",p10[i]);
	printf("\n");
}

void P8()
{
     int j;
     for(int i=0;i<8;i++)
     {
          j=p8order[i];
          p8[i]=p10[j-1];
     }
     for(int i=0;i<8;i++)
	     printf("%c ",p8[i]);
	printf("\n\n");
}

int main()
{
	printf("Enter the key input     : ");
	for(int i=0;i<10;i++)
	     scanf("%c",&key[i]);
	printf("Enter the P10 box order : ");
	for(int i=0;i<10;i++)
	     scanf("%d",&p10order[i]);
	printf("Enter the P8 box order  : ");
	for(int i=0;i<8;i++)
	     scanf("%d",&p8order[i]);
	printf("Enter the number of keys to be generated  : ");
	scanf("%d",&n);
	
	printf("\nKey after P10 box permutation: ");
	P10();      //P10 box permutation
	
	for(int i=0;i<n;i++)
	{
	     printf("Key after %d left shift   : ",i+1);
	     leftshift();     //left shift
	
	     printf("Key %d(P8 box permutation): ",i+1);
	     P8();       //P8 box permutation
	}
	return 0;
}