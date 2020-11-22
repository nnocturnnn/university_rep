
from math import sqrt
import inflect
import numpy
 
print("2.9")
x = float(input("x="))
y = float(input("y="))
r = float(input("r="))
h = sqrt(x**2 + y**2)
print("Расстояние до точки от начала координат равно %.2f" % h)
if h > r:
    print("точка находится за пределами")
else:
    print("точка принадлежит")

print("2.17")
a = int(input())
b = int(input())
c = int(input())
a, b, c = sorted([a, b, c])
if a + b <= c:
    print('impossible')
elif c**2 == (a**2) + (b**2):
    print('rectangular')
elif ((a**2) + (b**2) - (c**2)) / (2 * a * b) > 0:
    print('acute')
else:
    print('obtuse')

print("2.18")
import math

print("Введите коэффициенты для уравнения")
print("ax^2 + bx + c = 0:")
print("ax^4 + bx^2 + c = 0:")
a = float(input("a = "))
b = float(input("b = "))
c = float(input("c = "))

discr = b ** 2 - 4 * a * c
print("Дискриминант D = %.2f" % discr)

if discr > 0:
    x1 = (-b + math.sqrt(discr)) / (2 * a)
    x2 = (-b - math.sqrt(discr)) / (2 * a)
    print("x1 = %.2f \nx2 = %.2f" % (x1, x2))
elif discr == 0:
    x = -b / (2 * a)
    print("x = %.2f" % x)
else:
    print("Корней нет")

if discr > 0:
    x1 = (-b + math.sqrt(discr)) / (2 * a)
    x2 = (-b - math.sqrt(discr)) / (2 * a)
    print("x1 = %.2f \nx2 = %.2f" % (x1, x2))
elif discr == 0:
    x = -b / (2 * a)
    print("x = %.2f" % x)
else:
    print("Корней нет")
    
print("2.19")

M4 = numpy.array([[1, 1, 1], [1, 1, 1]])
v4 = numpy.array([0, 0]) 
M3 = numpy.array([[math.abs(1), math.abs(1)], [1, 1, 1]])
v3 = numpy.array([1, 0]) 

numpy.linalg.solve(M4, v4)
numpy.linalg.solve(M3, v3)

print("2.23-2.26")

year=2100
month=2 

f_leap_year=True
if year%400==0:
    print("год высокосный")
elif year%100==0:
    print("год невысокосный")
    f_leap_year=False
elif year%4==0:
    print("год высокосный")
else:
    print("год невысокосный")
    f_leap_year=False
print("---------------------")

print("Количество дней в месяце:")
nDays=31
if (month==2)and(f_leap_year==True): nDays=29
elif (month==2)and(f_leap_year==False): nDays=28
elif (month==4)or(month==6)or(month==9)or(month==11):
    nDays=30
print(nDays)

num_grib = input("Num gribow : ")
string = ""
if int(num_grib[-1]) > 1 and  int(num_grib[-1]) < 5:
    string = "griba"
else:
    string = "gribow"

print("I find " + num_grib + string)

p = inflect.engine()
print(p.number_to_words(99))