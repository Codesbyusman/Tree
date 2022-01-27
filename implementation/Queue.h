/*
	Muhammad Usman Shahid
	   Assignment 03
          20i-1797
		     T
*/

#pragma once

#include <string>

template <class T>
struct qdata
{
	T data;
	qdata<T>* next;
};

template <class T>
class Qeue
{

private:

	//the front and end of queue
	qdata<T>* front;
	qdata<T>* rear;

public:

	Qeue()
	{
		front = NULL;
		rear = NULL;

	}

	//returns value at front
	T frontElement()
	{
		return front->data;
	}

	//enqueue the given value --- always from rear
	void enqueue(T data)
	{
		//the data block to be added
		qdata<T>* newData = new qdata<T>;

		newData->data = data;

		//the first element
		if (front == NULL)
		{

			//seting the data
			newData->next = NULL;
			front = rear = newData;

		}
		else
		{
			//not the first element --- will add from rear side
			rear->next = newData;
			newData->next = NULL;
			rear = newData; //the new rear
		}

	}
	
	//returning the value at the front
	T dequeue()
	{
		
		T toreturn;
		//if queue is not empty
		if (!isEmpty())
		{

			//returning variable
			T toreturn = front->data;

			//only last one
			if (front == rear)
			{
				delete front;
				front = NULL;
				rear = NULL;

				return toreturn;
			}
			

			//will return will also delete
			qdata<T>* temp = front;

			
			//updating front
			front = front->next;

			//deleting the previous front now
			delete temp;

			
			//returning the value after deletion
			//1 show that good return
			return toreturn;
		}

		return toreturn;
	}

	//for seeing que is empty or not
	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true; //is empty
		}

		return false; //not empty
	}

	//destructing the whole queue
	~Qeue()
	{


		//deque till queue is not empty
		while (!isEmpty())
		{
			dequeue();
		}

	}
};