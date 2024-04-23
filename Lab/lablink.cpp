#include<bits/stdc++.h>
using namespace std; 

class node
{
    public: 
    int data; 
    node *next; 
};

node* insert_end(int val , node *head)
{
    node* tmp; 
    tmp = head; 
    while(tmp->next!=NULL) 
    {
        tmp = tmp->next; 
    }

    node *nw; 
    nw = new node();
    nw->data = val; 
    nw->next = NULL; 
    tmp->next = nw; 
    return head; 
}

void traverse(node* head)
{
    node* itr ; 
    itr = head; 
    while(itr->next!=NULL)
    {
        cout << itr->data << ' ';
        itr = itr->next; 
    }

    cout << itr->data << endl;
}

node* delete_beg(node *head)
{
    head->data=head->next->data; 
    head->next = head->next->next; 
    return head; 
}


node* delete_end(node* head)
{
    node* tmp ; 
    tmp = head; 
    while(tmp->next->next!=NULL)
    {
        tmp = tmp->next; 
    }
    tmp->next = NULL; 
    return head; 
}

node* delete_at(int pos, node* head)
{
    int cnt = 1; 
    node* tmp; 
    tmp = head; 
    while(cnt<pos-1)
    {
        cnt++; 
        tmp = tmp->next; 
    }
    node* nxt; 
    nxt = tmp->next->next; 
    tmp->next = nxt; 
    return head;  
}

int main()
{
   node* head; 
   head = new node();
   head->data = 1; 
   head->next = NULL;

   for(int i = 2;i<=10;i++)
   {
       head = insert_end(i, head);
   }

   traverse(head);

   head = delete_beg(head); 

   traverse(head);

   head = delete_end(head);
   traverse(head);

   head = delete_at(2, head);
   traverse(head);

}