
                    // TREE PROBLEM - 8
                    // WAP TO CONSTRUCT A BINARY TREE FROM ITS GIVEN INORDER AND LEVEL ORDER TRAVERSAL...


#include <iostream>
using namespace std;
struct Node{
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
void inorder(Node* root)            //modified
{
    if(root==NULL)
        return ;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
Node* buildTree(int in[],int level[],int start, int end,int* ptr)
{
    if(start>end)
        return NULL;
    Node* root=newNode(level[*ptr]);
    (*ptr)++;
    if(start==end)
        return root;
    int index=search(in,end,root->data);
    root->left=buildTree(in,level,start,index-1,ptr);
    root->right=buildTree(in,level,index+1,end,ptr);
    return root;
}
int main()
{
    int inOrder[] =    { 3,1,4,0,5,2,6};
    int levelOrder[] = { 0,1,2,3,4,5,6 };
    int n=sizeof(inOrder)/sizeof(inOrder[0]);
    int ptr=0;
    Node* root=buildTree(inOrder,levelOrder,0,n-1,&ptr);
    cout << "Constructed tree is: ";
    inorder(root);
    return 0;

}
