#include "Header.h"
#include <string.h>
#include <stdio.h>

#define isValueAtPos(i) (((code[i] != '_') /*&& (i >= codeLen -1)*/) ? true : (false))
#define toDigit(ch) (ch - '0')
void assignBitCodesRecursive(PriorityQueue q, TreeNode* curNode, int bitCodes[], int arrLength, int bitNum)
{
	/*
	if (curNode == NULL)
	{
		return;
	}
	//reached leaf node and need to assign bit ct
	if (curNode->left == NULL && curNode->right == NULL) 
	{
		curNode->information.byte.b1 = (isValueAtPos(0)) ? toDigit(code[0]) : toDigit('0');
		curNode->information.byte.b2 = (isValueAtPos(1)) ? toDigit(code[1]) : toDigit('0');
		curNode->information.byte.b3 = (isValueAtPos(2)) ? toDigit(code[2]) : toDigit('0');
		curNode->information.byte.b4 = (isValueAtPos(3)) ? toDigit(code[3]) : toDigit('0');
		curNode->information.byte.b5 = (isValueAtPos(4)) ? toDigit(code[4]) : toDigit('0');
		curNode->information.byte.b6 = (isValueAtPos(5)) ? toDigit(code[5]) : toDigit('0');
		curNode->information.byte.b7 = (isValueAtPos(6)) ? toDigit(code[6]) : toDigit('0');
		curNode->information.byte.b8 = (isValueAtPos(7)) ? toDigit(code[7]) : toDigit('0');
		curNode->information.numBits = codeLen;
	}
	code[codeLen] = '0';
	assignBitCodesRecursive(q, curNode->left, code, codeLen + 1);
	code[codeLen] = '1';
	assignBitCodesRecursive(q, curNode->right, code, codeLen + 1);
	*/
	if (curNode == NULL)
	{
		return;
	}
	//reached leaf node and need to assign bit ct
	if (curNode->left == NULL && curNode->right == NULL)
	{
		bitCodes[curNode->information.ch] = bitNum;
	}

	assignBitCodesRecursive(q, curNode->left, bitCodes, arrLength, bitNum << 1);
	assignBitCodesRecursive(q, curNode->right, bitCodes, arrLength, (bitNum << 1) + 1);
}
void assignBitCodes(PriorityQueue q, int* bitCodes, int arrLength)
{
	assignBitCodesRecursive(q, (TreeNode*)q.look(), bitCodes, arrLength, 0);
}

