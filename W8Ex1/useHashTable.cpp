#include <iostream>
#include "hashtable.h"

using namespace std;

int main() {

   // create the hash table

   HashTable<string, string> phoneBook(3);

   cout << "Hash table is " << (phoneBook.empty() ? "" : "not ") << "empty" << endl;
   cout << "Hash table contains " << phoneBook.size() << " entries" << endl << endl;


   // insert some values
   phoneBook.insert(new Record<string,string>("John", "3333 1111"));
   phoneBook.insert(new Record<string,string>("Peter", "3892 1234"));
   phoneBook.insert(new Record<string,string>("Maria", "0407 123 456"));
   phoneBook.insert(new Record<string,string>("Wendy", "0423 999 999"));
   phoneBook.insert(new Record<string,string>("Telstra", "1234"));
   phoneBook.insert(new Record<string,string>("Emergency", "000"));
   cout << endl << "Hash table is " << (phoneBook.empty() ? "" : "not ") << "empty" << endl;
   cout << "Hash table contains " << phoneBook.size() << " entries" << endl << endl;

   // erase an existing key
   cout << "Removing a record that exists - ";
   phoneBook.erase("John");
   cout << "Hash table contains " << phoneBook.size() << " entries" << endl << endl;

   // erase an non-existing key
   cout << "Removing a record that does not exist - ";
   phoneBook.erase("Fred");
   cout << "Hash table contains " << phoneBook.size() << " entries" << endl << endl;

   // empty the hash table
   phoneBook.clear();
   cout << "Hash table is " << (phoneBook.empty() ? "" : "not ") << "empty" << endl;
   cout << "Hash table contains " << phoneBook.size() << " entries" << endl;

   return 0;
}
