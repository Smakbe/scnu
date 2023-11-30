#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* befo; //���� ���Ḯ��Ʈ
}node;

node* insert(node* ptr,node* front){
    node* temp=ptr;
    node* newnode=(node*)malloc(sizeof(node));
    int d;
    printf("�����͸� �Է��Ͻÿ�.");
    scanf("%d",&d);
    newnode->data=d;
    newnode->befo=ptr;//���� ���Ḯ��Ʈ
    if(ptr->next!=NULL)
    {
        temp=ptr->next;
        ptr->next=newnode;
        newnode->next=temp;

    }
    else if(ptr->next==NULL)//ȯ���ϰ�� front
    {
        ptr->next=newnode;
        newnode->next=NULL;//ȯ���ϰ�� front
    }
    ptr=ptr->next;
    return ptr;
}

node* deletel(node* ptr,node* main)
{
    //���� ���Ḯ��Ʈ�� befo�� Ȱ���Ͽ� �� ���� ����
    if(ptr->next!=NULL)
    {

        node* check=main;
        node* before;
        while(check!=ptr)
        {
            before=check;
            check=check->next;
        }
        node* temp=ptr->next;
        before->next=temp;

        free(check);
        ptr=before;


        return ptr;


    }
    else if(ptr->next==NULL)
    {
        node* check=main;
        node* before;
        while(check->next!=NULL)
        {
            before=check;
            check=check->next;
        }
        printf("%d before�� ��",before->data);
        if(main==ptr)
        {
            printf("���� �� �����ϴ�.");
            return ptr;
        }
        before->next=NULL;
        free(check);
        ptr=before;

        return ptr;
    }
}

node* delete_first(node* main)
{
    node* temp=main;
    main=main->next;
    free(temp);
    return main;
}

node* first(node* main)
{
    node* newnode=(node*)malloc(sizeof(node));
    int d;
    printf("�����͸� �Է��Ͻÿ�.");
    scanf("%d",&d);
    newnode->data=d;
    newnode->next=main;
    newnode->befo=NULL;//���� ���Ḯ��Ʈ
    main=newnode;
    return main;
}

void printlist(node* main){
    node* temp=main;
    while(temp->next!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    printf("%d\n",temp->data);

}

int main(){
    int what=0;
    int stop=0;
    int d;
    printf("���� ó�� ����� �����͸� �Է��Ͻÿ�.");
    scanf("%d",&d);
    node* main=(node*)malloc(sizeof(node));
    main->data=d;
    main->next=NULL;
    main->befo=NULL;//���� ���Ḯ��Ʈ
    node* ptr=main;

    while(stop==0)
    {

        printlist(main);
        printf("���� ptr�� ������ = %d\n",ptr->data);
        printf("1. insert 2.delete 3.delete_first 4.first 5.ptrup 6.exit");
        scanf("%d",&what);
        switch(what)
        {
            case 1:
                {
                    ptr=insert(ptr,main);
                    break;
                }
            case 2:
                {
                    ptr=deletel(ptr,main);
                    break;
                }
            case 3:
                {
                    main=delete_first(main);
                    break;
                }
            case 4:
                {
                    main=first(main);
                    break;
                }
            case 5:
                {
                    if(ptr->next!=NULL){
                        ptr=ptr->next;
                    }
                    else if(ptr->next==NULL){
                        ptr=main;
                    }
                    break;
                }
            case 6:
                {
                    stop++;
                    break;
                }

        }
    }
}
