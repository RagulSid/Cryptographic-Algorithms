#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
long int p,q,n,t,e,d,temp[100],j,m[100],en[100],i;
char msg[100],c;

long int cd(long int x) 
{
     long int k=1;
     while(1) 
     {
          k=k+t;
          if(k%x==0)
               return(k/x);
     }
}

int prime(long int pr)
{
     int i;
     j=sqrt(pr);
     for (i=2;i<=j;i++)
     {
          if(pr%i==0)
               return 0;
     }
     return 1;
}

void encrypt()
{
     long int pt,ct,key=e,k,len;
     i=0;
     len=strlen(msg);
     while(i!=len)
     {
          pt=m[i];
          pt=pt-96;
          k=1;
          for(j=0;j<key;j++)
          {
               k=k*pt;
               k=k%n;
          }
          temp[i]=k;
          ct=k+96;	//ct=(k%26)+96;
          en[i]=ct;
          i++;
     }
     en[i]=-1;
     printf("\nENCRYPTED MESSAGE IS: ");
     for(i=0;en[i]!=-1;i++)
     {
          c=en[i];
          printf("%c",c);
     }
}

void decrypt()
{
     long int pt,ct,k;
     long int key=d;
     i=0;
     while(en[i]!=-1)
     {
          ct=temp[i];
          k=1;
          for (j=0;j<key;j++)
          {
               k=k*ct;
               k=k%n;
          }
          pt=k+96;
          m[i]=pt;
          i++;
     }
     m[i]=-1;
     printf("\nDECRYPTED MESSAGE IS: ");
     for (i=0;m[i]!=-1;i++)
     {
          c=m[i];
          printf("%c",c);
     }
}

int gcd(int a, int h)
{
     int temp;
     while(1)
     {
          temp = a%h;
          if(temp==0)
               return h;
          a = h;
          h = temp;
     }
}

void main()
{
     printf("\tRSA Algorithm\n");
     printf("ENTER FIRST PRIME NUMBER : ");
     scanf("%ld",&p);
     printf("ENTER SECOND PRIME NUMBER: ");
     scanf("%ld",&q);
     if(prime(p)==0||prime(q)==0||p==q)
     {
         printf("\nWRONG INPUT\n");
         exit(1);
     }
     printf("\nENTER MESSAGE: ");
     scanf("%s",msg);
     for (i=0;msg[i]!='\0';i++)
          m[i]=msg[i];
     n=p*q;
     t=(p-1)*(q-1);
     e=2;
     while(e<t)
     {
          if(gcd(e,t)==1)
               break;
          else
               e++;
     }
     printf("\ne value is %ld",e);
     d=cd(e);
     printf("\nd value is %ld",d);
     encrypt();
     decrypt();
}