#include <bits/stdc++.h>
using namespace std;

struct BinaryTree
{
    int val;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    BinaryTree(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    BinaryTree(int x, BinaryTree *lft, BinaryTree *rgt)
    {
        val = x;
        left = lft;
        rgt = rgt;
    }
};

int main()
{
    
}