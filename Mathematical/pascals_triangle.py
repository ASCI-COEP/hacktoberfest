def printPascal(n):
	for row in range(1, n + 1):
		ct = 1
		for i in range(1, row + 1):
			print(ct, end=" ")
			ct = int(ct * (row - i) / i)
		print("")
printPascal(int(input("Enter number of levels: ")))
