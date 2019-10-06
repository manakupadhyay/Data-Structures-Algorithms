
                    // IMPLEMENTATION OF BINARY SEARCH TREE...

#include <iostream>
using namespace std;
struct BST
{
    int data;
    BST* left;
    BST* right;
};
BST* insertNode(BST* root,int data);
void inorder(BST* root);
void postorder(BST* root);
void preorder(BST* root);
int findMinItr(BST* root);
int findMaxItr(BST* root);
int findMin(BST* root);
int findMax(BST* root);
bool findElement(BST* root,int value);
BST* deleteNode(BST* root,int data);
BST* findMinNode(BST* root);
int main()
{
    BST* root=NULL;
    root=insertNode(root,25);
    int value;
    char ch;
    do
    {
        cout << "Enter the element you want to insert: ";
        cin >> value;
        insertNode(root,value);
        cout << "Enter y for more and n for exit: ";
        cin >> ch;

    }while(ch=='y');
    do
    {
        cout << "Choose an option: " << endl;
        cout << "1. PreOrder Traversal" << endl;
        cout << "2. InOrder Traversal" << endl;
        cout << "3. PostOrder Traversal" << endl;
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 1: preorder(root);
                    cout << endl;
                    break;
            case 2: inorder(root);
                    cout << endl;
                    break;
            case 3: postorder(root);
                    cout << endl;
                    break;
            default: cout << "Invalid option" << endl;
        }
        cout << "Enter y for menu and n for exit" << endl;
        cin >> ch;
    }while(ch=='y');
    cout << "Minimum value through recursion is: ";
    int ans=findMin(root);
    cout << ans << endl;
    cout << "Maximum value through recursion is: ";
    ans=findMax(root);
    cout << ans << endl;
    cout << "Minimum value through iteration is: ";
    cout << findMinItr(root) << endl;
    cout << "Maximum value through iteration is: ";
    cout << findMaxItr(root) << endl;
    cout << "Enter the element you want to find: ";
    cin >> ans;
    bool b = findElement(root,ans);
    if(b)
        cout << "Element found in the tree" << endl;
    else
        cout << "Element not found in the tree" << endl;
    cout << "Enter the value of the node you want to delete: ";
    cin >> ans;
    root=deleteNode(root,ans);
    inorder(root);
    return 0;
}
BST* deleteNode(BST* root,int data)
{
    if(root==NULL) return NULL;
    if(root->data < data)
        root->right=deleteNode(root->right,data);
    else if(root->data > data)
        root->left=deleteNode(root->left,data);
    else                        // IF DATA IS FOUND...
    {                                               // CASE 1: NODE WITH NO CHILDREN(LEAF NODE)...
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
        }                                            // CASE 2: NODE WITH 1 CHILD...
        else if(root->left==NULL)
        {
            BST* temp=root;
            root=root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            BST* temp=root;
            root=root->left;
            delete temp;
        }
        else                                            // CASE 3: NODE WITH 2 CHILDREN...
        {
            BST* temp=findMinNode(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,root->data);

        }
    }
    return root;
}
BST* findMinNode(BST* root)
{
    BST* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
bool findElement(BST* root,int value)
{
    if(root==NULL) return false;            // FOR EMPTY TREE...
    if(root->data == value)
        return true;
    else if(root->data < value)
       return findElement(root->right,value);
    else if(root->data > value)
       return findElement(root->left,value);
}
int findMaxItr(BST* root)
{
    BST* temp=root;
    if(temp==NULL)              // FOR EMPTY TREE...
        return -1;
    while(temp->right!=NULL)
        temp=temp->right;
    return temp->data;
}
int findMinItr(BST* root)
{
    BST* temp=root;
    if(temp==NULL)              // FOR EMPTY TREE...
        return -1;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp->data;
}
int findMin(BST* root)
{
    if(root==NULL) return -1;           // FOR EMPTY TREE...
    if(root->left==NULL)
        return root->data;
    findMin(root->left);
}
int findMax(BST* root)
{
     if(root==NULL) return -1;          // FOR EMPTY TREE...
   if(root->right==NULL)
        return root->data;
    findMax(root->right);
}
BST* createNode(int data)
{
    BST* newNode=new BST();
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void inorder(BST* root)
{
    if(root==NULL)              // FOR EMPTY TREE...
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(BST* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";

}
void preorder(BST* root)
{
    if(root==NULL)              // FOR EMPTY TREE...
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
BST* insertNode(BST* root,int data)
{
    if(root==NULL)                  // FOR EMPTY TREE...
    {
        root=createNode(data);
        return root;
    }
    else if(root->data >= data)
    {
        root->left=insertNode(root->left,data);
    }
    else if(root->data < data)
    {

        root->right=insertNode(root->right,data);
    }
    return root;
}
