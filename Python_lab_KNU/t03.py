import math

print("3.39")
print("3.41")
print("3.42")
print("3.50")
print("3.51")
x = int(input("Input x : "))
a_list = [i**n for i in range(5)]
b_list = [(x - 1)**i for i in range(5)]
c_list = [x**2**i-1 for i in range(5)]
d_list = [(x**i)**i for i in range(5)]
e_list = [1/(x**2+1)**i for i in range(5)]
f_list = [math.sin**i*x for i in range(5)]
g_list = [math.cos*math.pi/i for i in range(5)]
s_a = sum([i for i in range(5)])
s_b = sum([i**-i for i in range(5)])
s_c = sum([1/i for i in range(5)])
s_d = sum([1/i-1*i for i in range(5)])  
s_e = sum([i-1/math.factorial(i) for i in range(5)]) - 1
s_f =  sum([i/i-1 for i in range(5)])
s_g =  sum([i/math.factorial(math.factorial(i)] for i in range(5))
