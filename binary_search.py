import random 
import time
from time import clock
import matplotlib.pyplot as plt 

list=[]
binary_time=[]
n_value=[]

for z in range(10):

    n=z*50
    for i in range(n):
        rand=random.randint(0,100)
        list.append(rand)

    print("The generated array is : ")
    for i in range(n):
        print(list[i],end=" ")
    print(" ")
    
    list.sort()
    def binarySearch(list, item):
        first = 0
        last = len(list)-1
        found = 0
   
        while first<=last and not found:
            midpoint = (first + last)//2
            if list[midpoint] == item:
                found = 1
                print("Element found!")
            else:
                if (list[midpoint]>item):
                  last = midpoint-1
                else:
                    first = midpoint+1
        if(found==0):
            print("Element not found!")
  
        return found

    start=clock()
    #list.sort()
    binarySearch(list,random.randint(0,100))
    end=clock()
    diff=end-start
    binary_time.append(diff)
    n_value.append(n)

plt.plot(n_value,binary_time,label="binary")
plt.legend()
plt.show()
  
  