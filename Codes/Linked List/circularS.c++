#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

//INSERTION

Node* insertFront(Node* head, int val)
{
    Node* newnode = new Node;
    newnode -> data = val;   

    if (head == NULL)
    {
        //cout <<"\nInside if(), i.e., first entry\n";
        head = newnode;
        head -> next = newnode;
        return head;
    }

    else
    {
        //cout <<"\nInside else(), i.e., 2....n entry\n";
        newnode -> next = head;
        Node* end = head;
        while (end -> next != head)     end = end -> next;

        end -> next = newnode;
        head = newnode;

        return head;
    }
}

Node* insertionEnd(Node* head, int val)         
{
    Node* last = head;
    Node* newnode= new Node;
    newnode->data = val;
    while(last->next != head)
    {
        last = last->next;
    }
    last->next = newnode;
    newnode->next = head;
    last = last->next;
    return head;
}

void insertionAfter(Node* head,int pos, int val)
{
    Node* tail = head;
    Node* newNode = new Node;
    newNode->data = val;
    int position=1;
    while(position != pos)
    {
        tail = tail->next;
        position++;
    }
    newNode->next = tail->next;
    tail->next = newNode;
}

/*void insertionBefore(Node* head,int pos, int val)           //?
{
    Node* tail = head;
    Node* newNode = new Node;
    newNode->data = val;
    int position = 1;
    while(position <pos)
    {
        tail = tail->next;
        position++;
    }
    newNode->next = tail->next;
    tail->next = newNode;
}*/

//DELETION

Node* delFront(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return NULL;
    }
    Node* temp = head;
    Node* temp1 = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = temp1->next;
    head = temp->next;
    delete(temp1);
    return head;

}

Node* delEnd(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* temp = head;
    Node* temp1 = head;
    while(temp->next != head)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    head = temp1->next;
    delete(temp);
    return head;
}

Node* delAfter(Node* head, int pos)
{
    Node* ptr = head;
    Node* temp = head;
    int position = 1;
    while(temp->next != head)
    {
        if(position!=pos)
        {
            temp = temp->next;
            //ptr = temp->next;
            position++;
        }
        else 
        {
            ptr = temp->next;
            temp->next = temp->next->next;
            delete(ptr);
        }
    }
    delFront(head);
    return head;
}

/*Node* delBefore(Node* head, int pos)
{

}*/

//SEARCHING
int search(Node* head, int val)
{
    Node* ptr = head;
    int ctr=1;
    while(ptr->data != val)
    {
        ctr++;
        ptr= ptr->next;
    }
    return ctr;
}

//DISPLAY

void display(Node* head)
{
    Node* temp = head;
    if(head == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }
    cout<<"Linked list is :: ";      
    do{
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    
    int n, end;
    cout<<"Enter number of nodes in linked list :: ";
    cin>>n;
    cout<<"Enter the value of nodes :: ";
    int key = 0;
    for(int i=0;i<n;i++)
    {
        cin >> key;
        head = insertFront(head, key);
    }
    display(head);
    //cout<<"Insertion at end :: ";
    //cin>>end;
    //head = insertionEnd(head,end);
    /*cout<<"Enter pos after which you want to insert node  ";
    int pos,mid;
    cin>>pos;
    cout<<"and value to be inserted:: ";
    cin>>mid;
    insertionAfter(head,pos,mid);
    display(head);
    int place,bef;
    cout<<"Enter position before whihch you want to insert node :: ";
    cin>>place;
    cout<<"Enter value to be inserted:: ";
    cin>>bef;
    insertionBefore(head,place,bef);
    display(head);*/
    cout<<"Enter the value of node you want to search :: ";
    int val;
    cin>>val;
    int res = search(head,val);
    cout<<"Position of node is :: "<<res<<endl;
    /*cout<<"Deletion from front :: ";
    head = delFront(head);
    display(head);
    cout<<"Deletion from end :: ";
    head = delEnd(head);
    display(head);*/
    int m;
    cout<<"Enter pos after which you want or delete :: ";
    cin>>m;
    head = delAfter(head,m);
    display(head);
    return 0;
}