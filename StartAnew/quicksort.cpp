#include<bits/stdc++.h>
using namespace std; 
#define ll long long 

ll Partition(vector<ll> &v, ll start, ll end)
{
    ll pix = start, pivot = end; 
    for(int i = start; i<end; i++)
    {
        if(v[i]<v[pivot]) 
        {
            swap(v[i], v[pix]); 
            pix++;  
        }
    }
    swap(v[pivot], v[pix]); 
    return pix;  
}

void quicksort(vector<ll> &v, ll start, ll end)
{
    if(start<end)
    {
        ll ix = Partition(v, start, end);  
        quicksort(v, start, ix-1); 
        quicksort(v, ix+1, end);  
    }
}

int main()
{
    ll n; 
    cin >> n; 
    vector<ll> v(n);  
    for(auto &i: v) cin >> i; 
    quicksort(v, 0, n-1);  
    for(auto i: v) cout << i << ' ';  
}