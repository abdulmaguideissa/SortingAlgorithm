/** @file
    ssrot.h

  * @brief description
    API to interface the implemetation of selection sort algorithm.
  
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


// ************* smallest **************
// private function declaration.
// brief description: finding the smallest element in an array set.
// inputs:  pointer to array of integers,
//          starting index to find the smallest,
//          array size.
// outputs: position of the smallest element.
// NOTES:
int32_t static
smallest(int32_t* arr, uint32_t k, uint32_t n);


// ************* selection_sort **************
// Sort an array using selection sort algorithm
void 
selection_sort(int32_t* arr, uint32_t n) {
	uint32_t static pos;
	uint32_t        k;
	int32_t         temp;

	for ( k = 0; k < n; k++ ) {
		pos  = smallest(arr, k, n);
		temp = arr[k];
		arr[k]   = arr[pos];
		arr[pos] = temp;
	}
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
