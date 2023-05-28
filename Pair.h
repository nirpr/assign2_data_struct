#ifndef __Pair_H
#define __Pair_H

#include <string>


class Pair {
public:
	int priority;
	std::string data;
	int ind;
	Pair* mutualP = nullptr;
};
#endif 

