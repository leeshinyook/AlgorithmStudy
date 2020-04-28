import sys
class node:
    def __init__(self,key):
        self.key =key
        self.left = None
        self.right = None
class bst:
    def __init__(self):
        self.root = None
    def insert(self,key):
        if self.root == None:
            self.root = node(key)
        else:
            current = self.root
            while True:
                if current.key > key:
                    if current.left == None:
                        current.left = node(key)
                        break
                    current = current.left
                elif current.key < key:
                    if current.right == None:
                        current.right = node(key)
                        break
                    current = current.right
def post(node):
    if(node.left):
        post(node.left)
    if(node.right):
        post(node.right)
    print(node.key)

b = bst()
while True:
    try:
        key = int(sys.stdin.readline())
        b.insert(key)
    except:
        break
post(b.root)