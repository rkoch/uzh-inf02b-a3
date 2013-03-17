//
//  main.cpp
//  Vectors
//
//  Created by Loc Nguyen on 23.02.12.
//  Copyright (c) 2012 University of Zurich. All rights reserved.
//
//  Authored by Remo Koch
//  Public repository at https://github.com/rkoch/uzh-inf02b-a3
//

#include <iostream>
#include "vectors.cpp"

#define PI 3.14159

int main(int argc, const char * argv[]) {

	ArrayVector<int> my_vector;

	for (int i = 0; i < 15; i++) {
		my_vector.insertAtRank(i, i * 2 + 2);
		std::cout << "in slot " << i << " is the number " << my_vector.elemAtRank(i) << "\n";
	};

	my_vector.removeAtRank(10);
	my_vector.removeAtRank(1);
	my_vector.removeAtRank(12);

	std::cout << "show vector after some removals\n";

	for (int i = 0; i < 12; i++) {
		std::cout << "in slot " << i << " is the number " << my_vector.elemAtRank(i) << "\n";

	}

	// 2) Own example here
	std::cout << std::endl << "2) My own example ------------" << std::endl;
	ArrayVector<float> other;

	for (int i = 0; i < 12; i++) {
		other.insertAtRank(i, i * PI);
		std::cout << "In slot " << i << " is the number " << other.elemAtRank(i) << std::endl;
	}

	std::cout << std::endl << "--- Size of vector: " << other.size() << " ---" << std::endl;

	while (!other.isEmpty()) {
		other.removeAtRank(0);
	}

	const char* res = other.isEmpty() ? "Yes" : "No";
	std::cout << "--- Is vector now empty? " << res << std::endl;

	return 0;
}

