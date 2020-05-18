
                // TREE PROBLEM 4...
                // WAP TO CONSTRUCT A BINARY SEARCH TREE FROM ITS LEVEL ORDER TRAVERSAL


#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* getNode(int data)
{
    Node *newNode =new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* levelOrder(Node* root,int data)
{
    if(root==NULL)
        root=getNode(data);
    else if(root->data >= data)
        root->left=levelOrder(root->left,data);
    else
        root->right=levelOrder(root->right, data);
    return root;
}
Node* constructBst(int arr[],int n)
{
    if(n==0)
        return NULL;
    Node* root=NULL;
    for(int i=0;i<n;i++)
    {
        root=levelOrder(root,arr[i]);
    }
    return root;
}
void inorderTraversal(Node* root)
{
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data <<" ";
    inorderTraversal(root->right);
}
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array is: ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    Node *root = constructBst(arr, n);

    cout << "InOrder Traversal: ";
    inorderTraversal(root);
    return 0;
}
