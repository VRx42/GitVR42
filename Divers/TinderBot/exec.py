import sys

x = len(sys.argv)
for i in range(x - 1):
    print (''.join(reversed(sys.argv[i + 1])))
    