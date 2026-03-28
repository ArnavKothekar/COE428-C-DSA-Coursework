#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){
	
	unsigned int i, j;

    /* Nothing to sort */
    if (first >= last)
        return;

    for (i = first + 1; i <= last; i++) {
        
        int key;
        myCopy(&array[i], &key);   // key = data[i]

        j = i;

        /* Shift elements of sorted portion to the right */
        while (j > first && myCompare(array[j - 1], key) > 0) {
            myCopy(&array[j - 1], &array[j]);
            j--;
        }

        /* Insert key into correct position */
        myCopy(&key, &array[j]);
    }
		
}
