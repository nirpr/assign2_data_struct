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
	minH1.delete_from_ind(max.mutualP);
	cout << max.priority << ' ' << max.data << endl;
}

void newADT::DeleteMin() {
	Pair min = minH2.deleteMin();
	maxH2.delete_from_ind(min.mutualP);
	cout << min.priority << ' ' << min.data << endl;
}

void  newADT::Insert(Pair& item) {
	Pair item_dup = item;
	Pair deletedMin, deletedMin_dup, deletedMax, deletedMax_dup;
	if (maxH2.isEmpty() || item.priority > maxH2.Max().priority)
	{
		item_dup.mutualP = maxH1.insert(item);
		item.mutualP = minH1.insert(item_dup);
		if (maxH1.getSize() > maxH2.getSize())
		{
			deletedMin = minH1.deleteMin();
			maxH1.delete_from_ind(deletedMin.mutualP);
			deletedMin_dup = deletedMin;
			deletedMin_dup.mutualP = maxH2.insert(deletedMin);
			deletedMin.mutualP = minH2.insert(deletedMin_dup);
		}
	}
	else
	{
		item_dup.mutualP = maxH2.insert(item);
		item.mutualP = minH2.insert(item_dup);
		if (maxH1.getSize() < maxH2.getSize())
		{
			deletedMax = maxH2.deleteMax();
			minH2.delete_from_ind(deletedMax.mutualP);
			deletedMax_dup = deletedMax;
			deletedMax_dup.mutualP = maxH1.insert(deletedMax);
			deletedMax.mutualP = minH1.insert(deletedMax_dup);
		}
	}
}

void newADT::Median(){
	Pair mid = maxH2.Max();
	cout << mid.priority << ' ' << mid.data << endl;
}