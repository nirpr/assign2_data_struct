#ifndef __UTILS_H
#define __UTILS_H

#include "newADT.h"
class newADT;

void chooseAction(newADT& adt, char c);
void breakProgram();
void endInputHandler();
void checkAllocation(Pair* ptr);
void checkInput();

#endif

