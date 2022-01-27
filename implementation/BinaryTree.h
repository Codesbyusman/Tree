/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#pragma once

//including the queue header file --- implemented
#include "Queue.h"
#include "Linklist.h" //linklist header file

template <class T>
struct btData
{
	T data;
	btData<T> *leftChild;
	btData<T> *rightChild;

	//at starting making the childs null
	btData()
	{

		leftChild = rightChild = NULL;
	}
};

template <class T>
class bTree
{

private:
	btData<T> *root;

public:
	bTree()
	{
		root = NULL;
	}

	//will do level wise insertion
	//the breathfirsttraversel
	void insert(T data)
	{

		//making the memory block to be added
		btData<T> *newData = new btData<T>;
		newData->data = data;

		//if the first insertion the root insertion
		if (root == NULL)
		{
			newData->leftChild = newData->rightChild = NULL; //no childs initallay
			root = newData;									 //the new node
		}
		else //insertion of other nodes
		{

			btData<T> *temp = root;

			//making a temp storage of queue
			Qeue<btData<T> *> tempStorage; //have the bstData type of queue

			//initiallay the parent node
			tempStorage.enqueue(root);

			//for inserying the data
			btData<T> *newData = new btData<T>;
			newData->data = data;

			//iterating infinetely and will break inside that
			while (true)
			{
				//dequeing the first in a temp node
				temp = tempStorage.dequeue();

				//now checking the childs

				//first will check left then right as level wise --- bft
				if (temp->leftChild == NULL)
				{
					//inserting the data
					temp->leftChild = newData;
					break; //as the insertion done
				}

				//not left child moving to right
				if (temp->rightChild == NULL)
				{
					//inserting the data
					temp->rightChild = newData;
					break; //as the insertion done
				}

				//if no mean right and left are there so moving that to queue
				tempStorage.enqueue(temp->leftChild);
				tempStorage.enqueue(temp->rightChild);

				//on next iteration will deque and will search position
			}
		}
	}

	//height from a specified node --- specific child
	//will find recursively
	int findHeight(btData<T> *strt)
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
		btData<T> *strt = root;

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

	//displaying linked list on each level
	int displayAlllevel()
	{
		//will do a breathfirst traverse and will display link lists
		//making a queue for temprary storage

		Linklist<int> levelList;				 //the lists
		btData<int> *temp = NULL, *temp2 = NULL; //the temp storage

		//if no element
		if (this->isEmpty())
		{
			cout << "\n\t Depth is -1 --- No tree exists" << endl;
			return 0; //thus made list are 0
		}
		else
		{
			//is not empty

			//if only one root depth = 0
			if (this->root->leftChild == NULL && this->root->rightChild == NULL)
			{
				levelList.insert(this->root->data);
				levelList.displayList();
				levelList.deleteList(); //will delete as not tostore anywhere
				return 1;				//0 height but 1 list
			}
			else
			{
				//not depth 0
				//using the tempeorary storage by using qeue
				Qeue<btData<T> *> tempStore;	 //the queue
				Qeue<btData<T> *> lastIteration; //for holding the last iteration childs

				//at start moving the root
				tempStore.enqueue(root);

				//while queue is not empty
				while (!tempStore.isEmpty())
				{

					//dequeing the the element in queue for iteration the temp storage
					temp = tempStore.dequeue();

					//saving this deque in another queue
					lastIteration.enqueue(temp);

					//if childs exist then enque in the queue
					if (temp->leftChild != NULL)
					{
						//the left child
						tempStore.enqueue(temp->leftChild);
					}

					if (temp->rightChild != NULL)
					{
						//the right child
						tempStore.enqueue(temp->rightChild);
					}
				}

				//now pushing the data stored in temp queue and printing the data
				int i = 0, j = 0; //the cunter for loops

				//run till the last iteration is not empty
				while (!lastIteration.isEmpty())
				{
					//will run in 2 multiples --- as first time 0 then 2 then 4 ---
					for (i = 0; i <= j; i++)
					{
						//mean while if the list was not empty then will insert n linked list
						if (!lastIteration.isEmpty())
						{
							//dequeing and inserting in the linked ist
							temp = lastIteration.dequeue();
							levelList.insert(temp->data);
						}
					}

					//displaying the list of last level as it was save by bfs --- level wise
					levelList.displayList();
					levelList.deleteList(); //deleting so to store next level

					j = j + i; //incrementing j in according to i runned
				}
			}

			cout << endl;

			//returning the number of linked list printed
			//that will be equal to the the number of depth of tree
			return this->findHegihtofTree() + 1;
		}
	}

	//to check tree
	bool isEmpty()
	{
		if (root == NULL)
		{
			//mean empty
			return true;
		}

		return false; //not empty
	}

	//overloaded function to call recursive function
	bool isBalance()
	{
		return isBalance(root);
	}

	//checking whether tree is balance or not
	//will call recursively
	bool isBalance(btData<T> *start)
	{
		//for storing the heights of sub trees from current node
		//to see whether balance from current node or not
		int heightR = 0, heightL = 0, bFactor = 0;

		//base case
		if (start == NULL)
		{
			return true; //because end one is balance go on
		}

		//finding heights of left and right
		heightL = findHeight(start->leftChild);
		heightR = findHeight(start->rightChild);

		//calculating the balance factor
		bFactor = heightL - heightR;

		//recursive calls to balance funtions in condition
		if (bFactor <= 1 && isBalance(start->leftChild) && isBalance(start->rightChild))
		{
			return true; //as balnced tree
		}

		return false;
	}

