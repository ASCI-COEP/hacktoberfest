#============================================================================
# Name        : Karatsuba.py
# Author      : Soumya Saurav
# Version     : 1.0
# Copyright   : You can use this code however and wherever you want.
# Description : python script to Perform Karatsbuba Multiplications
#============================================================================


import math
import sys

#Karatsuba's algorithm of fast multiplication
#https://en.wikipedia.org/wiki/Karatsuba_algorithm

def karatsuba(x,y):
	n1 = int(len(x)/2 + len(x)%2)
	n2 = int(len(y)/2 + len(y)%2)
	return multiply(int(x), int(y), n1, n2)

def multiply(x,y,n1,n2):
	#Base case if any of the digits in x and y has a length less than 10000 then normal multiplication is used.
	if(n1 < 10000 or n2 < 10000):
		return x*y
	n = max(n1,n2)
	power10 = pow(10,n)
	a = x/power10
	b = x - a*power10
	c = y/power10
	d = y - c*power10
	ac = multiply(a,c,len(str(a)), len(str(c)))
	aplusbcplusd = multiply(a+b,c+d,len(str(a+b)), len(str(c+d)))
	bd = multiply(b,d,len(str(b)), len(str(d)))

	# ---> (10^(n*2))*ac + (10^(n))*(ad + bc) + bd  
	# ---> (10^(n*2))*ac + (10^(n))*((a+b)*c+d) - ac - bd) + bd  

	return pow(10,n*2)*ac + (aplusbcplusd - ac - bd)*power10 + bd

#Driver

if __name__ == "__main__":
	x = input("Enter first number: ")
	y = input("Enter second number: ")
	#x = "2718281828459045235360287471352662497757247093699959574966967627"
	#y = "3141592653589793238462643383279502884197169399375105820974944592"
	print(karatsuba(x,y))