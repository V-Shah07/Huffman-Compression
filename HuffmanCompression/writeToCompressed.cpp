#include <stdio.h>
#pragma warning(disable:4996)

void writeCompression(FILE* fp)
{
	char ch = getc(fp);
	FILE* compressFile = fopen("compressed.bin", "wb");
	fputc(2, compressFile);
	fclose(compressFile);
}