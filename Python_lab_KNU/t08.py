
print("6.2")
i = ""
mist = set()
while 1:
    i = input("Input city : ")
    mist.add(i)
    if i in mist:
        print("Alredy contain")
    if i == 0:
        break
print("6.3")
count_Stud = 0
lst_uniq_lan = set()
for key, value in a_dict.items():
    count_Stud += 1
    lst_uniq_lan.add(value)

print("6.8")
alp = "abcdefghijklmnopqrstuvwxyz"
string = "fgdfsgdfgdfsgdfg"
list_a = []
list_b = []
list_c = []
count = 0
for i in string:
    for j in string:
        if i == j:
            count += 1
    if count == 1:
        list_a.append(i)
    if count > 2:
        list_b.append(i)
    count = 0
for i in alp:
    if i not in alp:
        list_c.append(i)