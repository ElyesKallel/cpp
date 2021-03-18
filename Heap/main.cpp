#include "pch.h"
#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	
	Heap myHeap(20); 

	//1 )-
	myHeap.push(4);
	myHeap.print();
	myHeap.push(7);
	myHeap.print();
	myHeap.push(3);
	myHeap.print();
	myHeap.push(9);
	myHeap.print();
	//2 )-
	int arr[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	for (int i = 0; i < 15; i++)
	{
		myHeap.push(arr[i]);
		myHeap.printb();
	}
	//3 )-
	int arr2[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	for (int i = 0; i < 15; i++)
	{
		myHeap.push(arr2[i]);
		myHeap.pop();
		myHeap.printb();
	}

	system("pause");
	return 0;
}