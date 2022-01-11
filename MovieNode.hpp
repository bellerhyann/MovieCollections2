#ifndef _MOVIENODE_HPP_
#define _MOVIENODE_HPP_
#include "Movie.hpp"

/*FILE: MovieCollection.hpp
AUTHOR: Belle Erhardt
DATE: 11/2020
Definition file for MovieNode class
*/
#include <string>
#include <iostream>
class MovieNode
{
private:
Movie _Value;
MovieNode* _Next;

public: 
//Default Constructor
MovieNode(): _Value(), _Next(NULL) {} 
//Basic Constructor
MovieNode(const Movie &Movie): _Value(Movie), _Next(NULL) {}

// accessor and modifier
const MovieNode* next() const {return _Next;}
MovieNode*& next() {return _Next;}

const Movie value() const {return _Value;}
Movie& value() {return _Value;}
// overloaded << 
friend std::ostream& operator<< (std::ostream &os, const MovieNode &m);
//std::ostream& print (std::ostream &os) const;
};
#endif


