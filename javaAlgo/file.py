import json
import re
import traceback
from sys import argv


def toFixed(numObj, digits=0):
    return f"{numObj:.{digits}f}"

def read_json(filename):
    try:
        with open(filename) as f:
            return json.load(f)
    except:
        return False

def read_csv(filename,utf):
    list_data = []
    try:
        with open(filename,encoding=utf) as f:
            while True:
                line = f.readline().rstrip()
                list_data.append(line.split(','))
                if not line:
                    break
            return list_data
    except:
        return False


def help_file(data, init_json):
    new_data = []
    new_dict = {}
    for i in data:
        if check(i):
            new_data.append(i)
    for i in new_data:
        if i[-1] in new_dict:
            pass
        else:
            new_dict.update({i[-1] : {'max' : 0, 'sum' : 0}})
    for i in new_data:
        if new_dict[i[-1]]['max'] < i[2]:
            new_dict[i[-1]].update({'max' : i[2],'sum': new_dict[i[-1]]['sum'] + i[0]})
        else:
            new_dict[i[-1]].update({'sum': new_dict[i[-1]]['sum'] + i[0]})
    new_dict = sorted(new_dict.items(), key=lambda e: e[1]["sum"])
    with open(init_json['input']['json'], "w") as outfile: 
        json.dump(new_dict, outfile)
    return new_data
    


def load_data(init_json):
    csv_data = read_csv(init_json['input']['csv'],init_json['input']['encoding'])
    if csv_data == False:
        print(f"input-csv {init_json['input']['csv']}: UPS")
        exit()
    print(f"input-csv {init_json['input']['csv']}: OK")
    csv_data = help_file(csv_data, init_json)
    json_data = read_json(init_json['input']['json'])
    if json_data == False:
        print(f"input-json {init_json['input']['json']}: UPS")
        exit()
    print(f"input-json {init_json['input']['json']}: OK")
    print("json?=csv: OK")
    return csv_data, json_data

def get_max(data,index,name):
    maxnum = 0
    for i in data:
        if maxnum < i[index] and i[-1] == name:
            maxnum = i[index]
        
    return maxnum

def get_max_list(data,index,maxx,name):
    list_max_kt = []
    for i in data:
        if maxx == i[index] and i[-1] == name:
            list_max_kt.append(i)
    list_max_kt.sort(key = lambda test_list: test_list[2],reverse=True)
    return list_max_kt

def output(csv_data,json_data,init_json):
    list_name = list(dict(json_data).keys())[:3]
    list_kt = []
    list_data = []
    for i in list_name:
        list_kt.append(get_max(csv_data,-2,i))
    for i in enumerate(list_name):
        list_data.append(get_max_list(csv_data,-2,list_kt[i[0]],i[1]))
    f = open(init_json['output']['fname'], "w",encoding=init_json['output']['encoding'])
    for i in range(len(list_kt)):
        f.write(f"{list_kt[i]}, {list_name[i]}, {list_data[i][0][-3]}\n")
        for k in range(len(list_data[i])):
            f.write(f"\t{list_data[i][k][0]}, {list_data[i][k][2]}, {list_data[i][k][-3]}, {list_data[i][k][3]}\n")
    return True

def check(row):
    type_l = ['шт','кг','м','кор']
    reg_ttn = r'^[a-zA-Z0-9]*$'
    reg_name = r'^[a-zA-Z0-9-_ ]*$'
    try:
        row[0] = float(row[0])
        row[2] = float(row[2])
        row[-2] = float(row[-2])
        if None in row or len(row) == 0:
            return False
        elif len(row[3])  != 12:
            return False
        elif row[2] < 0 or row[-2] < 0:
            return False
        elif len(row[-1]) < 5 or len(row[-1]) > 27:
            return False
        elif row[-3] not in type_l:
            return False
        elif re.match(reg_name, row[-1]) is not None and re.match(reg_ttn, row[3]) is not None:
            return True
        else:
            return False
    except:
        return False


def main():
    print("*****")
    if len(argv) != 2:
        print(f"***** program aborted *****")
        exit()
    init_filename = argv[1]
    init_json = read_json(init_filename)
    if init_json == False:
        print(f"ini {init_filename}: UPS")
        exit()
    print(f"ini {init_filename}: OK")
    csv_data, json_data = load_data(init_json)
    if output(csv_data, json_data,init_json) == False:
        print(f"output {init_json['output']['fname']}: UPS")
        exit()
    print(f"output {init_json['output']['fname']}: OK")
    


if __name__ == '__main__':
    main()

    
