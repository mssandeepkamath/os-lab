#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,m,i,j,k,ind=0;
  int allocated[100][100],need[100][100],available[100],max[100][100];
  int f[100]={0},ans[100];
  printf("Enter number of processes\n");
  scanf("%d",&n);
  printf("Enter number of resources\n");
  scanf("%d",&m);
  printf("Enter the allocated matrix\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      scanf("%d",&allocated[i][j]);
    }
  }
  printf("Enter the available array\n");
  for(int i=0;i<m;i++)
  {
    scanf("%d",&available[i]);
  }
  printf("Enter the maximum matrix\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      scanf("%d",&max[i][j]);
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      need[i][j]=max[i][j]-allocated[i][j];
    }
  }
  int y=0;
int flag=0;
  for(int k=0;k<5;k++)
  {
    for(int i=0;i<n;i++)
    {
    if(f[i]==0)
    {
      flag=0;
      for(int j=0;j<m;j++)
      {
        if(need[i][j]>available[j])
        {
          flag=1;
          break;
        }
      }

      if(flag==0)
      {
        ans[ind++]=i;
        for(y=0;y<m;y++)
        {
          available[y]+=allocated[i][y];
        }
        f[i]=1;
      }
    }

    }
  }
  flag=1;

  for(int i=0;i<n;i++)
  {
    if(f[i]==0)
    {
      printf("The given sequence is not safe\n");
      flag=0;
      break;
    }
  }

  if(flag==1)
  {
      printf("The safe sequence is:\n");
    for(int i=0;i<n-1;i++)
    {
    printf("P%d->",ans[i]);

    }
      printf("P%d",ans[n-1]);
  }
  return 0;
}
