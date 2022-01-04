#include<stdio.h> 
#include<stdlib.h>
#include<string.h> 

char arr[22][22],darr[22][22],emessage[111],retmessage[111],key[55],temp[55],temp2[55];
int k=0;

void cipher(int i,int r) 
{
	int j;
	for (j=0;j<r;j++) 
		emessage[k++]=arr[j][i];
}
void makeArray(int col,int row) 
{
	int i,j;
	for (i=0;i<row;i++)
		darr[i][col]=temp2[i];
}
int findMin() 
{
	int i,j,min,index;
	min=temp[0];
	index=0;
	for (j=0;temp[j]!='\0';j++) 
		if(temp[j]<min) 
		{
			min=temp[j];
			index=j;
		}
	temp[index]=123;
	return(index);
}

int main() 
{
	char message[50],dmessage[50];
	int i,j,klen,emlen,flag,n;
	int r,c,index,min,rows;
	printf("\tColumnar Transposition\n");
	printf("1 - Encryption\t2 - Decryption\t3 - Exit\n");
	do
	{
     	printf("\nEnter your choice : ");
     	scanf("%d",&n);
     	switch(n)
     	{
     	     case 1:
               	printf("Enter the key        : ");
               	fflush(stdin);
               	scanf("%s",key);
               	printf("Enter the plain text : ");
               	fflush(stdin);
               	scanf("%s",message);
               	strcpy(temp,key);
               	klen=strlen(key);
               	k=0;
               	flag=0;
               	for (i=0;flag!=1;i++) 
               		for (j=0;j<klen;j++) 
               		{
               			if(message[k]=='\0') 
               			{
               				flag=1;
               				arr[i][j]='_';
               			} 
               			else 
               				arr[i][j]=message[k++];
               		}
               	r=i;
               	c=j;
               	for (i=0;i<r;i++) {
               		for (j=0;j<c;j++)
               			printf("%c ",arr[i][j]);
               		printf("\n");
               	}
               	k=0;
               	for (i=0;i<klen;i++) 
               	{
               		index=findMin();
               		cipher(index,r);
               	}
               	emessage[k]='\0';
                    printf("\nThe resultant cipher text : ");
               	for (i=0;emessage[i]!='\0';i++) 
               	   printf("%c",emessage[i]);
               	printf("\n");
	               break;
	          case 2:
	               printf("Enter the key        : ");
               	fflush(stdin);
               	scanf("%s",key);
               	printf("Enter the cipher text : ");
               	fflush(stdin);
               	scanf("%s",emessage);
               	emlen=strlen(emessage);
               	strcpy(temp,key);
               	rows=emlen/klen;
               	j=0;
               	for (i=0,k=1;emessage[i]!='\0';i++,k++) 
               	{
               		temp2[j++]=emessage[i];
               		if((k%rows)==0) 
               		{
               			temp2[j]='\0';
               			index=findMin();
               			makeArray(index,rows);
               			j=0;
               		}
               	}
               	printf("\nArray Retrieved is\n");
               	k=0;
               	for (i=0;i<r;i++) 
               	{
               		for (j=0;j<c;j++) 
               		{
               			printf("%c ",darr[i][j]);
               			retmessage[k++]=darr[i][j];
               		}
               		printf("\n");
               	}
               	retmessage[k]='\0';
                    printf("The resultant plain text : ");
               	for (i=0;retmessage[i]!='\0';i++) 
               	     printf("%c",retmessage[i]);
               	printf("\n");
               	break;
               case 3:
                    printf("Exit");
                    exit(0);
          }
	}while(n==1 || n==2);
	return(0);
}