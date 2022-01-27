/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#include <iostream>

using namespace std;

//the implemented class of binary search tree
#include "BinarySearch_Tree.h"

//functin prototype
int makeMintree(int [] , const int);

int main()
{
	//the height storaing
	int height = 0;

	const int size = 10;

	int arrayToinsert[size] = {};

	//populating
	for (int i = 0; i < size; i++)
	{
		arrayToinsert[i] = i; //in increasing order
	}

	//calling the function and returning the height calculated
	height = makeMintree(arrayToinsert, size);
	
	cout << "\t The height of created tree is : " << height << endl;


	return 0;
}

int makeMintree(int arrayInsert[], const int size)
{

	//the tree object
	bsTree<int> tree;

	int i = 0;

	int mid = ( (size - 1) / 2); //finding the mid index

	//inserting the mid initallay to create minimum tree
	tree.insert(arrayInsert[mid]);

	//for portion less than mid
	for (i = mid-1; i >= 0; i--)
	{

		//inserting the first half
		tree.insert(arrayInsert[i]);
		

	}

	//for portion less than mid
	for (i = mid +1; i < size ; i++)
	{

		//inserting the first half
		tree.insert(arrayInsert[i]);


	}

	cout << "\n\t The minimal Binary Search Tree created " << endl;

	//will display pre-order
	tree.display();

	return tree.findHegihtofTree(); //returning the height of tree created
	
}