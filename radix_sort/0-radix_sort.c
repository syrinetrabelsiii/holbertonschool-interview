#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: array of integers to be sorted
 * @size: size of the array
 **/
void radix_sort(int *array, size_t size)
{
    int max, exp, *output;
    size_t i;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        int count[10] = {0};

        for (i = 0; i < size; i++)
            count[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = size - 1; (int)i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (i = 0; i < size; i++)
            array[i] = output[i];

        print_array(array, size);
    }

    free(output);
}
