#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Template<templateType T>
/*
	Insertion with recursion
*/
struct node
{
	int data;
	node *left;
	node *right;
};

node *create_node(int data)
{
	//temp->data
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node *insert(node* root,int data)  
{
	if(root==NULL)
	{
		return create_node(data);
	}

	if( data < root->data)
	{
	root->left=insert(root->left,data);
	}
	else if(data > root->data)
	{
	root->right=insert(root->right,data);
	}
	return root;
}
//level order traversal
void display(node *root)
{	
	if(root==NULL)
		return;
	queue<node *>q;
	q.push(root);

	while(!q.empty())
	{
		node *temp=q.front();
		cout<<temp->data<<" ";
		q.pop();

		if(temp->left!=NULL)
		{
			q.push(temp->left);
		}

		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
	}
}

int main(int argc,char* argv[])
{

	int n=(atoi)(argv[1]);
	node* root=create_node(n);

	for(int i=2;i<argc;i++)
	{
	int k=(atoi)(argv[i]);
	insert(root,k);

	}

	cout<<"Binary search tree  : \n";
	display(root);
	return 0;
}

