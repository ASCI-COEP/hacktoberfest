class ListNode:
    def __init__(self, next_node=None, value=None):
        self.next = next_node
        self.value = value

def find_loops(data):
    visited = []
    while data.next:
        if data.value not in visited:
            visited.append(data.value)
            data = data.next
        else:
            return True
    return False

if __name__ == '__main__':
    
    noloop = ListNode(value=1)
    aux = noloop
    for i in range(2,11):
        aux.next = ListNode(value=i)
        aux = aux.next
        
    loop = ListNode(value=1)
    aux = loop
    for i in range(2,11):
        aux.next = ListNode(value=i)
        aux = aux.next
    aux.next = loop
    
    print(f'First list has loops: {find_loops(noloop)}')
    print(f'Second list has loops: {find_loops(loop)}')
    


