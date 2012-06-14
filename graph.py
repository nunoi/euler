class graph():
    nodes = {}

    def addNode(self, node):
        value, children = node
        self.nodes[value] = children

    def removeNode(self, node):
        pass

    def printGraph(self):
        for value in self.nodes:
            print str(value) + ", " + str(self.nodes[value])

    def getRootNode(self):
        res = None
        all = []
        allchildren = []
        for v in self.nodes:
            c = self.nodes[v]
            all.append(v)
            c1, c2 = c
            if c1 not in allchildren:
                allchildren.append(c1)
            if c2 not in allchildren:
                allchildren.append(c2)
        print len(all)
        print len(allchildren)
        for v in all:
            if v not in allchildren:
                print "not in: " + str(v)
                res = v
        return res


