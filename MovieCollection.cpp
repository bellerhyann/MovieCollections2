#include "MovieCollection.hpp"
#include "Movie.hpp"

#include <iostream>
using namespace std;


// default constructor
 MovieCollection:: MovieCollection()
	{
	_head= NULL;
	_tail=NULL;	
	}
	
//fully qualified constructor
MovieCollection:: MovieCollection(istream &file) 
{
	Movie filler;
	if(file)
	{
	filler.read(file);
	_head = new MovieNode(filler);
	MovieNode* nodePtr = _head;
	Movie readIn;
	readIn.read(file);	
	while(file)
		{
		readIn.read(file);
		nodePtr->next() = new MovieNode(readIn);
		nodePtr= nodePtr->next();	
		readIn.read(file);	
		}
	}
}	
MovieCollection:: MovieCollection(const MovieCollection &LinkedList)
	{
	MovieNode* check =LinkedList._head;
	if(check!=NULL)
		{
		_head = new MovieNode();
		MovieNode* OriginalnodePtr =LinkedList._head;
		MovieNode* nodePtr = _head;
		nodePtr->value()= OriginalnodePtr->value();
		while(OriginalnodePtr->next()!=NULL)
			{
			nodePtr->next()= new MovieNode;
			nodePtr=nodePtr->next();
			OriginalnodePtr=OriginalnodePtr->next();
			nodePtr->value()= OriginalnodePtr->value();
			}
		}
	if(check==NULL)
		{
		_head=NULL;
		_tail=NULL;
		}	
	}	
//Methods Below
const int
MovieCollection::size()
	{
	int counter=1;
	MovieNode* nodePtr = _head;
	while(nodePtr->next() != NULL)
		{
		counter++;
		nodePtr = nodePtr-> next();
		}
	return counter;
	}
const double
MovieCollection::getRating(string Movie, int year)
	{
	string title = Movie;
	double rating = -1;
	bool found = false;
	MovieNode* nodePtr = _head;
	while(nodePtr !=NULL && !found)
		{
		if (nodePtr->value().title()==title && nodePtr->value().year())// found
			{
			found=true;
			rating = nodePtr->value().rating();
			}
		else if(nodePtr->value().title() != title)
			{
			nodePtr= nodePtr->next();
			}
		 
			
		}
	return rating;
	}
MovieNode*
MovieCollection::findTail()
	{
	MovieNode* tail = _head;
		while(tail->next() != NULL)
			{tail=tail->next(); }
	return tail;	
	}
ostream&
MovieCollection::print (ostream &os) const
{
  MovieNode* nodePtr = _head;
  while(nodePtr != NULL)
  	{
  	os << nodePtr->value() <<endl; 
  	nodePtr=nodePtr->next(); 
  	}
  return os;
}	
// overlaod << output operator for Movie's
ostream& operator<< (ostream &os, const MovieCollection &m)
{
  return m.print(os);
}
void
MovieCollection::clear()
	{
	MovieNode* tail = findTail();
	_head = tail->next();
	}
bool
MovieCollection:: checkMovie(Movie m)
	{
	bool newMovie = true;
	MovieNode* nodePtr = _head;
	while(nodePtr!=NULL && newMovie==true)
		{
		if(nodePtr->value() == m)
			{newMovie=false;}
		nodePtr= nodePtr->next();
		}
	return newMovie;
	}
//overloaded opperators Below
//1
MovieCollection& 
MovieCollection::operator+=(const Movie &m)
	{
	MovieNode* nodePtr = _head;
	if(_head == NULL)
		{
		MovieNode* append = new MovieNode(m);	
		_head=append;
		_head->value()= m;
		
		return *this;
		}
	while(nodePtr != NULL) 
		{
		nodePtr= nodePtr->next();
		if(checkMovie(m))
		{
		MovieNode* newHead = new MovieNode(m);
		newHead->next()=_head;
		_head =newHead;
		}
		
		}
		
	return *this;
	}
//2
MovieCollection&
MovieCollection::operator+=(MovieCollection &other)
	{
	MovieNode* nodePtr = _head;
	MovieNode* otherPtr = other.head();
	while(nodePtr != NULL)
		{
		if(checkMovie(otherPtr->value()))
			{
			operator+=(otherPtr->value());
			}
		nodePtr= nodePtr->next();
		}
	return *this;
	}	
//3
MovieCollection
MovieCollection::operator=(const MovieCollection other)
	{
	MovieNode* otherPtr = other._head;
	if(other._head == NULL)
		_head=NULL;
	if(otherPtr != NULL)
	{
	_head= new MovieNode();
	MovieNode* nodePtr = _head;
	nodePtr->value()= otherPtr->value();
	while(otherPtr->next() != NULL)
		{
		nodePtr->next()= new MovieNode();
		nodePtr->value()= otherPtr->value();
		otherPtr= otherPtr->next();
		nodePtr= nodePtr->next();
		}
	nodePtr->value()= otherPtr->value();	
	}
	return *this;
	}	
//4
MovieCollection&
MovieCollection::operator-=(Movie other)
	{
	bool newMovie = true;
	MovieNode* nodePtr = _head;
	MovieNode* before;
	if(nodePtr == NULL)
		return *this;
		
	if(nodePtr->value() == other)
	{	
		_head = _head->next();
		return *this;
	}
	while(nodePtr!=NULL && newMovie==true)
		{
		before = nodePtr;	
		nodePtr = nodePtr->next();
		
		if(nodePtr->value() == other)
			{
			newMovie=false;
			break;			
			}
		}
		if(newMovie != true)
		{
			before->next() = nodePtr -> next();
			return *this;
		}
	return *this;
	}		
//5
MovieCollection&
MovieCollection::operator-=(MovieCollection &other)
	{
	MovieNode* nodePtr = _head;
	MovieNode* otherPtr = other.head();
	while(nodePtr != NULL)
		{
		while(otherPtr != NULL)
			{
			if(nodePtr->value() == otherPtr->value())
			{
			operator-=(otherPtr->value());
			}
			otherPtr= otherPtr->next();	
			}
		nodePtr= nodePtr->next();
		otherPtr = other.head();	
		}
	return *this;
	}	
//test
//6
const MovieCollection 
MovieCollection::operator+(const MovieCollection &other) const
	{
	MovieCollection LargerList;
	LargerList.head() = new MovieNode();
	MovieNode* LargerListPtr =LargerList.head();
	MovieNode* leftNodePtr =_head;
	MovieNode* rightNodePtr =other._head;
	
	LargerListPtr->value()= leftNodePtr->value();
	while(leftNodePtr->next()!=NULL)
		{
		LargerList += leftNodePtr->value();
		leftNodePtr=leftNodePtr->next();	
		}
	while(rightNodePtr->next()!=NULL)
		{
		LargerList += rightNodePtr->value();
		rightNodePtr=rightNodePtr->next();
		}
	return LargerList;
	}		
//7
//test
const MovieCollection
MovieCollection::operator/(const MovieCollection other) 
	{
	MovieCollection dublicateList;
	
	MovieNode* leftPtr = _head;
	MovieNode* rightPtr =other._head;
	
	if(other._head != NULL && _head != NULL)
		{
		
		while(leftPtr != NULL)
			{	
			rightPtr= other._head;
			while(rightPtr != NULL)
				{
				if(leftPtr->value() == rightPtr->value())
					dublicateList+=leftPtr->value();
				rightPtr = rightPtr->next();
				}
				leftPtr = leftPtr->next();
			}
	}
	return dublicateList;
	}
	
/*

*/	
