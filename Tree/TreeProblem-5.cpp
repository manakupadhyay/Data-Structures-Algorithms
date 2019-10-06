
                        // TREE PROBLEM 5
                        // WAP TO CONSTRUCT A BALANCED BINARY TREE FROM ITS INORDER AND PREORDER TRAVERSAL...


#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
};
int search(int arr[], int strt, int end, int value)
{
    int i;
    for(i=strt;i<=end;i++)
    {
        if(arr[i]==value)
            return i;
    }
}
node* newNode(int data)
{
    node* newNode=new node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
node* buildTree(int in[], int pre[], int start, int end)
{
    static int preIndex = 0;
    if(start>end)
        return NULL;
    node* root=newNode(pre[preIndex++]);
    if(start==end)          // if size is one...
        return root;
    int index=search(in,start,end,root->data);
    root->left=buildTree(in,pre,start,index-1);
    root->right=buildTree(in,pre,index+1,end);

}
void printInorder(node* node)
{
    if (node == NULL)
        return;


    printInorder(node->left);


    cout<<node->data<<" ";


    printInorder(node->right);
}

int main()
{
    int in[] =  { 1,3,4,6,7,8,10,13,14};
    int pre[] = { 8,3,1,6,4,7,10,14,13};
    int len = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, pre, 0, len - 1);
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
