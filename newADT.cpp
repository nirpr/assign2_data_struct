#include "newADT.h"
using namespace std;

void newADT::Max()
{
	// the function prints the pair with the highest priority.
	if (!maxH1.isEmpty())
	{
		Pair* max = maxH1.Max();
		cout << max->priority << ' ' << max->data << endl;
	}
	else if (!maxH2.isEmpty())
	{
		Pair* max = maxH2.Max();
		cout << max->priority << ' ' << max->data << endl;
	}
	else
		breakProgram();
}

void newADT::Min() {
	// the function prints the pair with the lowest priority.
	if (!minH2.isEmpty())
	{
		Pair* min = minH2.Min();
		cout << min->priority << ' ' << min->data << endl;
	}
	else if (!minH1.isEmpty()) // if the lower heaps are empty print from the higher heaps.
	{
		Pair* min = minH1.Min();
		cout << min->priority << ' ' << min->data << endl;
	}
	else
		breakProgram();
}

void newADT::DeleteMax() {
	// the function prints and deletes the value with the highest priority.
	if (!maxH1.isEmpty())
	{
		Pair* max = maxH1.deleteMax(); // save the pointer for printing and deleteing
		Pair* max_dup = minH1.delete_from_ind(max->mutualP->ind); // same
		if (maxH1.getSize() + 1 < maxH2.getSize())
			even_heaps_high();
		cout << max->priority << ' ' << max->data << endl;
		delete max;
		delete max_dup;
	}
	else if (!maxH2.isEmpty())
	{
		Pair* max = maxH2.deleteMax();
		Pair* max_dup = minH2.delete_from_ind(max->mutualP->ind);
		cout << max->priority << ' ' << max->data << endl;
		delete max;
		delete max_dup;
	}
	else
		breakProgram();
}

void newADT::DeleteMin() {
	// the function prints and deletes the value with the lowest priority.
	if (!minH2.isEmpty())
	{
		Pair* min = minH2.deleteMin();
		Pair* min_dup = maxH2.delete_from_ind(min->mutualP->ind);
		if (maxH1.getSize() > maxH2.getSize())
			even_heaps_low();
		cout << min->priority << ' ' << min->data << endl;
		delete min;
		delete min_dup;
	}
	else if (!minH1.isEmpty())
	{
		Pair* min = minH1.deleteMin();
		Pair* min_dup = maxH1.delete_from_ind(min->mutualP->ind);
		cout << min->priority << ' ' << min->data << endl;
		delete min;
		delete min_dup;
	}
	else
		breakProgram();
}

void  newADT::Insert(Pair& item) {
	// the function inserts a new item to the adt and even the heaps if needed
	Pair* item_p, * item_dup_p;  
	item_p = new Pair;
	item_dup_p = new Pair;
	*item_p = *item_dup_p = item;
	item_p->mutualP = item_dup_p;
	item_dup_p->mutualP = item_p;
	if (maxH2.isEmpty() || item.priority > maxH2.Max()->priority)
	{
		item_p->ind = maxH1.insert(item_p);
		item_dup_p->ind = minH1.insert(item_dup_p);
		if (maxH1.getSize() > maxH2.getSize())
			even_heaps_low();
	}
	else
	{
		item_p->ind = maxH2.insert(item_p); //save his own index
		item_dup_p->ind = minH2.insert(item_dup_p); // same
		if (maxH1.getSize() + 1 < maxH2.getSize())
			even_heaps_high();
	}
}

void newADT::Median(){
	// the fucntion prints the pair with median priority.
	Pair* mid = maxH2.Max();
	cout << mid->priority << ' ' << mid->data << endl;
}

void newADT::even_heaps_low() {
	// the function removes one pair from the higher heaps and inserts it to the lower ones.
	Pair* deletedMin;
	Pair* deletedMin_dup;
	deletedMin = minH1.deleteMin(); // save the deleted pointer to insert it to the lower heaps
	deletedMin_dup = maxH1.delete_from_ind(deletedMin->mutualP->ind); //get the ind from the mutual pointer
	deletedMin_dup->ind = maxH2.insert(deletedMin_dup);
	deletedMin->ind = minH2.insert(deletedMin);
	deletedMin->mutualP = deletedMin_dup; // set mutual pointers
	deletedMin_dup->mutualP = deletedMin;
}

void newADT::even_heaps_high() {
	// the fucntion removes one pair from the lower heaps and inserts to the higher ones.
	Pair* deletedMax;
	Pair* deletedMax_dup;
	deletedMax = maxH2.deleteMax(); // save the deleted pointer to insert it to  the higher heaps
	deletedMax_dup = minH2.delete_from_ind(deletedMax->mutualP->ind); //get the ind from the mutual pointer
	deletedMax_dup->ind = maxH1.insert(deletedMax_dup);
	deletedMax->ind = minH1.insert(deletedMax);
	deletedMax->mutualP = deletedMax_dup; // set mutual pointers
	deletedMax_dup->mutualP = deletedMax;
}

void newADT::breakProgram()
{
	// exit function.
	cout << "wrong input";
	exit(1);
}