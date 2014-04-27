/// File: record.h
/// Store key and value information for a hash table.

#ifndef _record_h
#define _record_h

#include <string>
#include <iostream>

using namespace std;

template <typename Key, typename Value>
class Record {
public:

   /// No args constructor
   Record();

   /// Sets key into the record
   Record(Key);

   /// Sets key and values into the record
   Record(Key, Value);

   /// Accessors for the instance fields
   Key getKey();
   Value getValue();

   ///  Mutators for the instance fields
   void setValue(Value);

   /// Calculates the index to hash the record to based on the size of the table.
   unsigned int getHash(int M);

   /// provides a String representation of the record
   string toString();

private:
   Key key;
   Value value;
};

#include "record.cpp"

#endif // _record_h
