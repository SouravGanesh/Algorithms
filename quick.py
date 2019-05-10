import time
from time import clock
import random
import matplotlib.pyplot as plt 

q_list=[]
quick_list=[]
n_list=[]

for z in range (20):
    n=z*50
    list=[]
    for i in range(n):
        temp=random.randint(0,100)
        list.append(temp)
    print("generated array")
    for i in range(n):
        print(list[i])
    print(" ")
    print(" ")

    print("quick sort")

    q_list=list

    def partition( q_list , low , high ):
        i=(low-1)
        pivot=q_list[high]
        for j in range(low,high):
            if(q_list[j]<=pivot):
                i+=1
                q_list[i],q_list[j]=q_list[j],q_list[i]
            q_list[i+1],q_list[high]=q_list[high],q_list[i+1]
        return (i+1)

    def quick_sort(q_list,low,high):
        if(low<high):
            pi=partition(q_list,low,high)
            quick_sort(q_list,low,pi-1)
            quick_sort(q_list,pi+1,high)

	
    start=clock()
    quick_sort(q_list,0,n-1)
    end=clock()
    diff=end-start
    quick_list.append(diff)
    n_list.append(n)
    print("sorted array")
    for i in range(n):
            print(q_list[i])
    print(" ")    
    print(" ")

plt.plot(n_list,quick_list,label="q")
plt.legend()
plt.show()
