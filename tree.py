class Node():

    def __init__(self, data):
        self.left = None
        self.right = None
        self.parent = None
        self.data = data

    def insert(self, d, l, r, p):
        self.data = d
        self.left = l
        self.right = r
        self.parent = p
 
    def isRoot(self):
        if self.parent == None:
            return true
        return false

class Tree():

    def __init__(self):
        self.nodes = []

    def fromList(self, nodeList):
        for subList in nodeList:
            for n in subList:
                node = Node(n)
                self.nodes.append(node)

    def getRoot(self):
        if self.isRoot():
            return self
        return getRoot(self.parent)

    def printTree(self):
        for n in self.nodes:
            print n.data
