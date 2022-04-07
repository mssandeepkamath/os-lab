#include<bits/stdc++.h>

void swapp(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main()
{
  int p[100],wt[100],burst[100],su[100];
  float avg_wait=0.0,avg_tat=0.0;
  int n;
  printf("Enter number of processes\n");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    p[i]=i;
    printf("Enter the burst time for process %d: ",i);
    scanf("%d",&burst[i]);
    printf("Enter 0 if system process, 1 if user process\n");
    scanf("%d",&su[i]);
  }

for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1-i;j++)
{
  if(su[j]>su[j+1])
  {
    swapp(&burst[j],&burst[j+1]);
    swapp(&su[j],&su[j+1]);
    swapp(&p[j],&p[j+1]);
  }
}
}

  wt[0]=0;
for(int i=0;i<n;i++)
{
  wt[i+1]=wt[i]+burst[i];
  avg_wait+=wt[i];
  avg_tat+=wt[i]+burst[i];
}

printf("\nProcess No:\t System/User\t Burst\t wait time\t turn around time\t");
for(int i=0;i<n;i++)
{
  printf("\n%d\t\t%d\t\t%d\t%d\t\t\t%d\t",p[i],su[i],burst[i],wt[i],burst[i]+wt[i]);
}
printf("\nAverage wait time: %.2f\n",avg_wait/n);
printf("\nAverage turnaround time: %.2f\n",avg_tat/n);
return 0;


}
