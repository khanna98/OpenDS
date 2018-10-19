#include<iostream>
using namespace std;
struct node 
{
int data;
struct node *left,*right;
};
node* create(int data)
{
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
node* insert(node* root,int data)
{

	if(root==NULL)
	{
	root=create(data);

	}
	else if(data<(root->data))
	{
	root->left=insert(root->left,data);
	}
	else
	{
	root->right=insert(root->right,data);
	}
	return root;
}
void inorder(node* head,int low,int high)
{
	if(head==NULL)
	{
	return;
	}
	else
	{
	inorder(head->left,low,high);
	if((head->data<=high) && (head->data>=low))
	cout<<head->data<<endl;
	inorder(head->right,low,high);
	}	
}
int main(int argc,char *argv[])
{
struct node *root=NULL;
for(int i=1;i<argc-2;i++)
{
root=insert(root,atoi(argv[i]));
}
int high=atoi(argv[argc-1]);
int low=atoi(argv[argc-2]);
cout<<"INORDER"<<endl;
inorder(root,low,high);
}
