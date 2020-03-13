
import datetime as dt
import time

#dt_obj2 = datetime(3,30,2019,9,25)
#date_str = dt_obj2.strftime("%H:%M %Y-%m-%d")
#print (date_str)


#time_tuple = (3,30,2019,9,25)
#date_str = time.strftime("%H:%M %Y-%m-%d", (3,30,2019,9,25))
#print (date_str)

result = (3,30,2019,9,25)
date_and_time = dt.datetime(hour=result[0], minute=result[1], year=result[2], month=result[3], day=result[-1])
date_str = date_and_time.strftime("%H:%M %Y-%m-%d")
print (date_str)

result2 = (2, 2017)
date = dt.date(year=result2[1], month=result2[0], day=1)
date_str = date.strftime("%m/%Y")
print (date)

