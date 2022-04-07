#include<stdio.h>
#include<stdlib.h>

int page[100];
int frame[100];
int np;
int nf;
int time[100];
int counter=0;
int fault=0;
int flag1,flag2;

int time_cal()
{
  int mini=time[0];
  int pos=0;
  for(int i=0;i<nf;i++)
  {
    if(time[i]<mini)
    {
      mini=frame[i];
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
  for(int i=0;i<np;i++)
  {
    printf("For page %d:",page[i]);
    flag1=flag2=0;
    for(int j=0;j<nf;j++)
    {
      if(frame[j]==page[i])
      {
        counter++;
        time[j]=counter;
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
          counter++;
          time[j]=counter;
          frame[j]=page[i];
          fault++;
          flag2=1;
          break;
        }
      }
    }

    if(flag2==0)
    {
      int pos=time_cal();
      counter++;
      time[pos]=counter;
      frame[pos]=page[i];
      fault++;
    }

    for(int i=0;i<nf;i++)
    {
      if(frame[i]!=-1)
      {
        printf("%d ",frame[i]);
      }
    }
    printf("\n");

  }
}
