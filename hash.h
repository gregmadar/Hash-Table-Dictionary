// hash.h

#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include "list.h"

template <class KeyType>
class HashTable
{
    public:
        HashTable(int numSlots);
        HashTable(const HashTable<KeyType>& h);
        ~HashTable();

        KeyType* get(const KeyType& k) const;
        void insert(KeyType *k);
        void remove(const KeyType& k);

        std::string toString(int slot) const;

    private:
        int slots;
        List<KeyType> *table; // an array of List<KeyType>
};

class KeyError{ };

#include "hash.cpp"

#endif