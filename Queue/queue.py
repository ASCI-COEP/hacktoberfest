class Queue:
    def __init__(self):
        self.items = []
    def enq(self, data):
        self.items = [data] + self.items[:]
        #or self.items.insert(0, data)
    def deq(self):
        if(not self.isEmpty())
            return(self.items.pop())
        else:
            print('Already Empty')
    def isEmpty(self):
        return(self.items == [])
    def size(self):
        return(len(self.items))
    def printQueue(self):
        if(self.isEmpty()):
            print('Queue is empty')
        else:
            print(self.items)

q = Queue()
q.enq(2)
q.enq(4)
q.enq(8)
q.printQueue()
print(q.size())
r = Queue()
r.printQueue()
