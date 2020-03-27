def ft_map(function_to_apply, list_of_inputs):
    for i in list_of_inputs:
        yield(function_to_apply(i))


"""TEST
def addition(x):
    return (2 * x)

list_of_inputs = [1, 2, 3]

result1 = ft_map(addition, list_of_inputs)
print (list(result1))

result2 = map(addition, list_of_inputs)
print (list(result2))
"""