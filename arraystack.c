#include <stdio.h>
#define MAX 8


int main(){
    char array[MAX];
    int top=-1; //������ �������
    int what=0;
    int stop=0;
    char data=NULL;

    for(int i=0;i<MAX;i++)
    {
        array[i]=0;//�ʱ�ȭ
    }



    while(stop==0)
    {
        printf("1. push 2.pop 3.search 4.exit");
        scanf("%d",&what);
        switch(what){
            case 1: {
                printf("\n�����͸� �Է��Ͻÿ�. : ");
                scanf("%s",&data);
                top++;
                array[top]=data;

                printf("\n������ �Ϸ�Ǿ����ϴ�.\n");


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
                printf("������ �Ϸ�Ǿ����ϴ�.\n");
                for(int i=0;array[i]!=NULL;i++)
                {
                    printf("%c ",array[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                printf("�����͸� �Է��Ͻÿ�. : ");
                scanf("%s",&data);
                for(int i=0;i<MAX;i++)
                {
                    if(array[i]==data)
                    {
                        printf("%d ��°�� �����Ͱ� �ֽ��ϴ�.\n",i+1);
                        break;
                    }
                }
                break;
            }
            case 4: {
                printf("�����մϴ�.");
                stop++;

            }
        }
    }








}
