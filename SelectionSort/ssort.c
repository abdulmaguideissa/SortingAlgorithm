/** @file
    ssrot.c

  * @brief description
    implemetation of selection sort algorithm.
  
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

#include "ssort.h"

// ************* swap **************
// private function to swap two variables values
// using pointers
// inputs: pointer to the first integer,
//         pointer to the second integer.
// outputs: none
void static
swap(int32_t * a, int32_t * b);


// ************* smallest **************
// private function declaration.
// brief description: finding the smallest element in an array set.
// inputs:  pointer to array of integers,
//          starting index to find the smallest,
//          array size.
// outputs: position of the smallest element.
// NOTES:
int32_t static
smallest(int32_t * arr, uint32_t k, uint32_t n);


// ************* selection_sort **************
// Sort an array using selection sort algorithm
void 
selection_sort(int32_t* arr, uint32_t n) {
	uint32_t static pos;
	uint32_t        k;

	for ( k = 0; k < n; k++ ) {
		pos  = smallest(arr, k, n);
		swap(&arr[pos], &arr[k]);
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


// ************* smallest **************
// private function definition.
int32_t static
smallest(int32_t* arr, uint32_t k, uint32_t n) {
	uint32_t static pos;
	uint32_t        i;
	int32_t         small;
	
	pos = k;
	small = arr[k];

	for (i = k + 1; i < n; i++) {
		if (arr[i] < small) {
			small = arr[i];
			pos = i;
		}
	}
	return pos;
}

// ************* end of file *************