	//will return true if data found and will save the address of that node
	bool find(btData<T> *&assign, T data)
	{

		//doing a breathfirst search
		//if only root in the tree
		if (root->leftChild == NULL && root->rightChild == NULL)
		{

			//the root only thus
			if (root->data == data)
			{
				assign = root;
				return true;
			}

			return false; //no data at root and no mre tree
		}
		else
		{

			btData<T> *temp = root;

			//making a temp storage of queue
			Qeue<btData<T> *> tempStorage; //have the bstData type of queue

			//initiallay the parent node
			tempStorage.enqueue(root);

			//for inserying the data
			btData<T> *newData = new btData<T>;
			newData->data = data;

			//iterating infinetely and will break inside that
			while (true)
			{
				//dequeing the first in a temp node
				temp = tempStorage.dequeue();

				//now checking the childs

				//if root
				if (temp->data == data)
				{
					assign = temp;
					return true; //found and adress is return of founded node
				}

				//first will check left then right as level wise --- bft
				if (temp->leftChild == NULL)
				{
					//end tree
					return false;
				}
				else
				{
					if (temp->leftChild->data == data)
					{
						assign = temp->leftChild;
						return true; //found and adress is return of founded node
					}
				}

				//not left child moving to right
				if (temp->rightChild == NULL)
				{
					//end tree
					return false;
				}
				else
				{
					if (temp->rightChild->data == data)
					{
						assign = temp->rightChild;
						return true; //found and adress is return of founded node
					}
				}

				//if no mean right and left are there so moving that to queue
				tempStorage.enqueue(temp->leftChild);
				tempStorage.enqueue(temp->rightChild);

				//on next iteration will deque and will search position
			}

			return false; //no data found
		}
	}

	//checking whether the given nodes follow a same tree or not
	bool checkChilds(btData<T> *ofMainTree, btData<T> *ofSubTree)
	{
		//first checking the height is ok or not like if differ in height then will not check data thus
		int mainH = findHeight(ofMainTree);
		int subH = findHeight(ofSubTree);

		if (mainH != subH)
		{
			return false; //the heights differ not going furthure
		}

		//checking whether the data is same or not
		if (ofMainTree->data == ofSubTree->data)
		{
			return true; //same
		}
		else
		{
			return false; //not same
		}

		if (ofMainTree == NULL && ofSubTree == NULL)
		{
			return true; //the end reach
		}

		//checking the subsides
		if (checkChilds(ofMainTree->leftChild, ofSubTree->leftChild) && checkChilds(ofMainTree->rightChild, ofSubTree->leftChild))
		{
			return true;
		}

		//no if else than false
		return false;
	}

	//wil check whether the given is a subtree of calling tree
	bool isSubtree(bTree<T> subTree)
	{
		btData<T> *node = NULL;
		T toFind = subTree.root->data;

		//finding whether the given node exist in tree or not
		//finding and assigning that node adress in node
		//if the data exists of like that node then check furthure else not a sub tree
		if (find(node, toFind))
		{

			//will check whether the childs are same or not
			if (checkChilds(node->leftChild, subTree.root->leftChild) && checkChilds(node->rightChild, subTree.root->rightChild))
			{
				return true; //returning true because same childs
			}
			else
			{
				return false; //beacuse child differs
			}
		}

		return false; //notgone in if
	}

	//find the paths from root
	int findPaths(const int value)
	{
		return findPaths(root, value);
	}

	//for counting the paths in the node
	int findPaths(btData<T> *startNode, const int value)
	{
		int count = 0;
		int sum = 0;

		//for temporary usage
		btData<T> *temp = NULL;

		//using bfs extracting all nodes in a queue
		Qeue<btData<T> *> nodes;

		//stored in nodes queue
		extarctNodes(startNode, nodes);

		//now from each node checking the paths whether they are or not
		//check while the queue is not empty
		while (!nodes.isEmpty())
		{

			//dequeing the first node
			temp = nodes.dequeue();

			//if path exist then increment
			//will check the path existance
			//count is as alias will be updated --- passed by reference
			if (temp->data == value)
			{
				//the node data is search one than no path for that --- thus don't check
				continue;
			}

			//sum = 0;
			checkPath(temp, value, count, sum);
		}

		//returning the total paths detected
		return count;
	}

	//will extract all nodes from the tree in a queue
	void extarctNodes(btData<T> *startNode, Qeue<btData<T> *> &nodeHolder)
	{

		//if start node is not null
		if (startNode)
		{
			nodeHolder.enqueue(startNode);					 //enqueuing to the queue
			extarctNodes(startNode->leftChild, nodeHolder);	 //the left subtree
			extarctNodes(startNode->rightChild, nodeHolder); //the right subtree
		}
	}

	//will check from a given node to leaf whether the path is or not formed
	//and will update count accordingly
	//will do recursively
	void checkPath(btData<T> *start, const int key, int &pathCount, int &sum)
	{

		//a static variable updates on each call but not 0
		//static T sum = 0;

		//the end of tree
		if (start == NULL)
		{
			return;
		}

		sum = sum + start->data;

		//if sum matches the value
		if (sum == key)
		{
			//if found then count path and make sum again 0
			pathCount++;
			return;
			
		}

		checkPath(start->rightChild, key, pathCount, sum); //right side
		checkPath(start->leftChild, key, pathCount, sum); //left side

		sum = 0;
		
	}

	//recursive function for deleteing memory
	void deleteTree(btData<T> *iterate)
	{

		if (iterate)
		{
			deleteTree(iterate->leftChild);
			deleteTree(iterate->rightChild);
			delete iterate;
		}
	}

	//for deleting the node
	~bTree()
	{
		//will do depth first and start removing from the leaf node
		//will follow such pattern that --- first right child then left then parent
		deleteTree(root);
	}
};
