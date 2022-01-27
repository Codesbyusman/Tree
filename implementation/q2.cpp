/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#include <iostream>

using namespace std;

#include "BinaryTree.h" //the implemented binary tree class

int seeList(bTree<int>);

int main()
{
    bTree<int> tree;

    //for storing number of lists created
    int numOflist = 0;

    //making a tree from loop 
    for(int i = 0 ; i< 10 ; i++)
    {
        tree.insert(i);
    }

    cout<<"\n\t ::::: Binary Tree created :::::"<<endl;

    //will display and return number of lists 
    numOflist = seeList(tree);

    cout<<endl;

    //displaying number of lists
    if(numOflist == -1)
    {
        cout<<"\n\t No tree exist thus no link list"<<endl<<endl;
    }
    else 
    {
         cout<<"\n\tNumber of link list formed (depth of tree) = "<<numOflist<<endl<<endl;
    }

    return 0;
}

int seeList(bTree<int> tree)
{
    //will display and return number of lists 
    return tree.displayAlllevel();

}
