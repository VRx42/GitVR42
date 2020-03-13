


phrase = "A robot must protect its own existence as long as such protection does ! ? not conflict with the First or Second Law"
nb = 6

def words_split_nb(phrase, nb):
    list_words = phrase.split()
    print(list_words)
    new_list = []
    for x in list_words:
        if (len(x) >= 6):
            new_list.append(x)
    new_list = list(filter(lambda word: len(word) > nb, list_words))
    print(new_list)
words_split_nb(phrase, nb)




# python filterwords.py "Hello, my friend" 3
# ['Hello', 'friend']
# > python filterwords.py "A robot must protect its own existence as long as such protection
# 􏰀→ does not conflict with the First or Second Law" 6 ['protect', 'existence', 'protection', 'conflict']