/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#pragma once

#include "Queue.h"
#include "Linklist.h"
#include "math.h"
#include <string>

template <class T>
struct bstData
{
	T data;
	bstData<T> *leftChild;
	bstData<T> *rightChild;

	//at starting making the childs null
	bstData()
	{

		leftChild = rightChild = NULL;
	}
};

template <class T>
class bsTree
{
private:
	bstData<T> *root;

	//these functions are made private because root was deal here so not to give acess to all
	//and to strt display always from root
	//these three are recursive functions and are based on the principle of DFS

	//the pre order root,left,right
	void displayPreorder(bstData<T> *start)
	{
		//base case the end
		if (start == NULL)
		{
			return;
		}

		cout << start->data << " ";			//the root
		displayPreorder(start->leftChild);	//now going in the left bst
		displayPreorder(start->rightChild); //then in the left bst
	}

	//the inorder left,root,right
	void displayInorder(bstData<T> *start)
	{
		//base case the end
		if (start == NULL)
		{
			return;
		}

		displayInorder(start->leftChild);  //now going in the left bst
		cout << start->data << " ";		   //the root
		displayInorder(start->rightChild); //then in the left bst
	}

	//the postorder left,right,root
	void displayPostorder(bstData<T> *start)
	{
		//base case the end
		if (start == NULL)
		{
			return;
		}

		displayPostorder(start->leftChild);	 //now going in the left bst
		displayPostorder(start->rightChild); //then in the left bst
		cout << start->data << " ";			 //the root
	}

public:
	//initallay no tree
	bsTree()
	{
		root = NULL;
	}

	//for insertion
	void insert(T data)
	{

		//making the new memory to insert
		bstData<T> *newData = new bstData<T>;
		newData->data = data; //the value

		//if there is no tree --- making root then
		if (root == NULL)
		{
			//no left and right childs
			newData->leftChild = newData->rightChild = NULL;

			//now pointing the root to new memory
			root = newData;
		}
		else //the other nodes
		{

			//in binary search tree the left child is smaller than node and the right child is greater than node(root)
			//now checking the data where it will go

			//will iterate till the end of tree
			//such that the null reached

			bstData<T> *iterator = root; //for iteration

			while (iterator)
			{

				//now deciding about the iterator where to iterate in left sub bst or right sub bst
				if (data < iterator->data)
				{

					//the right place is in left subtree
					//if the left of iterator is empty then inserting directly as
					if (iterator->leftChild == NULL)
					{
						iterator->leftChild = newData;
						break; //as insertion done
					}

					//now searching in the left subtree if insertin not done
					iterator = iterator->leftChild;
				}
				else if (data > iterator->data)
				{
					//the right place is in right subtree
					//if the left of iterator is empty then inserting directly as
					if (iterator->rightChild == NULL)
					{
						iterator->rightChild = newData;
						break; //as insertion done
					}

					//now searching in the right subtree if insertin not done
					iterator = iterator->rightChild;
				}
				else
				{

					//the data is same so no duplicates
					cout << "\n\t ::: Insertion can not be done :::" << endl;
					break;
				}
			}
		}
	}

	//for finding the specific data --- iterator initallay will be root then will change
	bool find(T data, bstData<T> *iterator)
	{

		//doing a depth first traversal
		if (data == iterator->data)
		{
			//mean found
			return true;
		}
		else if (data < iterator->data)
		{
			//the data can be in the left sub tree
			//but before traversing looking that whether the other nodes exist or not
			if (iterator->leftChild == NULL)
			{
				//no more tree
				return false;
			}

			//else can be in the left subtree
			find(data, iterator->leftChild); //recursive call
		}
		else
		{
			//the data can be in the right sub tree
			//but before traversing looking that whether the other nodes exist or not
			if (iterator->rightChild == NULL)
			{
				//no more tree
				return false;
			}

			//else can be in the right subtree
			find(data, iterator->rightChild); //recursive call
		}
	}

