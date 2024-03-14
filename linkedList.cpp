#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = n;
}

void insertAtHead(node* &head,int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

bool searchInList(node* head,int val){
    while (head != NULL){
        if(head->data == val) return true;
        head = head->next;
    }
    return false;    
}

void deleteNode(node* &head,int val){
    if(head == NULL) return;
    if(head->next == NULL){
        if(head->data == val){
            delete head;
            head = NULL;
        }
        return;
    }
    if(head->data == val){
        node* next = head->next;
        delete head;
        head = next;
        return;
    }

    node* temp = head;
    while(temp->next->data != val) temp = temp->next;
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

node* reverseList(node* &head){
    node* prev = NULL;
    node* curr = head;
    node* next;
    if(curr == NULL || curr->next == NULL) return head;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void display(node* head){
    if(head == NULL){
        cout<<"NULL"<<endl;
        return;
    }
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtHead(head,0);
    display(head);
    cout<<searchInList(head,4)<<endl;
    deleteNode(head,0);
    display(head);
    head = reverseList(head);
    display(head);


    return 0;
}