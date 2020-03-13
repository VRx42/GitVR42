
import sys

def operations(x, y):
    #if not (isinstance(x, int)):
    #    raise TypeError("Only integers are allowed")

    s = x + y
    d = x - y
    p = x * y
    print('Sum = ', s)
    print('Difference = ', d)
    print('Produit = ', p)
    if (y != 0):
        q = x / y
        r = x % y
        print('Quotient = ', q)
        print('Remainder = ', r)
    else:
        print("Quotient = ERROR (div by zero)")
        print("Remainder = ERROR (modulo by zero)")

        
if (len(sys.argv) > 3):
    print('ERROR')
    exit(1)
#print(type(sys.argv[1]))
try:
    x = int(sys.argv[1])
    y = int(sys.argv[2])
except TypeError:
    print('Nombres uniquement')

operations (x, y)