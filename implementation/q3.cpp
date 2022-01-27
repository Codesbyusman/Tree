/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#include <iostream>

using namespace std;

//the implemented classes
#include "BinaryTree.h"

bool checkBalance(bTree<int> );

int main()
{
    bTree<int> tree;

    //making a tree from loop 
    for(int i = 0 ; i< 10 ; i++)
    {
        tree.insert(i);
    }

    cout<<"\n\t    ::::: Binary Tree created :::::"<<endl;

    if(checkBalance(tree))
    {
        cout<<"\n\t :::::: Binary Tree is balanced ::::::"<<endl<<endl;
    }
    else
    {
        cout<<"\n\t :::::: Binary Tree is not balanced ::::::"<<endl<<endl;
    }
    return 0;
}

//checking the balance
bool checkBalance(bTree<int> tree )
{
    return tree.isBalance(); //returning the result 
}