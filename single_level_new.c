#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dir
{
  char dir_name[100];
  char file_name[100][100];
  int file_count;
}dir;

int main()
{
  dir.file_count=0;
  char f[100];
  int i;
  printf("\nEnter the Directory name\n");
  scanf("%s",dir.dir_name);
  int opt;
  do
  {
    printf("Enter the option\n");
    printf("1.Create a file\t2.Delete a file\t3.Search for a file\t4.Display\t5.Exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
      printf("Enter the file name\n");
      scanf("%s",dir.file_name[dir.file_count]);
      dir.file_count++;
      break;
      case 2:
      printf("Enter the file name\n");
      scanf("%s",f);
      for(i=0;i<dir.file_count;i++)
      {
        if(strcmp(dir.file_name[i],f)==0)
        {
          printf("Deletion successfull\n");
          strcpy(dir.file_name[i],dir.file_name[dir.file_count-1]);
          break;
        }
      }
      if(i!=dir.file_count)
      {
        dir.file_count--;
      }
      else
      {
        printf("Deletion Unsuccessful, Element not found\n");
      }
      break;
      case 3:
      printf("Enter the file name\n");
      scanf("%s",f);
      for(i=0;i<dir.file_count;i++)
      {
        if(strcmp(dir.file_name[i],f)==0)
        {
          printf("Element found\n");
          break;
        }
      }
      if(i==dir.file_count)
      {
        printf("Element not found\n");
      }
      break;
      case 4:
      printf("Files in directory %s are:\n",dir.dir_name);
      for(int i=0;i<dir.file_count;i++)
      {
        printf("%s ",dir.file_name[i]);
      }
      break;
      case 5:
      break;
    }

  }while(opt!=5);

  return 0;

}
