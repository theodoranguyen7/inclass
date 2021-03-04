#include <stdio.h>

int sum_array_c(int *arr, int len);
int sum_array_rec_c(int *arr, int len);
int sum_array_s(int *arr, int len);
int sum_array_rec_s(int *arr, int len);

int main(int argc, char **argv) {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("sum_array_c: %d\n", sum_array_c(arr, 5));
    printf("sum_array_rc: %d\n", sum_array_rec_c(arr, 5));
    printf("sum_array_s: %d\n", sum_array_s(arr, 5));
    printf("sum_array_rs: %d\n", sum_array_rec_s(arr, 5));
    return 0;
}
