def selection_sort(arr):
    """Return a sorted array.
    
    :param arr: An array of integers.
    """

    for i in range(len(arr)):
        # Find the index of the minimum element in the remaining unsorted array.
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[min_idx] > arr[j]:
                min_idx = j

        # Swap the values
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

    return arr


unsorted_arr = [2, 8, 1, 16, 4]
print(selection_sort(unsorted_arr))
