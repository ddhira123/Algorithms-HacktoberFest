
#simple linked list append node at left , right and at speecific location of linked list
class node:
    def __init__(self,data):
        self.data=data
        self.next=None

class link:
    def __init__(self):
        self.head=None
    #append new node at left side of linked list       
    def left(self,data):
        box = node(data)
        box.next=self.head
        self.head=box
    #append new node at right side of linked list
    def right(self,data):
        box= node(data)
        if self.head is None:
            self.head=box
            return
        temp=self.head
        while temp.next:
            temp=temp.next
        temp.next=box
    #append at specific location 
    def specific(self,data,index):
        if index==1:
            box=node(data)
            box.next=self.head
            self.head=box
            return
        i=1
        n=self.head
        while i<index-1 and n is not None:
            n=n.next
            i +=1
        if n is None:
            print("index out of bounnd sorry...")
            return
        else:
            box=node(data)
            box.next=n.next
            n.next=box
    def plink(self):
        temp=self.head
        while temp:
            print(temp.data),
            temp=temp.next
l=link()
l.right(40)
l.left(5)
l.left(4)
l.left(2)
l.right(55)
l.right(100)
l.specific(1001,3)
l.specific(5999,1)
l.plink()


