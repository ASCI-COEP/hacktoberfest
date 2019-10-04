#!usr/bin/env/python 3
#This script finds matrices U V and S present in the Singular Value Decomposition of a matrix useful in PCA.

import math
import numpy as np
from scipy.sparse import linalg
n=int(input('Enter the no. of rows of matrix'))
p=int(input('Enter the no. of columns of matrix'))
mat=[[0]*p for i in range(0,n)]
for i in range(0,n):
	for j in range(0,p):
		mat[i][j]=int(input('Enter element {0}{1}  '.format(i+1,j+1)))
mat = np.array(mat)
mat_tr = mat.transpose()
mat_x_mat_tr = np.matmul(mat,mat_tr)
mat_tr_x_mat = np.matmul(mat_tr,mat)
U = linalg.eigsh(mat_x_mat_tr)[1]
V = linalg.eigsh(mat_tr_x_mat)[1]
V_tr = V.transpose()				#FOR ORTHOGONAL MATRIX mat_tr =mat_inv
sigma_sq  = linalg.eigs(mat_tr_x_mat)[0]
sigma = sigma_sq**(0.5)  			#BROADCASTING
def display(x):
	for  i in range(len(x)):
		for j  in range(len(x[0])):
			if(j ==0):
				print("|",x[i][j],end="\t")
			elif j ==(len(x[0])-1):
				print(x[i][j],"|")
			else:
				print(x[i][j],end = "\t")
print("\t\t\tOUTPUT")
print(mat,"\n")
print("U = {}\n".format(U))
print("V_tr = {}\n".format(V_tr))
print("Sigma = {}\n".format(sigma))
#print("{0} = {1}{2}{3} ".format(display(mat),display(U),sigma,display(V_tr)))