	//the container function that will call above reccursive function
	//function overloading
	bool find(T data)
	{
		//will be rrturn that above function ill return
		return find(data, root);
	}

	//overloaded functions that will call the inner private functions
	void displayPreorder()
	{

		displayPreorder(root);

		cout << endl;
	}

	void displayInorder()
	{

		displayInorder(root);

		cout << endl;
	}

	void displayPostorder()
	{
		displayPostorder(root);

		cout << endl;
	}

	//height from a specified node --- specific child
	//will find recursively
	int findHeight(bstData<T> *strt)
	{
		//for storing the depth of left and right and will return accordingly so that may contribute next
		int deepl = 0, deepr = 0;

		//go till leaf
		if (strt == NULL)
		{
			//no length --- the null
			return -1;
		}

		//call again --- and find length in deepl(left) and deepr(right)
		deepl = findHeight(strt->leftChild);  //left depth
		deepr = findHeight(strt->rightChild); //right depth

		//now checking which will contribute
		if (deepl >= deepr)
		{
			//if the left height is greater or equal to the right depth
			//adding 1 to left depth returned as connected to the current iteration node and returning
			return (deepl + 1);
		}
		else
		{
			//if the right height is greater  to the left depth
			//adding 1 to left depth returned as connected to the current iteration node
			return (deepr + 1);
		}
	}

	//will find the height from root
	int findHegihtofTree()
	{
		//the starting of tree
		bstData<T> *strt = root;

		int heightLeft = 0, heightRight = 0;

		//will find the two heights
		//finding the heights of left and right childs
		heightLeft = findHeight(strt->leftChild);	//left child of root
		heightRight = findHeight(strt->rightChild); //right child of root

		if (heightLeft >= heightRight)
		{
			//the left child has depest root thus addig 1 and returning height of tree -- equality will also be dealt
			heightLeft++;
			return heightLeft;
		}
		else
		{
			//the right child has depest root thus addig 1 and returning height of tree
			heightRight++;
			return heightRight;
		}
	}

	//recursive function for deleteing memory
	void deletebTree(bstData<T> *iterate)
	{

		if (iterate)
		{
			deletebTree(iterate->leftChild);
			deletebTree(iterate->rightChild);
			delete iterate;
		}
	}

	void display()
	{
		//will display the in oder such
		cout << "\n\t Pre order : ";
		displayPreorder();
		cout << endl;
	}

	//for populating arrays
	void populateArrays(string *s1, string *s2, const int size)
	{
		for (int i = 0; i < size; i++)
		{
			s1[i] = s2[i]; //entering in s2 in the s1 array
		}
	}
	//for extracting the nodes
	void extractNodes(Qeue<string> &nodeHolder)
	{
		//a temprary queue for breathfirst traversal
		Qeue<bstData<T> *> temp;

		bstData<T> *iterator = root;

		//pushing the node as a string
		string s = to_string(iterator->data);
		nodeHolder.enqueue(s);

		//pushing it to the temp
		temp.enqueue(iterator);

		//while temporary is not empty
		while (!temp.isEmpty())
		{
			iterator = temp.dequeue(); //dequeing

			//the left child
			if (iterator->leftChild == NULL)
			{

				s = "null";
				nodeHolder.enqueue(s);
			}
			else
			{

				//now to the node holder
				s = to_string(iterator->leftChild->data);
				nodeHolder.enqueue(s);
				temp.enqueue(iterator->leftChild);
			}

			//the right child
			if (iterator->rightChild == NULL)
			{
				s = "null";
				nodeHolder.enqueue(s);
			}
			else
			{

				s = to_string(iterator->rightChild->data);
				nodeHolder.enqueue(s);

				//enqueing to queue
				temp.enqueue(iterator->rightChild);
			}
		}
	}

	//for checking whether the string is repeated or not deu to empty childs
	bool areEqual(string *s1, string *s2, const int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (s1[i] != s2[i])
			{
				return false; //not equal
			}
		}

