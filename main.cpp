#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "util.h"
#include "heap.h"
using namespace std;
int main()
{
	// variables for the parser... 
	char c;
	int i, v, f, n, k;
	HEAP heap;
	ELEMENT *a = new ELEMENT[heap.capacity];
	printf("Content of HEAPinput.txt\n");
	ifstream myfile;
	myfile.open("HEAPinput.txt");
	int size = 0;
	if (!myfile.is_open())
	{
		cout << "There was a problem opening ﬁle HEAPinput.txt for reading.";
	}
	else
	{
		myfile >> size;
		cout << size << endl;
		for (int in = 0; in < size; in++)
		{
			myfile >> a[in].key;
			cout << a[in].key << endl;
		}
	}
	cout << "Commands are:" << endl;
	while (1) {
		c = nextCommand(&i, &v, &f, &n, &k);
		switch (c)
		{
		case 's':
		case 'S':
			printf("COMMAND: %c.\n", c);
			printf("The program is going to be terminated.\n");
			exit(0);
		case 'k':
		case 'K':
			printf("COMMAND: %c %d %d %d.\n", c, i, v, f);
			heap.DecreaseKey(heap, i, v, f);
			break;
		case 'c':
		case 'C':
			printf("COMMAND: %c %d.\n", c, n);
			heap = heap.Initialize(n);
			//printf("%d", heap.capacity);
			break;
		case 'r':
		case 'R':
			heap.BuildHeap(heap, a, size);
			//printf("%d", heap.size);
			break;
		case 'w':
		case 'W':
			heap.printHeap(heap);
			break;
		case 'i':
		case 'I':
			printf("COMMAND: %c %d %d.\n", c, k, f);
			heap.Insert(heap, k, f);
			break;
		case 'd':
		case 'D':
			printf("COMMAND: %c %d.\n", c, f);
			printf("%d", heap.H[1].key);
			heap.DeleteMin(heap, f);
		default: break;
		}
	}
	exit(0);
}