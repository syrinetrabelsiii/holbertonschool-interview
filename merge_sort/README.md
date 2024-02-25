# Merge Sort

Merge sort is a popular sorting algorithm that follows the divide and conquer strategy. It divides the array into two halves, sorts them separately, and then merges them. This process continues recursively until the array is fully sorted.

## Algorithm

1. If the array has only one element, return it as it is already sorted.
2. Find the middle point to divide the array into two halves.
3. Recursively call merge sort for the first half.
4. Recursively call merge sort for the second half.
5. Merge the two halves by comparing each element and placing the smaller one in the result array.

## Time Complexity

The time complexity of merge sort in the worst case, average case, and best case is O(n log n).

## Space Complexity

The space complexity of merge sort is O(n), as it requires additional space to store the left and right sub-arrays during the merge process.