#include<stdio.h>
#include<stdlib.h>
#define BUFFER 5

int s=1;
int empty=BUFFER;
int full=0;
int ele=0;

int wait(int s)
{
  return --s;
}

int signal(int s)
{
  return ++s;
}

void produce()
{
  s=wait(s);
  empty=wait(empty);
  full=signal(full);
  ele++;
  printf("Producer produced item %d\n",ele);
  s=signal(s);
}

void consume()
{
  s=wait(s);
  empty=signal(empty);
  full=wait(full);
  printf("Consumer consumed item %d\n",ele);
  ele--;
  s=signal(s);
}

int main()
{
  int opt;
  do {
    printf("Enter option\n");
    printf("1-Produce,2-Consume,3-exi\n");
    scanf("%d",&opt);
    switch(opt)
    {
      case 1:
            if(s==1 && empty!=0)
            {
              produce();
            }
            else
            {
              printf("Buffer full\n");
            }

            break;

    case 2:
        if(s==1 && full!=0)
        {
          consume();
        }
        else
        {
          printf("Buffer empty\n");
        }

        break;

   case 3:
   break;
    }
  } while(opt!=3);
  return 0;
}
