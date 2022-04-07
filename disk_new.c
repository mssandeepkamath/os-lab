#include<stdio.h>
#include<stdlib.h>

int headpos;
int disk[100];
int n;
int curpos;
int total_head=0;
int cdisk[100];

int abss(int x)
{
  if(x>=0)
  return x;
  else
  return -x;
}
void swapp(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

void sortt(int arr[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        swapp(&cdisk[j],&cdisk[j+1]);
      }
    }
  }
}

void copy()
{
  for(int i=0;i<n;i++)
  {
    cdisk[i]=disk[i];
  }
}

int main()
{
  printf("Enter the head position\n");
  scanf("%d",&headpos);
  printf("Enter number of requests\n");
  scanf("%d",&n);
  printf("Enter the disk requests\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&disk[i]);
  }
  printf("\n__________________________________________________\n");
  printf("FCFS\n");
  curpos=headpos;
  for(int i=0;i<n;i++)
  {
    printf("Head moves from cyclinder position %d to %d\n",curpos,disk[i]);
    total_head+=abss(curpos-disk[i]);
    curpos=disk[i];
  }
  printf("Total head movement: %d\n",total_head);
  printf("\n__________________________________________________\n");
  printf("SSTF\n");
  curpos=headpos;
  int nextpos;
  copy();
  total_head=0;
  for(int i=0;i<n;i++)
  {
      nextpos=-1;
      int d=9999;
    for(int j=0;j<n;j++)
    {
      if(cdisk[j]!=-1 && abss(cdisk[j]-curpos)<d)
      {
        d=abss(cdisk[j]-curpos);
        nextpos=j;
      }
    }
      printf("Disk head moves from cylinder position %d to %d\n",curpos,cdisk[nextpos]);
      total_head+=abss(curpos-cdisk[nextpos]);
      curpos=cdisk[nextpos];
      cdisk[nextpos]=-1;
  }
  printf("Total head movement: %d\n",total_head);
  printf("\n__________________________________________________\n");
  printf("SCAN\n");
  copy();
  cdisk[n]=0;
  cdisk[n+1]=200;
  sortt(cdisk,n+2);
  curpos=headpos;
  int a=0;
  for(int i=0;cdisk[i]<=curpos;i++)
  {
    a++;
  }
  a--;
  total_head=0;
  for(int i=a;i>=0;i--)
  {
      printf("Disk head moves from cylinder position %d to %d\n",curpos,cdisk[i]);
      total_head+=abss(curpos-cdisk[i]);
      curpos=cdisk[i];
      cdisk[i]=-1;
  }
  for(int i=0;i<n+2;i++)
  {
    if(cdisk[i]!=-1)
    {
      printf("Disk head moves from cylinder position %d to %d\n",curpos,cdisk[i]);
      total_head+=abss(curpos-cdisk[i]);
      curpos=cdisk[i];
      cdisk[i]=-1;
    }
  }
  printf("Total head movement: %d\n",total_head);
  printf("\n__________________________________________________\n");
  printf("C-SCAN\n");
  copy();
  sortt(cdisk,n);
  a=0;
  total_head=0;
  curpos=headpos;
  for(int i=0;cdisk[i]<=curpos;i++)
  {
    a++;
  }
  a--;
  for(int i=a;i>=0;i--)
  {
      printf("Disk head moves from cylinder position %d to %d\n",curpos,cdisk[i]);
      total_head+=abss(curpos-cdisk[i]);
      curpos=cdisk[i];
      cdisk[i]=-1;
  }
  for(int i=0;i<n;i++)
  {
    if(cdisk[i]!=-1)
    {
      printf("Disk head moves from cylinder position %d to %d\n",curpos,cdisk[i]);
      total_head+=abss(curpos-cdisk[i]);
      curpos=cdisk[i];
      cdisk[i]=-1;
    }

  }
  printf("Total head movement: %d",total_head);
    return 0;


}
