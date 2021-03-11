import numpy as np
import random
from plot_data import plot_data

def insertion_sort(values):
    k = 0
    n = len(values) - 1
    comparisons = 0
    while k+1 <= n:
        i = k+1
        curr_val = values[i]
        comparisons += 1
        while i>0 and values[i-1] > curr_val:
            values[i] = values[i-1]
            i=i-1
            comparisons += 1
        values[i] = curr_val
        k = k + 1
    return comparisons


def bubble_sort(arr): 
    count = 0
    n = len(arr) 
    for i in range(n-1): 
        for j in range(0, n-i-1):
            count += 1
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
    return count

def bubble_impr_sort(arr):
    count = 0
    update=True
    n=len(arr)
    while(update==True and n>1):
        update = False
        for i in range(len(arr)-1):
            if arr[i]>arr[i+1]:
                count += 1
                arr[i],arr[i+1]=arr[i+1],arr[i]
                update = True
        n-=1
    return count

def generate_data(n, gen_typ="random"):
    if gen_type=="best":
        a = [i+1 for i in range(n)]
        return a
    elif gen_type=="worst":
        a = [i+1 for i in reversed(range(n))]
        return a
    else:
        a = [i+1 for i in range(n)]
        random.shuffle(a)
        return a


sizes = [10, 100,1000]
types = ["random", "best", "worst"]
data_plot = {'random': {'bubble':{}, 'insertion':{}, 'bubble_impr':{}}, 
             'best': {'bubble':{}, 'insertion':{}, 'bubble_impr':{}},
             'worst': {'bubble':{}, 'insertion':{}, 'bubble_impr':{}}}
for n in sizes:
    print("\nDATA SIZE: ", n)
for gen_type in types:

        print("\n\tDATA TYPE:", gen_type)
        data = generate_data(n, gen_type)

data_bubble = np.copy(data)
bubble_op_count = bubble_sort(data_bubble)
print("\tBubble sort operation count:", int(bubble_op_count))
data_plot[gen_type]['bubble'][n] = bubble_op_count
data_bubble_impr = np.copy(data)
bubble_impr_op_count = bubble_impr_sort(data_bubble_impr)
print("\tImproved bubble sort operation count:", int(bubble_impr_op_count))
data_plot[gen_type]['bubble_impr'][n] = bubble_impr_op_count
data_insertion = np.copy(data)
insertion_op_count = insertion_sort(data_insertion)
print("\tInsertion sort operation count:", int(insertion_op_count))
data_plot[gen_type]['insertion'][n] = insertion_op_count
plot_data(data_plot, logarithmic=True, oneplot=True)
