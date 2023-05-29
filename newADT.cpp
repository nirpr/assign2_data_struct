#include "newADT.h"
using namespace std;

void newADT::Max()
{
	if (!maxH1.isEmpty())
	{
		Pair max = maxH1.Max();
		cout << max.priority << ' ' << max.data << endl;
	}
	else if (!maxH2.isEmpty())
	{
		Pair max = maxH2.Max();
		cout << max.priority << ' ' << max.data << endl;
	}
	else
	{
		cout << "wrong input";
		exit(1);
	}
}

void newADT::Min() {
	if (!minH2.isEmpty())
	{
		Pair min = minH2.Min();
		cout << min.priority << ' ' << min.data << endl;
	}
	else if (!minH1.isEmpty())
	{
		Pair min = minH1.Min();
		cout << min.priority << ' ' << min.data << endl;
	}
	else
	{
		cout << "wrong input";
		exit(1);
	}
}

void newADT::DeleteMax() {
	if (!maxH1.isEmpty())
	{
		Pair max = maxH1.deleteMax();
		minH1.delete_from_ind(max.mutualP->ind);
		if (maxH1.getSize() + 1 < maxH2.getSize())
			even_heaps_high();
		cout << max.priority << ' ' << max.data << endl;
	}
	else if (!maxH2.isEmpty())
	{
		Pair max = maxH2.deleteMax();
		minH2.delete_from_ind(max.mutualP->ind);
		cout << max.priority << ' ' << max.data << endl;
	}
	else
	{
		cout << "wrong input";
		exit(1);
	}
}

void newADT::DeleteMin() {
	if (!minH2.isEmpty())
	{
		Pair min = minH2.deleteMin();
		maxH2.delete_from_ind(min.mutualP->ind);
		if (maxH1.getSize() > maxH2.getSize())
			even_heaps_low();
		cout << min.priority << ' ' << min.data << endl;
	}
	else if (!minH1.isEmpty())
	{
		Pair min = minH1.deleteMin();
		maxH1.delete_from_ind(min.mutualP->ind);
		cout << min.priority << ' ' << min.data << endl;
	}
	else
	{
		cout << "wrong input";
		exit(1);
	}
}

void  newADT::Insert(Pair& item) {
	Pair* item_p, * item_dup_p;  // the problem is with the mutualP after the first deletetion it's not right.
	item_p = new Pair;
	item_dup_p = new Pair;
	*item_p = *item_dup_p = item;
	item_p->mutualP = item_dup_p;
	item_dup_p->mutualP = item_p;
	if (maxH2.isEmpty() || item.priority > maxH2.Max().priority)
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
	Pair mid = maxH2.Max();
	cout << mid.priority << ' ' << mid.data << endl;
}

void newADT::even_heaps_low() {
	Pair* deletedMin = new Pair;
	Pair* deletedMin_dup = new Pair;
	*deletedMin = minH1.deleteMin();
	*deletedMin_dup = maxH1.delete_from_ind(deletedMin->mutualP->ind); //get the ind from the mutual pointer
	deletedMin_dup->ind = maxH2.insert(deletedMin_dup);
	deletedMin->ind = minH2.insert(deletedMin);
	deletedMin->mutualP = deletedMin_dup;
	deletedMin_dup->mutualP = deletedMin;
}

void newADT::even_heaps_high() {
	Pair* deletedMax = new Pair;
	Pair* deletedMax_dup = new Pair;
	*deletedMax = maxH2.deleteMax();
	*deletedMax_dup = minH2.delete_from_ind(deletedMax->mutualP->ind);
	deletedMax_dup->ind = maxH1.insert(deletedMax_dup);
	deletedMax->ind = minH1.insert(deletedMax);
	deletedMax->mutualP = deletedMax_dup;
	deletedMax_dup->mutualP = deletedMax;
}