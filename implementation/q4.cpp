/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#include <iostream>
using namespace std;

#include "BinarySearch_Tree.h"

void printPossibleways(bsTree<int> );

int main()
{

    bsTree<int> T;
    T.insert(10);
    T.insert(5);
    T.insert(13);
    T.insert(4);
    T.insert(6);
    T.insert(15);
    T.insert(12);
    

   printPossibleways(T);

   cout<<endl;


}

//for displaying the combinations
void printPossibleways(bsTree<int>  tree)
{
    tree.displayPossible_Combinations();
}