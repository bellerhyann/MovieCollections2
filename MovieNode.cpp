#include "MovieNode.hpp"
#include "Movie.hpp"

#include <iostream>
using namespace std;
	
// overlaod << output operator for Movie's
ostream& operator<< (ostream &os, const MovieNode &m)
{
  return os<<m._Next;
}

