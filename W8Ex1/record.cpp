/// File: record.cpp
/// Implementation for Record class.
#include <math.h>
#ifdef _record_h

/// No args constructor
template <typename Key, typename Value>
Record<Key,Value>::Record() {
}

/// Sets key and values into the record
template <typename Key, typename Value>
Record<Key,Value>::Record(Key key) {
    this->key = key;
}

/// Sets key and values into the record
template <typename Key, typename Value>
Record<Key,Value>::Record(Key key, Value value) {
    this->key = key;
    this->value = value;
}

/// Accessors for the instance fields
template <typename Key, typename Value>
Key Record<Key,Value>::getKey() {
    return key;
}

template <typename Key, typename Value>
Value Record<Key,Value>::getValue() {
    return value;
}

///  Value mutator
template <typename Key, typename Value>
void Record<Key,Value>::setValue(Value value) {
   this->value = value;
}

/// Calculates the index to hash the record at based on the size of the table.
/// Uses Multiplication Hash algorithm A = 5 ^ 2 - 1 / 2
template <typename Key, typename Value>
unsigned int Record<Key,Value>::getHash(int M) {
    unsigned int index = 0;
    /*unsigned int prime = 31;
    for (unsigned int i = 0; i < key.length(); i++) {
        index += prime * index + (unsigned int) key[i];
    }*/
    double A = (pow(5,.5) - 1) / 2;
    for (unsigned int i = 0; i < key.length(); i++) {
        index += (int)M * (A * (unsigned int) key[i]- (int)(A*(unsigned int) key[i]));
    }
    return index % M;
}

template <typename Key, typename Value>
string Record<Key,Value>::toString() {
   return key + " - " + value;
}

#endif // _record_h
