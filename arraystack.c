#include <stdio.h>
#define MAX 8


int main(){
    char array[MAX];
    int top=-1; //최초의 공백상태
    int what=0;
    int stop=0;
    char data=NULL;

    for(int i=0;i<MAX;i++)
    {
        array[i]=0;//초기화
    }



    while(stop==0)
    {
        printf("1. push 2.pop 3.search 4.exit");
        scanf("%d",&what);
        switch(what){
            case 1: {
                printf("\n데이터를 입력하시오. : ");
                scanf("%s",&data);
                top++;
                array[top]=data;

                printf("\n삽입이 완료되었습니다.\n");


                //for(int i=0;array[i]!=NULL;i++)
                //{
                //    printf("%c ",array[i]);
                //}
                int a=0;
                while(array[a]!=NULL)
                {
                    printf("%c",array[a]);
                    a++;
                }
                printf("\n");
                break;
            }
            case 2: {
                printf("%c",array[top]);
                array[top]=NULL;
                top--;
                printf("삭제가 완료되었습니다.\n");
                for(int i=0;array[i]!=NULL;i++)
                {
                    printf("%c ",array[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                printf("데이터를 입력하시오. : ");
                scanf("%s",&data);
                for(int i=0;i<MAX;i++)
                {
                    if(array[i]==data)
                    {
                        printf("%d 번째에 데이터가 있습니다.\n",i+1);
                        break;
                    }
                }
                break;
            }
            case 4: {
                printf("종료합니다.");
                stop++;

            }
        }
    }








}
