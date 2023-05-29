#include "Max_heap.h"

Max_heap::Max_heap() {
	// Initialize the data array elements to nullptr
	for (int i = 0; i < 100; i++) {
		data[i] = nullptr;
	}
	heapSize = 0;
}

Max_heap::~Max_heap() {
	// Deallocate memory for each Pair object in the heap
	for (int i = 0; i < heapSize; i++) {
		delete data[i];
	}
}


int Max_heap::Parent(int node) {
	return (node - 1) / 2;
}

int Max_heap::Left(int node) {
	return node * 2 + 1;
}

int Max_heap::Right(int node) {
	return node * 2 + 2;
}

void Max_heap::FixHeap(int node) {
	// the function fixes the heap if the root is not the max priority.
	int max;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (data[left]->priority > data[node]->priority))
		max = left;
	else
		max = node;
	if ((right < heapSize) && (data[right]->priority > data[max]->priority))
		max = right;
	if (max != node) {
		std::swap(data[node], data[max]);
		std::swap(data[node]->ind, data[max]->ind);
		FixHeap(max);
	}
}

Pair* Max_heap::deleteMax() {
	// the function returns the max pair and removes it from the data arr
	if (heapSize < 1)
		breakProgram();
	Pair* max = data[0];
	heapSize--;
	data[0] = data[heapSize];
	data[0]->ind = 0;
	FixHeap(0);
	return max;
}

int Max_heap::insert(Pair* item) {
	// the function inserts a pair to the heap.
	if (heapSize == H_MAX_SIZE)
		heapFull();
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)]->priority < item->priority)) {
		data[i] = data[Parent(i)];
		data[i]->ind = i;
		i = Parent(i);
	}
	data[i] = item;
	return i;
}

Pair* Max_heap::Max() {
	// returns max priority pair.
	Pair* max = data[0];
	return max;
}

Pair* Max_heap::delete_from_ind(int ind) {
	// the function deletes a pair from a specific index.
	Pair* deleted_ind = data[ind];
	heapSize--;
	data[ind] = data[heapSize];
	data[ind]->ind = ind;
	FixHeap(ind);
	return deleted_ind;
}

void Max_heap::heapFull()
{
	//when the heap is full the program stops running
	std::cout << "No more space in heap";
	exit(1);
}

void Max_heap::breakProgram()
{
	// exit function.
	std::cout << "wrong input";
	exit(1);
}