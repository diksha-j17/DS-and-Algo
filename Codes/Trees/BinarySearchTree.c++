/*Implementation of binary search tree*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

void insert(int key, Node** root)
{
    if(*root == NULL)
    {
        Node* newNode = new Node();
        newNode->data = key;
        newNode->left = newNode->right = NULL;
        *root = newNode;
        return;
    }
    if((*root)->data > key)
        insert(key,&(*root)->left);
    if((*root)->data < key)
        insert(key,&(*root)->right);
}

Node* remove(int key, Node* root)
{
    if(root == NULL)
        return root;
    if((root)->data > key)
    {
        (root)->left = remove(key, (root)->left);
        return (root);
    }
    else if(root->data < key )
    {
        root->right = remove(key,root->right);
        return root;
    }

        if(root->left == NULL)
        {
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node* temp = root->left;
            delete(root);
            return temp;
        }
    else
    {
        Node* temp = root;
        Node* temp2 = root->right;
        if(temp->left != NULL)
        {
            temp2 = temp;
            temp = temp->left;
        }
        if(temp2 != root)
            temp2->left = temp->right;
        else
            temp2->right = temp->right;
        root->data = temp->data;
        delete(temp);
        return root;
    }
}
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* search(Node* root, int key)
{
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return root;
    if(root->data > key)
        return search(root->left, key);
    else
        return search(root->right,key);
}
int main()
{
    Node* root = NULL;
    int choice;
    cout<<"Insert Node in tree\n";
    int n,key=0;
    cout<<"Enter the number of nodes in binary search tree :: ";
    cin>>n;
    cout<<"Enter nodes :: ";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        insert(key,&root);
        key=0;
    }
    cout<<"Tree is :: ";
    inorder(root);
    cout<<endl;
    do{
    cout<<"************** MENU ***************\n";
    cout<<"0.Exit\n";
    cout<<"1. Insert Node in tree\n";
    cout<<"2. Delete a Node from tree\n";
    cout<<"3. Inorder Traversal\n";
    cout<<"4. Preorder Traversal\n";
    cout<<"5. Postorder Traversal\n";
    cout<<"6. Search a node\n";
    cout<<"Enter your choice :: ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            {
                int n,key=0;
                cout<<"Enter the number of nodes in binary search tree :: ";
                cin>>n;
                cout<<"Enter nodes :: ";
                for(int i=0;i<n;i++)
                {
                    cin>>key;
                    insert(key,&root);
                    key=0;
                }
                cout<<"Tree is :: ";
                inorder(root);
                cout<<endl;
                break;
            }
            case 2:
            {
                int key=0;
                cout<<"Enter the node to be deleted :: ";
                cin>>key;
                root = remove(key,root);
                cout<<"Tree is :: ";
                inorder(root);
                cout<<endl;
                break;
            }
            case 3:
            {
                cout<<"Tree after inorder traversal is :: ";
                inorder(root);
                cout<<endl;
                break;
            }
            case 4:
            {
                cout<<"Tree after preorder traversal is :: ";
                preorder(root);
                cout<<endl;
                break;
            }
            case 5:
            {
                cout<<"Tree after postorder traversal is :: ";
                postorder(root);
                cout<<endl;
                break;
            }
            case 6:
            {
                cout<<"Enter the node you want to search in tree :: ";
                int find;
                cin>>find;
                root = search(root,find);
                if(!root)        cout<<"Node not found\n";
                else            cout<<"Node found! \n";
                break;
            }
            default:
            {
                cout<<"Wrong choice \n";
                break;
            }
        }
    }while(choice < 7);
    return 0;
}