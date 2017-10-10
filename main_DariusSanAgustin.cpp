#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "Bag.h"
//s#include "Student.h"

using namespace std;

/*
 * Darius San Agustin Sept. 12, 2017
 * Project 3: Students & Custom Bag [Ext from HW2]
 * Instructor: Cesar Rojas
 * IDE: Eclipse Neon CDT (Uses C++11)
 */

//-Main-Function--------------------------------------------------------------

int main() {
	srand(time(0));
	const int numStudents = 100;
	Bag bag_stds;

	for(int i = 0; i < numStudents; ++i) {
		bag_stds.insert(Student());
	}

	bag_stds.sort_descending();

	cout << bag_stds << endl;

	return 0;
}

