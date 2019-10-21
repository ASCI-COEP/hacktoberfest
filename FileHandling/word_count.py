import sys
fileName = sys.argv[1]
try:
	file = open(fileName, "r")
except Exception as IOError:
	print(fileName + " does not exists")
	exit(1)
no_lines = 0
no_words = 0
no_characters = 0
line = file.readline()

while line:
	line = line.rstrip()
	print(line)
	no_lines += 1
	no_words += len(line.split())
	no_characters += len(line)
	line = file.readline()
file.close()
print("Number of Lines: " + str(no_lines))
print("Number of Words: " + str(no_words))
print("Number of Characters: " + str(no_characters))
exit(0)