
            // TREE PROBLEM -10
            // CHECK WHETHER BST CONTAINS DEAD END OR NOT...


#include <bits/stdc++.h>
using namespace std;

// A BST node
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
bool deadEnd(Node* root,int min=1,int max=INT_MAX)
{
   if (root==NULL)
        return false;

    if (min == max)
        return true;

    return deadEnd(root->left, min, root->data - 1) ||
           deadEnd(root->right, root->data + 1, max);
}
int main()
{

    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    if (deadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
