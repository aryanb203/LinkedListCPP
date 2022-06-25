#include<iostream>

using namespace std;

class node{
    public:

    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void Display(node* &head){
node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;
delete temp;
}

void InsertAtHead(node* &head, int x){
node* newnode= new node(x);
newnode->next=head;
head = newnode;
}

void InsertAtTail(node* &head, int x){
node* temp=head;
node* end= new node(x);
if(temp==NULL){
    InsertAtHead(head, x);
    return;
}

while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=end;
end->prev=temp;
}


void InsertAtPos(node* &head, int x, int pos){
    node* temp=head;
    for(int i=1; i<pos-1; i++){
        temp=temp->next;
    }
    node* newnode = new node(x);
    temp->next->prev=newnode;
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
}



int main(){
node* head= new node(5);
InsertAtTail(head, 6);
InsertAtTail(head, 7);
InsertAtTail(head, 9);
InsertAtHead(head, 4);
Display(head);
InsertAtPos(head, 8, 5);
Display(head);
return 0;    
}