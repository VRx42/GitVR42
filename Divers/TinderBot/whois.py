import sys



if (len(sys.argv) != 2):
    print('ERROR')
    exit()

nb = sys.argv[1]

if (nb.isdigit() == False):
    print('ERROR')
    exit()

elif (int(sys.argv[1]) == 0):
    print("I'm Zero")
elif (int(sys.argv[1]) % 2 == 0):
    print("I'm Even")
elif (int(sys.argv[1]) % 2 == 1):
    print("I'm Odd")
else:
    print('ERROR')

#faut gerer quand cest pas le bon format