#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char uppercase(char t[])
{
     int i;
    for(i=0;i<=strlen(t);i++)
     {
          if(t[i]>=97&&t[i]<=122)
               t[i]=t[i]-32;
     }
     t[i]='\0';
     return t[100];
}

char generatekey(char t[],char key[],char genkey[])
{
     int i,j;
     for(i=0,j=0; i < strlen(t); i++,j++)
     {
          if(j == strlen(key))
               j = 0;
          genkey[i] = key[j];
     }
     genkey[i] = '\0';
     return genkey[100];
}

int main()
{
	char pt[100]={'\0'},ct[100]={'\0'},key[25]={'\0'},genkey[100]={'\0'};
	int n,i,j;
	printf("\tVignere cipher\n");
	printf("1 - Encryption\t2 - Decryption\t3 - Exit\n");
	do
	{
     	printf("\nEnter your choice : ");
     	scanf("%d",&n);
     	switch(n)
     	{
     	     case 1:
               	printf("Enter a plain text : ");
                    scanf("%s",pt);
                    uppercase(pt);
               	printf("Enter key\t   : ");
               	scanf("%s", key);
                    uppercase(key);
                    generatekey(pt,key,genkey);
                    printf("Generated Key      : %s\n", genkey);
                    for(i=0; i < strlen(pt); i++)
                         ct[i] = ((pt[i] + genkey[i]) % 26) + 'A';
               	printf("The resultant cipher text : %s \n", ct);
               	break;
               case 2:
               	printf("Enter a cipher text : ");
                    scanf("%s",ct);
                    uppercase(ct);
               	printf("Enter key\t    : ");
               	scanf("%s", key);
               	uppercase(key);
                    generatekey(ct,key,genkey);
                    printf("Generated Key       : %s\n", genkey);
                    for(i=0; i < strlen(ct); i++)
                         pt[i] = (((ct[i] - genkey[i]) + 26) % 26) + 'A';
               	printf("The resultant plain text : %s \n", pt);
               	break;
               case 3:
                    printf("Exit");
                    exit(0);
          }
	}while(n==1 || n==2);
	return 0;
}