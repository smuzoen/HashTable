#include <iostream>



using namespace std;

#ifdef _hashtable_h

const static double MAXIMUM_LOAD = 0.75;
const static int INITIAL_CAPACITY = 3;
const static int MULTIPLIER = 3;

/// no args constructor
template <typename Key, typename Value>
HashTable<Key,Value>::HashTable() {
   capacity = INITIAL_CAPACITY;
   data.resize(capacity);
   for (int i = 0; i < capacity; i++) {
      data[i].resize(0);
   }
   numElements = 0;
}

/// constructor to set the number of buckets
template <typename Key, typename Value>
HashTable<Key,Value>::HashTable(int tableSize) {
   capacity = tableSize;
   data.resize(capacity);
   for (int index = 0; index < capacity; index++) {
      data[index].resize(0);
   }
   numElements = 0;
}

/// destructor
template <typename Key, typename Value>
HashTable<Key,Value>::~HashTable() {
   clear();
}

/// returns number of elements in the table
template <typename Key, typename Value>
int HashTable<Key,Value>::size() {
   return numElements;
}

/// returns if the table is empty or not
template <typename Key, typename Value>
bool HashTable<Key,Value>::empty() {
   return numElements == 0;
}

/// clears all data
template <typename Key, typename Value>
void HashTable<Key,Value>::clear() {

   typename vector< Record<Key,Value>* >::iterator iter;
   for (unsigned int index = 0; index < capacity; index++) {
      if (!data[index].empty()) {
         for (iter = data[index].begin(); iter != data[index].end(); iter++) {
            cout << "Deleting " << (*iter)->toString() << endl;
            delete *iter;
            numElements--;
         }
         data[index].resize(0);
      }
   }
}

/// insert a record into the hash table
template <typename Key, typename Value>
void HashTable<Key,Value>::insert(Record<Key,Value>* record) {

   // calculate the index of the bucket for this record
   int index = record->getHash(capacity);
    cout << "Inserting " << record->toString() << " in bucket " << index << endl;

   data[index].push_back(record);
   numElements++;
   loadFactor = (double) numElements / capacity;

   if (loadFactor > MAXIMUM_LOAD) {
      cout << "REHASHING" << endl;
      rehash();
   }
}

/// search for a key
template <typename Key, typename Value>
Record<Key,Value>* HashTable<Key,Value>::find(Key key) {
   typename vector< Record<Key,Value>  *>::iterator iter;

   // create a temporary record to get the hash bucket
   Record<Key,Value>* temp;
   temp = new Record<Key,Value>(key);
   int index = temp->getHash(capacity);
   delete temp;

   // traverse chain to find exact record
   for (iter = data[index].begin(); iter != data[index].end(); iter++) {
      if ((*iter)->getKey() == key) {
         return *iter;
      }
   }
   return NULL;
}

/// remove a key
template <typename Key, typename Value>
void HashTable<Key,Value>::erase(Key key) {

   typename vector<Record<Key,Value>  *>::iterator iter;

   // create a temporary record to get the hash bucket
   Record<Key,Value>* temp = new Record<Key,Value>(key);
   int index = temp->getHash(capacity);
   delete temp;

   // traverse chain to find exact record
   for (iter = data[index].begin(); iter != data[index].end(); iter++) {
      if ((*iter)->getKey() == key) {

         // get a handle to the object, remove from vector and delete
         temp = *iter;
         data[index].erase(iter);
         delete temp;
         numElements--;
         break;
      }
   }
}

/// When table reaches loadFactor capacity limit make a bigger vector and rehash the data
template <typename Key, typename Value>
void HashTable<Key,Value>::rehash() {
   typename vector<Record<Key,Value>  *>::iterator iter;

   capacity = capacity * MULTIPLIER;
   vector< vector<Record<Key,Value>  *> > newData(capacity);

   for (unsigned int index = 0; index < data.size(); index++) {
      if (!data[index].empty()) {
         for (iter = data[index].begin(); iter != data[index].end(); iter++) {
            Record<Key,Value>* temp = *iter;
            int newIndex = temp->getHash(capacity);
            cout << temp->toString() << " goes in bucket " << newIndex << endl;
            newData[newIndex].push_back(temp);
         }
         data[index].clear();
      }
   }

   data = newData;
}

#endif

