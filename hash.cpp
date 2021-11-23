// hash.cpp 

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*=================================================================
HashTable(int numSlots)       // Default Constructor
Preconditon: None
Postcondition: Creates an empty hashtable instance of size numSlots
=================================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
    slots = numSlots;
    table = new List<KeyType>[numSlots]; // an array of KeyType
}

/*====================================================================
HashTable(const HashTable<KeyType>& h)    // Copy Constructor
Precondition: Must be a given hashtable
Postcondition: Traverses the hash table and makes a copy of its values to transfer to another hash table
====================================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h)
{
    slots = h.numSlots;
    table = h.table;
}

/*======================================================
~HashTable()      // Destructor
Precondition: None
Postcondition: Deallocates the hash table
=======================================================*/
template <class KeyType>
HashTable<KeyType>::~HashTable()
{
    delete[] table;
    slots = 0;
}

/*=======================================================================
get(const KeyType& k) const   // Return first record with key equal to k
Precondition: Must be a given hash table
Postcondition: Returns a pointer to a record with key k if one exists; otherwise, return NIL
=======================================================================*/
template <class KeyType>
KeyType *HashTable<KeyType>::get(const KeyType& k) const
{
    int slot = k.hash() % slots; // compute key slot corresponding to k 
    List<KeyType> *pos = &table[slot]; // find the list that contains k at slot position
    Node<KeyType> *cur = pos->head;

    if(cur == NULL)
    {
        throw KeyError();   // if the list at slot is empty 
    }

    while(cur != NULL)
    {
        if(*(cur) -> item == k)
            return cur->item;   // node found
        else
            cur = cur->next;    // traverse till reach node to find
    }
    throw KeyError();   // throw error if k does not exist in hash table
}

/*============================================================================
insert(KeyType *k)       // Insert record with key equal to k to the hashtable
Precondition: k's value >= 0. Also, if k's value is not already a key in the hashtable, then the hashtable has space for another record
Postcondition: If the table already had a record with key equal to k's value, then that record is replaced by k. Otherwise, k has been added as a new record of the hashtable
=============================================================================*/
template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{
    int slot = k->hash() % slots;   // compute slot corresponding to k 
    List<KeyType> *pos = &table[slot];  // find the list that contains k at slot position 
    Node<KeyType> *cur = pos->head; 
    pos->insert(0, k);  // insert at head of list
}

/*=======================================================================================
remove(const KeyType& k)    // Delete first record with key equal to k from the hashtable
Precondition: Must be a given hash table
Postcondition: If a record was in the hashtable with the specified key k, then that record has been removed; otherwise the hashtable is unchanged.
========================================================================================*/
template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k)
{
    KeyType *temp = get(k); // find node to remove
    if (temp == NULL)
        throw KeyError();   // if node containing k not found

    int slot = k.hash() % slots; // compute slto
    List<KeyType> *pos = &table[slot];  // find list at slot position that contains k
    pos->remove(k); // remove k from list
}

/*======================================================
toString(int slot) const
=======================================================*/
template <class KeyType>
std::string HashTable<KeyType>::toString(int slot) const
{
    List<KeyType> *pos = &table[slot];  // find list at slot position 
    Node<KeyType> *cur = pos->head;

    stringstream s;

    while(cur != NULL)
    {
        s << (cur->item)->toString() << ", ";
        cur = cur->next;
    }
    string returnString = s.str();
    return returnString.substr(0, returnString.size() - 2);
}

