#pragma once
#include <stdio.h>
#include "C:\Vivaan\important vivi\coding\SR\Visual_Studio\Algorithms\PriorityQueue\PriorityQueue\PriorityQueue.h"


typedef unsigned char ubyte;

//frequency, ch, byte, and numBits used for leaf nodes
//only frequency used for parent nodes
struct info 
{
public:
	int frequency = 0;
	char ch = 0;
};
struct TreeNode //template for nodes in Huffman Coding Binary Tree
{
	TreeNode* left;
	TreeNode* right;
	info information;
};

//assigns bit codes to all leaf nodes
void assignBitCodes(PriorityQueue q, int* bitCodes, int arrLength);

void writeCompression(FILE* fp);
