import pandas as pd
from datetime import datetime
import seaborn as sns
import matplotlib.pyplot as plt

df = pd.read_csv ('Test_AB.csv',sep=';',parse_dates=['time_stamp'])
del df['reg_date']
start_date = "2017-03-23 16:00:00"
end_date = "2018-03-23 23:00:00"
after_start_date = df["time_stamp"] >= start_date
before_end_date = df["time_stamp"] <= end_date
between_two_dates = after_start_date & before_end_date
filtered_dates = df. loc[between_two_dates]
man = filtered_dates[filtered_dates['gender'] == 'm']
woman = filtered_dates[filtered_dates['gender'] == 'f']
tele = filtered_dates[filtered_dates['platform_id'] == 7]
desk = filtered_dates[filtered_dates['platform_id'] == 6]
man_with = man[man['sender_id'] % 2 == 0]
man_without =  man[man['sender_id'] % 2 != 0]
wman_with = woman[woman['sender_id'] % 2 == 0]
wman_without = woman[woman['sender_id'] % 2 != 0]
with_new_tele = tele[tele['sender_id'] % 2 == 0]
withpout_new_tele = tele[tele['sender_id'] % 2 != 0]
with_new_desk = desk[desk['sender_id'] % 2 == 0]
withpout_new_desk = desk[desk['sender_id'] % 2 != 0]
dict_res = {}
dict_res["with new feature desktop"] = len(with_new_desk)
dict_res["with new feature mobile"] = len(with_new_tele)
dict_res["without new feature desktop"] = len(withpout_new_desk)
dict_res["without new feature mobile"] = len(withpout_new_tele)
dict_res["woman with new feature"] = len(wman_with)
dict_res["woman without new feature"] = len(wman_without)
dict_res["man with new feature"] = len(man_with)
dict_res["man without new feature"] = len(man_without)
plt.bar(*zip(*dict_res.items()), color="red")
plt.xticks(rotation=15)
plt.show()
