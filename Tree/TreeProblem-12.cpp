
                    // TREE PROBLEM-12
                    // SUM TREE...
    // WRONG SOLUTION: IT WILL CHECK ONLY FOR ROOT NODE...

#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *left, *right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}
void postorder(Node* root,int* a,int* i)
{
    if(root==NULL)
        return;
    postorder(root->left,a,i);
   // cout << root->data << " ";
    postorder(root->right,a,i);
    cout << root->data << " ";
    a[(*i)++]=root->data;

}
int countnodes(Node* root)
{
    if(root==NULL)
        return 0;
    return 1+ countnodes(root->left)+countnodes(root->right);
}
int main()
{
     Node* root = NULL;
    /*root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    root=insert(root,20);
    */
    root=newNode(13);
    root->left=newNode(3);
    root->right=newNode(4);
    root->left->left=newNode(1);
    root->left->right=newNode(2);
    root->right->left=newNode(1);
    root->right->right=newNode(2);
    int n=countnodes(root);
    int arr[n];
    int i=0;
    cout << "Number of nodes in the BST is: " << n << endl;
    cout << "Post order : ";
    postorder(root,arr,&i);

    //for(int j=0;j<n;j++)
     //   cout << arr[j] << " ";
    int sum=0;
    for(int i=0;i<n-1;i++)
        sum+=arr[i];
    cout << endl;
    if(sum==arr[n-1])
        cout << "yes " << endl;
    else
        cout << "NO " << endl;
    cout << endl;
}
