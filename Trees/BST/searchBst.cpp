#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Template<templateType T>
/*
	Searching 
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
//Searching 
bool search(node *root,int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	else if(root->data >= data)
		search(root->left,data);
	else
	search(root->right,data);
}



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
	int c=0,h;
	int num;
	for(int i=2;i<argc-1;i++)
	{
	int k=(atoi)(argv[i]);
	insert(root,k);
	}
	int val=(atoi)(argv[argc-1]);
	if(search(root,val))
	cout<<"Present";
	else
	cout<<"Not present";
	//display(root);
	return 0;
}

