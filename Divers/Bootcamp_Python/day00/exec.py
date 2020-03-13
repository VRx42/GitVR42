import sys

txt_droit = sys.argv[1]
txt_reverse = txt_droit[:0:-1]#ou [::-1]
#commence a la fin, finit a 0 et on avance de -1

print(txt_reverse)

#ou avec une fonction
def my_function(x):
  return x[::-1]