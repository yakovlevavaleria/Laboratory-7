// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct computer
{
	char CPU[16];
	int CPU_freq;
	int RAM;
	int HardDisk;
	char VideoCard[16];
};

struct List
{
	computer comp;
	List *CompNext, *CompPrev;
};

void AddToList(List *& cList, List *comp, bool ToFirst)
{
	if (cList == 0)
	{
		cList = comp->CompNext = comp->CompPrev = comp;
		return;
	}
	comp->CompNext = cList;
	comp->CompPrev = cList->CompPrev;
	cList->CompPrev->CompNext = comp;
	cList->CompPrev = comp;
	if (ToFirst) cList = comp;
}

void PrintList(List *cP)
{

	List *compP = cP;
	do
	{
		printf("%s %d %d %d %s\n", compP->comp.CPU, compP->comp.CPU_freq,
			compP->comp.RAM, compP->comp.HardDisk, compP->comp.VideoCard);
		compP = compP->CompNext;
	} while (compP != cP);


}
int main(int argc, char* argv[])
{
	unsigned int n;
	List *CompList = 0, *compP;

	FILE *compF;
	compF = fopen("Computers.txt", "rt");
	if (compF == 0)
	{
		printf("Error. File not found!");
		system("pause");
		return 0;
	}

	fscanf(compF, "%d\n", &n);
	for (unsigned int i = 0; i < n; ++i)
	{
		compP = (List *)malloc(sizeof(List));


		fscanf(compF, " %[^\n]%d\n%d\n%d\n%[^\n]",
			compP->comp.CPU, &compP->comp.CPU_freq,
			&compP->comp.RAM, &compP->comp.HardDisk, compP->comp.VideoCard);

		AddToList(CompList, compP, false);
		fclose(compF);
		printf("List of computers:\n");
		PrintList(CompList);
		system("pause");
		return 0;
	}
