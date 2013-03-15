//
//  main.cpp
//  Vectors
//
//  Created by Loc Nguyen on 23.02.12.
//  Copyright (c) 2012 University of Zurich. All rights reserved.
//

#include <iostream>
#include "vectors.cpp"

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

	// TODO own Example here!

	return 0;
}

