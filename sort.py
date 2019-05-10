
import time
from time import clock
import random
import matplotlib.pyplot as plt

#-------------Generate a random array---------------------#

bubble_list=[]
selection_list=[]
merge_list=[]
heap_list=[]
quick_list=[]
insertion_list=[]
n_list=[]

b_list=[]
s_list=[]
q_list=[]
i_list=[]
h_list=[]
m_list=[]

for z in range (20):

	n=z*50
	list=[]
	for i in range(n):
		temp=random.randint(0,100)
		list.append(temp)
	#n=len(list)
	print("The generated array is : ")
	for i in range(n):
		print(list[i],end=" ")
	print(" ")
	print(" ")

#-------------Bubble Sort---------------------#

	print("BUBBLE SORT")
	print(" ")
	b_list=list

	start=clock()

	def bubbleSort(b_list):
		for i in range(n):
			for j in range(0,n-i-1):
				if(list[j]>list[j+1]):
					list[j],list[j+1]=list[j+1],list[j]

	bubbleSort(b_list)

	end = clock()
	diff=end-start
	bubble_list.append(diff)
	n_list.append(n)

	print("The sorted array is :")
	for i in range(n):
		print(b_list[i],end=" ")
	print(" ")
	print(" ")


#-------------Selection Sort---------------------#

	print("SELECTION SORT")
	print(" ")
	s_list=list

	start=clock()

	for i in range(n): 
      
    		min_idx = i 
    		for j in range(i+1, n): 
        		if s_list[min_idx] > s_list[j]: 
            			min_idx = j 
                
    		s_list[i], s_list[min_idx] = s_list[min_idx], s_list[i] 

	end=clock()
	diff=end-start
	selection_list.append(diff)
  
	print ("Sorted array is : ") 
	for i in range(n): 
    		print(s_list[i],end=" ")
	print(" ")  
	print(" ")

#-------------Quick Sort---------------------#
	
	q_list=list
	print("QUICK SORT")
	print(" ")

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
	print("The sorted list is : ")
	for i in range(n):
		print(q_list[i],end=" ")
	print("")
	print("")
	quick_list.append(diff)

#-------------Merge Sort---------------------#

	print("MERGE SORT")
	print("")

	m_list=list

	def merge_sort(m_list):
		if len(m_list) > 1 :
			mid=len(m_list)//2
			L=m_list[:mid]	
			R=m_list[mid:]
			merge_sort(L)
			merge_sort(R)
			i = j = k = 0
			while i < len(L) and j < len(R):
				if L[i] < R[j]:
					m_list[k]=L[i]
					i+=1
				else:
					m_list[k]=R[j]
					j+=1
				k+=1
			while i < len(L):
				m_list[k]=L[i]
				i+=1
				k+=1
			while j < len(R):
				m_list[k]=R[j]
				j+=1
				k+=1

	start=clock()
	merge_sort(m_list)
	end=clock()
	diff=end-start
	merge_list.append(diff)
	print("The sorted array is : ")
	for i in range(n):
		print(m_list[i],end = " ")
	print("")

#-----------------Insertion sort-------------------#
	i_list=list

	def insertion_sort(i_list):
		for i in range(1,len(i_list)):
			key=i_list[i]
			j=i-1
			while j>=0 and key<i_list[j]:
				i_list[j+1]=i_list[j]
				j-=1
			i_list[j+1]=key

	start=clock()
	insertion_sort(i_list)
	end=clock()
	diff=end-start
	insertion_list.append(diff)

#------------------Heap sort------------#

	h_list=list

	def heapify(h_list,n,i):
		largest=i
		l=2*i+1
		r=2*i+2
		if l < n and h_list[i] < h_list[l]:
			largest=l
		if r < n and h_list[largest] < h_list[r]:
			largest=r
		if largest!=i:
			h_list[i],h_list[largest]=h_list[largest],h_list[i]
			heapify(h_list,n,largest)

	def heasort(h_list):
		n=len(h_list)
		for i in range(n , -1, -1):
			heapify(h_list,n,i)
		for i in range(n-1,0,-1):
			h_list[i],h_list[0]=h_list[0],h_list[i]
			heapify(h_list,i,0)

	start=clock()
	heasort(h_list)
	end=clock()
	diff=end-start
	heap_list.append(diff)




plt.plot(n_list,bubble_list,label="Bubble")
plt.plot(n_list,selection_list,label="Selection")
plt.plot(n_list,quick_list,label="Quick")
plt.plot(n_list,merge_list,label="Merge")
plt.plot(n_list,insertion_list,label="Insertion")
plt.plot(n_list,heap_list,label="Heap")
plt.legend()
plt.show()