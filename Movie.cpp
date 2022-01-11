#include "Movie.hpp"

#include <iostream>
using namespace std;

// equality comparison
bool
Movie::operator==(const Movie &other) const
{
  // two movies are only the same if they have same title and release year
  return _title==other._title && _year==other._year;
} 

// inewuslity is just the opposite of equality. 
bool
Movie::operator!=(const Movie &other) const
{
  return ! (*this==other);
}

// assignement operator
const Movie&
Movie::operator=(const Movie &other)
{
  // build a new movie that is a duplicate of the rhs. 
  Movie *returnValuePtr = new Movie(other._title, other._year, other._rating);

  // updtae this move to be the same as the rhs
  _title = other._title;
  _year = other._year;
  _rating = other._rating;

  // return copy of the rhs. 
  return *returnValuePtr;
}

// dump movie to stream 
ostream&
Movie::print (ostream &os) const
{
  // easy - just dump each instance variable
  os << _title << "  (" << _year << ")   " << _rating << "/10";
  return os;
}

// read movie from stream
istream&
Movie::read (istream &is)
{
  // pretty straight forward - just read each component. 
  getline(is, _title);
  is >> _year;
  is >> _rating;

  // last component will not have forcibly read newline - let's get that
  //   newline out of the way now. 
  string dummy;
  getline(is, dummy);
  
  return is;
}

// overlaod << output operator for Movie's
ostream& operator<< (ostream &os, const Movie &m)
{
  return m.print(os);
}

// overlaod >> input operator for Movie's
istream& operator>> (istream &is, Movie &m)
{
  return m.read(is);
}

