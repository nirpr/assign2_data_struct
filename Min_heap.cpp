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

Pair Min_heap::deleteMin() {
	//if (heapSize < 1)
		// need to handle error
	Pair min = *data[0];
	delete data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return min;
}

int Min_heap::insert(Pair& item) {
	//if (heapSize == H_SIZE)
		//handle error
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)]->priority > item.priority)) {
		data[i] = data[Parent(i)];
		data[i]->ind = i;
		i = Parent(i);
	}
	Pair* pItem = new Pair;
	*pItem = item;
	pItem->ind = i; // Set the ind value of the new Pair object
	data[i] = pItem;
	return i;
}

Pair Min_heap::Min() {
	Pair min = *data[0];
	return min;
}

Pair Min_heap::delete_from_ind(int ind) {
	Pair deleted_ind = *data[ind];
	delete data[ind];
	heapSize--;
	data[ind] = data[heapSize];
	//data[ind]->ind = ind;
	FixHeap(ind);
	return deleted_ind;
}