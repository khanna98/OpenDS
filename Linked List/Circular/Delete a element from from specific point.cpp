// Task :
//
// Delete a element from specific point in Circular Linked List

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class list
{
    node *head, *ptr;
    public:
        list()
        {
            head = NULL;
            ptr = NULL;
        }

        node *create_node(int);
        void insert(int);
        void display();
        void delete_node(int,int);
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
        ptr = head;
    }
    else
    {
        ptr -> next = temp;
        ptr = ptr -> next;
    }
    ptr -> next = head;
}

void list :: display()
{
    node *temp = new node;
    temp = head;
    if(head == NULL)
    {
        cout<<"No elements in the List";
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

void list :: delete_node(int pos,int n)
{
    node *p = new node;
    node *b;
    p = head;

    if(pos == 0)
    {
        b = head;
        ptr -> next = b -> next;
        head = head -> next;
        delete b;
    }

    else if(pos == n-1)
    {
        node *a;

        while(p -> next -> next != head)
        {
            p = p -> next;
        }
        a = p -> next;
        p -> next = head;
        delete a;
    }

    else
    {
        node *c = new node;
        int count = 0;
        while(count != pos - 1)
        {
            c = p -> next;
            count++;
        }
        c = c->next;
        b = c->next;
        c -> next = b -> next;
        delete b;
    }
}

int main()
{
    list l;
    int n, num;
    cout<<"Enter List Size : ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Number : ";
        cin>>num;
        l.insert(num);
    }

    cout<<"Before Deletition : ";
    l.display();

    int pos;
    cout<<"Enter Position(starting from 0) : ";
    cin>>pos;

    while(pos > n-1)
    {
        cout<<"Position entered is larger than the List Size...TRY AGAIN"<<endl;
        cout<<"Enter Position(starting from 0) : ";
        cin>>pos;
    }
    cout<<"After Deletition : ";
    l.delete_node(pos,n);
    l.display();

    return 0;
}
