n = int(input("Enter size of array and max element in array "))
max_element = int(input("Enter max element ")) 
l = list()
for x in range(0, n):
	l.append(int(input()))

print("list before sorting")
print(l)

count_arr = [0 for x in range(0, max_element + 1)]

for x in l:
	count_arr[x] += 1

i = 0
for x in range(0, max_element + 1):
	for y in range(0, count_arr[x]):
		l[i] = x
		i += 1

print("list after sorting")
print(l)
