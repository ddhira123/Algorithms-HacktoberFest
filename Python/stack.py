from collections import deque

simplestack = deque()

print("Add character to stack")

simplestack.append("r")
simplestack.append("e")
simplestack.append("b")
simplestack.append("o")
simplestack.append("t")
simplestack.append("k")
simplestack.append("c")
simplestack.append("a")
simplestack.append("h")

print("Word in stack now")

print(simplestack)

print("After Pop from stack")

print(simplestack.pop()+simplestack.pop()+simplestack.pop()+simplestack.pop()+simplestack.pop()+simplestack.pop()+simplestack.pop()+simplestack.pop()+simplestack.pop())