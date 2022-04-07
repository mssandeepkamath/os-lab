#include<stdio.h>
#include<stdlib.h>

int hole[100];
int process[100];
int np;
int nh;


int firstfit(int process)
{
  int pos=999;
  for(int i=0;i<nh;i++)
  {
    if(hole[i]>=process)
    {
      pos=i;
      return pos;
    }
  }
return pos;
}

int bestfit(int process)
{
  int best=9999;
  int pos=999;
  for(int i=0;i<nh;i++)
  {
    if(hole[i]>=process && hole[i]<=best)
    {
      best=hole[i];
      pos=i;
    }
  }
  return pos;
}


int worstfit(int process)
{
  int worst=hole[0];
  int pos;
  for(int i=0;i<nh;i++)
  {
    if(hole[i]>worst)
    {
      worst=hole[i];
      pos=i;
    }
  }
  if(worst>=process)
  return pos;
  else
  return 999;
}

void display(int choice)
{
  int pos;
  for(int i=0;i<np;i++)
  {
    printf("process:%d\tprocess size:%d\t",i,process[i]);
    if(choice==1)
     pos=firstfit(process[i]);
    else if(choice==2)
     pos=bestfit(process[i]);
    else
     pos=worstfit(process[i]);

    if(pos==999)
    {
      printf("Memory not allocated\n");
    }
    else
    {
      printf("block number %d\n",pos+1);
      hole[pos]-=process[i];
    }
  }
}


int main()
{
  printf("Enter number of holes\n");
  scanf("%d",&nh);
  printf("Enter the block size of holes\n");
  for(int i=0;i<nh;i++)
  {
    scanf("%d",&hole[i]);
  }
  printf("Enter number of process\n");
  scanf("%d",&np);
  printf("Enter the size of the process\n");
  for(int i=0;i<np;i++)
  {
    scanf("%d",&process[i]);
  }
  int choice;
printf("Enter the choice 1-firstfit,2-bestfit,3-worstfit\n");
scanf("%d",&choice);
switch(choice)
{
  case 1:
   display(1);
  break;
  case 2:
  display(2);
  break;
  case 3:
  display(3);
  break;
  default:
  break;
}
  return 0;
}
