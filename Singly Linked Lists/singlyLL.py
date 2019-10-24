class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class SinglyLL:
    def __init__(self):
        self.head = None
        
    def displayList(self):
        cur_node = self.head
        if(self.head is not None):
            while(cur_node is not None):
                print(cur_node.data, end = ' ')
                cur_node = cur_node.next
            print()
        else:
            print('List is empty')
            return
        
    def countNodes(self):
        cur_node = self.head
        count = 0
        if(self.head is None):
            return(count)
        else:
            while(cur_node is not None):
                count += 1
                cur_node = cur_node.next
            return(count)
        
    def search(self, x):
        cur_node = self.head
        pos = 0
        flag = 0
        if(self.head is None):
            print('Not found list empty')
            return
        else:
            while(cur_node is not None):
                if(cur_node.data == x):
                    print('Element {} found at index {}'.format(x, pos))
                    flag = 1
                    return True
                cur_node = cur_node.next
                pos += 1
            if(flag == 0):
                print('Element not found')
                return False

    def insertatbeginning(self, data):
        new_node = Node(data) #created a new node
        new_node.next = self.head   #set the next of new node to current head
        self.head = new_node    #set the head to the current node since we want to add at the start

    def insertatend(self, data):
        new_node = Node(data)   #created a new node with value 'data'
        if(self.head is not None):  #if the LL is not empty
            cur_node = self.head        #first set cur_node to head
            while(cur_node.next is not None):   #traverse until cur_node points to the last node of list
                cur_node = cur_node.next        
            cur_node.next = new_node    #set the last node's next to the new_node
        else:
            self.head = new_node    #if list empty just make head point to the new_node

    def insertafter(self, data, x): #insert node of value 'data' after node with value x
        new_node = Node(data)
        if(self.head is not None):
            cur_node = self.head
            while(cur_node is not None):
                if(cur_node.data == x):
                    break
                cur_node = cur_node.next
            new_node.next = cur_node.next
            cur_node.next = new_node
        else:
            self.head = new_node
        

            
            
            


a = SinglyLL()
a.displayList()
print(a.countNodes())
a.search(2)
a.insertatbeginning(3)
a.insertatbeginning(4)
a.insertatend(5)
a.displayList()
print(a.countNodes())
a.search(3)
                
                
