#include<stdio.h>
#include<stdlib.h>
int main()
{
	char pt[100],ct[100], ch;
	int n, i, k,key;
	printf("\tCaesar cipher\n");
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
               	printf("Enter key\t   : ");
               	scanf("%d", &k);
               	key=k%26;
               	for(i = 0; pt[i] != '\0'; ++i)
               	{
               		ch = pt[i];
               		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
               		{
               			ch = ch + key;
               			if(ch > 'z')
               				ch = ch - 'z' + 'a' - 1;
               			if(ch > 'Z' && ch < 'a')
               				ch = ch - 'Z' + 'A' - 1;
               			ct[i] = ch;
               		}
               	}
               	printf("The resultant cipher text : %s \n", ct);
               	break;
     	     case 2:
               	printf("Enter a cipher text : ");
               	scanf("%s",ct);
               	printf("Enter key\t   : ");
               	scanf("%d", &k);
               	key=k%26;
               	for(i = 0; ct[i] != '\0'; ++i)
               	{
               		ch = ct[i];
               		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
               		{
               			ch = ch - key;
				if(ch < 'A')
               		          ch = ch + 'Z' - 'A' + 1;
               			if(ch < 'a' && ch > 'Z')
               				ch = ch + 'z' - 'a' + 1;
               			pt[i] = ch;
               		}
               	}
               	printf("The resultant plain text : %s \n", pt);
               	break;
               case 3:
		    printf("Exit");
                    exit(0);
     	}
	}while(n==1 || n==2);
	return 0;
}