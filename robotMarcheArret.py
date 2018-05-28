from megapi import *

def read(d):
    print("distance: "+str(d))
    if d > 20:
        bot.motorRun(M1, 150)
        bot.motorRun(M2, 150)
    else:
        bot.motorRun(M1, 0)
        bot.motorRun(M2, 0)
        sleep(1)

bot = MegaPi()
bot.start()
while 1:
   bot.ultrasonicSensorRead(4, read)
