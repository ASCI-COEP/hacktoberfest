"""
Counts every Line, Whitespaces, Characters and Words written in a text within a file.
This solution relies on the use of Regular Expressions.
"""

import re
import os

homePath = os.path.expanduser("~") + "/"
filePath = raw_input("Insert the path of your file to count. Example: /documents/sample.txt\nThis is your current home path below, please start from there:\n> " + homePath)
file = open(homePath + filePath, "r")
string = file.read()

class Counter:
    def countLines(self, string):
        result = re.findall("\n", string)
        print "Lines:", len(result) + 1
    
    def countWhitespaces(self, string):
        result = re.findall(" ", string)
        print "Whitespaces:", len(result)
    
    def countCharacters(self, string):
        result = re.findall("(\S|\N)", string)
        print "Characters:", len(result)
    
    def countWords(self, string):
        def filterCondition(elem):
            return elem != ''
        result = filter(filterCondition, re.split("\n|\s", string))
        print "Words:", len(result)

counter = Counter()
counter.countLines(string)
counter.countWhitespaces(string)
counter.countCharacters(string)
counter.countWords(string)

file.close()
