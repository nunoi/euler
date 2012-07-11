#!/usr/bin/python

from graph import Vertex
from graph import Graph

FILE = "p018_tree.txt"

#def readGraph():
#    f = open(FILE)
#    parents = []
#    g = graph.graph()
#    for line in f:
#        children = line.split(" ")
#        if parents != []:
#            for p in parents:
#                node = (int(p), [int(children[parents.index(p)]), \
#                                 int(children[parents.index(p) + 1])])
#                g.addNode(node)
#        parents = children
#    return g

def readFile():
    f = open(FILE)
    vertices = []
    for line in f:
        verts = line.split(" ")
        tmp = []
        for v in verts:
            tmp.append(int(v))
        vertices.append(tmp)
    return vertices

def makeGraph(vertices):
    f = open(FILE)
    g = Graph(True)
    for i in range(len(vertices)):
        for k in range(len(vertices[i])):
            g.addVertex(vertices[i][k])
    print (len(g.vertices))
    for i in range(len(vertices) - 1):
        for k in range(len(vertices[i])):
            print str(i) + "   " + str(k)
            g.addEdge((g.vertices[(i*(i+1)/2) + k-1],
                g.vertices[((i+1)*(i+2)/2) + k-1]))
            print ((i+1)*(i+2)/2) + k + 1
            g.addEdge((g.vertices[(i*(i+1)/2) + k-1],
                g.vertices[((i+1)*(i+2)/2) + k-1 + 1]))
    return g

def getMaxSum(g):
    sum = 0
    v = g.vertices[0]
    sum = v.data
    return sum

vertices = readFile()
g = makeGraph(vertices)

v = g.vertices[3]
for e in g.getEdges(v):
    a, b = e
    print str(a.data) + "   " + str(b.data)

#g.printGraph()
#g.printEdges()
#print getMaxSum(g)


# Test graph class

#g = Graph()
#g.addVertex()
#g.addVertex()
#g.addVertex()
#g.addVertex()
#
#g.addEdge((g.vertices[-1],g.vertices[-2]))
#g.addEdge((g.vertices[-2],g.vertices[-3]))
#g.addEdge((g.vertices[-3],g.vertices[-4]))
#
#g.printGraph()
#g.printEdges()



