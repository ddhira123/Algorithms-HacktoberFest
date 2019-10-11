import gc
import math
import random
from collections import defaultdict

class Graph:
	def __init__(self):
		self.graph=defaultdict(list)

	def addEdge(self,u,v):
		self.graph[u].append(v)

	def visitNode(self, v, visited):
		visited[v]=True;
		print(v),

		for i in self.graph:
			if visited[i]==False:
				self.visitNode(i, visited)

	def DFS(self, v):
		visited=[False]*(len(self.graph))
		self.visitNode(v, visited)

def makeGraph():
	g=Graph()
	g.addEdge(0,1)
	g.addEdge(0,4)
	g.addEdge(0,5)
	g.addEdge(0,9)
	g.addEdge(1,11)
	g.addEdge(1,2)
	g.addEdge(1,5)
	g.addEdge(0,5)
	g.addEdge(2,4)

	for i in range(0,3):
		print ("\n"+"Connected components at Vertex ",i," : ")
		g.DFS(i)

makeGraph()
