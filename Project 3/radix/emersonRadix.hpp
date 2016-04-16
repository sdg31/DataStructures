#ifndef EMERSONRADIX_HPP
#define EMERSONRADIX_HPP

#include <iostream>
#include <vector>

// modified current implementations to work with template vectors
template <typename T>
void countingSort(std::vector<T>& v, int digit) {
	//initalize an array to store the counts of each number in the input array
	int count[10] = {0};
	std::vector<T> output(v.size(), 0);


	//fill the count array with the number of each element in input array 
	int temp = 0;
	for(int i = 0; i < v.size(); i++) {
		temp = (v[i]/digit) % 10;
		count[temp]++;
	}

	//modify the count array so that the value correspond to indecies and 
	//not simply counts. This allows the values to be inserted in the final
	//sorting step
	for(int i = 1; i < 10; i++) {
		count[i] += count[i-1];
	}

	//Inert input records into their corresponding bins
	int loc = 0;
	for(int i = v.size()-1; i >= 0; i--) {
		loc = count[(v[i]/digit) % 10];
		output[loc] = v[i];
		count[(v[i]/digit) % 10]--;
	}

	//Reset the array given to the sorted values from the output
	for(int i = 0; i < v.size(); i++) {
		v[i] = output[i];
	}
}

// modified current implementations to work with template vectors
template <typename T>
void emersonSort(std::vector<T>& v) {
	//initialize values and find the maximum value of the ipnut array
	//to know how many decimal places to sort
	T max = v[0];
	for(int i = 0; i < v.size(); i++){
		if(max < v[i])
			max = v[i];
	}
	
	//Do the work of sorting on each digit
	//First the one's place
	//Then two's place
	//Then three's place and so on until the maximum digit is reached
	for(int digit = 1; max/digit > 0; digit = digit * 10){
		countingSort(v, digit);
	}
}

#endif
