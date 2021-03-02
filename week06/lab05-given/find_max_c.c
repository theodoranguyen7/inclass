// Find the largest element in the array of length N

int find_max_c(int *array, int n)
{
    int i;
    int max = array[0];  // Start by assuming the first element is the max

    for (i = 1; i < n; i++) {
        if (array[i] > max) {
            max = array[i];  // New max
        }
    }

    return max; 
}
