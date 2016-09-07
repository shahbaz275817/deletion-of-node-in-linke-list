#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define NULL 0
struct linked_list
{
    int number;
    struct linked_list *next;
};
typedef struct linked_list node; /*node type defined */
void main()
{
    node *head;
    int vdel;
    void create(node *p);
    int count(node *p);
    void print(node *p);
    void del(node *p,int vdel);
    head = (node *)malloc(sizeof(node));
    create(head);
    printf("\n");
    print(head);
    printf("\n");
    printf("\n Number of items = %d \n",count(head));
    printf("enter the elemet you want to delete\n");
    scanf("%d",&vdel);
    del(head,vdel);
    printf("the new linked list is \n");
    print(head);
    getch();
}

void create(node *list)
{
    printf("input a number \n");
    scanf("%d",&list->number);
    if(list->number==-999)
    {
        list->next = NULL;
    }
    else
    {
        list->next = (node *)malloc(sizeof(node));
        create(list->next);
    }
}
void print(node *list)
{
    if(list->next != NULL)
    {
       printf("\n %d",list->number);
       //if(list->next->next==NULL)
        //    printf("%d",list->next->number);
        print(list->next);
    }
}
int count(node *list)
{
    if(list->next==NULL)
        return (0);
    else
        return(1+count(list->next));
}
void del(node *list,int vdel)
{
    if(list->number==vdel)                      //deletion at beg
    {
        node *temp;
        temp=list->next;
        //list=list->next;
        list->number=list->next->number;
        list->next=list->next->next;
        free(temp);
    }
    else if(list->next->number==vdel)           //deletion at mid or end
    {
        node *gnode;
        gnode=list->next;
        list->next=list->next->next;
        free(gnode);
    }
    else
        {
            del(list->next->next,vdel);
        }

}
