#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "C:\Vivaan\important vivi\coding\SR\Visual_Studio\Algorithms\PriorityQueue\PriorityQueue\PriorityQueue.h"
#include "Header.h"

#pragma warning(disable:4996)
#define FILENAME "C:\\Users\\hshah\\Desktop\\Data.txt"


int cmpTreeNodes(void* a, void* b)
{
	TreeNode* x = (TreeNode*)a;
	TreeNode* y = (TreeNode*)b;
	
	return x->information.frequency - y->information.frequency;
}

int main()
{
	FILE* fp = fopen(FILENAME, "r");

	TreeNode nodes[255] = { 0 };
	int ct = 0;
	char ch = getc(fp);
	for (; ch != EOF; )
	{
		if (nodes[ch].information.frequency == 0) //has not been counted before
		{
			nodes[ch].information.ch = ch;
		}
		nodes[ch].information.frequency++;
		ch = getc(fp);
	}
	PriorityQueue nodesQueue(PriorityQueue::min, sizeof(TreeNode), cmpTreeNodes);
	for (int i = 0; i < sizeof(nodes)/sizeof(nodes[0]); ++i)
	{
		if (nodes[i].information.frequency != 0) //occurs in data
		{
			nodesQueue.add(&nodes[i]);
		}
	}
	/*
	while (nodesQueue.getLength() > 0)
	{
		printf("%c %d\n", ((TreeNode*)nodesQueue.look())->information.ch, ((TreeNode*)nodesQueue.look())->information.frequency);
		nodesQueue.get();
	}
	*/
	
	TreeNode treeNode1, treeNode2;
	TreeNode parentNodes[255] = { 0 }; //stores independent memory locations for every joint node
	for (int i = 0; nodesQueue.getLength() >= 2 && i < sizeof(parentNodes)/sizeof(TreeNode); i++) //goes through and joins all leaf nodes of letters
	{
		printf("Currently %d elements in queue...\n", nodesQueue.getLength());
		parentNodes[i].left = (TreeNode*)nodesQueue.get();
		parentNodes[i].right = (TreeNode*)nodesQueue.get();
		parentNodes[i].information.frequency = parentNodes[i].left->information.frequency + parentNodes[i].right->information.frequency;
		nodesQueue.add(&parentNodes[i]);
	}
	printf("Final node: %c-%d", ((TreeNode*)nodesQueue.look())->information.ch, ((TreeNode*)nodesQueue.look())->information.frequency);
	int bitCodes[128] = { 0 };
	assignBitCodes(nodesQueue, bitCodes, sizeof(bitCodes)/sizeof(bitCodes[0]));
	writeCompression(fp);
	fclose(fp);
}