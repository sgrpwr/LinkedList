#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void printList(struct node *n){
  while(n!=NULL){
    printf("%d ",n->data);
    n = n->next;
  }
} 

void push(struct node** head_ref, int new_data){
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void pop(struct node **head_ref, int key){
  struct node* temp = *head_ref, *prev;
  if(temp!=NULL && temp->data==key){
    *head_ref == temp->next;
    free(temp);
    return;
  }
  while(temp!=NULL && temp->data!=key){
    prev=temp;
    temp=temp->next;
  }
  if(temp==NULL) return;
  prev->next = temp->next;
  free(temp);
}



int main(void) {
  struct node* head = NULL;
  push(&head,1);
  push(&head,4);
  push(&head,3);
  printList(head);
  pop(&head,4);
  printf("\n");
  printList(head);
  return 0;
}