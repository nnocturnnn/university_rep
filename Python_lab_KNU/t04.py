
print("4.1 a,c")
num_a = 0
num_c = 0
need_list = [4, 4 , 0, 0, 12, 7, 5, 4, 3]

for i in need_list:
    if i == 0:
        num_c += 1

print("num_a = " + str(num_a))
print("num_c = "+ str(len(need_list) - len(set(need_list))))

print("4.2 a, b")

list_start = [i for i in range(10)]
list_a = []
for i in range(0,len(list_start),2):
    list_a.append(list_start[i])
list_b = [i**2 for i in list_start]
print(list_b)
print(list_a)

print("4.12")

def merger(a, b):
    new_list = []
    d = a + b
    while d:
        new_list.append(d.pop(d.index(min(d))))
    return new_list

print("4.13")

x = int(input())
n = int(input())
list_mno = [i * x**n for i in range(n)]
print(list_mno)