// FILE: Bag.h
// CLASS PROVIDED: Bag (adapted from textbook, CS Dept. Akira Kawaguchi)
// NOTE: this file may not be modified.
//
// TYPEDEF and MEMBER CONSTANTS for the Bag class:
//   typedef ____ value_type
//     Bag::value_type is the data type of the items in the Bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     Bag::size_type is the data type of any variable that keeps track of how many items
//     are in a Bag.
//
//   static const size_type CAPACITY = _____
//     Bag::CAPACITY is the maximum number of items that a Bag can hold.
//
// CONSTRUCTOR for the Bag class:
//   Bag()
//     Postcondition: The Bag has been initialized as an empty Bag.
//
// MODIFICATION MEMBER FUNCTIONS for the Bag class:
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the Bag, then one copy has been removed;
//     otherwise the Bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the Bag.
//
// CONSTANT MEMBER FUNCTIONS for the Bag class:
//   size_type size() const
//     Postcondition: The return value is the total number of items in the Bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the Bag.
//
// VALUE SEMANTICS for the Bag class:
//    Assignments and the copy constructor may be used with Bag objects.

#ifndef MAIN_SAVITCH_BAG1_H
#define MAIN_SAVITCH_BAG1_H
#include <iostream>   
#include <cstdlib>    // Provides size_t
#include "Student.h"  // Your Student class definition 
//using namespace std;

class Bag { 
 public:
  // TYPEDEFS and MEMBER CONSTANTS
  typedef Student value_type;
  typedef std::size_t size_type;
  static const size_type CAPACITY = 200;

  // CONSTRUCTOR 
  Bag() : used(0) {}

  // MODIFICATION MEMBER FUNCTIONS
  bool erase_one(const value_type& target);
  void insert(const value_type& entry);

  // CONSTANT MEMBER FUNCTIONS
  size_type size() const { return used; }
  size_type count(const value_type& target) const;

  // WHAT IS REQUIRED TO IMPLEMENT
  void sort_descending();         // Apply sort as defined in the assignment.
  value_type find_max() const;    // Return max value element.
  friend bool operator==(const Bag&, const Bag&);   // Bag equivalency check.
  friend std::ostream& operator<<(std::ostream&, const Bag&); // Enlist elements.

 private:
  value_type data[CAPACITY];      // Array to store items
  size_type used;                 // How much of array is used
};

Bag sort_descending(const Bag&); // This is required to implement.

#endif
