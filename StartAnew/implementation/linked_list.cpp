#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    int val;
    LinkedList *next;
    LinkedList()
    {
        this->val = 0;
        this->next = NULL;
    }
    LinkedList(int value)
    {
        this->val = value;
        this->next = NULL;
    }

    LinkedList(int value, LinkedList *next)
    {
        this->val = value;
        this->next = next;
    }
};

int main()
{
    LinkedList *head;

    LinkedList *temp = head;

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        temp->next = new LinkedList(x);
        temp = temp->next;
    }

    temp = head->next;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}