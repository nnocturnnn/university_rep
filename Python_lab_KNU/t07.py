
import pandas as pd

print("6.10")

inputy = input("Input city : ")
for key, value in a_dict.items():
    list_Val = value.split()
    for i in list_Val:
        if i == inputy:
            print(key)

print("6.11")

data = pd.from_dict(need_dict)
print(data)
marc = input("Input car : ")
print(data['num'])
data = data.loc[data["Car"] == marc]
print(data['name'])

print("6.12")

summa = 0
for key, value in a_dict.items():
    summa += int(key) * value

print("6.16")

new_Dict = {}
for key, value in a_dict.items():
    list_Val = value.split()
    for i in list_Val:
        new_Dict[i] = key
