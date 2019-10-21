import sys
fileName = sys.argv[1]
try:
	file = open(fileName, "r")
except Exception as IOError:
	print(fileName + " does not exists")
	exit(1)
line = file.readline()
while line:
	print(line.rstrip())
	line = file.readline()
file.close()
exit(0)