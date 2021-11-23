// query_movies.cpp 

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <sys/time.h>
#include "dict.h"
using namespace std;

void createMoviesDict(string fileName, Dictionary<Element>& moviesD)
{
    //Dictionary<Element> moviesDict;
    string line;

    ifstream input(fileName);

    timeval timeBefore, timeAfter; // timeval type defined in sys/time.h
    long diffSeconds, diffUSeconds; // elapsed seconds and microseconds
    gettimeofday(&timeBefore, NULL); // get the time before
    
    while(getline(input, line)) 
    {
        string title, cast, year;
        int end = line.find("(");
        title = line.substr(0, end - 1);
        year = line.substr(line.find("(",1)+1, line.find(")",2));
        cast = line.substr(line.find("\t",1)+1, line.find("\n",1));

        Element * newElement = new Element(title, cast);

        moviesD.insert(newElement);
    }
    
    gettimeofday(&timeAfter, NULL); // get the time after
    diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec; // elapsed seconds
    diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec; // elapsed microseconds
    double time = diffSeconds + diffUSeconds / 1000000.0; // total elapsed time

    input.close(); 

    cout << "The time to input all of movies: " << time << endl;
}

int main()
{
    string fileName = "movies_mpaa.txt"; 
    Dictionary<Element> moviesDict(11);
    createMoviesDict(fileName, moviesDict);

    //Testing to find cast of "A Woman Named Jackie"
    string textTitle1 = "\"A Woman Named Jackie\"";
    Element compEl1(textTitle1, "");
    Element * found1 = moviesDict.get(compEl1);
    cout << "The cast for \"A Woman Named Jackie\": " << (*found1).getValue() << endl;

    cout << endl;

    //Testing to find cast of "10 Years"
    string textTitle2 = "10 Years";
    Element compEl2(textTitle2, "");
    Element * found2 = moviesDict.get(compEl2);
    cout << "The cast for \"10 Years\": " << (*found2).getValue() << endl;
    
    cout << endl;

    return 0; 
}