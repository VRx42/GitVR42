
def ft_filter(boolean_function, sequence):
    for i in sequence:
        if (boolean_function(i) == True):
            yield(i)


""""TEST
def fun(variable): 
    letters = ['a', 'e', 'i', 'o', 'u'] 
    if (variable in letters): 
        return True
    else: 
        return False

sequence = ['g', 'e', 'e', 'j', 'k', 's', 'p', 'r']

result = ft_filter(fun, sequence)
print(list(result))
"""