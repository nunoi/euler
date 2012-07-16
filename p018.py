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

def getParentIndex(i, k):
    # add 1 to both args to account for arrays starting at zero
    #i = i + 1
    #k = k + 1

    res = ((i) * (i + 1)/2) + k
    return res

def getChildrenIndexes(i, k):
    #res = ((i + 1) * (i + 2)/2) + k - 1
    res = getParentIndex(i, k) + i + 1
    return (res, res + 1)

def makeGraph(vertices):
    f = open(FILE)
    g = Graph(True)
    for i in range(len(vertices)):
        for k in range(len(vertices[i])):
            g.addVertex(vertices[i][k])
    for i in range(len(vertices) - 1):
        for k in range(len(vertices[i])):
            #print str(i) + " " + str(k) + " : " + str(getParentIndex(i, k)) + " " + str(getChildrenIndexes(i, k))
            p = getParentIndex(i, k)
            a, b = getChildrenIndexes(i, k)
            g.addEdge((g.vertices[p], g.vertices[a]))
            g.addEdge((g.vertices[p], g.vertices[b]))
    return g

def getChildren(v):
    children = []
    for e in g.getEdges(v):
        a, b = e
        if b != v:
            children.append(b)
    return children

def getMaxSum(g):
    a = None
    b = None
    sum = 0
    used_vertices = []
    vertex = g.vertices[0]
    sum = vertex.data
    while (getChildren(vertex) != []):
        used_vertices.append(vertex)
        max_v = None
        for v in getChildren(vertex):
            if v != None:
                if max_v == None:
                    max_v = v
                if v.data >= max_v.data:
                    max_v = v
        vertex = max_v
        print str(vertex.data) + " : " + str(sum)
        sum = sum + vertex.data
    return sum

vertices = readFile()
g = makeGraph(vertices)

#print str(g.vertices[17].data)
#print str(g.vertices[109].data)
#print str(g.vertices[119].data)
#print str(g.vertices[17]==g.vertices[109])
#v = g.vertices[119]
#for e in g.getEdges(v):
#    a, b = e
#    print str(a.data) + "   " + str(b.data)

#g.printGraph()
#g.printEdges()
print getMaxSum(g)


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



