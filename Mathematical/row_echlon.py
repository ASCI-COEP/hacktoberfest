#!usr/bin/env/python 3
#This script converts any matrix to its row echlon form


n=int(input('Enter the no. of rows of matrix'))
p=int(input('Enter the no. of columns of matrix'))
matrix=[[0]*p for i in range(0,n)]
#print(matrix)
m=matrix
for i in range(0,n):
	for j in range(0,p):
		m[i][j]=int(input('Enter element {0}{1}  '.format(i+1,j+1)))
for i in range(0,n):
	for j in range(0,p):
		print(float(m[i][j]),end="\t\t\t")
	print()
print()
for i in range(0,n):
	for j in range(i+1,n):
		while(m[i][i]==0&i<n):
			for l in range(0,p):
				m[i][l],m[j][l]=m[j][l],m[i][l]
			i+=1
		temp=float(m[j][i]/m[i][i])
		for k in range(i,p):
			m[j][k]=m[j][k]-temp*m[i][k]	
print("\t\t\tROW ECHLON FORM")		
for i in range(0,n):
	for j in range(0,p):
		print(float(m[i][j]),end="\t\t\t")
	print()
	
	

