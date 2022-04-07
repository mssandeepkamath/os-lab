#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dir{
  char dir_name[100];
  char file_name[100][100];
  int file_count;
}dir[100];


int main()
{
  int dir_count=0;
  int i,j,k;
  int opt;
  char d[100],f[100];

  do
  {
    printf("Enter the option\n");
    printf("1.create a directory\t2.create a file\t3.delete a file\t4.search for a file\t5.display\t6.exit\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
      printf("Enter the name of the directory\n");
      scanf("%s",dir[dir_count].dir_name);
      dir[dir_count].file_count=0;
      dir_count++;
      printf("Directory created successfully\n");
      break;
      case 2:
      printf("Enter the name of the directory\n");
      scanf("%s",d);
      for(i=0;i<dir_count;i++)
      {
        if(strcmp(d,dir[i].dir_name)==0)
        {
          printf("Enter file name\n");
          scanf("%s",dir[i].file_name[dir[i].file_count]);
          dir[i].file_count++;
          printf("File created\n");
          break;
        }
      }
      if(i==dir_count)
      {
        printf("Directory not found\n");
      }
      break;
      case 3:
      printf("Enter the name of the directory\n");
      scanf("%s",d);
      for(i=0;i<dir_count;i++)
      {
        if(strcmp(d,dir[i].dir_name)==0)
        {
          printf("Enter file name\n");
          scanf("%s",f);
          for(j=0;j<dir[i].file_count;j++)
          {
            if(strcmp(f,dir[i].file_name[j])==0)
            {
              printf("File deleted\n");
              strcpy(dir[i].file_name[j],dir[i].file_name[dir[i].file_count-1]);
              break;
            }
          }
          if(i==dir[i].file_count)
          {
            printf("File not found\n");
            break;
          }else
          {
            dir[i].file_count--;
          }
          break;
        }
      }
      if(i==dir_count)
      {
        printf("Directory not found\n");
      }
      break;
      case 4:
      printf("Enter the name of the directory\n");
      scanf("%s",d);
      for(i=0;i<dir_count;i++)
      {
        if(strcmp(d,dir[i].dir_name)==0)
        {
          printf("Enter file name\n");
          scanf("%s",f);
          for(j=0;j<dir[i].file_count;j++)
          {
            if(strcmp(f,dir[i].file_name[j])==0)
            {
              printf("File found\n");
              break;
            }
          }
          if(i==dir[i].file_count)
          {
            printf("File not found\n");
            break;
          }
          break;
        }
      }
      if(i==dir_count)
      {
        printf("Directory not found\n");
      }
      break;
      case 5:
      printf("Directory->files\n");
      for(int i=0;i<dir_count;i++)
      {
        printf("%s->",dir[i].dir_name);
      for(int j=0;j<dir[i].file_count;j++)
      {
        printf("%s->",dir[i].file_name[j]);
      }
      printf("\n");
      }

      break;
      case 6:
      break;
    }

  }while(opt!=6);

  return 0;
}
