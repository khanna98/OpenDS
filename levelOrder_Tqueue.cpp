#include<iostream>
#include<queue>
using namespace std;
struct node
{
	char data;
	node *left,*right;
};
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
node* newNode(char data)
{
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int main()
{
	node *root=newNode('A');
	root->left=newNode('B');
	root->right=newNode('C');
	root->left->left=newNode('D');
	root->left->right=newNode('-');
	root->right->left=newNode('-');
	root->right->right=newNode('G');

	cout<<"Level Order traversal using Queue is : \n";
	display(root);
	return 0;
}
