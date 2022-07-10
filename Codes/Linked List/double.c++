#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node* prev;
};

//INSERTION 

void pushList(Node** head,int value)     //insertion into list
{
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;

    if(*head != NULL)           //i.e. newnode->next != null
    {
        (*head)->prev = newNode;
    }
    *head = newNode;    //move head pointer to new node
}

void insertEnd(Node** head,int value)
{
    Node* newNode = new Node;
    Node* last = *head;
    newNode->data = value;
    newNode->next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void insertOnPos(Node* Nnode, int value)
{
    Node* newNode = new Node;
    newNode->data= value;
    if(Nnode == NULL)
    {
        cout<<"Cannot add a node\n";
    }
    newNode->next = Nnode->next;
    Nnode->next = newNode;
    newNode->prev = Nnode;
    if(newNode->next == NULL)
    {
        newNode->next->prev = newNode;
    }
}

//DELETION

Node* delFront(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* ptr = head;
    head = head->next;
    delete(ptr);
    return head;
}

Node* delEnd(Node* head)
{
    Node* ptr = head;
    if(head == NULL)
        return NULL;
    else 
    {
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        Node* prevnode = (ptr->prev);
        
        prevnode->next = NULL;
        delete(ptr);
        return head;
    }
}

Node* delMid(Node* head,int pos)
{
    int count = 0;
    Node* temp = head;
    while(temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next !=NULL)                   //deletion of last node not working
        temp->next->prev = temp->prev;
    delete(temp);
    return head;
}

//SEARCHING

void search(Node* head, int ele)
{
    Node* curr = head;
    int pos=1,flag=0;
    while(curr != NULL)
    {
        if(curr->data == ele)
        {
            flag=1;
            break;
        }
        else{
            curr = curr->next;
            pos++;
        }
    } 
    if(flag==1)
    {
        cout<<"Element found at "<<pos<<" position\n";
    }
    else{
        cout<<"Element not found\n";
    }
}

//DISPLAY

void display(Node* node)
{
    cout<<"Linked List is :: ";
    while(node != NULL)
    {
        cout<<node->data<<"<->";
        node = node->next;
    }
    if(node == NULL)
    {
        cout<<"NULL";
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    int data,n;
    cout<<"Enter number of nodes in Doubly linked list :: ";
    cin>>n;
    int arr[n];
    cout<<"Enter values of the nodes :: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        pushList(&head,*(arr+i));
    }
    display(head);
    /*int valLast;
    cout<<"Enter value to be entered at the last position :: ";
    cin>>valLast;
    insertEnd(&head,valLast);
    display(head);
    head = delFront(head);
    cout<<"Linked list after deletion of first node :: ";
    display(head);
    head = delEnd(head);
    cout<<"Linked list after deletion of last node :: ";
    display(head);
    cout<<"Enter the position you want to delete :: ";
    int pos;
    cin>>pos;
    head = delMid(head,pos);
    cout<<"Linked List after removal of specific node :: ";
    display(head);
    int element,res;
    cout<<"Enter the element you want to search:: ";
    cin>>element;
    search(head,element);
    cout<<"Enter the value which you want to insert:: ";
    int val;
    cin>>val;
    insertOnPos(head->next->next,val);
    display(head);*/
    return 0;
}