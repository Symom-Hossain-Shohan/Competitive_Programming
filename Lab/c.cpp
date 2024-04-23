#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void print(node *head)
{
    if (head == 0)
    {
        cout << "Empty" << endl;
    }
    node *ptr = head;
    while (ptr != 0)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}

node *add_at_end(node *ptr, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->link = 0;
    ptr->link = temp;
    return temp;
}

node *add_at_beginning(node *head, int data)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->link = 0;

    ptr->link = head;
    head = ptr;
    return head;
}

void add_at_pos(node *head, int data, int pos)
{
    node *ptr = head;
    node *ptr2 = (node *)malloc(sizeof(node));
    ptr2->data = data;
    ptr2->link = 0;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

node *del_first(node *head)
{
    if (head == 0)
    {
        cout << "Empty" << endl;
    }
    else
    {
        node *temp = head;
        head = head->link;
        free(temp);
    }
    return head;
}

node *del_last(node *head)
{
    if (head == 0)
    {
        cout << "Empty" << endl;
    }
    else if (head->link == 0)
    {
        free(head);
        head = 0;
    }
    else
    {
        node *temp = head;
        node *temp2 = head;
        while (temp->link != 0)
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = 0;
        free(temp);
        temp = 0;
    }
    return head;
}

node *del_pos(node *head, int pos)
{
    node *current = head;
    node *prev = head;
    if (head == 0)
    {
        cout << "Empty" << endl;
    }
    else if (pos == 1)
    {
        head = current->link;
        free(current);
        current = 0;
    }
    else
    {
        while (pos != 1)
        {
            prev = current;
            current = current->link;
            pos--;
        }
        prev->link=current->link;
        free(current);
        current=0;
    }
    return head;
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 1;
    head->link = 0;
    node *ptr = head;
    for (int i = 0; i < 10; i++)
    {
        int x;
        // cin >> x;
        x = i + 2;
        ptr = add_at_end(ptr, x);
    }

    print(head);

    head = add_at_beginning(head, 99);
    print(head);

    add_at_pos(head, 88, 8);
    print(head);

    head = del_first(head);
    print(head);

    head = del_last(head);
    print(head);

    head = del_pos(head,5);
    print(head);

    return 0;
}
