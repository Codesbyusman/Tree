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

//will take tree and value and will return the paths exist
int countPaths(bTree<int> , const int);

int main()
{
    int value = 0;
    int paths = 0;

    cout<<"\n\t Enter the Value : ";
    cin>>value;

    //making a tree
    bTree<int> tree;

    tree.insert(13);
    tree.insert(-4);
    tree.insert(5);
    tree.insert(0);
    tree.insert(0);
    tree.insert(0);
    tree.insert(4);

    

    /*
        tree created is
            13
         -4     5
        0  0   4  

    */

   //for 9  will be 2
   //for 18 will be 1
   //for 13 will be 0
   
    paths = countPaths(tree, value);

    cout<<"\n\t ::::: In created tree the paths to value "<<value<<" are "<<paths<<endl<<endl;
    return 0;
}

//will take tree and value and will return the paths exist
int countPaths(bTree<int> tree, const int value)
{
    //if tree is empty than no path exist
    if(tree.isEmpty())
    {
        return 0;
    }
    else //the may exist find and return the value
    {
        return tree.findPaths(value);
    }

}
