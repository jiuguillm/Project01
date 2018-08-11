#include "heap.h"
#include <stdio.h>
#include <cstdlib>
HEAP HEAP::Initialize(int n)
{
	HEAP heap;
	heap.capacity = n;
	heap.size = 0;
	heap.H = (struct ELEMENT*)malloc(n * sizeof(struct ELEMENT));
	return heap;
}
void HEAP::BuildHeap(HEAP heap, ELEMENT A[], int n)
{
	int s = 0;
	if (heap.capacity == 0)
	{
		printf("Sorry!!! It can not be done. Please intialize the heap first.\n");
	}// make sure heap exists.
	if (n > heap.capacity)
	{
		printf("Sorry!!! It can not be done. Please increase the capacity of heap first.\n");
	}//make sure heap is large enough

	else
	{
		for (int i = 1; i <= heap.capacity; i++)
		{
			heap.H[i].key = A[i - 1].key;
			heap.size++;
		}//end of for loop
		minHeapify(heap, heap.capacity / 2);

		/*while (i != 0)
		{
		if (heap.H[i].key >= heap.H[i / 2].key)
		{
		break;
		}
		else//switch
		{
		temp = heap.H[i / 2].key;//index of i/2 is parent of i
		heap.H[i / 2].key = heap.H[i].key;
		}
		i = i / 2;
		}*/
	}
}
void HEAP::Insert(HEAP heap, int k, int flag)
{
	if (heap.capacity == 0)
	{
		printf("Sorry!!! It can not be done. Please intialize the heap first.\n");
	}// make sure heap exists.
	if (heap.size + 1 > heap.capacity)
	{
		printf("Sorry!!! It can not be done. Please increase the capacity of heap first.\n");
	}//make sure heap is large enough
	int i = heap.size + 1;//insert position
	int temp;
	if (flag == 1)
	{
		printHeap(heap);//print old heap
	}
	heap.H[i].key = k;
	heap.size++;
	while (i != 0)
	{
		if (heap.H[i].key >= heap.H[i / 2].key)//no switch
		{
			break;
		}
		else//switch
		{
			temp = heap.H[i / 2].key;//index of i/2 is parent of i
			heap.H[i / 2].key = heap.H[i].key;
		}
		i = i / 2;
	}
	printHeap(heap);//print new heap
}
void HEAP::DeleteMin(HEAP heap, int flag)
{
	if (heap.capacity == 0)
	{
		printf("Sorry!!! It can not be done. Please intialize the heap first.\n");
	}// make sure heap exists.
	ELEMENT *a = new ELEMENT[heap.capacity];
	for (int i = 2; i <= heap.size; i++)
	{
		a[i - 1] = heap.H[i];
	}
	BuildHeap(heap, a, sizeof(a));
	delete[] a;
	printHeap(heap);
}
void HEAP::DecreaseKey(HEAP heap, int index, int value, int flag)
{
	if (heap.capacity == 0)
	{
		printf("Sorry!!! It can not be done. Please intialize the heap first.\n");
	}// make sure heap exists.
	int temp;
	if (flag == 1)
	{
		printHeap(heap);//print old heap
	}
	heap.H[index].key = value;
	while (index != 0)
	{
		if (heap.H[index].key >= heap.H[index / 2].key)
		{
			break;
		}
		else//switch
		{
			temp = heap.H[index / 2].key;//index of i/2 is parent of i
			heap.H[index / 2].key = heap.H[index].key;
		}
		index = index / 2;
	}
	printHeap(heap);//print new Heap
}
void HEAP::printHeap(HEAP heap)
{
	if (heap.capacity == 0)
	{
		printf("Sorry!!! It can not be done. Please intialize the heap first.\n");
	}// make sure heap exists.
	int i = 1;
	printf("The capacity is %d.\n", heap.capacity);
	printf("Size is %d.\n", heap.size);
	while (i <= size)
	{
		printf("%d\n", heap.H[i].key);
		i++;
	}
}
void minHeapify(HEAP heap, int n)
{
	int l = n / 2;
	int r = n / 2 + 1;
	int s = 0;
	int temp = 0;
	if (l <= heap.size && heap.H[l].key < heap.H[n].key)
	{
		s = l;
	}
	else if (r <= heap.size && heap.H[r].key < heap.H[n].key)
	{
		s = r;
	}
	else
	{
		s = n;
	}
	if (s != n)
	{
		temp = heap.H[n].key;
		heap.H[n].key = heap.H[s].key;
		heap.H[s].key = temp;
		minHeapify(heap, s);
	}

}