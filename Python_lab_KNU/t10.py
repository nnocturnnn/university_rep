

import math
from scipy import integrate
from math import cos, pi

def IsPrime(n):
    d = 2
    while n % d != 0:
        d += 1
    return d == n

print("8.2")
n = int(input("Input int : "))
list_n = [i for i in range(n)]
for i in list_n:
    if math.sqrt(i) == math.pow(math.sqrt(i)):
        print(i)
    if IsPrime(i):
        print(i)
    


print("8.9")
def integr(finn, secc):
    func = lambda x: 1/cos(x)
    
    answer = integrate.quad(func, finn, secc)
    print(answer)

print("8.12")
def mygcd(n, m):
    return math.gcd(n,m)

print("8.14")
def triangle(rows):

       for rownum in range (rows):
           newValue=1
           PrintingList = list()
           for iteration in range (rownum):
               newValue = newValue * ( rownum-iteration ) * 1 / ( iteration + 1 )
               PrintingList.append(int(newValue))
           print(PrintingList)
       print()

print("8.16-21")
def summa_cifr(a, count, result):
    c = ''
    c = c + a[count]
    c = int(c)
    result = result + c
    if count < len(a):
        return summa_cifr(a,count+1, result)
    else:
        return result

def DigitCount(n):
           return len(str(DigitCount(n)))

def max_digit(value):
    str_value = str(value)
    def recursive(position, _max):
        if position == len (str_value):
            return int(_max)
        if str_value[position] > _max:
            _max = str_value[position]
        return recursive(position+1,_max)
    return recursive(0, '-1')

def is_symmetric(string):
    if len(string) == 1:
        return True
    else:
        return string[0] == string[-1] and is_symmetric(string[1:-1])

def start(string):
    return string.startswith()

def contain(sub, string):
    return sub in string