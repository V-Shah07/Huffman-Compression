#include "C:\Vivaan\important vivi\coding\SR\Visual_Studio\Algorithms\PriorityQueue\PriorityQueue\PriorityQueue.h"

#include <stdlib.h>

void PriorityQueue::increaseSize()
{
	arr = (void**)realloc(arr, (2 * arrLength + 1) * sizeof(void*));
	/*for (int i = arrLength; i < 2 * arrLength + 1; ++i)
	{
		arr[i] = calloc(1, sizeof(void));
	}*/
	++arrLength;
}

void PriorityQueue::addToMin(void* val)
{
	int insertIndex = arrLength;
	increaseSize();
	arr[insertIndex] = val;
	int valIndex = insertIndex; //index of where value is located
	int swapIndex;
	void* temp;
	while (true)
	{
		swapIndex = (valIndex - 1) / 2;
		if (swapIndex < 0)
		{
			swapIndex = 0;
		}
		if (cmp(arr[valIndex], arr[swapIndex]) < 0) //child is less than parent so swap is needed
		{
			temp = arr[valIndex];
			arr[valIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			valIndex = swapIndex;
		}
		else //in right spot, no need to continue
		{
			return;
		}
	}
}

void PriorityQueue::addToMax(void* val)
{
	int insertIndex = arrLength;
	increaseSize(); //length is changed over here
	arr[insertIndex] = val;
	int valIndex = insertIndex; //index of where value is located
	int swapIndex;
	void* temp;
	while (true)
	{
		swapIndex = (valIndex - 1) / 2;
		if (valIndex < 1)
		{
			return;
		}
		if (cmp(arr[valIndex], arr[swapIndex]) > 0) //child is greater than parent so swap is needed
		{
			temp = arr[valIndex];
			arr[valIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			valIndex = swapIndex;
		}
		else //in right spot, no need to continue
		{
			return;
		}
	}
}

void* PriorityQueue::getMin()
{
	void* returnValue = arr[0];
	arr[0] = arr[arrLength - 1];

	int headIndex = 0;
	int swapIndex;
	void* temp;
	while (true)
	{
		//determining smallest child
		if ((headIndex * 2 + 1 < arrLength) && (headIndex * 2 + 2 < arrLength))
		{
			if (cmp(arr[headIndex * 2 + 1], arr[headIndex * 2 + 2]) < 0) //left child smaller than right child
			{
				swapIndex = headIndex * 2 + 1;
			}
			else //right child smaller than left child
			{
				swapIndex = headIndex * 2 + 2;
			}
		}
		else if (headIndex * 2 + 1 < arrLength) //if it only has one child, make that the swapIndex
		{
			swapIndex = headIndex * 2 + 1;
		}
		else //if there are no children, break out of this loop
		{
			break;
		}
		//actually swapping and terminating if no need to swap
		if (cmp(arr[headIndex], arr[swapIndex]) > 0) //swap if the head is larger than the child
		{
			temp = arr[headIndex];
			arr[headIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			headIndex = swapIndex;
		}
		else
		{
			break;
		}
	}
	arrLength--;
	return returnValue;
}

void* PriorityQueue::getMax()
{
	void* returnValue = arr[0];
	arr[0] = arr[arrLength - 1];

	int headIndex = 0;
	int swapIndex;
	void* temp;
	while (true)
	{
		//determining biggest child
		if ((headIndex * 2 + 1 < arrLength) && (headIndex * 2 + 2 < arrLength))
		{
			if (cmp(arr[headIndex * 2 + 1], arr[headIndex * 2 + 2]) > 0) //left child bigger than right child
			{
				swapIndex = headIndex * 2 + 1;
			}
			else //right child bigger than left child
			{
				swapIndex = headIndex * 2 + 2;
			}
		}
		else if (headIndex * 2 + 1 < arrLength) // if it only has one child, make that swapIndex
		{
			swapIndex = headIndex * 2 + 1;
		}
		else //no children is a signal to break out the loop
		{
			break;
		}
		//actually swapping and terminating if no need to swap
		if (cmp(arr[headIndex], arr[swapIndex]) < 0) //swap if head is smaller than child
		{
			temp = arr[headIndex];
			arr[headIndex] = arr[swapIndex];
			arr[swapIndex] = temp;
			headIndex = swapIndex;
		}
		else
		{
			break;
		}
	}
	arrLength--;
	return returnValue;
}

PriorityQueue::PriorityQueue(Type t, int size, int (*compare)(void*, void*))
{
	arr = NULL;
	arrLength = 0;
	elementSize = size;
	treeType = t;
	cmp = compare;
}

int PriorityQueue::getLength()
{
	return arrLength;
}

void PriorityQueue::add(void* val)
{
	if (treeType == min)
	{
		addToMin(val);
	}
	else
	{
		addToMax(val);
	}
}

void* PriorityQueue::get()
{
	if (treeType == min)
	{
		return getMin();
	}
	else
	{
		return getMax();
	}
}

void* PriorityQueue::look()
{
	return arr[0];
}