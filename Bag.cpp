// FILE: Bag.cpp
// CLASS IMPLEMENTED: bag (see bag.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <cassert>   // Provides assert function
#include <algorithm>
#include <functional>
#include "Bag.h"
using namespace std;

const Bag::size_type Bag::CAPACITY;
    
bool Bag::erase_one(const value_type& target) {
  size_type index; // The location of target in the data array    

  // First, set index to the location of target in the data array,
  // which could be as small as 0 or as large as used-1. If target is not
  // in the array, then index will be set equal to used.
  index = 0; 
  while ((index < used) && (data[index] != target))
    ++index;
  
  if (index == used)
    return false; // target isn't in the bag, so no work to do.
  
  // When execution reaches here, target is in the bag at data[index].
  // So, reduce used by 1 and copy the last item onto data[index].
  --used;
  data[index] = data[used];    
  return true;
}

Bag::size_type Bag::count(const value_type& target) const {
  size_type answer = 0;
  for (size_type i = 0; i < used; ++i)
    if (target == data[i])
      ++answer;
  return answer;
}

void Bag::insert(const value_type& entry) {
  // Library facilities used: cassert
  assert(size() < CAPACITY);
  
  data[used] = entry;
  ++used;
}

//================== Required Implemenation Starts Here ======================
typedef Student value_type;

void Bag::sort_descending() {
	//sort(data, data + used); // The easy way out

	// lambda function to take care of quicksort's partition function
	auto partition = [](Bag::value_type data[], size_t used, size_t& pivot_idx)
	// Precondition: used > 1, and data is an array (or subarray)
	// with at least used elements.
	// Postcondition: The function has selected some “pivot value”
	// that occurs in data[0]. . .data[used-1]. The elements of data
	// have then been rearranged and the pivot index set so that
	// -- data[pivot_index] is equal to the pivot;
	// -- each item before data[pivot_index] is <= the pivot;
	// -- each item after data[pivot_index] is > the pivot.
	-> void {
		assert(used > 1);

		// 1.
		value_type pivot = data[0];
		size_t too_big_idx = 1, too_small_idx = used - 1;

		// 2.
		while(too_big_idx <= too_small_idx) {
			if(too_big_idx < used && data[too_big_idx] <= pivot)
				++too_big_idx;

			if(data[too_small_idx] >= pivot)
				--too_small_idx;

			if(too_big_idx < too_small_idx)
				swap(data[too_big_idx], data[too_small_idx]);
		}

		// 3.
		pivot_idx = too_small_idx;
		swap(data[pivot_idx], data[0]);
	};

	// lambda function for quicksort
	function<void(value_type[], size_t&)> quicksort =
			[&](value_type data[], size_t& used) -> void {
		size_t pivot_idx, n1, n2;

		if(used > 1) {
			partition(data, used, pivot_idx);

			n1 = pivot_idx;
			n2 = used - n1 - 1;

			// recursive calls to sort the subarrays
			quicksort(data, n1);
			quicksort((data + pivot_idx + 1), n2);
		}
	};

	quicksort(data, used);
	reverse(data, data + used);
}

Bag::value_type Bag::find_max() const {
	Student max;

	for(size_t i = 0; i < used; ++i) {
		if(data[i] > max)
			max = data[i];
	}

	return max;
}

bool operator==(const Bag& lhs, const Bag& rhs) {
	if(lhs.size() != rhs.size())
		return false;

	// if you're here, this means they have the same sizes
	// now loop through them and compare the elements

	for(int i = 0, len = lhs.size(); i < len; ++i) {
		if(lhs.data[i] != rhs.data[i]) return false;
	}

	// if you made it here, that means that all elements are equal
	// order does matter
	return true;
}

ostream& operator<<(ostream& o, const Bag& b) {
	for(size_t i = 0; i < b.used; ++i) {
		o << b.data[i] << std::endl;
	}

	return o << std::endl;
}

Bag sort_descending(const Bag& b) {
	Bag a = b;

	a.sort_descending();

	return a;
}
