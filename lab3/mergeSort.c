#include "mySort.h"

void merge(int array[], unsigned int first, unsigned int mid, unsigned int last)
{
    int temp[MAX_SIZE_N_TO_SORT];

    unsigned int i = first;
    unsigned int j = mid + 1;
    unsigned int k = first;

    /* Merge into temp array */
    while (i <= mid && j <= last) {

        if (myCompare(array[i], array[j]) <= 0) {
            myCopy(&array[i], &temp[k]);
            i++;
        } else {
            myCopy(&array[j], &temp[k]);
            j++;
        }
        k++;
    }

    /* Copy remaining elements from left half */
    while (i <= mid) {
        myCopy(&array[i], &temp[k]);
        i++;
        k++;
    }

    /* Copy remaining elements from right half */
    while (j <= last) {
        myCopy(&array[j], &temp[k]);
        j++;
        k++;
    }

    /* Copy merged elements back into original array */
    for (i = first; i <= last; i++) {
        myCopy(&temp[i], &array[i]);
    }
}


/* Recursive MergeSort */
void mySort(int array[], unsigned int first, unsigned int last)
{
    if (first >= last)
        return;

    unsigned int mid = first + (last - first) / 2;

    mySort(array, first, mid);
    mySort(array, mid + 1, last);

    merge(array, first, mid, last);
}