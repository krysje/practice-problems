#include <bits/stdc++.h> 
using namespace std;


class node {
    public:
    int data;
    node* next;

    node(int value){
        data = value;
        next = NULL;
    }
};

void insertAtTail(node* &head, int value){

    node* n = new node(value);

    if(head ==NULL){
        head = n;
        return;
    }

    node* ptr = head;

    while(ptr->next != NULL)
        ptr = ptr->next;
    
    ptr->next = n;

}

void insertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next = head;
    head = n;

}

void displayList(node* head){
    node* ptr = head;

    if(head == NULL){
        cout<<"List is Empty\n"; 
        return;
    }

    while(ptr != NULL){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL"<<endl;
}


int main(){

    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    displayList(head);

    insertAtHead(head, 4);
    insertAtHead(head, 5);

    displayList(head);


}