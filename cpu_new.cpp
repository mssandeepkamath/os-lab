#include<bits/stdc++.h>

int burst[100];
int wait[100];
int n;
int burstcpy[100];
int b[100];

void copy()
{
  for(int i=0;i<n;i++)
  {
    burstcpy[i]=burst[i];
    b[i]=i;
  }
}

void swapp(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

void sortt(int A[])
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1-i;j++)
    {
      if(A[j]>A[j+1])
      {
        swapp(&burstcpy[j],&burstcpy[j+1]);
        swapp(&b[j],&b[j+1]);
      }
    }
  }
}

void wt_calc(int burstcpy[],int b[])
{
  wait[0]=0;
  float avgwait=0.0;
  float avgtat=0.0;
  for(int i=0;i<n;i++)
  {
    wait[i+1]=wait[i]+burstcpy[i];
    printf("Wait time for process %d : %d\n",b[i],wait[i]);
    avgwait+=wait[i];
    printf("Turn arount time for process %d : %d\n",b[i],wait[i]+burstcpy[i]);
    avgtat+=wait[i]+burstcpy[i];
  }
  printf("Average wait time: %.2f\n",avgwait/n);
  printf("Average turn around time: %.2f\n",avgtat/n);
}

void FCFS()
{
copy();
wt_calc(burstcpy,b);
}

void SJF()
{
copy();
sortt(burstcpy);
wt_calc(burstcpy,b);
}

void prior()
{
  int priority[100];
  for(int i=0;i<n;i++)
  {
    printf("Enter the priority for process %d\n",i);
    scanf("%d",&priority[i]);
  }
copy();
sortt(priority);
wt_calc(burstcpy,b);
}

void RR()
{
  copy();
  int completion[100];
  int tq;
  int t=0;
  int isComplete=0;
  float avg_wait=0.0;
  float avg_tat=0.0;
  printf("Enter the time quantum\n");
  scanf("%d",&tq);
  for(int i=0;isComplete!=n;i=(i+1)%n)
  {
    if(burstcpy[i]>0)
    {
      if(burstcpy[i]>tq)
      {
        t+=tq;
        burstcpy[i]-=tq;
      }
      else
      {
        t+=burstcpy[i];
        burstcpy[i]=0;
        completion[i]=t;
        isComplete++;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    printf("Wait time for process %d is %d\n",i,completion[i]-burst[i]);
    avg_wait+=completion[i]-burst[i];
    printf("Turn around time for process %d is %d\n",i,completion[i]);
    avg_tat+=completion[i];
  }
  printf("Average wait time: %.2f\n",avg_wait/n);
  printf("Average turn around time %.2f\n",avg_tat/n);
}

int main()
{
  int opt;
  do {
    printf("Enter number of process\n");
    scanf("%d",&n);
    printf("Enter the burst time\n");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&burst[i]);
      b[i]=i;
    }
    printf("Enter the option\n");
    printf("1-FCFS,2-SJF,3-Priority,4-Round Robin,5-exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
      FCFS();
      break;
      case 2:
       SJF();
      break;
      case 3:
      prior();
      break;
      case 4:
      RR();
      break;
      case 5:
      break;
      default:
      printf("Invalid input\n");
      break;
    }
  } while(opt!=5);
}
