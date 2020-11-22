import math

print("#3.1")
n = int(input("Input n num: "))
print(math.factorial(n))

print("#3.4")
i = 0
while i < 1:
    print("|x|y|")
    print("|" + str(i) + "|" + str(math.sin(i)))
    i += 0.1

print("#3.19")

num = 345
int_num = int(input("Need input : "))
for i in str(num):
    if i == str(int_num):
        print("Contain")

print("#3.32")

nums = int(input("Need input : "))
if str(nums) == str(nums)[::-1]:
    print("Palindrome")
else:
    print("Not palindrome")

print("#3.34")

def pali(nums):
    if str(nums) == str(nums)[::-1]:
        print("Palindrome")
        return True
    else:
        print("Not palindrome")
        return False
    

def IsPrime(n):
    d = 2
    while n % d != 0:
        d += 1
    return d == n

list_needbl = []
int_n = int(input("Need input : "))
for i in range(int_n):
    if IsPrime(i):
        list_needbl.append(i)
    if pali(i):
        list_needbl.append(i)

print("#3.47")

def fibonacci(n):
    a, b = 1, 1
    for i in range(n):
        yield a
        a, b = b, a + b

def tribonacci(n):
    if n in (1, 2):
        return 0
    if n in (3,):
        return 1
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3)

n = int(input("Need input : "))
data = list(fibonacci(n))
data_tr = list(tribonacci(n))
print("Summ fibo: " + str(sum(data)))
print("Summ tribo: " + str(sum(data_tr)))

print("#3.48")

x = int(input("Input int : "))
print("3.67")
resh = math.sin(x) / 3
print("3,68")
roz = math.exp(x**3 + 4*x**2 + x - 6)