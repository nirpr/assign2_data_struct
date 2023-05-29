#include "Min_heap.h"

Min_heap::Min_heap() {
	// Initialize the data array elements to nullptr
	for (int i = 0; i < 100; i++) {
		data[i] = nullptr;
	}
	heapSize = 0;
}

Min_heap::~Min_heap() {
	// Deallocate memory for each Pair object in the heap
	for (int i = 0; i < heapSize; i++) {
		delete data[i];
	}
}

int Min_heap::Parent(int node) {
	return (node - 1) / 2;
}

int Min_heap::Left(int node) {
	return node * 2 + 1;
}

int Min_heap::Right(int node) {
	return node * 2 + 2;
}

void Min_heap::FixHeap(int node) {
	// the function fixes the heap if the root is not the min priority.
	int min;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (data[left]->priority < data[node]->priority))
		min = left;
	else
		min = node;
	if ((right < heapSize) && (data[right]->priority < data[min]->priority))
		min = right;
	if (min != node) {
		std::swap(data[node], data[min]);
		std::swap(data[node]->ind, data[min]->ind);
		FixHeap(min);
	}
}

Pair* Min_heap::deleteMin() {
	// the function returns the min pair and removes it from the data arr

	if (heapSize < 1)
		breakProgram();
	Pair* min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	data[0]->ind = 0;
	FixHeap(0);
	return min;
}

void Min_heap::breakProgram()
{
	// exit function.
	std::cout << "wrong input";
	exit(1);
}

int Min_heap::insert(Pair* item) {
	// the function inserts a pair to the heap.

	if (heapSize == H_MIN_SIZE)
		heapFull();

	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)]->priority > item->priority)) {
		data[i] = data[Parent(i)];
		data[i]->ind = i;
		i = Parent(i);
	}
	data[i] = item;
	return i;
}

void Min_heap::heapFull()
{
	//when the heap is full the program stops running
	std::cout << "No more space in heap";
	exit(1);
}

Pair* Min_heap::Min() {
	// returns min priority pair.
	Pair* min = data[0];
	return min;
}

Pair* Min_heap::delete_from_ind(int ind) {
	// the function deletes a pair from a specific index.
	Pair* deleted_ind = data[ind];
	heapSize--;
	data[ind] = data[heapSize];
	data[ind]->ind = ind;
	FixHeap(ind);
	return deleted_ind;
}