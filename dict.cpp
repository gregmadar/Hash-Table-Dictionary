// dict.cpp 

/*======================================================================
Dictionary(const Dictionary<KeyType>& dict)        // copy constructor
Precondition: Must be given a dictionary
Postcondition: Iterates through the dictionary and makes a copy of its values to transfer to another dictionary
======================================================================*/
template <class KeyType>
Dictionary<KeyType>::Dictionary(const Dictionary<KeyType>& dict) : HashTable<KeyType> (dict) {}

/*=================================================================================
get(const KeyType& k)              // return first element with key equal to k
Precondition: Must be a given dictionary
Postcondition: Calls the "get" method inherited from HashTable class
=================================================================================*/
template <class KeyType>
KeyType* Dictionary<KeyType>::get(const KeyType& k) const
{
  return HashTable<KeyType>::get(k);
}

/*=========================================================================================
insert(const KeyType& k)          // insert element with key equal k to the dictionary
Precondition: Must be a given dictionary
Postcondition: Calls the "insert" method inherited from HashTable class
==========================================================================================*/
template <class KeyType>
void Dictionary<KeyType>::insert(KeyType * k)
{
  bool duplicate = true; 
  try 
  { // check if k is in Dictionary 
    KeyType* nodeFound = HashTable<KeyType>::get(*k); 
    duplicate = true; 
  }
  catch(...)
  {
    duplicate = false; 
  }
  if (!duplicate) 
    HashTable<KeyType>::insert(k); // insert if not found duplicate
}

/*================================================================================================
remove(const KeyType& k)         // delete first element with key equal k from the dictionary
Precondition: Must be a given dictionary
Postcondition: Calls the "remove" method inherited from HashTable class
================================================================================================*/
template <class KeyType>
void Dictionary<KeyType>::remove(const KeyType& k)
{
  HashTable<KeyType>::remove(k);
}

