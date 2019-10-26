import os
import multiprocessing
import inspect
import sched
import time
import random

#inspect(multiprocessing)
#help(multiprocessing)

#lets do a simple linear search.

def linear_1(l,n):
    for item in l:
        if item == n:
            print("Found!", end=" ")
            return
    return -1

def linear_2(l,n):
    for item in l:
        if item == n:
            print("Found!", end=" ")
            return
    return -1

def linear_3(l,n):
    for item in l:
        if item == n:
            print("Found!", end=" ")
            return
    return -1

def linear_4(l,n):
    for item in l:
        if item == n:
            print("Found!", end=" ")
            return
    return -1

def solution(n):
    linear = []
    x = 0
    # n=int(input("Enter size of array to be searched : "))
    for i in range(n):
        # linear.append(int(input("Enter element : ")))
        linear.append(random.randint(0,500))
    linear.sort()
    # print (linear)
    # x = int(input("Enter the number to be searched for : "))
    x=random.randint(0,500)
    if n < 4:
        start = time.time()
        linear_1(linear,x)
        end = time.time()
        printf("Size too small to use multiprocessing. Using single array appraoch instead")
        printf(end-start," secnods to execute task")
    else :

        len = n//4;
        l1, l2, l3, l4 = linear[:len], linear[len:2*len], linear[2*len:3*len], linear[3*len:]

        # print(l1,l2,l3,l4)

        p1 = multiprocessing.Process(target=linear_1, args=(l1, x))
        p2 = multiprocessing.Process(target=linear_2, args=(l2, x))
        p3 = multiprocessing.Process(target=linear_3, args=(l3, x))
        p4 = multiprocessing.Process(target=linear_4, args=(l4, x))

        start = time.time()
        p1.start()
        p2.start()
        p3.start()
        p4.start()
        end = time.time()

        p1.join()
        p2.join()
        p3.join()
        p4.join()

        print(end-start," seconds for distributed search")
        start=time.time()
        linear_1(linear, x)
        end=time.time()
        print(end-start," seconds for regular search")

solution(20)

size_list=[500,1000,10000,100000,250000,500000,1000000,2000000,2500000,3000000,4000000,5000000]
for i in range(len(size_list)):
    print("Size : ",size_list[i])
    solution(size_list[i])
