class Stack:
    def __init__(self):
        self.items = []
    def push(self, data):
        self.items.append(data)
    def isEmpty(self):
        return(self.items == [])
    def pop(self):
        return(self.items.pop())
    def printStack(self):
        print(self.items)
    def peek(self):
        print(self.items[-1])


s = Stack()
print(s.isEmpty())
s.push(2)
s.push(3)
s.push(4)
s.printStack()
print(s.pop())
s.printStack()
s.push('lol')
s.peek()
