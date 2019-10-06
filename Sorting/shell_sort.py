def shell_sort(unsorted_array, size):
    gap = size / 2
    gap_index = gap
    while gap > 0:
        for gap_index in range(gap, size):
            temp_item = unsorted_array[gap_index]
            insert_index = gap_index

            while insert_index >= gap and unsorted_array[insert_index - gap] > temp_item:
                unsorted_array[insert_index] = unsorted_array[insert_index - gap]
                insert_index -= gap
            unsorted_array[insert_index] = temp_item
        gap /= 2


array_of_numbers = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
shell_sort(array_of_numbers, len(array_of_numbers))
print(array_of_numbers)