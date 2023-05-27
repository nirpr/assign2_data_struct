#ifndef __Pair_H
#define __Pair_H

#include <string>


class Pair {
public:
	int priority;
	std::string data;
	//int mutualP;
	int ind;
	class Pair* mutualP = nullptr;
};
#endif 

