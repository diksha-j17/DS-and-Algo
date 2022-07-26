/*Binary tree basics Insertion, deletion, LCA, Level order, Views, Diameter of tree*/
#include<bits/stdc++.h>
#include<queue>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

//Insertion

Node* insert(int key, Node* root)
{
    if(root == NULL)
    {
        Node* newNode = new Node();
        newNode->data = key;
        newNode->right = newNode->left = NULL;
        return newNode;
    }
    queue<struct Node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct Node* temp = q.front();
        q.pop();

        if(temp->left != NULL)
            q.push(temp->left);
        else{     
                Node* newNode = new Node();
                newNode->data = key;
                temp->left = newNode;
                return root;
            }
        if(temp->right != NULL)
            q.push(temp->right);
        else{   
                Node* newNode = new Node();
                newNode->data = key;
                temp->right = newNode;
                return root;     
            }
    }
    return root;
}

//Deletion

Node* remove(int key,Node* root)
{
    if(root == NULL)
        return NULL;
    if(root->left == NULL && root->right == NULL)
        {
            if(root->data == key)
                return NULL;
            else
                return root;
        }
    queue<Node*>q;
    q.push(root);

    Node* temp;
    Node* last;
    Node* del_temp = NULL;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data == key)
            del_temp = temp;
        if(temp->left)
        {
            last = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            last = temp;
            q.push(temp->right);
        }
    }   
    if(del_temp != NULL)
    {
        del_temp->data = temp->data;
        if(last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete(temp);
    }
    return root;
}

//Inorder, Preorder and Postorder traversals 

void inorder(Node* temp)
{
    if(!temp)
        return;
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
}

void preorder(Node* temp)
{
    if(!temp)
        return;
    cout<<temp->data<<" ";
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(Node* temp)
{
    if(!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->data<<" ";
}

void levelOrder(Node* root)
{
    if(root == NULL)
        return;
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        cout<<node->data<<" ";
        q.pop();

        if(node->left != NULL)
            q.push(node->left);
        if(node->right != NULL)
            q.push(node->right);
    }

}

//Finding LCA (Lowest common ancestor)
//Using boolean values to check corner case, if n1 or n2 not present in the tree.

Node* LCA(Node* root,int n1, int n2, bool &v1, bool &v2)
{
    if(root == NULL)        return NULL;
    if(root->data == n1)    
    {
        v1 = true;
        return root;
    }
    if(root->data == n2)
    {
        v2 = true;
        return root;
    }
    Node* left_lca = LCA(root->left,n1,n2,v1,v2);
    Node* right_lca = LCA(root->right,n1,n2,v1,v2);

    if(left_lca && right_lca)       return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}

bool find(Node* root, int key)
{
    if(root == NULL)
        return false;
    if(root->data == key || find(root->left, key) || find(root->right, key))
        return true;
    return false;
}

Node* findLCA(Node* root, int n1, int n2)
{
    bool v1 = false, v2 = false;
    Node* lca = LCA(root,n1,n2,v1,v2);
    if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;
    return NULL;
}

//Find diameter of tree and height of tree
int height(Node* root)
{
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(Node* root)
{
    if(root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter  = diameter(root->left);
    int rdiameter = diameter(root->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

//Mirror tree
void mirror(Node* root)
{
    if(root == NULL)
        return;
    else
    {
        Node* temp = NULL;
        mirror(root->left);
        mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;

        inorder(root);
    }
}

int childSum(Node* root)
{
    int sum = 0;
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return 1;
    else{
        if(root->left != NULL)
            sum += root->left->data;
        if(root->right != NULL)
            sum += root->right->data;
        return ((root->data == sum) && ((childSum(root->left)) && (childSum(root->right))));          
    }  
}

int maxInBinary(Node* root)
{
    if(root == NULL)
        return 0;
    return max(root->data,max(maxInBinary(root->left),maxInBinary(root->right)));
}

int balTree(Node* root)
{
    if(root == NULL)
        return 0;
    int lh = balTree(root->left);
    if(lh == -1)
        return false;
    int rh = balTree(root->right);
    if(rh == -1)
        return -1;
    
    if(abs(lh-rh) > 1)
        return -1;
    else
        return max(lh,rh)+1;
}
int main()
{
    Node* root = NULL;
    int choice;
    cout<<"Insert Node in tree\n";
    int n,key=0;
    cout<<"Enter the number of nodes in binary tree :: ";
    cin>>n;
    cout<<"Enter nodes :: ";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        root = insert(key,root);
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
    cout<<"6. Level Order Traversal\n";
    cout<<"7. Find LCA for pair of nodes\n";
    cout<<"8. Height of tree\n";
    cout<<"9. Find diameter of tree\n";
    cout<<"10. Mirror of tree\n";
    cout<<"11. Verfiy child sum property\n";
    cout<<"12. Maximum in binary tree\n";
    cout<<"13. Check for Balanced Tree\n";
    cout<<"Enter your choice :: ";
    cin>>choice;

        switch(choice)
        {
            case 1:
            {
                int n,key=0;
                cout<<"Enter the number of nodes in binary tree :: ";
                cin>>n;
                cout<<"Enter nodes :: ";
                for(int i=0;i<n;i++)
                {
                    cin>>key;
                    root = insert(key,root);
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
                cout<<"Tree after level order traversal is :: ";
                levelOrder(root);
                cout<<endl;
                break;
            }
            case 7:
            {
                cout<<"Number of pairs you want to find LCA for :: ";
                int test;
                cin>>test;
                while(test--)
                {
                    cout<<"Input the nodes for which LCA is to be found :: ";
                    int n1,n2; 
                    cin>>n1>>n2;
                    Node* lca = findLCA(root,n1,n2);
                    if(lca != NULL)
                    {
                        printf("The LCA for %d and %d is :: %d",n1,n2,lca->data);
                        cout<<endl;
                    }
                    else
                        cout<<"Key not present\n";
                }
                break;
            }
            case 8:
            {
                cout<<"The height of the tree is :: ";
                int h = height(root);
                cout<<h<<endl;
                break;
            }
            case 9:
            {
                cout<<"Diameter of tree is :: ";
                int d = diameter(root);
                cout<<d<<endl;
                break;
            }
            case 10:
            {
                cout<<"Original tree is :: ";
                inorder(root);
                cout<<endl;
                cout<<"Mirror Tree is :: ";
                mirror(root);
                cout<<endl;
                break;
            }
            case 11:
            {
                int sum;
                if(childSum(root))
                    cout<<"Child Sum Property verified ! "<<endl;
                else
                    cout<<"Property not verified\n";
                break;
            }
            case 12:
            {
                int maxx;
                maxx = maxInBinary(root);
                cout<<"Maxmium in binary tree is :: "<<maxx;
                cout<<endl;
                break;
            }
            case 13:
            {
                int res;
                res = balTree(root);
                if(res)     cout<<"Tree is Balanced\n";
                else        cout<<"Tree Not Balanced\n";
                break;
            }
            default:
                cout<<"Invalid Input\n";
                break;
        }
    }while((choice >= 1) && (choice < 17));
    return 0;
}