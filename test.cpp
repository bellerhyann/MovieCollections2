#include <iostream>
#include <fstream>

#include <iostream>
#include <fstream>

#include "Movie.hpp"
#include "MovieCollection.hpp"
#include "MovieNode.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  MovieCollection simple;
  ifstream ifile("someMovies1.txt");
  MovieCollection fromFile(ifile);
  ifile.close();
  MovieCollection duplicate(fromFile);
  cout<< endl <<duplicate << endl;
  cout<<"^prints duplicate fromFile"<<endl;
  cout << "========================================================="<<endl << endl;
  Movie stw("Star Wars", 1977, 9);// To remove in the Middle
  simple+=stw;
  Movie cinders("Mark of Zorro, The", 1940, 8); // To Remove the Head
  simple += cinders;
  Movie belle("Belle", 2000, 8); // To Remove the Head
  simple += belle;
  
  MovieCollection test;
  test = ( fromFile/ simple);
  //test = fromFile / simple;
  test.print(cout);
  //cout<< endl <<test << endl;
  cout<<"should Print fromFile / simple"<<endl;
  cout << "========================================================="<<endl << endl;
  cout<<simple<<endl;
  cout<<"prints out simple"<<endl;
  cout << "========================================================="<<endl << endl;
    cout<<duplicate<<endl;
  cout << "========================================================="<<endl << endl;
    cout<<fromFile<<endl;
    
  /*
   
  

  
  cout<<fromFile << endl;
  cout << "========================================================="<<endl << endl;
  cout << "Same Duplicate... SHOULD NOT HAVE CHANGED\n" << endl; 
  cout << duplicate << endl;//SHOULD NOT HAVE CHANGED
  cout << "========================================================="<<endl << endl;
  
 
  simple += stw;
  cout << simple;

  cout << "========================================================="<<endl << endl;
  duplicate -= simple; // Delete top and somewhere in the middle (StarWars)
  cout << duplicate << endl;
  cout << "========================================================="<<endl << endl;
 
  duplicate.clear();
  cout<<duplicate << endl;

  
  
  
   Movie temp("Fantasia", 1940, 9);
  simple+= temp;
  
  cout<<fromFile.size()<< endl;
  
  
       <<endl << endl;
  fromFile+=temp;
  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining, Fantasia ... (not necessarily in this orer)
  cout << fromFile; 
  cout << "========================================================="
       <<endl << endl;

  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining  ... (not necessarily in this order, but not
  //       including Fantasia!)
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;
  

  MovieCollection otherDup;
  Movie fod("Field of Dreams" , 1989, 10);
  //otherDup = duplicate += fod;
  
  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining, Field of Dreams  ... (not necessarily in this
  //    order)
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;
  
  // should give: Mark of Zorro, Cinderella, , Magnificent Seven,
  //    Funny Thing Happened on the Way to the Forum, MASH, Star Wars,
  //    Airplane!, Shining, Field of Dreams  ... (not necessarily in this
  //    order)
  cout << otherDup;
  cout << "========================================================="
       <<endl << endl;

  Movie cinders("Cinderella", 1950, 7);
  otherDup-=cinders;

  // same as last output, but without Cinderella. 
  cout << otherDup;
  cout << "========================================================="
       <<endl << endl;

  // same as last output, but WITH Cinderella.
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;

  duplicate.clear();

  // should be empty. 
  cout << duplicate;
  cout << "========================================================="
       <<endl << endl;
  
  // same as last output of otherDup, certainly not empty!
  cout << otherDup;
  cout << "========================================================="
       <<endl << endl;
  */
}
