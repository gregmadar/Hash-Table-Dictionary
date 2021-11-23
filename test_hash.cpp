// test_hash.cpp

#include "hash.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std; 

class Dummy // test class 
{
    private: 
        int key; 
    public: 
        Dummy() {}
        Dummy(int &data): key(data) {}
        ~Dummy() {}
        
        int hash() const
        {
            return key; 
        }

        bool operator==(const Dummy &d) const // load equality operator
        {
            if (d.key == key)
            {
                return true; 
            }
            else 
                return false; 
        }

        bool operator!=(const Dummy &d) const // load inequality operator
        {
            return !(*this == d); 
        }

        std::string toString() const // string representation 
        {
            std::stringstream ss;
            ss << key; 
	        return ss.str();
        }

        
};

int main()
{
    // Test constructor
    HashTable<Dummy> table(7);
    
    // Test insert method
    int a = 1; 
    Dummy *d1 = new Dummy(a); 
    table.insert(d1);
    
    int b = 2; 
    Dummy *d2 = new Dummy(b); 
    table.insert(d2);

    int c = 9; 
    Dummy d3(c); 
    table.insert(&d3);
    
    int d = 8; 
    Dummy d4(d); 
    table.insert(&d4);

    int e = 3; 
    Dummy d5(e); // existing node not yet inserted to hashtable

    // Test get method
    assert((table.get(*d1))->toString() == "1");
    assert(table.get(*d2)->toString() == "2") ;
    try
    {
        assert(table.get(d5)->toString() == "3"); 
    }
    catch (...)
    {
        cout << "get() method caught KeyError" << endl;
    }
    assert(table.get(d3)->toString() == "9");
    assert(table.get(d4)->toString() == "8");

    table.insert(&d5);

    // Test toString method
    assert(table.toString(2) == "9, 2"); 
    assert(table.toString(1) == "8, 1"); 
    assert(table.toString(3) == "3"); 
    
    table.remove(d4); 
    // Test remove method
    try 
    {
        assert((table.get(d4))->toString() == "8");
    }
    catch(...)
    {
        cout << "get() method caught KeyError()." << endl;
    }
    
    // remove method error when getting nonexisting element
    try
    {
        table.remove(d4); 
    }
    catch(...)
    {
        cout << "remove() method caught KeyError()." << endl;
    }

    assert(table.toString(1) == "1"); 

    return 0;
}