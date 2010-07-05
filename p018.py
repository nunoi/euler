#!/usr/bin/python

import graph

FILE = "p018_tree.txt"

def readGraph():
    f = open(FILE)
    parents = []
    g = graph.graph()
    for line in f:
        children = line.split(" ")
        if parents != []:
            for p in parents:
                node = (int(p), [int(children[parents.index(p)]), \
                                 int(children[parents.index(p) + 1])])
                g.addNode(node)
        parents = children
    return g 

g = readGraph()
#g.printGraph()
print g.getRootNode()
