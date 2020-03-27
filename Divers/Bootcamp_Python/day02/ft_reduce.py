import functools

def ft_reduce(function_to_apply, list_of_inputs):
    res = function_to_apply(list_of_inputs[0],list_of_inputs[1])
    if (len(list_of_inputs) == 2):
        return (res)
    else:
        new_list_inputs = [res] + list_of_inputs[2:]
        return (ft_reduce(function_to_apply, new_list_inputs))


"""commentaires
 - utilisation d'une récursive pour réduire la liste après chaque opération sur 
 les deux premiers éléments de la liste.
"""


"""TEST
res = 3
lis = [1, 3, 5, 6, 2, 1]

new_list = [res] + lis[1:]
print(type(new_list))


print ("The sum of the list elements is : ",end="") 
print (functools.reduce(lambda a,b : a*b,lis))

result = ft_reduce(lambda a,b : a*b, lis)
print ("The sum of the list elements is : ",end="") 
print(result)
"""