// Task :
//
// Insert a Node/Element at a Specific Position

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

class list
{
    node *head, *tail;
    public:
        list()
        {
            head = NULL;
            tail = NULL;
        }

        node* create_node(int);
        void insert(int);
        void display();
        void insert_at_pos(int,int);
};

node* list :: create_node(int value)
{
    node *temp = new node;
    temp -> data = value;
    temp -> next = head;
    return temp;
}

void list :: insert(int value)
{
    node *temp;
    temp = create_node(value);
    if(head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        tail -> next = temp;
        tail = tail -> next;
    }
}

void list :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"List is Empty"<<endl;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
            if(temp == head)
            {
                break;
            }
        }
        cout<<endl;
    }
}

void list :: insert_at_pos(int position,int value)
{
    node *temp = new node;
    temp -> data = value;
    if(position == 0)
    {
        temp -> next = NULL;
        head = temp;
    }
    else
    {
        node *c = new node;
        int count = 1;
        c = head;
        while(count != position)
        {
            c = c->next;
            count++;
        }
        temp -> next = c -> next;
        c -> next = temp;
    }
}

int main()
{
    list l;
    int n,num;
    cout<<"Enter List Size : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<"Before Insertition : ";
    l.display();

    int pos,no;
    cout<<"Enter Position(List Postion Starting With Zero) : ";
    cin>>pos;
    cout<<"Enter Number : ";
    cin>>no;

    l.insert_at_pos(pos,no);

    cout<<"After Insertition : ";
    l.display();

    return 0;
}
