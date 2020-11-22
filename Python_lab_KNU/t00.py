import math


print("#1.2")

num = 345
num_str = str(num)
summ = 0
for i in num_str:
    summ += int(i)

print(summ) 


print("#1.5")

z = int(input("Input int: "))
f_a = 4*z**4 + 3*z**3 + 2*z**2 + z + 1
f_b = z**4 + 2*z**2 + 1
print("a) f(z)= " + str(f_a))
print("b) f(z)= " + str(f_b))


print("#1.7")

numz = int(input("Input int: "))
print(str(numz) + "    " + str(numz) + "    " + str(numz))
print("   " + str(numz) + "   " + str(numz) + "   ")
print(str(numz) + "    " + str(numz) + "    " + str(numz))
print(str(numz) + "-------" + str(numz))
print("|   " + str(numz) + "   |")
print(str(numz) + "-------" + str(numz))


print("#1.9")
a_tri = int(input("Please input a: "))
b_tri = int(input("Please input b: "))
c_tri = int(input("Please input c: "))
S_tri = a_tri + b_tri + c_tri * 1/2
print("Square triangel = " + str(S_tri))

print("#1.24")

num_tri = 456
num_tri_str = str(num_tri)
print("Hund = " + num_tri_str[0] + " Desyat = " + num_tri_str[1] + " Single = " + num_tri_str[2])
print("Reverse = " + num_tri_str[::-1])