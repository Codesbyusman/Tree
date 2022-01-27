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

//to check the subtree
bool checkSubtree(bTree<int> , bTree<int>);

int main()
{
    bTree<int>  tree1 , tree2, tree3;

    /* the tree making

            0
         1       2
      3    4    5 6
     7 8  9 -

    */

    for(int i = 0 ;i< 10 ; i++)
    {
        tree1.insert(i);
    }

    /* the tree making --- tree2

          2
         5 6
        
    */

    //making tree2 
    tree2.insert(2);
    tree2.insert(5);
    tree2.insert(6);


    //checking
     if(checkSubtree(tree1, tree2))
    {
        cout<<"\n\t ::: Tree2 is a sub tree of Tree1"<<endl;
    }
    else
    {
        cout<<"\n\t ::: Tree2 is not a sub tree of Tree1"<<endl;
    }

    /* the tree making ---tree 3

         2
       5   6 
      2 4
    */
   
     //making tree3 
    tree3.insert(2);
    tree3.insert(5);
    tree3.insert(6);
    tree3.insert(2);
    tree3.insert(4);


    //checking
     if(checkSubtree(tree1, tree3))
    {
        cout<<"\n\t ::: Tree3 is a sub tree of Tree1"<<endl;
    }
    else
    {
        cout<<"\n\t ::: Tree3 is not a sub tree of Tree1"<<endl;
    }
    
   
    cout<<endl;
    
    return 0;

}

//to check the subtree
bool checkSubtree(bTree<int> T1 , bTree<int> T2)
{
    //returning the result
    return T1.isSubtree(T2);
}