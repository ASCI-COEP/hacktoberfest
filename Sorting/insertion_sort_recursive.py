'''
A recursive implementation of Insertion Sort
'''

def insertion_sort_recursive(array_to_be_sorted, size):
    if size > 0:
        insertion_index = size - 1
        insertion_sort_recursive(array_to_be_sorted, size - 1)
        insert(array_to_be_sorted, insertion_index, array_to_be_sorted[size])

def insert(array_to_be_sorted, insertion_index, last_element):
    while insertion_index >= 0 and array_to_be_sorted[insertion_index] > last_element:
        array_to_be_sorted[insertion_index + 1] = array_to_be_sorted[insertion_index]
        insertion_index -= 1

    array_to_be_sorted[insertion_index + 1] = last_element

array_of_numbers = [5,4,3,2,1]
insertion_sort_recursive(array_of_numbers, len(array_of_numbers) - 1)
print(array_of_numbers)