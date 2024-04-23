#include<bits/stdc++.h>
using namespace std; 

class node 
{
    public: 
    int data; 
    node * next; 

};



node * insert_end(int val, node *first)
{
    node *tmp = first; 
    while (tmp->next!=NULL)
    {
        tmp = tmp->next; 
    }

    node *newnode ; 
    newnode = new node();

    newnode->data = val; 
    newnode->next = NULL; 
    tmp->next= newnode; 
    
    return first; 
    
}

int main()
{
    node *first  ;
    first = new node();
    first->data = 1; 
    first->next = NULL; 
    for(int i=0;i<5;i++)
    {
        first  = insert_end(i, first);
    }

    node *tmp; 

    tmp = first; 
    while(tmp->next!=NULL) 
    {
        cout << tmp->data << ' ';
        tmp = tmp->next; 
    }
    cout << tmp->data << ' '; 

}