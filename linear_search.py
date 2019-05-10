import random 
import time
from time import clock
import matplotlib.pyplot as plt 

list1=[]
linear_time=[]
n_list=[]

for i in range(100):
	
	n=i*50

#----------Random array--------------#
	for j in range(n):
		temp=random.randint(0,100)
		list1.append(temp)
#----------Random array--------------#

	print("The generated array is : ")

	for j in range(n):
		print(list1[j],end=" ")
	print(" ")

	key=random.randint(0,100)
	z=0

	start=clock()
	for j in range(n):
		if(list1[j]==key):
			z=1
			print("Element found!")
			break

	if(z==0):
		print("Element not found!")
	end=clock()

	diff=end-start
	linear_time.append(diff)
	n_list.append(n)

plt.plot(n_list,linear_time,label="linear")
plt.legend()
plt.show()





