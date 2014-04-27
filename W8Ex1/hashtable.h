/// File: hashtable.h
/// Interface for a chaining hashtable.

#ifndef _hashtable_h
#define _hashtable_h

#include <vector>
#include "record.h"

using namespace std;

template <typename Key, typename Value>
class HashTable {
public:

   /// no args constructor - sets the number of buckets to a preset INITIAL CAPACITY
   HashTable();

   /// constructor to set the number of buckets
   HashTable(int tableSize);

   /// destructor
   ~HashTable();

   /// utility methods
   int size();
   bool empty();
   void clear();

   /// insert a record into the hash table
   void insert(Record<Key, Value>* record);

   /// search for a key
   Record<Key, Value>* find(Key key);

   /// remove a key
   void erase(Key key);

private:
   vector< vector< Record<Key,Value>* > > data;
   unsigned int numElements;
   unsigned int capacity;
   double loadFactor;

   void rehash();

};
#include "hashtable.cpp"

#endif // _hashtable_h

