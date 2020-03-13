import sys


if (len(sys.argv) != 2):
    print('ERROR')
    sys.exit(1)
try:
     nb = int(sys.argv[1])
except:
    print('ERROR')
    sys.exit(1)
if (nb == 0):
    print('I\'M ZERO')
    sys.exit(1)
elif (nb % 2 == 1):
    print('I\'M ODD')
elif (nb % 2 == 0):
    print('I\'M EVEN')
else:
    print('ERROR')

