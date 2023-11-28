#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* up;
    struct node* left;
    struct node* right;
}node;



node* addnode(node* root,int a)
{
    if(root==NULL)
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->left=NULL;
        newnode->up=NULL;
        newnode->right=NULL;

        root=newnode;
        return root;
    }
    else
    {

        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=a;
        newnode->up=root;
        newnode->left=NULL;
        newnode->right=NULL;

        int where=0;
        printf("1.left 2.right");
        scanf("%d",&where);
        if(where==1)
        {
            if(root->left==NULL)
            {
                root->left=newnode;
                return root;
            }
            else
            {
                printf("left is not empty");
                free(newnode);
                return root;
            }

        }
        else if(where==2)
        {
            if(root->right==NULL)
            {
                root->right=newnode;
                return root;
            }
            else
            {
                printf("right is not empty");
                free(newnode);
                return root;
            }
        }

    }
}

void gnorder(node* root) //LRV
{
    node* temp=root;
    if(temp->left!=NULL)
    {
        gnorder(temp->left);
    }
    if(temp->right!=NULL)
    {
        gnorder(temp->right);
    }
    printf("%d",temp->data);
}


node* ptrmove(node* ptr)
{
    int where;
    printf("1.left 2.right 3. up");
    scanf("%d",&where);

    if(where==1)
    {
        if(ptr->left==NULL)
        {
            printf("left is null");
            return ptr;
        }
        ptr=ptr->left;
        return ptr;
    }
    else if(where==2)
    {
        if(ptr->right==NULL)
        {
            printf("right is null");
            return ptr;
        }
        ptr=ptr->right;
        return ptr;
    }
    else if(where==3)
    {
        if(ptr->up==NULL)
        {
            printf("root node");
            return ptr;
        }
        ptr=ptr->up;
        return ptr;
    }
}

void lvorder(node* root)
{
    printf("%d",root->data);

    if(root->left!=NULL)
    {
        printf("%d",(root->left)->data);
    }
    if(root->right!=NULL)
    {
        printf("%d",(root->right)->data);
    }
}



int main(){
    int dat,what,stop=0;
    node* root=NULL;

    while(stop==0)
    {

        if(root!=NULL)
        {
            printf("  %d\n",root->data); //현재 노드의 데이터
            printf("%p %p",root->left,root->right); //노드의 왼쪽/오른쪽 값
        }

        printf("1.addnode 2.order 3.ptrmove");
        scanf("%d",&what);
        if(what==1)
        {
            printf("데이터를 입력하시오.");
            scanf("%d",&dat);
            root=addnode(root,dat);
        }
        else if(what==2)
        {
            gnorder(root);
        }
        else if(what==3)
        {
            root=ptrmove(root);
        }
        else if(what==4)
        {
            lvorder(root);
        }
        else
        {
            printf("다시 입력해주세요.");
        }
    }
}
