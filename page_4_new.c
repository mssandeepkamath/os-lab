#include<stdio.h>
#include<stdlib.h>

int page[100];
int frame[100];
int nf,np;
int optimal[100]={0};
int flag1=0,flag2=0;
int fault;


int optimal_cal(int k)
{
int ele;
int found=0;
int pos=-1;
int j;
int i;
for(i=0;i<nf;i++)
{
for(j=k;j<np;j++)
{
  if(frame[i]==page[j])
  {
   if(j>pos)
   {
     ele=i;
     pos=j;
   }
   found=1;
  }
}
if(found==0)
{
  ele=i;
  break;
}
found=0;
}
return ele;
}



int main()
{
  printf("Enter number of pages\n");
  scanf("%d",&np);
  printf("Enter number of frames\n");
  scanf("%d",&nf);
  printf("Enter the pages\n");
  for(int i=0;i<np;i++)
  {
    scanf("%d",&page[i]);
  }


  for(int i=0;i<nf;i++)
  {
    frame[i]=-1;
  }

  for(int i=0;i<np;i++)
  {
    printf("For page %d: ",page[i]);
    flag1=flag2=0;
    for(int j=0;j<nf;j++)
    {
      if(frame[j]==page[i])
      {
        flag1=flag2=1;
        break;
      }
    }

    if(flag1==0)
    {
      for(int j=0;j<nf;j++)
      {
        if(frame[j]==-1)
        {
          frame[j]=page[i];
          flag2=1;
          fault++;
          break;
        }
      }
    }
    if(flag2==0)
    {
      int pos=optimal_cal(i+1);
      frame[pos]=page[i];
      fault++;
    }

     for(int j=0;j<nf;j++)
     {
       if(frame[j]!=-1)
       {
         printf("%d ",frame[j]);
       }
     }
     printf("\n");

  }

  printf("Total Page Fault: %d\n",fault);

  return 0;
}
