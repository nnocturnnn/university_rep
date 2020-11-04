from spyre import server
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np
import csv
import pandas as pd
import random
import datetime
import time

i = 1
lol = []
allt = ["All","1thermometer","2thermometer","3thermometer","4thermometer"]
uniqTemp = ["°F","°C","K"]
iteri = 1


def csv_read(file,count):
    i = 0
    lst = []
    reader = csv.DictReader(file, delimiter=',')
    for line in reader:
        if count == i:
            break
        lst.append(line)
        i += 1
    return lst
# while i < 500:
#     tm1 = random.randrange(30,45)
#     tm2 = random.randrange(30,45)
#     tm3 = random.randrange(30,45)
#     tm4 = random.randrange(30,45)
#     string = str(tm1) + ',' + str(tm2) + ','  + str(tm3) + ',' + str(tm4) + ',' + dateappnow + ',' + '\n'
#     f = open("data.csv","w+")
#     f.write(string)
#     f.close
#     time.sleep(1)

def fApp(listname):
    listy = []
    for i in range(len(listname)):
        listy.append(dict({'label' : listname[i],
                           'value' : listname[i]}))
    return listy

AlltforApp = fApp(allt)
TmpforApp = fApp(uniqTemp)


class SimpleApp(server.App):
    title = "TEG"
    inputs = [
    {
        "type": 'dropdown',
        "label": 'Term',
        "options": TmpforApp,
        "value": 'GOOG',
        "key": 'Therm',
        "action_id": "update_data"
    },
    {
        "type": 'dropdown',
        "label": 'Thermometr',
        "options": AlltforApp,
        "value": 'GOOG',
        "key": 'Thermom',
        "action_id": "update_data"
    },
    {
        "type":'text',
        "label": 'Date',
        "value" : '2020-04-26:2020-04-26',
        "key": 'title',
        "action_id" : "refresh",
    }]

    tabs = ["Plot", "Table","Monitor"]

    controls = [{    "type" : "hidden",
                    "id" : "update_data"}]

    outputs = [{
                    "type" : "plot",
                    "id" : "plot",
                    "control_id" : "update_data",
                    "tab" : "Plot"},
                {
                    "type": "html",
                    "id": "simple_html_output",
                    "tab" : "Monitor",
                    "control_id" : "update_data",
                    "on_page_load" : True
                },
                { "type" : "table",
                    "id" : "table_id",
                    "control_id" : "update_data",
                    "tab" : "Table",
                    "on_page_load" : True }]


    def getHTML(self, params):
        with open("data.csv", 'r') as f:
            for iteri in range(13):
                f.readline()
            x = f.readline()
        date = datetime.datetime.now().strftime("%Y-%m-%d-%H.%M.%S")
        templist = x.split(',')
        templist = [x + params['Therm'] for x in templist]
        return '<font "text-align: center; size=50" face="Arial">Thermal field temperature right now :\n %s   %s   %s   %s - %s</font>' % (templist[0],templist[1],templist[2],templist[3], date)

    def getData(self, params):
        with open("data.csv", 'r') as f:
            buf = csv_read(f,95)
        df = pd.DataFrame.from_records(buf)
        del df['name']
        if params['Therm'] == '°F':
            df['tm1'] = df['tm1'].apply(lambda x: (int(x)*9/5)+32)
            df['tm2'] = df['tm2'].apply(lambda x: (int(x)*9/5)+32) 
            df['tm3'] = df['tm3'].apply(lambda x: (int(x)*9/5)+32) 
            df['tm4'] = df['tm4'].apply(lambda x: (int(x)*9/5)+32) 
        if params['Thermom'] == '1thermometer':
            del df['tm4']
            del df['tm2']
            del df['tm3']
        elif params['Thermom'] == '2thermometer':
            del df['tm1']
            del df['tm3']
            del df['tm4']
        elif params['Thermom'] == '3thermometer':
            del df['tm1']
            del df['tm2']
            del df['tm4']
        elif params['Thermom'] == '4thermometer':
            del df['tm1']
            del df['tm2']
            del df['tm3']
        return df
        

    def getPlot(self, params):
        df = self.getData(params).set_index('data')
        df=df.astype(float)
        plt_obj = df.plot(figsize=(16,7))
        plt_obj.set_xlabel("Date",fontsize=20)
        plt_obj.set_ylabel(params['Therm'],fontsize=20)
        plt_obj.set_title('temperature from the ' + params['Thermom'] 
                          + ' in ' + params['Therm'])
        fig = plt_obj.get_figure()
        fig.autofmt_xdate()
        return fig
    
app = SimpleApp()
app.launch(port=9093)