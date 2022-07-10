#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

/* INSERTION*/
void push(struct Node** head,int node_data)         //insert new node in LL in front
{
    struct Node* newNode = new Node;
    newNode->data = node_data;
    newNode->next = (*head);
    (*head) = newNode;          //move the head pointer to newNode
}
void pushAfter(struct Node* prev,int node_data)        //insert new node after a given node
{
    if(prev == NULL)
    {
        cout<<"Previous node is NULL ";
        return;
    }
        struct Node* newNode = new Node;
        newNode->data = node_data;
        newNode->next = prev->next;
        prev->next = newNode;
}
void replace(struct Node** head, int act, int replc)
{
    Node* curr = *head;
    while(curr!= NULL)
    {
        if(curr->data == act)
        {
            struct Node* newNode = new Node;
            newNode->data = replc;
            newNode->next = (*head);
            //newNode->next = curr->next;
            //curr->next = newNode;
        }
    }
}
void append(struct Node** head,int node_data)           //insert new node at end of LL
{
    struct Node* newNode = new Node;
    struct Node* last = *head;
    newNode->data = node_data;
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    while(last->next != NULL)
        last = last->next;
        last->next = newNode;
        return;
}

/*DELETION*/

Node* delfront(struct Node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* removeEnd(struct Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node* sec_last = head;
    while(sec_last->next->next != NULL)
        sec_last = sec_last->next;
    delete(sec_last->next);
    sec_last->next = NULL;
    return head;
}

int search(Node* head, int key)
{
    int pos = 1;
    Node* curr = head;
    while(curr!= NULL)
    {
        if(curr->data == key)
        {
            return pos;
        }
        else
        {
            pos++;
            curr = curr->next;
        } 
    }
    return -1;
}
void display(struct Node* node)
{
    while(node != NULL)
    {
        cout<<node->data<<"->";
        node = node->next;
    }
    if(node == NULL)
    {
        cout<<"null";
    }
    cout<<endl;
}

int main()
{
    struct Node* head = NULL;
    int n,val,ans,rep;
    cout<<"Enter the number of nodes in the list :: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the nodes of the linked list :: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        push(&head,*(arr+i));
    }
    cout<<"LINKED LIST IS "<<endl;
    display(head);
    /*Node* temp;
    int key,pos;
    head = delfront(head);
    cout<<"Linked list after removal of first node :: ";
    display(head);
    head = removeEnd(head);
    cout<<"Linked list after removal of last node :: ";
    display(head);
    cout<<"Enter the element you want to search :: ";
    cin>>key;
    cout<<"Position of the element is :: ";
    pos = search(head,key);
    if(pos == -1)
    {
        cout<<"Element not found"<<endl;
    }
    else 
    {
        cout<<pos<<endl;
    }
    cout<<"Search and replace an element in the linked list "<<endl;
    cout<<"Input the element you want to search: ";
    cin>>val;
    ans = search(head,val);
    if(ans == -1)
    {
        cout<<"The element is not found in the linked list"<<endl;
    }
    else 
    {
        cout<<"Enter the replaced value:: ";
        cin>>rep;
        replace(&head,val,rep);
    }
    cout<<"LINKED LIST IS ";
    display(head);
    //append(&head,95);           //insertion at end of Linked list
    //cout<<"MODIFIED LINKED LIST IS "<<endl;
    //display(head);*/
    return 0;
} 