#ifndef _MOVIECOLLECTION_HPP_
#define _MOVIECOL_HPP_
#include "Movie.hpp"
#include "MovieNode.hpp"

/*FILE: MovieCollection.hpp
AUTHOR: Belle Erhardt
DATE: 11/2020
Definition file for MovieCollection class
*/
#include <string>
#include <iostream>


class MovieCollection
{
private:
MovieNode* _head;
MovieNode* _tail;

public: 
// default constructor
MovieCollection();
//fully qualified constructor
MovieCollection(std::istream &file);
//Copy Constructor
MovieCollection(const MovieCollection &LinkedList);

// finctions to write out/read in Movie via a stream 
std::ostream& print (std::ostream &os) const;

// accessor and modifier
const MovieNode* head() const {return _head;}
MovieNode*& head() {return _head;}

//New Methods
const int size();
const double getRating(std::string Movie, int year);
MovieNode* findTail();
void clear();
bool checkMovie(Movie m);

//overloaded assignments
//1
MovieCollection& operator+=(const Movie &m);   
//2
MovieCollection& operator+=(MovieCollection &other); 
//3
MovieCollection operator=(MovieCollection other);
//4
MovieCollection& operator-=(Movie other);   
//5
MovieCollection& operator-=(MovieCollection &other);   
//6
const MovieCollection operator+(const MovieCollection &other) const;  
//7
const MovieCollection operator/(const MovieCollection other) ;


// overloaded << and >> operators. 
friend std::ostream& operator<< (std::ostream &os, const MovieCollection &m);
friend std::istream& MovieCollection(std::istream &file);
};
#endif
