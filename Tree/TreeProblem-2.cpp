
                    // TREE PROBLEM 2...
        // WAP TO MAKE A BALANCED BST FROM SORTED LINKED LIST....

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct tree
{
	int info;
	struct tree *left;
	struct tree *right;
 } treenode;

 struct node
 {
 	int data;
 	node *next;
 };

node *linknode(int data,node *next)         // for making linked list..
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=next;
	return newnode;
}
void addend(node **headref,int data)        // for making linked list...
{
	if(*headref==NULL)
	{
		*headref=linknode(data,NULL);
	}
	else
	{
		node *temp=*headref;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=linknode(data,NULL);
	}
}
void print(node *head)          // print linked list...
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
int countNodes(node* head)          // counting the number of nodes in the list..
{
    int count=0;
    node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
node* getMiddleNode(node* head,node** head1,node** head2)           // getting the middle node of the list(using tortoise/hare algorithm)...
{
   node *slow=head;
	node *fast=head;
	node *prev=head;
	int count=countNodes(head);
	while(fast!=NULL && fast->next!=NULL)
	{
		prev=slow;
		slow=slow->next;
		fast=fast->next->next;
   }
   if(count>1)
   {
   prev->next=NULL;
   *head1=head;
   *head2=slow->next;
  }
  else
  {
  	*head1=NULL;
  	*head2=NULL;
  }
  return slow;
}
void inorder(tree *root)            //
{
	if(root==NULL)
	return ;
	inorder(root->left);
	cout<<root->info<<" ";
	inorder(root->right);
}
 treenode *createnode(int info,treenode *left,treenode *right) //creation of a node of tree
 {
 	treenode *newnode=(treenode*)malloc(sizeof(treenode));
 	newnode->info=info;
 	newnode->left=left;
 	newnode->right=right;
 	return newnode;
 }
tree* getTree(node* head)           // making the tree...
{
   if(head==NULL)
    return NULL;
    node* head1;
    node* head2;
    node* temp=getMiddleNode(head,&head1,&head2);
    treenode* root=createnode(temp->data,NULL,NULL);
        root->left=getTree(head1);
        root->right=getTree(head2);
    return root;
}
void postorder(treenode* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->info << " ";
}
int main()
{
	node *head=NULL;
	addend(&head,1);
	addend(&head,2);
	addend(&head,3);
	addend(&head,4);
	addend(&head,5);
	addend(&head,6);
	addend(&head,7);
    cout << "Sorted Linked List is: ";
    print(head);
    cout << endl;
    treenode* root=getTree(head);
    cout << "Balanced BST is: ";
    postorder(root);
	cout << endl;
	return 0;
}
