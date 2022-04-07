#include<stdio.h>
#include<stdlib.h>

int page[100];
int frame[100];
int nf,np;
int freq[100];
int flag1=0,flag2=0;
int fault;


int freq_cal()
{
  int mini=freq[0];
  int pos=0;
  for(int i=0;i<nf;i++)
{
  if(freq[i]<mini)
  {
    mini=freq[i];
    pos=i;
  }
}
return pos;
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

  for(int i=0;i<nf;i++)
  {
    freq[i]=0;
  }

  for(int i=0;i<np;i++)
  {
    printf("For page %d: ",page[i]);
    flag1=flag2=0;
    for(int j=0;j<nf;j++)
    {
      if(frame[j]==page[i])
      {
        freq[j]++;
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
          freq[j]++;
          frame[j]=page[i];
          flag2=1;
          fault++;
          break;
        }
      }
    }
    if(flag2==0)
    {
      int pos=freq_cal();
      frame[pos]=page[i];
      freq[pos]=1;
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
