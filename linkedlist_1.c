#include <stdio.h>
#include <stdlib.h>
struct node{
   
    struct node *next;
     int data;
};
struct node*pt;
void ptr(struct node *a){
    while(a!=NULL){
        printf("%d \n",a->data);
        a=a->next;
    }
}
struct node *insertatbeg(struct node *start,int data){
    struct node*pt;
    pt= (struct node *)malloc(sizeof(struct node ));
    pt->next=start;
   pt->data=data;
   return pt;
}
struct node *insertatend(struct node*start,int data){
    struct node *ptr;
      ptr= (struct node *)malloc(sizeof(struct node ));
      ptr=start;
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->data=data;
      ptr->next->next=NULL;
      return NULL;

}


int main(){    
struct node *start;
struct node *first;
struct node *second;
struct node *third;
struct node *fourth;
struct node *fifth;
struct node *sixth;
struct node *seventh;
struct node *x;


struct node *insertinbet;

start= (struct node *)malloc(sizeof(struct node ));
first= (struct node *)malloc(sizeof(struct node ));
second= (struct node *)malloc(sizeof(struct node ));
third= (struct node *)malloc(sizeof(struct node ));
fourth= (struct node *)malloc(sizeof(struct node ));
fifth= (struct node *)malloc(sizeof(struct node ));
sixth= (struct node *)malloc(sizeof(struct node ));
seventh= (struct node *)malloc(sizeof(struct node ));

x= (struct node *)malloc(sizeof(struct node ));


insertinbet= (struct node *)malloc(sizeof(struct node ));



start->data=7;
start->next=first;
first->data=8;
first->next=second;
second->data=9;
second->next=insertinbet;
insertinbet->data=5;
insertinbet->next=third;
third->data=10;
third->next=fourth;
fourth->data=11;
fourth->next=fifth;
fifth->data=12;
fifth->next=sixth;
sixth->data=13;
sixth->next=seventh;
seventh->data=14;
seventh->next=NULL;




ptr(start);
x=start;
start=insertatbeg(start,56);
start=insertatbeg(start,47);
printf("\n");
ptr(start);
pt=x;
printf("\n%d\n",pt->next->data);
insertatend(start,120);
ptr(start);

return 0;
}