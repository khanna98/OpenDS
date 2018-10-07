#include<iostream>
using namespace std;
struct node
{
int data;
node* next;
node* prev;
}*head,*tail;

void split1(node **newList1,node **newList2)
{
		
	node *slowptr=head;
node *fastptr=head;
	while(fastptr->next!=head && fastptr->next->next!=head)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
	}
	while(fastptr->next!=head)
	{
		fastptr=fastptr->next;
	}
	*newList1=head;
	*newList2=slowptr->next;
	slowptr->next=head;
	fastptr->next=*newList2;


}

void insertAtEnd(int x)
{

node *temp=new node;
node *temp1;//=new node;
temp->data=x;
temp->next=NULL;
 temp->prev=NULL;
if(head==NULL)
{
head=temp;
temp->next=head;
temp->prev=head;


}
else
{
temp1=head;
while(temp1->next!=head)
{
temp1=temp1->next;
}
temp1->next=temp;
temp->prev=temp1;
temp->next=head;

/*
temp->next=head;
temp->prev=temp;
head=temp;*/

//temp->next=head;
//head=temp;
}



}

void display()
{
//cout<<"in";
node *temp=head;
while(temp->next!=head)
{
cout<<temp->data<<" ";
temp=temp->next;

}
cout<<temp->data;

}

int main(int argc, char **argv)
{
int arr[100];
node *newList1=NULL,*newList2=NULL;
int n=argc-1;
for(int i=0;i<n;i++)
{
arr[i]=(atoi)(argv[i+1]);
insertAtEnd(arr[i]);
}
 
 split1(&newList1,&newList2);
display();


}
