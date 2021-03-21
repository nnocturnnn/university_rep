import re

f_str = "abbbсссc"
s_str = "UAAK4345IO"
t_str = "UUUUa"
fo_str = "fd2ssd d1fgsqw fdgs  fdg"
five_str = "gdfgs Dfdsg DFG dfgsfg1"
six_str = "2012-09-09:13-13-13"
seven_str = "gdfsgdd1ddasaas sdas1assad sdfaaaasad1a"

def is_vowel(char):
    all_vowels = 'aeiou'
    return char in all_vowels

def first_def(f_str):
    b_count = 0
    b_str = ""
    c_str = ""
    d_str = ""
    c_count = 0
    d_count = 0
    k = 0
    if f_str[1] == 'a':
        print(f"{f_str} - not match")
    else:
        for i in f_str:
            if i == 'b':
                b_count += 1
                c_count += 1
                d_count += 1
        for i in range(b_count):
            b_str += "b"
            c_str += "c"
            d_str += "d"
        if (b_count == 1 or b_count == 3) and (c_count > 2 and c_count < 5) and (d_count < 5):
            if (b_str in f_str ) and (c_str in f_str) and (d_str in f_str):
                print(f"{f_str} - match")
            else:
                print(f"{f_str} - not 2match")
        else:
            print(f"{f_str} - not match")

def numb(s_str):
    test = ["UA", "AK","BC", "BK", "DC"]
    for i in test:
        if s_str.startswith(i):
            lenny = len(s_str)
            if s_str[-3].isdigit() and s_str[-4].isdigit() and s_str[-5].isdigit() and s_str[-6].isdigit():
                if s_str.endswith("IO") or s_str.endswith("WG") or s_str.endswith("ZK"):
                    print(f"{s_str} - match")
                    break
                else:
                    print(f"{s_str} - not match")
            else:
                print(f"{s_str} - not match")
        else:
            print(f"{s_str} - not match")

def upper(t_str):
    count = 0
    for i in t_str:
        if i.isupper():
            count +=1
    if count < 4:
        print(f"{t_str} - match")
    else:
        print(f"{t_str} - not match")


def space(fo_str):
    l_word = fo_str.split()
    if len(l_word) < 4:
        print(f"{fo_str} - match")
    else:
        false_space = fo_str.index(l_word[2]) + len(l_word) + 1
        if fo_str[false_space] == ' ':
            print(f"{fo_str} - not match")
        else:
            print(f"{fo_str} - match")


def five(five_str):
    count = 0
    l_word = five_str.split()
    for i in five_str:
        if len(i) > 7:
            for k in i:
                if k.isdigit():
                    count += 1
                    break
    if count > 4 and count < 8:
        print(f"{five_str} - match")
    else:
        print(f"{five_str} - not match")

def six(six_str):
    date_reg_exp = re.compile('\[0-9]{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1]):(2[0-3]|[01][0-9])-[0-5][0-9]-[0-5][0-9]')
    matches_list=date_reg_exp.findall(six_str)
    print(len(matches_list))
    if len(matches_list) < 3:
        print(f"{six_str} - not match")
    else:
        print(f"{six_str} -  match")

def seven(seven_str):
    count = 0
    l_word = seven_str.split()
    for i in l_word:
        for k in i:
            wow_count = 0
            digit = 0
            if is_vowel(k):
                wow_count += 1
            if k.isdigit():
                digit = 1
        if wow_count > 3 and digit == 1:
            count += 1
    if count > 1:
        print(f"{seven_str} - match")
    else:
        print(f"{seven_str} - not match")

first_def(f_str)
numb(s_str)
upper(t_str)
five(five_str)
space(fo_str)
six(six_str)
seven(seven_str)