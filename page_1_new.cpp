#include<stdio.h>
#include<stdlib.h>

int page[100];
int frame[100];
int np,nf;
int fault;
int hit;

int ishit(int item)
{
  hit=0;
  for(int i=0;i<nf;i++)
  {
    if(frame[i]==item)
    {
      hit=1;
      return hit;
    }
  }
  return hit;
}

void display()
{
  for(int i=0;i<nf;i++)
  {
    if(frame[i]!=-1)
    {
      printf("%d ",frame[i]);
    }

  }
    printf("\n");
}

int main()
{
  printf("Enter number of pages\n");
  scanf("%d",&np);
  printf("Enter number of frames\n");
  scanf("%d",&nf);
  printf("Enter the pages size\n");
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
    if(ishit(page[i])==0)
    {
      for(int i=1;i<nf;i++)
      {
        frame[i-1]=frame[i];
      }
      frame[nf-1]=page[i];
      fault++;
      display();
    }
    else
    {
      printf("No page fault\n");
    }
  }

  printf("Total page fault:%d\n",fault);


}
