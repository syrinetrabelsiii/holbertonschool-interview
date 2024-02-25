#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    int *left_array = malloc(n1 * sizeof(int));
    int *right_array = malloc(n2 * sizeof(int));

    if (!left_array || !right_array)
    {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n1; i++)
        left_array[i] = array[left + i];
    for (j = 0; j < n2; j++)
        right_array[j] = array[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (left_array[i] <= right_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }

    free(left_array);
    free(right_array);
}

void merge_sort(int *array, size_t size)
{
    size_t left, mid, right;

    if (size < 2)
        return;

    left = 0;
    mid = size / 2;
    right = size - 1;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(array, mid - left + 1);
    printf("[right]: ");
    print_array(array + mid + 1, right - mid);

    merge(array, left, mid, right);

    printf("[Done]: ");
    print_array(array, size);
    printf("\n");
}
