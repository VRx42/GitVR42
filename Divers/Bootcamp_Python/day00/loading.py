
# from time import sleep

# def     ft_progress(lst):
#     yield "="

# listy = range(1000)
# ret = 0
# for elem in ft_progress(listy):
#     ret += (elem + 3) % 5
#     sleep(0.01)
# print()
# print(ret)

import sys, time

def create_bar(n, max_n):
	len_bar = 23
	len_arrow = len_bar * n // max_n
	bar = "["
	i = 0
	while i < len_arrow:
		bar += "="
		i += 1
	bar += ">"
	while i < len_bar:
		bar += " "
		i += 1
	bar += "]"
	return bar

def ft_progress(lst):
	start = time.time()
	max_lst = lst[-1]
	for i in lst:
		eta = lst[-1] if i == 0 else lst[-1] / i
		delta = time.time() - start
		eta = delta * eta - delta
		per = i * 100 // max_lst
		print("ETA: {:5.2f}s [{:3}%] {} {:4}/{:4} | elapsed time {:5.2f}s".format(eta, per, create_bar(i, max_lst), i + 1, max_lst + 1, delta), end="\r", flush=True)
		yield i

listy = range(200000)
ret = 0
for elem in ft_progress(listy):
	ret += elem
	time.sleep(0.00005)
print()
print(ret)