
import math
import pandas as pd

print("9.1")

f = open("file.txt")
summ = 0
zero_count = 0
num_l = f.readline().split(' ')
num_l_int = [int(i) for i in num_l]
for i in  num_l_int:
    summ += i
    if i < 0:
        zero_count += 1
    
print(summ)
print(zero_count)
print(num_l[-1])
print(max(num_l_int))
print(min(num_l_int))
print(max(num_l_int) + min(num_l_int))
print(num_l_int[1] - num_l_int[-1])
print(summ / len(num_l))

print("9.2")


def largest_monotonic_subsequence(lst):

       def increasing(lst):
           beg,end,best = 0,0,[0,0]
           for i in range(len(lst)-1):
               if lst[i] <= lst[i+1]:
                   end = i+1
                   if end - beg > best[1] - best[0]:
                       best = beg, end 
               else:
                   beg = i+1
           return (best[0],best[1]+1)

       def decreasing(lst):
           beg,end,best = 0,0,[0,0]
           for i in range(len(lst)-1):
               if lst[i] >= lst[i+1]:
                   end = i+1
                   if end - beg > best[1] - best[0]:
                       best = beg, end 
               else:
                   beg = i+1
           return (best[0],best[1]+1)

       incr = increasing(lst)
       decr = decreasing(lst)
       return lst[slice(*max([incr,decr], key = lambda x: x[1]-x[0]))]

f = open("file.txt")
num_l = f.readline().split(' ')
num_l_int = [int(i) for i in num_l]
print(len(num_l_int) - len(set(num_l_int)))
i = 0
minny = 0
maxxy = 0
while i < len(num_l_int):
    if i % 2 == 0:
        if i < maxxy:
            maxxy = i
    else:
        if i < minny:
            minny = i

print(maxxy - minny)
print(largest_monotonic_subsequence(num_l_int))

print("9.5")

f = open("F")
num_l = f.readline().split(' ')
cout = 0
num_l_int = [int(i) for i in num_l]
for i in set(num_l_int):
    if i > 0:
        if cout % 2 == 0:
            if i % 3 == 0 and i % 5 == 0:
                if math.sqrt(i):
                    f.write(str(i) + " ")



print("9.11")

data = pd.read_csv("car.txt")
print(data)
marc = input("Input car : ")
print(data['num'])
data = data.loc[data["Car"] == marc]
print(data['name'])


print("9.14")
data = pd.read_csv("db.txt")
print(data)
initial = input("Input initial : ")
data = data.loc[data["initial"] == initial]
print(data['number'])