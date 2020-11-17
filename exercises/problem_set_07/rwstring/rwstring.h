#ifndef RWSTRING_H_INCLUDED
#define RWSTRING_H_INCLUDED

void writestring(fstream &fs, string str, unsigned int size);

string readstring(fstream &fs, unsigned int size);

#include "rwstring.hpp"

#endif // RWSTRING_H_INCLUDED

