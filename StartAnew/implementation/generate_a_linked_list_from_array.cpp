#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    Node(int val, Node *next)
    {
        this->val = val;
        this->next = next;
    }
};

int main()
{
    Node *head = new Node(0);

    vector<int> arr = {1, 2, 3, 4, 5};
    Node *temp = head;

    for (int i = 0; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    head = head->next;

    temp = head;

    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}