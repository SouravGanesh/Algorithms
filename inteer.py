import random
import time
from time import clock
import matplotlib.pyplot as plt

list1 = []
inter_time = []
n_list = []

for i in range(10):

    n = i*50

#----------Random array--------------#
    for j in range(n):
        temp = random.randint(0, 100)
        list1.append(temp)
#----------Random array--------------#

    print("The generated array is : ")

    for j in range(n):
        print(list1[j], end=" ")
    print(" ")

    
    list1.sort()


    def interpolationSearch(list,ele):
        n=len(list)
        low=0
        high=n-1
        while low<=high and ele>=list[low] and ele<=list[high]:
            if low==high:
                if list[low]==ele:
                    return low
                return -1
            pos=low+int(((float(high-low)/(list[high]-list[low]))*(ele-list[low])))
            if list[pos]==ele:
                return pos
            else:
                high=pos-1
        return -1
    
    start=clock()
    interpolationSearch(list1,random.randint(0,100))
    end=clock()
    diff=end-start
    inter_time.append(diff)
    n_list.append(n)

plt.plot(n_list,inter_time,label="inter")
plt.legend()
plt.show()





