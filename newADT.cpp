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
	cout << max.priority << ' ' << max.data << endl;
}

void newADT::DeleteMin() {
	Pair min = minH2.deleteMin();
	cout << min.priority << ' ' << min.data << endl;
}