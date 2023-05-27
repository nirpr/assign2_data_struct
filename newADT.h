#ifndef __NEWADT_H
#define __NEWADT_H

#include "Max_heap.h"
#include "Min_heap.h"
#include <iostream>


class newADT {
private:
	Max_heap maxH1, maxH2;
	Min_heap minH1, minH2;
public:
	void Max();
	void DeleteMax();
	void Min();
	void DeleteMin();
	void Insert(Pair& item);
	void Median();
};




#endif

