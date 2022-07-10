#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

//INSERTION

void insertFront(Node** head,int val)
{
    Node* newNode = new Node;
    newNode->data = val;
    if(*head == NULL)
    {
        newNode->data = val;
        newNode ->next = newNode->prev = newNode;
        *head = newNode;
    }
    else{
        Node* last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        *head = newNode;
    }
}

void insertEnd(Node** head, int val)
{
    Node* newNode = new Node;
    Node* ptr = *head;
    newNode->data = val;
    while(ptr->next != *head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = *head;
    newNode->prev = ptr->next;
}

void insertionAfter(Node** head, int val,int key)
{
    cout<<"In function\n";
    Node* ptr = *head;
    Node* newNode = new Node;
    newNode->data = val; 
    while(ptr->data != key)
    {
        ptr = ptr->next;
    }
    Node* next = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = next;
    next->prev = newNode;
}

//DELETION
void delFront(Node** head)
{
    if(*head != NULL)
    {
        if((*head)->next == NULL)
        {
            *head = NULL;
        }
        else{
            Node* temp = *head;
            Node* first = *head;
            while(temp->next != *head)
            {
                temp = temp->next;
            }
            *head = (*head)->next;
            (*head)->prev = temp;
            temp->next = *head;
            delete(first);
        }
        
    }
}

void delEnd(Node** head)
{
    if(*head != NULL)
    {
        if((*head)-> next == *head)
        {
            *head = NULL;
        }
        else{
            Node* temp = *head;
            while(temp->next->next != *head)
            {
                temp = temp->next;
            }
            Node* last = temp->next;
            temp->next = *head;
            (*head)->prev = temp;
            delete(last);
        }
    }
}

void delMid(Node** head, int key)
{
    int pos=1;
    if(*head != NULL)
    {
        if((*head)->next == *head)
        {
            *head = NULL;
        }
        else{
            Node* temp = (*head);
            while(pos<key)
            {
                temp = temp->next;
                pos++;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete(temp);
        }
    }
}

//SEARCHING

int search(Node* head,int pos)
{
    int position = 1;
    int res;
    Node* temp = head;
    while(temp->data != pos)
    {
        position++;
        temp = temp->next; 
    }
    return position;
}

void display(Node* head)
{
    Node* ptr = head;
    cout<<"Circular doubly linked list is :: ";
    while(ptr->next != head)
    {
        cout<<ptr->data<<" <=> ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
}

int main()
{
    Node* head = NULL;
    int temp=0;
    int n;
    cout<<"Enter number of nodes in circular doubly linked list:: ";
    cin>>n;
    int key;
    cout<<"Enter values of nodes :: ";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        insertFront(&head,key);
    }
    display(head);
    cout<<"Enter value to be inserted at last position :: ";
    int value,val,node;
    cin>>value;
    insertEnd(&head,value);
    display(head);
    int del;
    /*cout<<"Enter node after which you want to enter new node:: ";
    cin>>temp;
    cout<<"Enter value of new node :: ";
    cin>>val;
    insertionAfter(&head,val,temp);
    display(head);
    cout<<"Enter node you want to search :: ";
    cin>>node;
    int res = search(head,node);
    cout<<"Position of node is :: "<<res<<"\n";*/
    cout<<"Linked List after deletion of front node :: ";
    delFront(&head);
    display(head);
    cout<<"linked list after deletion of last node::  ";
    delEnd(&head);
    display(head);
    cout<<"Enter the value you want to delete :: ";
    int pos;
    cin>>pos;
    delMid(&head,pos);
    display(head);
    return 0;
}