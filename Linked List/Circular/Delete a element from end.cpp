// Task :
//
// Delete a element from beginning in Circular Linked List

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
        void delete_node();
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

void list :: delete_node()
{
    node *p = new node;
    node *a;
    p = head;

    while(p -> next -> next != head)
    {
        p = p -> next;
    }
    a = p -> next;
    p -> next = head;
    delete a;
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

    cout<<"After Deletition : ";
    l.delete_node();
    l.display();

    return 0;
}