		return true; //equal
	}

	//will display the possible combinations that can result same bst
	void displayPossible_Combinations()
	{
		int i = 0;
		int numOfnodes = 0; //forcalculating number of nodes
		int height = findHegihtofTree();

		string swap = ""; //for swapping

		//using formula (2^h+1) - 1
		//finding the number of nodes
		numOfnodes = pow(2, height + 1) - 1;

		//making a dynamic allocated array for nodes
		string *nodesinTree = new string[numOfnodes];
		string *dummyArray = new string[numOfnodes]; //a dummy arrray to process
		string *previousArray = new string[numOfnodes];

		//doing a breathfirst to extract the nodes of tree thus
		Qeue<string> storeNodes;

		//calling a function to extract the nodes
		extractNodes(storeNodes);

		//now filling the array from queue
		//the last will be many nulls as the breathfirst search that will be ig nored
		for (i = 0; i < numOfnodes; i++)
		{
			nodesinTree[i] = storeNodes.dequeue(); //dequeing and entering in the array
		}

		int j = 0;

		for (i = 0; i < numOfnodes; i++)
		{
			if (nodesinTree[i] == "null")
			{
				j = i;
				while (j < numOfnodes - 1)
				{
					//swaping till next null not meet
					swap = nodesinTree[j];
					nodesinTree[j] = nodesinTree[j + 1];
					nodesinTree[j + 1] = swap;

					j++;
				}
			}
		}

		//finding the new no of nodes ... before the null detected
		for (i = 0; i < numOfnodes; i++)
		{
			if (nodesinTree[i] == "null")
			{
				break;
			}
		}

		numOfnodes = i--;
		//populating the dummy array
		populateArrays(dummyArray, nodesinTree, numOfnodes); //entering in the dummy array

		//will process and will display the possible combinations
		//jumping to two and swaping them as on the same childs --- swapping between siblings
		for (i = 1; i < numOfnodes; i += 2)
		{

			//swap the i and i+1 and will do this three time of swaped
			swap = dummyArray[i];
			dummyArray[i] = dummyArray[i + 1];
			dummyArray[i + 1] = swap;

			//after swaping displaying
			cout << "\t ::: Combination :";
			displayArray(dummyArray, numOfnodes);
		}

		//again populating the dummy array as messed up before
		//populating the dummy array
		populateArrays(dummyArray, nodesinTree, numOfnodes); //entering in the dummy array

		//do not swap done before
		if (numOfnodes == 3)
		{
			cout << "\t ::: Combination :";
			displayArray(dummyArray, numOfnodes);
			return;
		}

		//now the rest three possible combinations
		//jumping to two and swaping them as on the same childs --- swapping
		//between siblings but will deal in next iteration a new populated
		//array in which only next two will be changed
		for (i = 1; i < numOfnodes; i += 2)
		{
			//swap the i and i+1 and will do this three time of swaped
			swap = dummyArray[i];
			dummyArray[i] = dummyArray[i + 1];
			dummyArray[i + 1] = swap;

			//after swaping displaying the array
			cout << "\t ::: Combination :";
			displayArray(dummyArray, numOfnodes);

			//again swaping the swaped gain previous state to be deal in next iteration
			//swap the i and i+1 and will restore the array
			swap = dummyArray[i];
			dummyArray[i] = dummyArray[i + 1];
			dummyArray[i + 1] = swap;
		}
	}

	//will disply the array of combinations
	void displayArray(string *a, const int s)
	{
		//displaying the array
		for (int i = 0; i < s; i++)
		{
			//if null no child leave to print
			if (a[i] == "null")
			{
				continue;
			}

			cout << a[i] << " ";
		}
		cout << endl;
	}

	//for deleting the node
	~bsTree()
	{
		//will do depth first and start removing from the leaf node
		//will follow such pattern that --- first right child then left then parent
		deletebTree(root);
	}
};
