/** @file
    isort.c

  * @brief description
    implementation of insertion sort algorithm
  
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

#include "isort.h"


// ************* insertion_sort **************
void 
insertion_sort(int32_t* arr, uint32_t n) {
	uint32_t i;
	uint32_t j;
	int32_t  value;

	for ( i = 1; i < n; i++ ) {
		value = arr[i];		     // Get new value from unsorted set
		j     = i - 1;			 // Start from the sorted set
		while ( (value < arr[j]) && (j >= 0) ) {  // Search for proper position of this value
			arr[j + 1] = arr[j];	  // Exchange the values
			j--;
		}
		arr[j + 1] = value;			// Insert this new value
	}
}

// ************* end of file *************
