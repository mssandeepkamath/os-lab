#include<stdio.h>
#include<stdlib.h>
#define size 5



int eat(int tb[],int cs[],int p)
{
  if(cs[p]==1 && cs[(p+1)%size]==1)
  {
    printf("philosopher %d is eating\n",p+1);
    cs[p]=0;
    cs[(p+1)%size]=0;
    tb[p]=1;
    return 0;
  }
  else
   return -1;
}

void think(int tb[],int cs[],int p)
{
  if(cs[p]!=0 || cs[(p+1)%size]!=0)
  {
    return;
  }
  else
  {
    cs[p]=1;
    cs[(p+1)%size]=1;
    tb[p]=0;
    printf("chopstick %d anad %d are placed\n",p+1,(p+2)%size);
    printf("philosopher %d is thinkning\n",p+1);

  }
}



int main()
{
  int tb[5]={0};
  int cs[5]={1,1,1,1,1};
  int hq[10]={0};
  int sq[10]={0};
  int j=-1,j1=-1;
  for(int i=0;i<5;i++)
  {
    int x=eat(tb,cs,i);
    if(x==-1)
    {
      hq[++j]=i+1;
    }
    else
    {
      sq[++j1]=i+1;
    }
  }
  printf("Hungry queue:\n");
  for(int i=0;i<=j;i++)
  {
    printf("%d ",hq[i]);
  }
  printf("\n");
  while(j1>-1)
  {
    think(tb,cs,sq[j1]-1);
    j1--;
  }
  int count=0;
  while(count<=j)
  {
    for(int i=0;i<=j;i++)
    {
      if(hq[i]!=0)
      {
        int x=eat(tb,cs,hq[i]-1);
        if(x==0)
        {
          sq[++j1]=hq[i];
          hq[i]=0;
          count++;
        }

      }
    }
    for(int i=0;i<=j1;i++)
    {
      think(tb,cs,sq[i]-1);
    }

  }
    return 0;

}
