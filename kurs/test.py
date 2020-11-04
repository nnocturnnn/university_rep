import random
import datetime
import time

i = 0


while i < 500:
    dateappnow = datetime.datetime.now().strftime("%Y-%m-%d-%H.%M.%S")
    tm1 = random.randrange(30,45)
    tm2 = random.randrange(30,45)
    tm3 = random.randrange(30,45)
    tm4 = random.randrange(30,45)
    string = str(tm1) + ',' + str(tm2) + ','  + str(tm3) + ',' + str(tm4) + ',' + dateappnow + ',' + '\n'
    f = open("data.csv","a+")
    f.write(string)
    f.close()
    time.sleep(1)

