#include<stdio.h>
#include<stdlib.h>


void sequencial()
{
  int file[100]={0};
  int start,length;
  int i;
  int choice;
  x:
  printf("Enter the starting block and the length\n");
  scanf("%d %d",&start,&length);
  for(i=start;i<(start+length);i++)
  {
    if(file[i]==0)
    {
      file[i]=1;
      printf("%d-->%d\n",i,file[i]);
    }
    else
    {
      printf("Block already allocated\n");
      break;
    }
  }
  if(i==start+length)
  {
    printf("The file allocated\n");
  }
  printf("Do you want to enter more?(Yes-1,No-0)\n");
  scanf("%d",&choice);
  if(choice==1)
  goto x;
  else
  exit(0);
}

void linked()
{
  int file[100]={0};
  int length,start,k,i,n,a,choice;
  printf("Enter number of blocks already alloocated\n");
  scanf("%d",&n);
  printf("Enter the allocated block number\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a);
    file[a]=1;
  }
  x:
  printf("Enter the starting block and length\n");
  scanf("%d %d",&start,&length);
  k=length;
  for(int i=start;i<start+k;i++)
  {
    if(file[i]==0)
    {
      file[i]=1;
      printf("%d-->%d\n",i,file[i]);
    }
    else
    {
      printf("%d-->allocated\n",i);
      k++;
    }
  }
  printf("File allocated succesfully\n");
  printf("Do you want to enter more?(Yes-1,No-0)\n");
  scanf("%d",&choice);
  if(choice==1)
  goto x;
  else
  exit(0);
}

void indexed()
{
  int file[100]={0};
  int index[100]={0};
  int index_pos;
  int n;
  int choice;
  x:
  printf("Enter the index block\n");
  scanf("%d",&index_pos);
  if(file[index_pos]==1)
  {
    printf("Block already allocated\n");
    goto x;
  }
  else
  {
    file[index_pos]=1;
    printf("Enter number of blocks linked into index\n");
    scanf("%d",&n);
  }
printf("Enter the blocks positions\n");
for(int i=0;i<n;i++)
{
  scanf("%d",&index[i]);
}

for(int i=0;i<n;i++)
{
  if(file[index[i]]==1)
  {
    printf("Block already allocated\n");
    goto x;
  }
  else
  {
    file[index[i]]=1;
    printf("%d->%d:%d\n",index_pos,index[i],file[index[i]]);
  }
}
printf("Do you want to enter more?(Yes-1,No-0)\n");
scanf("%d",&choice);
if(choice==1)
goto x;
else
exit(0);
}

int main()
{
  int opt;
  printf("1-sequencial\n2-Linked\n3-Indexed\n");
  scanf("%d",&opt);
  switch(opt)
  {
    case 1:sequencial();
    break;
    case 2:linked();
    break;
    case 3:indexed();
    break;
    default:
    printf("Invalid Input\n");
    break;
  }
  return 0;
}
