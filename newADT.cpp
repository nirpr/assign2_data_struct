#include "newADT.h"
using namespace std;

void newADT::Max() {
	Pair max = maxH1.Max();
	cout << max.priority << ' ' << max.data << endl;
}

void newADT::Min() {
	Pair min = minH2.Min();
	cout << min.priority << ' ' << min.data << endl;
}

void newADT::DeleteMax() {
	Pair max = maxH1.deleteMax();
	minH1.delete_from_ind(max.ind);
	cout << max.priority << ' ' << max.data << endl;
}

void newADT::DeleteMin() {
	Pair min = minH2.deleteMin();
	maxH2.delete_from_ind(min.ind);
	cout << min.priority << ' ' << min.data << endl;
}

void  newADT::Insert(Pair& item) {
	Pair item_dup = item; // the problem is with the mutualP after the first deletetion it's not right.
	Pair deletedMin, deletedMin_dup, deletedMax, deletedMax_dup;
	item.mutualP = &item_dup; // set mutual pointers
	item_dup.mutualP = &item;
	if (maxH2.isEmpty() || item.priority > maxH2.Max().priority)
	{
		item.ind = maxH1.insert(item);
		item_dup.ind = minH1.insert(item_dup);
		if (maxH1.getSize() > maxH2.getSize())
		{
			deletedMin = minH1.deleteMin();
			deletedMin_dup = maxH1.delete_from_ind(deletedMin.mutualP->ind); //get the ind from the mutual pointer
			deletedMin_dup.ind = maxH2.insert(deletedMin_dup);
			deletedMin.ind = minH2.insert(deletedMin);
		}
	}
	else
	{
		item.ind = maxH2.insert(item); //save his own index
		item_dup.ind = minH2.insert(item_dup); // same
		if (maxH1.getSize() < maxH2.getSize())
		{
			deletedMax = maxH2.deleteMax();
			deletedMax_dup = minH2.delete_from_ind(deletedMax.mutualP->ind);
			deletedMax_dup.ind = maxH1.insert(deletedMax_dup);
			deletedMax.ind = minH1.insert(deletedMax);
		}
	}
}

void newADT::Median(){
	Pair mid = maxH2.Max();
	cout << mid.priority << ' ' << mid.data << endl;
}