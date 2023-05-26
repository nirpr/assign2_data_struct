#include "Min_heap.h"

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
	if ((left < heapSize) && (data[left].priority < data[node].priority))
		min = left;
	else
		min = node;
	if ((right < heapSize) && (data[right].priority < data[node].priority))
		min = right;
	if (min != node) {
		std::swap(data[node], data[min]);
		FixHeap(min);
	}
}

Pair Min_heap::deleteMin() {
	//if (heapSize < 1)
		// need to handle error
	Pair min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return min;
}

void Min_heap::insert(Pair item) {
	//if (heapSize == H_SIZE)
		//handle error
	int i = heapSize;
	heapSize++;

	while ((i > 0) && (data[Parent(i)].priority > item.priority)) {
		data[i] = data[Parent(i)];
		i = Parent(i);
	}
	data[i] = item;
}

Pair Min_heap::Min() {
	Pair min = data[0];
	return min;
}