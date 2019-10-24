'''
DEQUEUE
Methods and Attributes
Deque() creates a new deque that is empty. It needs no parameters and returns an empty deque.
addFront(item) adds a new item to the front of the deque. It needs the item and returns nothing.
addRear(item) adds a new item to the rear of the deque. It needs the item and returns nothing.
removeFront() removes the front item from the deque. It needs no parameters and returns the item. The deque is modified.
removeRear() removes the rear item from the deque. It needs no parameters and returns the item. The deque is modified.
isEmpty() tests to see whether the deque is empty. It needs no parameters and returns a boolean value.
size() returns the number of items in the deque. It needs no parameters and returns an integer.
'''

class Dequeue:
    def __init__(self):
        self.items = []
    def isEmpty(self):
        return(self.items == [])
    def size(self):
        return(len(self.items))
    def addFront(self, data):
        self.items.append(data)
    def addRear(self, data):
        self.items = [data] + self.items[:]
    def removeFront(self):
        return(self.items.pop())
    def removeRear(self):
        x = self.items[0]
        self.items = self.items[1:]
        return(x)
        #or return(self.items.pop(0))

    
d = Dequeue()
d.addFront('hello')
d.addRear('world')
print(d.size())

print(d.removeFront() + ' ' +  d.removeRear())
print(d.size())
