#Contains functions for pre-order, post-order and in-order traversals of a given binary tree.

#Each node of the tree is defined using a class called Node
class Node:
    def __init__(self, key):
        '''
        Creates a node object.
        Members:
            left: reference to the left Node
            right: reference to the right Node
            val: content of the Node
        '''

        self.left = None
        self.right = None
        self.val = key

#Pre-order function
def print_pre_order(root):
    '''
    Input: root Node of a given tree
    Output: Sequence of val printed in pre-order
    '''
    if root:
        print(root.val, end = " ")
        print_pre_order(root.left)
        print_pre_order(root.right)
    
    #unnecessary else, hence commented
    # else:
    #     print(f"root Node is None")

#Post-order function
def print_post_order(root):
    '''
    Input: root Node of a given tree
    Output: Sequence of val printed in post-order
    '''
    if root:
        print_post_order(root.left)
        print_post_order(root.right)
        print(root.val, end = " ")
    
    #unnecessary else, hence commented
    # else:
    #     print(f"root Node is None")

#In-order function
def print_in_order(root):
    '''
    Input: root Node of a given tree
    Output: Sequence of val printed in in-order
    '''
    if root:
        print_in_order(root.left)
        print(root.val, end = " ")
        print_in_order(root.right)

    #unnecessary else, hence commented
    # else:
    #     print(f"root Node is None")


if __name__ == '__main__':
    #verification of traversals
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.right = Node(4)
    root.left.left = Node(5)

    print(f"Pre-order traversal of the given binary tree:")
    print_pre_order(root)
    print()

    print(f"Post-order traversal of the given binary tree:")
    print_post_order(root)
    print()

    print(f"In-order traversal of the given binary tree:")
    print_in_order(root)
    print()