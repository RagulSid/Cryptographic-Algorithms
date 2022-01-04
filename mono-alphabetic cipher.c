#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
     char pt[50]={'\0'},ct[50]={'\0'},ch;
     char alph[]  ="abcdefghijklmnopqrstuvwxyz";
     char cipher[]="yzajvpqertuomlnkwihdfsgcbx";
     int n,pos,j=0,i=0,k=0;
     printf("\tMono-Alphabetic cipher\n");
	printf("1 - Encryption\t2 - Decryption\t3 - Exit\n");
	do
	{
     	printf("\nEnter your choice : ");
     	scanf("%d",&n);
     	switch(n)
     	{
     	     case 1:
               	printf("Enter a plain text        : ");
                    scanf("%s",pt);
                    while(pt[i]!='\0')
                    {
                         ch=pt[i];
                         for(j=0;j<26;j++)
                         {
                              if(pt[i] == alph[j])
                              {
                                   pos=j;
                                   break;
                              }
                         }
                         ct[i]=cipher[pos];
                         i++;
                    }
                    printf("The resultant cipher text : %s\n",ct);
               	break;
     	     case 2:
               	printf("Enter a cipher text       : ");
                    scanf("%s",ct);
                    while(ct[i]!='\0')
                    {
                         ch=ct[i];
                         for(j=0;j<26;j++)
                         {
                              if(ct[i] == cipher[j])
                              {
                                   pos=j;
                                   break;
                              }
                         }
                         pt[i]=alph[pos];
                         i++;
                    }
                    printf("The resultant plain text  : %s\n",pt);
               	break;
               case 3:
		    printf("Exit");
                    exit(0);
     	}
	}while(n==1 || n==2);
     return 0;
}