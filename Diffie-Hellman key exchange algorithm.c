#include <stdio.h>
#include<math.h>
int power(int base,int exponent,int q)
{
     int k=1;
     for (int j=0;j<exponent;j++)
     { 
          k=k*base;
          k=k%q;
     }
     return k;
}

int main()
{
     int q,alpha,Xa,Xb,Ya,Yb,k1,k2;
     printf("\tDiffie-Hellman key exchange Algorithm\n");
     printf("Enter the value of q\t\t: ");
     scanf("%d",&q);
     printf("Enter the primitive root α\t: ");
     scanf("%d",&alpha);
     printf("Enter the private key of User A : ");
     scanf("%d",&Xa);
     printf("Enter the private key of User B : ");
     scanf("%d",&Xb);
     Ya=power(alpha,Xa,q);
     Yb=power(alpha,Xb,q);
     k1=power(Yb,Xa,q);
     k2=power(Ya,Xb,q);
     printf("\nPublic key of User A: %d\nPublic key of User B: %d\n",Ya,Yb);
     printf("\nKey 1: %d\nKey 2: %d\n",k1,k2);
     return 0;
}