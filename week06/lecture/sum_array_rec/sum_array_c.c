int sum_array_rec_c(int *arr, int len) {
    int sum = *arr;
    if (len == 1)
        return sum;
    return sum + sum_array_rec_c(arr + 1, len - 1);
}

int sum_array_c(int *arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}
