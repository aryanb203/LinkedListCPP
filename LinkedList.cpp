#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }

}*head=NULL;

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head, int val){
    node *n = new node(val);
    n->next=head;
    head=n;

}

void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void displayRev(node *head){ //displaying linked list in reversed order using recursion
    node *temp=head;
    if(temp!=NULL){
        displayRev(temp->next);
        cout<<temp->data<<" ";
    }

}

void countnode(node *head){
    node *temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    cout<<count<<endl;
}


bool search(node* head, int key){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==key)
            return true;
    temp=temp->next;
    }
    return false;
}

void DisplaySum(node *head){
    node *temp=head;
    int sum=0;
    while(temp!=NULL){
        sum+=temp->data;
        temp=temp->next;
    }
    cout<<sum<<endl;
}

void deleteAtHead(node* &head){
node *del=head;
head=head->next;
delete del;
}

void deletion(node* &head, int val){

    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    if(head->data==val){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while((temp->next->data)!=val){
        temp=temp->next;
    }
    node* deleteNode=temp->next;
    temp->next=temp->next->next;
    delete deleteNode;
}

void reverseSliding(node* &head){
    node* p=head;
    node* q=NULL;
    node *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;

        q->next=r;
    }
    head=q;
}

node* reverseRecursive(node* &head){
    if(head==NULL || head->next==NULL)
        return head;

    node* newhead= reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;

    return newhead;
}

node* merge2LL(node* l1, node* l2){
    if(l1==NULL)    return l2;
    if(l2==NULL)    return l1;
    node* swap;
    if(l1->data>l2->data){
        swap=l2;
        l2=l1;
        l1=swap;
    }
    node* res=l1;
    
    while(l1!=NULL && l2!=NULL){
        node *temp=NULL;
        while(l1!=NULL && (l1->data)<=(l2->data)){
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        node* swap=l1;
        l1=l2;
        l2=swap;
    }
    

return res;

}

node* reversek(node* &head, int k){ //learn properly
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;

    int count=0;
    while(currptr!=NULL && count<k){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }

    if(nextptr!=NULL)
            head->next=reversek(nextptr, k);
    
    return prevptr;
}

int isCycle(node* &head){
    node* p=head;
    node* q=head;

    while(q!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
        if(p==q)
            return 1;
    }
    return 0;  
}

void removeCycle(node* &head){
    node* p=head;
    node* q=head;

    do
    {
        p=p->next;
        q=q->next->next;
    } while (p!=q);
    
    p=head;
    while(p->next!=q->next){
        p=p->next;
        q=q->next;
    }
    q->next=NULL;
}

void DisplayCircular(node* &head){
    node* p=head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);

}



int main(){

    node *head1=NULL;
    node *head2=NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    display(head);
    insertAtHead(head, 2);
    display(head);
    cout<<search(head, 3)<<endl;
    displayRev(head);
    cout<<endl;
    countnode(head);
    DisplaySum(head);
    

    insertAtTail(head1,2);
    insertAtTail(head1,8);
    insertAtTail(head1,10);
    insertAtTail(head1,15);
    insertAtTail(head2,4);
    insertAtTail(head2,7);
    insertAtTail(head2,12);
    insertAtTail(head2,14);
    insertAtTail(head2,17);

    node* head=merge2LL(head1, head2);
    display(head);
    node* reversekhead= reversek(head,5);
    display(reversekhead);
    node* t1=head;
    while(t1->next!=NULL){
        t1=t1->next;
    }
    t1->next=head;
    

    cout<<isCycle(head)<<endl;
    removeCycle(head);
    cout<<isCycle(head)<<endl;

return 0;
}