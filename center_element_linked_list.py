import gc
import math
import random

class Node:
	def __init__(self, data):
		self.data=data;
		self.next=None;

class LinkedList:

	def __init__(self):
		self.head=None;
		self.length=0;

	def push(self, value):
		new_node=Node(value);
		new_node.next=self.head;
		self.head=new_node;
		self.length=self.length+1;

	def printList(self):
		temp=self.head
		while(temp):
			print(temp.data),
			temp=temp.next
		print('\n')

	def printCenter(self):
		#use the self.length param
		temp=self.head;
		count=0
		while(temp):
			
			if(count==self.length/2):
				print(temp.data)
				return #memory usage is half
			else:
				temp=temp.next
			count=count+1; #keep count

def makeList():

	linked=LinkedList()
	for i in range(15):
		linked.push(i)
	linked.printList()
	print("Length : ",linked.length)
	print("Center element : "),
	linked.printCenter()

makeList()