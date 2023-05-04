#include "search_algos.h"
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0) {
        return -1;
    }

    int mid = (size - 1) / 2;

    if (array[mid] == value) {
        while (mid > 0 && array[mid - 1] == value) {
            mid--;
        }
        return mid;
    }
     printf("Searching in array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("\n");

    if (array[mid] > value) {
        return advanced_binary(array, mid, value);
    } else {
        int subproblem_index = advanced_binary(&array[mid + 1], size - mid - 1, value);
        if (subproblem_index == -1) {
            return -1;
        } else {
            return mid + 1 + subproblem_index;
        }
    }
}
