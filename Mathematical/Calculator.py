"""
   Ashutoshsingh Jitendrasingh Pardeshi
   FY Computer Engineering
   MIS No. :- 111903141
"""
import math
print("1 : Addition")
print("2 : Subtraction")
print("3 : Multiplication")
print("4 : Division-Displays Remainder")
print("5 : Division-Displays Quotient")
print("6 : Power To be raised")
print("7 : Square")
print("8 : Square root")
print("9 : Sine function")
print("10 : Cosine Function")
print("11 : Tangent Function")
print("12 : Logarithm to base 10")
print("13 : Logarithm to base e")

a = input("Enter which option you would like to execute :- Option ")  # Taking the input from user

otp_list = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13']
if a in otp_list:  # Input validation
    pass
else:
    print("\nYou have entered the wrong option number. Last chance for retry.")
    a = input("Enter which option you would like to execute :- Option ")

if a == "1" or a == "2" or a == "3":
    n1 = int(input("Enter the first number:- "))
    n2 = int(input("Enter the second number:-"))
    if a == "1":
        print("The addition of the two numbers is ", n1+n2)
    elif a == "2":
        print("The subtraction of the two numbers is ", abs(n1-n2))
    elif a == "3":
        print("The multiplication of the two numbers is ", n1*n2)
if a == "4" or a == "5":
    n1 = float(input("Enter the dividend :- "))
    n2 = float(input("Enter the divisor :- "))
    if a == "5":
        print("The quotient of the division  ", n1/n2)
    if a == "4":
        print("The remainder of the division is ", n1 % n2)
if a == "6" or a == "7" or a == "8":
    n1 = int(input("Enter the number:- "))
    if a == "6":
        n2 = int(input("Enter the power:- "))
        print("%d raised to %d is : %d " % (n1, n2, n1**n2))
    if a == "7":
        print("The square of the number is : ", n1**2)
    if a == "8":
        print("The square root of the number is : ", n1**0.5)
if a == "9" or a == "10" or a == "11":
    n1 = float(input("Enter the angle in radians :- "))
    if a == "9":
        print("The sine function of the angle is : ", math.sin(n1))
    if a == "10":
        print("The cosine function of the angle is : ", math.cos(n1))
    if a == "11":
        print("The tangent function of the angle is : ", math.tan(n1))
if a == "12" or a == "13":
    n1 = float(input("Enter the number:- "))
    if a == "12":
        print("The natural logarithm of the number is : ", math.log10(n1))
    if a == "13":
        print("The logarithm of the number to the base e is : ", math.log(n1))
