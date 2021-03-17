import pandas as pd
import json
from google.colab import files
import io
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt


uploaded = files.upload()


data = json.load(io.BytesIO(uploaded['generated_data_employee.json']))
df = pd.json_normalize(data)
del df["_id"]
del df["guid"]
del df["isActive"]
del df['eyeColor']
del df['gender']
del df['email']
del df['phone']
del df['about']
del df['registered']
del df['latitude']
del df['longitude']
del df['favoriteFruit']
del df['tags']
AgeGroup = pd.cut(df.age,bins=[18,30,40,50,60],labels=['Teen','Adult','Pre','Grand'])
df.insert(7,"Age group",AgeGroup)
ms = df.groupby("Age group")['salary'].mean()
df.loc[df['Age group'] == 'Teen', 'mid salary'] = ms['Teen'] 
df.loc[df['Age group'] == 'Adult', 'mid salary'] = ms['Adult']
df.loc[df['Age group'] == 'Pre', 'mid salary'] = ms['Pre'] 
df.loc[df['Age group'] == 'Grand', 'mid salary'] = ms['Grand']

df2 = df[['Age group','company','mid salary']]
df2 = df2.drop_duplicates(["Age group","company"])
df2.pivot(index="Age group",columns="company",values="mid salary")
friend_array = x = np.zeros((96, 96))
np.set_printoptions(threshold=np.inf)
for row in df.iterrows():
  for i in row[1]['friends']:
    if i < 96:
      r = row[0]
      c = i
      friend_array[r][c] = 1

G=nx.from_numpy_array(friend_array)

nx.draw(G, with_labels=True, pos=nx.spring_layout(G), node_size=250)
plt.show()