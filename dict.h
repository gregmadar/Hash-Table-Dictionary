// dict.h 

#ifndef DICT_H
#define DICT_H

#include <iostream>
#include <string>
#include <vector>
#include "hash.h"
using namespace std; 

class Element
{
  public: 
    string key; 
    string value; 
    Element(string k, string data)
    {
		key = k;
		value = data;
	}

	friend ostream &operator<<(ostream &output, const Element & ele) 
    {
		output <<  ele.key << ": " << ele.value << "\n";
		return output;
	}

    string getValue()
    {
        return value; 
    }

    string toString()
    {
        return value; 
    }
    
    int hash() const 
    {
        int length = key.length();
        int hashVal = 19;
        int xOrVal = 53;
        for (int i = 0; i < length; i++) {
            hashVal = (hashVal*37) + key.at(i);
            xOrVal = xOrVal ^ key.at(length - 1 - i);
        }
        hashVal *= xOrVal;
        return abs(hashVal);    
    }
};

// Operators for Element class
bool operator<(const Element& e1, const Element& e2)
{
	if (e1.key <= e2.key) 
    return true;
	else 
    return false;
}

bool operator>(const Element& e1, const Element& e2)
{
	if (e1.key >= e2.key) 
    return true;
	else 
    return false;
}

bool operator==(const Element& e1, const Element& e2)
{
	if (e1.key == e2.key) 
    return true;
	else 
    return false;
}

bool operator!=(const Element& e1, const Element& e2)
{
	if (!(e1 == e2)) 
    return true;
	else 
    return false;
}

bool operator<=(const Element& e1, const Element& e2)
{
	if ((e1 == e2) || (e1 < e2))
    return true;
	else 
    return false;
}

bool operator>=(const Element& e1, const Element& e2)
{
	if ((e1 == e2) || (e1 > e2))
    return true;
	else 
    return false;
}

template <class KeyType>
class Dictionary : public HashTable<KeyType>
{
  public:
    Dictionary(int tableSlots) : HashTable<KeyType> (tableSlots) { }; // constructor
    Dictionary(const Dictionary<KeyType>& dict); // copy constructor
    
    KeyType* get(const KeyType& k) const; // return an element with key k in dictionary
    void insert(KeyType * k); // insert a new element with key k into the dictionary
    void remove(const KeyType& k) ; // delete the element with key k from the dictionary
    
    // Specify that dictionary will be referring to the following members of HashTable<KeyType>
    using HashTable<KeyType>::get;
    using HashTable<KeyType>::insert;
    using HashTable<KeyType>::remove;
    using HashTable<KeyType>::toString;
};

#include "dict.cpp"

#endif