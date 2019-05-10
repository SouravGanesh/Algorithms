import time
from time import clock
import random
import matplotlib.pyplot as plt 

s_list=[]
selection_list=[]
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

    print("selection sort")
    s_list=list
    start=clock()

    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if s_list[min_index]>s_list[j]:
                min_index=j
        s_list[i],s_list[min_index]=s_list[min_index],s_list[i]

    end =clock()
    diff=end-start
    selection_list.append(diff)
    n_list.append(n)
    print("sorted array")
    for i in range(n):
        print(s_list[i])
    print(" ")    
    print(" ")

plt.plot(n_list,selection_list,label="s")
plt.legend()
plt.show()
