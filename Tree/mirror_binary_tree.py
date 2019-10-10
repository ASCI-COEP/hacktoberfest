# Python 3 program to convert a Binary Tree to its mirror

class newNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def mirror(root):
    if (root == None):
        return

    que = []
    que.append(root)

    # Do BFS. While doing BFS, keep swapping left and right children
    while (len(que)):

        # pop top node from queue
        curr = que[0]
        que.pop(0)

        # swap left child with right child
        curr.left, curr.right = curr.right, curr.left

        # append left and right children to queue
        if (curr.left):
            que.append(curr.left)
        if (curr.right):
            que.append(curr.right)

def inorder(node):
    if (node == None):
        return
    inorder(node.left)
    print(node.data, end=" ")
    inorder(node.right)

if __name__ == "__main__":
    root = newNode(4)
    root.left = newNode(2)
    root.right = newNode(5)
    root.left.left = newNode(1)
    root.left.right = newNode(3)

    print("inorder traversal of the given binary tree is: ")
    inorder(root)

    mirror(root)

    print("\ninorder traversal of the mirror tree is: ")
    inorder(root)
