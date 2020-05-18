
                    // TREE PROBLEMS...
        // WAP TO CONVERT A BINARY TREE TO BINARY SEARCH TREE.


#include <iostream>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);

}
node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void sortArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-1)-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void copytoArray(node* root,int arr[],int *n)       // i have applied inorder traversal..we can traverse with other techniques also...
{
    if(root==NULL)
        return;
    copytoArray(root->left,arr,n);
    arr[*n]=root->data;
    (*n)++;
    copytoArray(root->right,arr,n);
}
int count(node* root)
{
    if(root==NULL)
        return 0;
    return count(root->left)+count(root->right)+1;
}
void arrayToBST(int arr[],node* root,int *n)
{
    if(root==NULL) return;
    arrayToBST(arr,root->left,n);
    root->data=arr[*n];
    (*n)++;
    arrayToBST(arr,root->right,n);
}
int main()
{
    struct node *root = NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
    cout << "Inorder traversal of the binary tree is: ";
    inorder(root);
    cout << endl;
    int n=count(root);          // count the number of node in the binary tree..
    int arr[n];                 // make an array of size(number of nodes in the binary tree).
    int i=0;
    copytoArray(root,arr,&i);    // copy the nodes of the binary tree to array...
    sortArray(arr,n);           // sort the array...
    int j=0;
    arrayToBST(arr,root,&j);    //make the binary search tree with array...
    cout << "Following is Inorder Traversal of the converted BST: \n" << endl;
    inorder(root);
    return 0;
}
