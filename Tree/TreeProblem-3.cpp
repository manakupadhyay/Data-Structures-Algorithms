
                    // TREE PROBLEM-3
                    // WAP TO MAKE A BALANCED BINARY TREE FROM A SORTED ARRAY...


#include <iostream>
using namespace std;

class TNode
{
    public:
    int data;
    TNode* left;
    TNode* right;
};
void preOrder(TNode* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";
     preOrder(node->left);
    preOrder(node->right);
}
TNode* newNode(int data)
{
    TNode* node = new TNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
TNode* arrayToBST(int arr[],int start,int end)
{
    if(start>end)
        return NULL;
    int mid=(start+end)/2;
    TNode* root=newNode(arr[mid]);
    root->left=arrayToBST(arr,start,mid-1);
    root->right=arrayToBST(arr,mid+1,end);
    return root;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7,8,9,10,11,12,13,15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sorted array is: ";
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    TNode *root = arrayToBST(arr, 0, n-1);
    cout << "InOrder Traversal of constructed BST \n";
    preOrder(root);

    return 0;
}
