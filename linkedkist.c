#include <stdio.h>
#include <stdlib.h>

//declaring structure variable
struct node{
    int data;
    struct node *next;
};
//function for printing all elements in linked list
void print(struct node *start){
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr=start;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
//funciotn for deleting first node
struct node* del(struct node*start){
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}
//function for deleting last node
struct node * delend(struct node*start){
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr=start;
    if(start->next==NULL){
        del(start);
    }else{
    while(ptr->next->next!=NULL){
          ptr=ptr->next;
    }   
    free(ptr->next);
    ptr->next=NULL;
    return start;
}
}
//function for deleting at index
struct node*delindex(struct node*head,int index){
    if(index==0){
        del(head);
    }else{
    struct node*ptr=malloc(sizeof(struct node));
     struct node*qtr=malloc(sizeof(struct node));
    int i=0;
    ptr=head;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    qtr=ptr->next;
    ptr->next=ptr->next->next;
    free(qtr);
    return (head);
    
}
}
//function for deleting a node with given value
struct node *search_del(struct node *start,int data){
    struct node *ptr=malloc(sizeof(struct node ));
    struct node *qtr=malloc(sizeof(struct node ));
    ptr=start;
    if(start->next==NULL){
        del(start);
    }else{
    while(ptr->next->data!=data){
        ptr=ptr->next;
    }
    qtr=ptr->next;
    ptr->next=ptr->next->next;
    free(qtr);
    return start;
}
}
//function for deleting index with a given value covering all corner cases
struct node *delete(struct node*start,int data){
    struct node*ptr=malloc(sizeof(struct node));
    struct node*qtr=malloc(sizeof(struct node));
    ptr=start;
    qtr=start->next;
    if(start->data==data){
       start=start->next;
       free(ptr);
       return start;   
    }
    else{
    while(qtr->data!=data && qtr->next!=NULL){
        ptr=ptr->next;
        qtr=qtr->next;
    }
    if(qtr->data==data){
        ptr->next=qtr->next;
        free(qtr);
        return start;
    }else {
        printf("invalid input\n");
    }
}
}

int main(){
    //variable declaration
    struct node* start;
    struct node* first;
    struct node* second;
    struct node* third;

    //memory allocation
    start=malloc(sizeof(struct node));
    first=malloc(sizeof(struct node));
    second=malloc(sizeof(struct node));
    third=malloc(sizeof(struct node));

    //data given
    start->data=90;
    start->next=first;
    first->data=20;
    first->next=second;
    second->data=30;
    second->next=third;
    third->data=40;
    third->next=NULL;

      //print function
      printf("all elements of linked list:\n");
       print(start);
    
      //deleting a node at beginning
      // printf("\nafter deleting first node\n");
      // start= del(start);
      //print(start);
   
      //deleting node at end
      //printf("\nafter deleting last node\n");
      //start=delend(start);
     // print(start);
     
       
      //deleting node at index
      //printf("deleting at index\n");
      //start=delindex(start,0);
      //print(start);

      //deleting a node with given value
      //printf("after deleting node of desired value\n");
      //start=search_del(start,20);
      //print(start);
      
      //deleting node with a given value covering all cases
      //printf("after deleting given node");
      //start=delete(start,90);
      //print(start);
    return 0;
}
