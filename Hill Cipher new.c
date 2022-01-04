#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float mes[3][1], encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], invmat[3][3];
 
void encryption() 
{
     int i, j, k;
     for(i = 0; i < 3; i++)
          for(k = 0; k < 3; k++)
               encrypt[i][0] = encrypt[i][0] + a[i][k] * mes[k][0];
     printf("The resultant cipher text : ");
     for(i = 0; i < 3; i++)
          printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));
}
 
 
int det(int a,int b,int c,int d)
{
     int x;
     x=(a*d)-(c*b);
     return x;
}

void inverse()
{
     int i,j;
     float a,adjoint[3][3];
     adjoint[0][0]=det(b[1][1],b[1][2],b[2][1],b[2][2]);
     adjoint[0][1]=-det(b[1][0],b[1][2],b[2][0],b[2][2]);
     adjoint[0][2]=det(b[1][0],b[1][1],b[2][0],b[2][1]);
     
     adjoint[1][0]=-det(b[0][1],b[0][2],b[2][1],b[2][2]);
     adjoint[1][1]=det(b[0][0],b[0][2],b[2][0],b[2][2]);
     adjoint[1][2]=-det(b[0][0],b[0][1],b[2][0],b[2][1]);
     
     adjoint[2][0]=det(b[0][1],b[0][2],b[1][1],b[1][2]);
     adjoint[2][1]=-det(b[0][0],b[0][2],b[1][0],b[1][2]);
     adjoint[2][2]=det(b[0][0],b[0][1],b[1][0],b[1][1]);
     
     for(int i=0;i<3;i++)
     {
          for(int j=0;j<3;j++)
          {
               printf("%lf ",adjoint[i][j]);
          }
          printf("\n");
     }
     int d=0;
     for(i=0;i<3;i++)
          d+=b[0][i]*adjoint[0][i];
     
     d=(d+26)%26;
     printf("%d\n",d);
     
     for(int x=1;x<26;x++)
	  if(((d%26)*(x%26))%26 == 1)
		a=x;
	printf("%lf\n",a);
	
	
     for(i=0;i<3;i++)
          for(j=0;j<3;j++)
          {
               invmat[j][i]=(adjoint[i][j]*a);
               invmat[j][i]=fmod(invmat[j][i],26);
          }
     for(i=0;i<3;i++)
          for(j=0;j<3;j++)
          {
               if(invmat[j][i]<0)
                    invmat[j][i]=invmat[j][i]+26;
          }
               
     printf("\nInverse matrix : \n");
     for(i=0;i<3;i++){
          for(j=0;j<3;j++)
               printf("%lf ",invmat[j][i]);
          printf("\n");
     }
} 
 
 
void decryption() 
{
     int i, j, k;
     inverse();
     for(i = 0; i < 3; i++)
          for(k = 0; k < 3; k++)
               decrypt[i][0] = decrypt[i][0] + invmat[i][k] * encrypt[k][0];
     
     printf("The resultant plain text :  ");
     for(i = 0; i < 3; i++)
          printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));
     printf("\n");
}
 
void getKeyMessage() 
{
     int i, j;
     char msg[3];
     printf("Enter key 3x3 matrix :\n");
     for(i = 0; i < 3; i++)
          for(j = 0; j < 3; j++) 
               scanf("%f", &a[i][j]);
     printf("\nEnter the plain text : ");
     scanf("%s", msg);
     for(i = 0; i < 3; i++)
          mes[i][0] = msg[i] - 97;
}
 
void getKeyEncrypt() 
{
     int i,j,k;
     char cip[3];
     printf("Enter key 3x3 matrix :\n");
     for(i = 0; i < 3; i++)
          for(j = 0; j < 3; j++) 
              scanf("%f", &b[i][j]);
     printf("\nEnter the cipher text : ");
     scanf("%s", cip);
     for(i = 0; i < 3; i++)
          encrypt[i][0] = cip[i] - 97;
     
}

void main() 
{
     int n;
	printf("\tHill cipher\n");
	printf("\n");
	printf("1 - Encryption\t2 - Decryption\t3 - Exit\n");
	do
	{
     	printf("\nEnter your choice : ");
     	scanf("%d",&n);
     	switch(n)
     	{
     	     case 1:
     	          getKeyMessage();
               	encryption();
               	printf("\n");
               	break;
     	     case 2:
     	          getKeyEncrypt();
               	decryption();
               	printf("\n");
               	break;
               case 3:
		    printf("Exit");
                    exit(0);
     	}
	}while(n==1 || n==2);
}