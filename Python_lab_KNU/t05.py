
from random import random
import numpy as np

print("4.15")
def diagonal(l,c):
    s = 0
    i = 0
    while i < N:
        if c == '1':
            s += l[i][i]
        else:
            s += l[i][N-i-1]
        i += 1
    return s

N = 10
a = []
num_zero = 0
np.sum(a)
for i in range(N):
  for j in range(N):
      if a[i][j] == 0:
          num_zero += 1
for i in range(N):
    b = []
    for j in range(N):
        n = int(random()*10)
        b.append(n)
        print("%3d" % n, end='')
    a.append(b)
    print()

ch = input("Главная (1) или побочная (2): ")
if ch == '1' or ch == '2':
    summa = diagonal(a,ch)
    print(summa)


print("4.18")
num_zero18 = 0
matriz = []
for i in range(N):
  for j in range(N):
      if matriz[i][j] == 0:
          num_zero += 1

np.unique(matriz)

print("4.24")
list_b = [i**2 for i in range(15)]

print("4.26")
int_N = int(input("Input number : "))
list_B_a = [i+1/2 for i in range(n)]