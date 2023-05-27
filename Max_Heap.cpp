#include "Max_heap.h"

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
	int max;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize) && (data[left].priority > data[node].priority))
		max = left;
	else
		max = node;
	if ((right < heapSize) && (data[right].priority > data[node].priority))
		max = right;
	if (max != node) {
		std::swap(data[node], data[max]);
		FixHeap(max);
	}
}

Pair Max_heap::deleteMax() {
	//if (heapSize < 1)
		// need to handle error
	Pair max = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return max;
}

int Max_heap::insert(Pair item) {
	//if (heapSize == H_SIZE)
		//handle error
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].priority < item.priority)) {
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = item;
	return i;
}

Pair Max_heap::Max() {
	Pair max = data[0];
	return max;
}

void Max_heap::delete_from_ind(int ind) {
	data[ind] = data[heapSize - 1];
	FixHeap(ind);
	heapSize--;
}