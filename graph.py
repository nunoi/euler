
class Vertex():
    data = None

    def __init__(self, data = None):
        self.data = data

class Graph():
    vertices = []
    edges = []
    directed = False

    def __init__(self, directed = False):
        self.directed = directed

    def addVertex(self, data = None):
        v = Vertex(data)
        self.vertices.append(v)

    def removeVertex(self, v):
        self.vertices.remove(v)

    def addEdge(self, edge):
        a, b = edge
        self.edges.append((a, b))
        if not self.directed:
            self.edges.append((b, a))

    def getEdges(self, v = None):
        if v != None:
            return self.getEdgesForVertex(v)
        else:
            return self.getAllEdges()

    def removeEdge(self, edge):
        a, b = edge
        self.edges.remove((a, b))
        if not directed:
            self.edges.remove((b, a))

    def getAllEdges(self):
        return self.edges

    def getEdgesForVertex(self, v):
        edgeList = []
        for e in self.edges:
            a, b = e
            if a == v or b == v:
                edgeList.append(e)
        return edgeList

    def printGraph(self):
        for vertex in self.vertices:
            s = ""
            if vertex.data != None:
                s = str(vertex.data) + " : "
            s = s + str(vertex)
            print s

    def printEdges(self):
        print(str(self.edges))


