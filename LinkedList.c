#include<stdio.h>
#include<conio.h>
int main(){
       float a,b,c;
       printf("Enter a number plz :");
       scanf("%f",&a);
       printf("Enter another number plz :");
       scanf("%f",&b);
       c=a*b;
       printf("Multiplication is : %f",c);
       getch();
       return 0;
       }
#include <stdio.h>
#include <stdlib.h>

struct node{
  int info;
  struct node* link;
};

struct node *START = NULL;

struct node* createNode(){
  struct node *n;
  n = (struct node*)malloc(sizeof(struct node));
  return(n);
}

void insertNode(){
  struct node *temp, *t;
  temp = createNode();
  printf("Enter a number");
  scanf("%d",&temp->info);
  temp->link = NULL;
  if(START==NULL) START = temp;
  else{
    t = START;
    while(t->link!=NULL){
      t = t->link;
    }
    t->link = temp;
  }
}

void deleteNode(){
  struct node *r;
  if(START==NULL) printf("List if Empty");
  else{
    r = START;
    START = START->link;
    free(r);
  }
}

void viewList(){
  struct node *t;
  if(START==NULL) printf("List if Empty");
  else{
    t = START;
    while(t!=NULL){
      printf("%d ",t->info);
      t = t->link;
    }
  }
}

int menu(){
  int ch;
  printf("\n1. Add Value to the list");
  printf("\n2. Delete first Value");
  printf("\n3. View List");
  printf("\n4. Exit");
  printf("\n\n Enter your choice:");
  scanf("%d",&ch);
  return(ch);
}

void main(){
  while(1){
    //clrscr();
    switch(menu()){
      case 1:
            insertNode();
            break;
      case 2:
            deleteNode();
            break;
      case 3:
            viewList();
            break;
      case 4:
            exit(0);
      default: printf("Invalid Choice");
    }
    //getch();
  }
}