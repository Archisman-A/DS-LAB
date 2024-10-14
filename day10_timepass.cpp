#include <bits/stdc++.h>
using namespace std;

struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
	
};

void insert(struct Node** root, int x)
{
    if(*root==NULL)
	{
		struct Node *newnode= (struct Node*)malloc(sizeof(struct Node));
		newnode->data=x;
		newnode->left= newnode->right = NULL;
		
		*root=newnode;
	}	
	else if(x < (*root)->data )
	insert(&((*root)->left),x);
	else insert(&((*root)->right),x);
}
void preorder(struct Node* root)
{
	if(root==NULL)
	return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}
bool search(struct Node *root, int key)
{
	if(root==NULL)
	return false;
	else if(key==root->data)
	return true;
	else if(key<root->data)
	return search(root->left, key);
	else return search(root->right, key);
	
}

struct Node* getNext(struct Node* root)
{
	struct Node* temp=root;
	temp=temp->right;
	
	while(temp!=NULL && temp->left!=NULL)
	temp=temp->left;
	
	return temp;
}

struct Node* delNode(struct Node* root, int key)
{
	if(root==NULL)
	return root;
	
	if(key<root->data)
	root->left= delNode(root->left,key);
	else if(key >root->data)
	root->right= delNode(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		if(root->right==NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		
		struct Node* temp = getNext(root);
		root->data= temp->data;
		root->right= delNode(root->right, temp->data);
	}
	return root;
}

int sum(struct Node* root)
{
	if(root==NULL)
	return 0;
	else return root->data + sum(root->left) + sum(root->right);
	
}

void sumOfSubtree(struct Node* root, int x)
{
	if(root==NULL)
	cout<< "key not found\n" ;
	else if(root->data==x)
	cout << sum(root)<< endl;
	else if (x< root->data)
	sumOfSubtree(root->left,x);
	else sumOfSubtree(root->right,x);
	
}

int main()
{
	
	int n;
	cout << "enter size of array:\n";
	cin >> n;
	int arr[n];
	cout <<"enter the elements:\n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	struct Node* root = NULL;
	
	for(int i=0;i<n;i++)
	insert(&root,arr[i]);
	
	
	int x;
	cout <<"enter key to search:\n";
	cin >>x;
	
	sumOfSubtree(root,x);
//	
//	if(search(root,x))
//	cout <<"key is present\n";
//	else cout <<"key is not present\n";
//	
//	cout << "The BST: " ;
//	preorder(root);
//	cout << endl;
//	
//	cout << "enter value to be deleted:";
//	cin >> x;
//	
//	if(search(root,x))
//	root= delNode(root,x);
//	else 
//	{
//		cout <<"given value not found, hence no deletion\n";
//		return 0;
//	}	
//	
//	cout <<"new tree: ";
//	preorder(root);
//	cout << endl;
//	
//	
}
