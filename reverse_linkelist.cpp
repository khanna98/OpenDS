#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
void createNode(node **head,int data)
{
	node *temp=new node;
	temp->data=data;
	temp->next=*head;
	*head=temp;
}
node *reverse(node *head)
{
	node *current,*next,*prev;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
void display(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" "<<endl;
		head=head->next;
	}
}

int main(int argc,char *argv[])
{
	int i;
	node *head=NULL;
	node *tail=NULL;
	for(i=0;i<argc-1;i++)
	{
		int k=(atoi)(argv[i+1]);
		createNode(&head,k);
	}

	display(head);
}
