
print("5.1")
print("""
     Aa Bb Cc Dd Ee Ff Gg Hh
     Ii Jj Kk Ll Mm Nn Oo Pp
     Qq Rr Ss Tt Uu Vv Ww Xx""")


print("5.5 and 5.27")

string = "sdfs222234ds1fvs4325df34dfg6"
max_num = 0
max_count = 0
count = 0
summ = 0
list_dub = []
list_no = []
list_all = [i for i in range(10)]
set_yes = set()
for i in string:
    if i.isdigit():
        print(i)
        num = int(i)
        summ += num
        if num > max_num:
            max_num = num
        for j in string:
            if j.isdigit():
                if num == int(j):
                    count +=1
        if count > max_count:
            max_count = count
        if count == 2:
            list_dub.append(num)
        count = 0
        set_yes.add(num)
    else:
        print(i)
print(max_num)
print(max_count)
print(summ)
print(list(set(list_all) - set_yes))

print("5.31")
text = input("Input text : ")
world_list = text.split(' ')
list_start = []
list_end = []
list_zadan = []
list_start_end = []
list_three = []
lett = input("Input letter : ")
count = 0
print(len(text))
for i in world_list:
    if i[0] == lett:
        list_start.append(i)
    if i[-1] == lett:
        list_end.append(i)
    if lett in i:
        list_zadan.append(i)
    if i[0] == lett and i[-1] == lett:
        list_start_end.append(i)
    for j in i:
        if j == lett:
            count += 1
    if count > 2:
        list_three.append(i)
    count = 0

print("5.32")

text = input("Input text : ")
world_list = text.split(' ')
minn_count = 0
maxx_count = 0
minn_World = ""
maxx_World = ""
for i in world_list:
    if len(i) > max_count:
        max_count = len(i)
        maxx_World = i
    if len(i) > minn_count:
        minn_count = len(i)
        minn_World = i

print("5.39")

CONV_TABLE = ((1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
    (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
    (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'), (1, 'I'))

def arab_to_roman( number ):
   if number <= 0: return ''

   ret = ''
   for arab, roman in CONV_TABLE:
       while number >= arab:
           ret += roman
           number -= arab

   return ret

def roman_to_arab( txt ):
    txt = txt.upper()
    ret = 0
    for arab, roman in CONV_TABLE:
        while txt.startswith( roman ):
            ret += arab
            txt = txt[ len( roman ): ]
    return ret


for i in ( 0, 4, 8, 9, 31, 46, 99, 583, 888, 1668, 1989, 2009, 2010, 2011, 3999 ):
    arab = arab_to_roman( i )
    roman = roman_to_arab( arab )
    print(i, arab, roman)