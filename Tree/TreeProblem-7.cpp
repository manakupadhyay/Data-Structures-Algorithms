
                // TREE PROBLEM-7
                // WAP TO CONSTRUCT A BINARY TREE FROM ITS INORDER AND POSTORDER TRAVERSAL...


#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* newNode= new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
int search(int arr[],int value,int n)
{
    int i;
    for( i=0;i<=n;i++)
    {
        if(arr[i]==value)
            return i;
    }
}
void inorder(Node* root)
{
    if(root==NULL)
        return ;
        cout << root->data << " ";  // changed...
    inorder(root->left);

    inorder(root->right);
}
Node* buildTree(int in[],int post[],int start,int end,int* ptr)
{
    if(start>end)
        return NULL;
    Node* root=newNode(post[*ptr]);
    (*ptr)--;

    if(start==end)              // if the node has no children...
        return root;
    int index=search(in,root->data,end);
     root->right=buildTree(in,post,index+1,end,ptr);
    root->left=buildTree(in,post,start,index-1,ptr);

    return root;
}
int main()
{
    int in[]   = {9,3,2,5,4};
    int post[] = {5,9,3,4,2};
    int n=sizeof(in)/sizeof(in[0]);
    int ptr=n-1;
    Node* root=buildTree(in,post,0,n-1,&ptr);
    cout << "Constructed tree is: ";
    inorder(root);
    return 0;
}
