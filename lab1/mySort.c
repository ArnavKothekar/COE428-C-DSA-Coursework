void mySort(int array[], unsigned int num_elements){
    unsigned int i, j;
    int temp;
    for (i = 0; i < num_elements; i++) {
        for (j = 0; j < num_elements - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
