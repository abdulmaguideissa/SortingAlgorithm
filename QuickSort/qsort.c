/** @file
    qsort.c
  
  * @brief description
    implementation of quick sort algorithm
  
  * @author
    Abdulmaguid Eissa
  
  * @date
    January, 2019
  
  *	@COPYRIGHT NOTICE
  *
  *
  *
* */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#include "qsort.h"



// ************* swap **************
// private function to swap two variables values
// using pointers
// inputs: pointer to the first integer,
//         pointer to the second integer.
// outputs: none
void static
swap(int32_t * a, int32_t * b);

// ************* arr_partition **************
// private function declaration.
// inputs: pointer to array of integers,
//         begining poistion of the array,
//         end position of the array.
// outputs: position.
// NOTES:   merging the broken subarrays into one complete array.
// Split the array using partition function
uint32_t static
arr_partition(int32_t *arr, uint32_t beg, uint32_t end);



// ************* quick_sort **************
void 
quick_sort(int32_t* arr, uint32_t beg, uint32_t end) {
	uint32_t static location;

	if ( beg < end ) {
		location = arr_partition(arr, beg, end);
		quick_sort(arr, beg, location - 1);
		quick_sort(arr, location + 1, end);
	}
}


// ************* swap **************
// private function definition.
void static
swap(int32_t * a, int32_t * b) {
	(*a) ^= (*b);
	(*b) ^= (*a);
	(*a) ^= (*b);
}

// ************* arr_partition **************
// private function definition.
uint32_t static
arr_partition(int32_t *arr, uint32_t beg, uint32_t end) {
	uint32_t static location;
	uint32_t left;
	uint32_t right;
	bool     flag;

	location = beg;
	left     = beg;
	right    = end;
	flag     = false;

	while (!flag) {
		while ((arr[location] <= arr[right]) && (location != right)) {
			right--;					  // Shift to the left of arr
		}
		if (location == right) {
			flag = true;
		}
		else if (arr[location] > arr[right]) {
			swap(&arr[right], &arr[location]);  // Swap the values
			location = right;
		}
		if (!flag) {
			while ((arr[location] >= arr[left]) && (location != left)) {
				left++;						 // Shift to the right of arr
			}
			if (location == left) {
				flag = true;
			}
			else if (arr[location] < arr[left]) {
				swap(&arr[left], &arr[location]);  // Swap the values
				location = left;
			}
		}
	}
	return location;
}


// ************* end of file *************
