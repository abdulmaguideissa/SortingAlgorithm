/** @file
    bsort.c

  * @brief description
    implementation of bubble sort algorithm
  
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

#include "bsort.h"


// ************* swap **************
// private function to swap two variables values
// using pointers
// inputs: pointer to the first integer,
//         pointer to the second integer.
// outputs: none
void static
swap(int32_t * a, int32_t * b);


// ************* bubble_sort **************
// boolean flag to exit an already sorted array.
void 
bubble_sort(int32_t *arr, uint32_t n) {
	uint32_t i; 
	uint32_t j;
	bool     flag;

	flag = 0;

	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n - i - 1; j++ ) {
			if ( arr[j] > arr[j + 1] ) {
				flag = 1;
				swap(arr[j], arr[j + 1]);
			}
		}
		if ( flag == 0 ) {       // Array is sorted 
			return;
		}
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


// ************* end of file *************
