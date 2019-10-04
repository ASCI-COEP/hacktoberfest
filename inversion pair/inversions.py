import sys

#sys.setrecursionlimit(100000000)

#Reading in the file name which contains the elements of the array.

file_name = sys.argv[1]
with open(file_name) as f:
    content = f.readlines()
content = [int(x.strip()) for x in content]

#Algo

def mergeandcountsplitinv(B , C, Bstart , Bend, Cstart, Cend):
	arr = []
	i = Bstart
	j = Cstart
	invcount = 0
	
	#A = B+C
	#print(Bstart, Bend, Cstart, Cend, B, C)
	
	while i <= Bend and j <= Cend:
		
		#print(i,j)
		
		if C[j] < B[i]:
			arr.append(C[j])
			invcount += Bend - i + 1
			#print(invcount)
			j+=1
		else:
			arr.append(B[i])
			i+=1

	while i<= Bend:
		arr.append(B[i])
		i+=1
	while j <= Cend:
		arr.append(C[j])
		j+=1
	return (arr , invcount)

def sortcount(A, start, end):
	if start < end:
		m = (end+start)//2
		B = A[start:m+1]
		C = A[m+1:end+1]
		#print("B, C : ",B,C)

		(B, X) = sortcount(B, 0 ,m)
		(C, Y) = sortcount(C, 0, len(C) - 1)
		(D, Z) = mergeandcountsplitinv(B , C, 0 , m, 0 , len(C) - 1)
		return (D, X+Y+Z)
	else:
		return (A, 0)
		

#Driver
if __name__ == "__main__":
	print(sortcount(content, 0, len(content)-1)[1])