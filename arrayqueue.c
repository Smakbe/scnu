#include <stdio.h>
#define MAX 8
int main(){
    int what=0;
    int stop=0;
    int data=0;
    int count=0;

    int queue[MAX];
    for(int i=0;i<MAX;i++)
    {
        queue[i]=0;//초기화
    }
    int front=-1;
    int rear=-1;
    while(stop==0)
    {
        printf("front : %d rear : %d\n",front,rear);
        printf("1. enqueue 2. dequeue 3.out");
        scanf("%d",&what);

        switch(what){
            case 1 : {
                if(count==MAX&&front==rear){
                    printf("꽉 찬 상태입니다.\n");
                    break;
                }
                else{
                    if(rear==-1&&front==-1)
                    {
                        rear++;
                        front++;
                    }
                    printf("\n데이터를 입력하시오. : ");
                    scanf("%d",&data);
                    queue[rear]=data;
                    rear++;
                    if(rear==MAX)
                    {
                        rear=0;
                    }
                    count++;
                    for(int i=0;i<MAX;i++)
                    {
                        printf("%d",queue[i]);
                    }
                    printf("\n");
                    break;
                }

            }
            case 2 : {
                if(count==0){
                    printf("공백상태입니다.");
                    break;
                }
                printf("dequeue\n");
                queue[front]=NULL;
                front++;
                if(front==MAX)
                {
                    front=0;
                }
                count--;
                for(int i=0;i<MAX;i++)
                {
                    printf("%d",queue[i]);
                }
                printf("\n");
                break;
            }
            case 3 : {
                stop++;
                break;
            }
        }
    }
}
