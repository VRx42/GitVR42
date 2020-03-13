t = ( 0, 4, 132.42222, 10000, 12345.67)

#day_00, ex_04 : 132.42, 1.00e+04, 1.23e+04

day = 'day_{:02}'.format(t[0])
ex = 'ex_{:02}'.format(t[1])
first = '{:.5}'.format(t[2])
second = '{:.2e}'.format(t[3])
third = '{:.2e}'.format(t[4])

t2 = (day, ex, first, second, third)

#print('t2 = %s' % t2)

print("%s, %s : %s, %s, %s" % t2)
