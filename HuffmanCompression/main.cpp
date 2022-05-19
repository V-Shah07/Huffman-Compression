#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "C:\Vivaan\important vivi\coding\SR\Visual_Studio\Algorithms\PriorityQueue\PriorityQueue\PriorityQueue.h"
#pragma warning(disable:4996)
#define FILENAME "C:\\Users\\hshah\\Desktop\\Data.txt"



struct info
{
	int frequency;
	char ch;
	int bitCt;
};
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	info value; //int combinedFrequency
};

int cmpTreeNodes(void* a, void* b)
{
	info x = ((TreeNode*)a)->value;
	info y = ((TreeNode*)b)->value;
	return x.frequency - y.frequency;
}
void addTreeNode(TreeNode t, PriorityQueue* q)
{
	(*q).add(&t);
}
int main()
{
	FILE* fp = fopen(FILENAME, "r");

	fseek(fp, 0L, SEEK_END);
	long long fileSize = ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	int num = 256;
	TreeNode* nodes = (TreeNode*)calloc(num, sizeof(TreeNode));

	int ct = 0;
	char ch = getc(fp);
	for (int i = 0; (i < num) && (ch != EOF); i++)
	{
		if (ch >= num)
		{
			nodes = (TreeNode*)realloc(nodes, num * 2 * sizeof(TreeNode));

			nodes = (TreeNode*)memset(nodes + ch, 0, num * sizeof(TreeNode));
			num *= 2;
		}
		if (nodes[ch].value.frequency == 0) //has not been counted before
		{
			nodes[ch].value.ch = ch;
		}
		nodes[ch].value.frequency++;
		ch = getc(fp);
	}
	PriorityQueue nodesQueue(PriorityQueue::max, sizeof(TreeNode), cmpTreeNodes);
	for (int i = 0; i < num; ++i)
	{
		if (nodes[i].value.frequency != 0) //occurs in data
		{
			nodesQueue.add(&nodes[i]);
		}
	}
	/*
	while (nodesQueue.getLength() >= 0)
	{
		printf("%c %d\n",(*(TreeNode*)nodesQueue.look()).value.ch, (*(TreeNode*)nodesQueue.look()).value.frequency);
		nodesQueue.get();
	}
	*/
	TreeNode treeNode1, treeNode2;
	TreeNode parentNodes[255] = { 0 }; //stores independent memory locations for every joint node
	for (int i = 0; nodesQueue.getLength() >= 2 && i < sizeof(parentNodes)/sizeof(TreeNode); i++) //goes through and joins all leaf nodes of letters
	{
		printf("Currently %d elements in queue...", nodesQueue.getLength());
		_sleep(2000);
		treeNode1 = *(TreeNode*)nodesQueue.get();
		treeNode2 = *(TreeNode*)nodesQueue.get();
		parentNodes[i].value.frequency = treeNode1.value.frequency + treeNode2.value.frequency;
		nodesQueue.add(&parentNodes[i]);
		printf("Added a node that consists of %c-%d and %c-%d\n", treeNode1.value.ch, treeNode1.value.frequency, treeNode2.value.ch, treeNode2.value.frequency);
		_sleep(2000);
	}
	printf("Final node: %c-%d", ((TreeNode*)nodesQueue.look())->value.ch, ((TreeNode*)nodesQueue.look())->value.frequency);

	
	

}