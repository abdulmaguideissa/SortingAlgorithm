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
#include <stdlib.h>

#include "msort.h"

#define SIZE    100

// ************* merge **************
// private function declaration.
// inputs: pointer to array of integers,
//         mid podition of the array,
//         begining poistion of the array,
//         end position of the array.
// outputs: none.
// NOTES:   merging the broken subarrays into one complete array.
void static
merge(int32_t *arr, uint32_t mid, uint32_t beg, uint32_t end);



// ************* merge_sort **************
// Merge sort algorithm using divide and conquer "recursion".
void 
merge_sort(int32_t *arr, uint32_t beg, uint32_t end) {
	uint32_t mid;

	if ( beg < end ) {
	    mid = (end + beg) / 2;
		merge_sort(arr, beg, mid);	      // Left array
		merge_sort(arr, mid + 1, end);	  // Right array
		merge(arr, mid, beg, end);
	}
}


// ************* merge **************
// private function definition.
void static 
merge(int32_t *arr, uint32_t mid, uint32_t beg, uint32_t end) {
	uint32_t index;
	uint32_t i;
	uint32_t j;
	uint32_t temp[SIZE];
	uint32_t k;

	index = beg;
	i     = beg;
	j     = mid + 1;

	while ((i <= mid) && (j <= end)) {   // Compare and find the smaller element of the subarrays 
		if (arr[i] < arr[j]) {
			temp[index] = arr[i];
			i++;
		} // End of if
		else {
			temp[index] = arr[j];
			j++;
		} // End of else
		index++;
	} // End of while

	if (i > mid) {	        // Copy the remaining elements of the right subarray, if any.
		while (j <= end) {
			temp[index] = arr[j];
			j++;
			index++;
		} // End of while
	} // End of if
	else {			            // Copy the remaining elements of the left subarray, if any.
		while (i <= mid) {
			temp[index] = arr[i];
			i++;
			index++;
		} // End of while
	} // End of else

	  // Copy the context of temp back to arr
	k = beg;
	while (k < index) {
		arr[k] = temp[k];
		k++;
	} // End of while
}

// ************* end of file *************