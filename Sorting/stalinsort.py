# STALIN SORT - A sorting algorithm that eliminates all elements that are out of order to create a sorted array

print('Enter space seperated array: ')

arr = list(map(int, input().split()))
sortedarr = []

old = arr[0]

sortedarr.append(old)

for x in arr[1:]:
    if x >= old:
        sortedarr.append(x)
        old = x

print(' '.join(map(str,sortedarr)))

