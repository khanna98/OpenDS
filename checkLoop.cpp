#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};


class linked_list
{
private:
	struct node *head=NULL;
	
	struct node* create_node(int val)
	{
		struct node* t=new struct node;
		t->data=val;
		t->next=NULL;
	}
public:
	void insert_end(int val)
	{
		struct node *temp=create_node(val);
	
		if(head==NULL)
			head=temp;
		else
		{
			struct node *t=head;
			while(t->next!=NULL)
				t=t->next;
			t->next=temp;	
		}
	}
	void insert_begin(int val)
	{
		struct node *temp=create_node(val);
	
		if(head==NULL)
			head=temp;
		else
		{
			temp->next=head;
			head=temp;	
		}
	}
	int count()
	{
		int tot=0;
		struct node *temp=head;
		while(temp!=NULL)
		{
			tot++;
			temp=temp->next;
		}
	return tot;	
	}
	void create_loop()
	{
		struct node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=head->next->next->next;	
	}
	bool check_loop()
	{
		struct node *t1=head;
		struct node *t2=head;
		
		bool flag=false;
	while(t1&& t2 &&t2->next)
	{
		t1=t1->next;
		t2=t2->next->next;
	
		if(t1==t2)
		{
			flag=true;
			break;
		}
	}
	
	return flag;	
	}
};

int main()
{
	linked_list l;
	l.insert_begin(1);
	l.insert_end(2);
	l.insert_end(10);
	l.insert_end(12);
	l.insert_end(14);
	l.insert_end(16);
	l.insert_end(18);
	l.insert_end(20);
	cout<<"Currently loop existing condition is "<<l.check_loop()<<endl;
	l.create_loop();
	cout<<"Currently loop existing condition is "<<l.check_loop()<<endl;
	//cout<<"Total elements in array are "<<l.count()<<endl;	
return 0;

