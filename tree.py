class Tree():

    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def fromList(self, nodeList):
        for subList in nodeList:
            for n in subList:
                node = Tree(n)

    def getRoot(self):
        if self.isRoot():
            return self
        return getRoot(self.parent)

    def printTree(self):
        for n in self.nodes:
            print n.data
