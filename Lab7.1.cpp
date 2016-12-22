// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct computer
{
	char CPU[16];
	unsigned int CPU_freq;
	unsigned int RAM;
	unsigned int HardDisk;
	char VideoCard[16];
};

int main(int argc, char* argv[])
{
	unsigned int n;
	computer *comp;
	printf("Enter the number of computers: ");
	scanf_s("%d", &n);
	cin.get();
	comp = new computer[n];
	for (unsigned int i = 0; i < n; ++i)
	{
		printf("Enter the information about the computer N%d:\n", i + 1);
		printf("CPU: ");
		fflush(stdin);	gets_s(comp[i].CPU, 15);
		printf("CPU_freq: ");
		fflush(stdin);	scanf_s("%d", &comp[i].CPU_freq);
		printf("RAM: ");
		fflush(stdin);	scanf_s("%d", &comp[i].RAM);
		printf("Hard disk: ");
		fflush(stdin);	scanf_s("%d", &comp[i].HardDisk);
		printf("Video card: "); cin.get();
		fflush(stdin);	gets_s(comp[i].VideoCard, 15);
	}
	FILE *compF;
	fopen_s(&compF, "Computers.txt", "wt");
	fprintf(compF, "%d\n", n);
	for (unsigned int i = 0; i < n; i++)
		fprintf(compF, "%s\n%d\n%d\n%d\n%s\n",
		comp[i].CPU, comp[i].CPU_freq, comp[i].RAM,
		comp[i].HardDisk, comp[i].VideoCard);
	fclose(compF);
	system("pause");
	return 0;
}