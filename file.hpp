#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <string>
#include "vector.h"
#include "room.h"
using namespace std;

template<typename T>
vector<T*>rfile(const string& f);

template<typename T>
void wfile(const string& f, const vector<T*>& data);


#endif
