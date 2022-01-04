#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
void encrypt(char pt[], int key)
{
     int len = strlen(pt), i, j, k = -1, row = 0, col = 0;
     char railMatrix[key][len];
     for(i = 0; i < key; i++)
          for(j = 0; j < len; j++)
               railMatrix[i][j] = '-';
     for(i = 0; i < len; i++)
     {
          railMatrix[row][col++] = pt[i];
          if(row == 0 || row == key-1)
               k= k * (-1);
          row = row + k;
     }
     for(i=0;i<key;i++)
     {
          for(j=0;j<len;j++)
               printf("%c ",railMatrix[i][j]);
          printf("\n");
     }
     printf("The resultant cipher text : ");
     for(i = 0; i < key; i++)
          for(j = 0; j < len; j++)
               if(railMatrix[i][j] != '-')
                    printf("%c", railMatrix[i][j]);
}
 
void decrypt(char ct[], int key)
{
     int len = strlen(ct), i, j, k = -1, row = 0, col = 0, m = 0;
     char railMatrix[key][len];
     for(i = 0; i < key; ++i)
          for(j = 0; j < len; ++j)
               railMatrix[i][j] = '-';
     for(i = 0; i < len; ++i)
     {
          railMatrix[row][col++] = '*';
          if(row == 0 || row == key-1)
               k= k * (-1);
          row = row + k;
     }
     for(i = 0; i < key; ++i)
          for(j = 0; j < len; ++j)
               if(railMatrix[i][j] == '*')
                    railMatrix[i][j] = ct[m++];
     row = col = 0;
     k = -1;
     for(i=0;i<key;i++)
     {
          for(j=0;j<len;j++)
               printf("%c ",railMatrix[i][j]);
          printf("\n");
     }
     printf("The resultant plain text : ");
     for(i = 0; i < len; ++i)
     {
          printf("%c", railMatrix[row][col++]);
          if(row == 0 || row == key-1)
               k= k * (-1);
          row = row + k;
     }
}
 
int main(){
     char pt[30], ct[30];
     int key,n;
     printf("\tRail Fence cipher\n");
	printf("1 - Encryption\t2 - Decryption\t3 - Exit");
	do
	{
     	printf("\n\nEnter your choice : ");
     	scanf("%d",&n);
     	switch(n)
     	{
     	     case 1:
                    printf("Enter the plain text : ");
                    scanf("%s",pt);
                    printf("Enter the key        : ");
                    scanf("%d",&key);
                    encrypt(pt, key);
                    break;
               case 2:
                    printf("Enter the cipher text : ");
                    scanf("%s",ct);
                    printf("Enter the key         : ");
                    scanf("%d",&key);
                    decrypt(ct, key);
                    break;
               case 3:
                    printf("Exit");
                    exit(0);
          }
	}while(n==1 || n==2);
     return 0;
}