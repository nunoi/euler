#!/usr/bin/python

from tree import Tree

FILE = "p018_tree.txt"

def readTree():
    nodes = []
    f = open(FILE)
    for line in f:
        numbers = line.split(" ")
        tmp = []
        for n in numbers:
            tmp.append(int(n))
        nodes.append(tmp)
    return nodes


treeList = readTree()
#print treeList
tree = Tree()
tree.fromList(treeList)
tree.printTree()
#root = graph.Node(tree[1])
#for i in range(0, len(tree[1:]), 2):
#    root.insert(i, i + 1)
#root.print_tree()

