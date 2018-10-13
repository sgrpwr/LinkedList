#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
};
struct node *head;

void begInsert();   
void lastInsert();  
void ramdomInsert();  
void begDelete();  
void lastDelete();  
void randDelete();  
void display();  
void search();

int main() {
  //code
  int choice=0;
  while(choice!=9){
    cout<<"Please enter your choice:"<<endl;
    cin>>choice;
    switch(choice){
    case(1):
           begInsert();
           break;
    case(2):
           lastInsert();
           break;
    case(3):
           ramdomInsert();
           break;
    case(4):
           begDelete();
           break;
    case(5):
           randDelete();
           break;
    case(6):
           lastDelete();
           break;
    case(7):
           display();
           break;
    case(8):
           search();
           break;
    case(9):
           exit(0);
           break;
    default: cout<<"Wrong choice"<<endl;
  }
 }
 return 0;
}

void begInsert(){
  node *ptr;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr==NULL) cout<<"Overflow"<<endl;
  else{
    cout<<"Enter data for beginning:"<<endl;
    cin>>item;
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    cout<<"Node inserted at the beginning"<<endl;
  } 
}

void lastInsert(){
  node *ptr,*temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node *));
  if(ptr == NULL) cout<<"OVERFLOW"<<endl;     
  else{
      cout<<"Enter data for Last insertion:"<<endl;
      cin>>item;
      ptr->data = item;
      if(head==NULL){
         ptr->next = NULL;
         ptr = head;
         cout<<"Node inserted at the Last"<<endl;
        }
      else{
         temp = head;
         while(temp->next!=NULL) temp = temp->next;
      }
      temp->next = ptr;
      ptr->next = NULL;
      cout<<"Node inserted at the Last"<<endl;
  }
}

void ramdomInsert(){
  int i, loc, item;
  node *ptr, *temp;
  cout<<"Enter location and item respectively:"<<endl;
  cin>>loc>>item;
  ptr = (struct node*)malloc(sizeof(struct node*));
  ptr->data = item;
  temp=head;
  for(int i=0; i<loc; i++){
    temp=temp->next;
    if(temp==NULL){
      cout<<"Cannot insert"<<endl;
      return;
    }
  }
  ptr->next = temp->next;
    temp->next = ptr;
    cout<<"Inserted"<<endl;
}

void begDelete(){
  node *ptr;
  if(head==NULL) cout<<"List is empty"<<endl;
  else{
    ptr = head;
    head=ptr->next;
    free(ptr);
    cout<<"Deted"<<endl;
  }
}

void lastDelete(){
  node *ptr,*temp;
  if(head==NULL) cout<<"List is empty"<<endl;
  else if(head->next==NULL){
    head=NULL;
    free(head);
    cout<<"The only node has been deleted"<<endl;
  }
  else{
    ptr = head;
    while(ptr->next!=NULL){
      temp=ptr;
      ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
    cout<<"Deleted last node"<<endl;
  }
  temp=head;
  while(temp->next!=NULL) temp = temp->next;
}

void randDelete(){
  node *ptr,*temp;
  int loc;
  cout<<"Enter the loc:"<<endl;
  cin>>loc;
  ptr=head;
  for(int i=0; i<loc; i++){
    temp=ptr;
    ptr=ptr->next;
    if(ptr->next==NULL){
      cout<<"cannot deleted"<<endl;
      return;
    }
  }
  temp->next=ptr->next;
  free(ptr);
  cout<<"Deleted"<<endl;
}

void display(){
  node *ptr;
  if(head==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  else{
    ptr=head;
    while(ptr!=NULL){
    cout<<ptr->data<<endl;
    ptr=ptr->next;
  }
}
}

void search(){
  node *ptr;
  int item,i=0,flag=0;
  if(head==NULL){cout<<"List is empty"; return;}
  else{
    ptr=head;
    while(ptr!=NULL){
      i++;
      if(ptr->data==item){
        cout<<"It is fount on"<<i<<"th position"<<endl;
        flag=1;
        return;
      }
      ptr=ptr->next;
    }
    if(flag==0) cout<<"Number is not in the list"<<endl;
  }
}