

import random


def generator(text, sep=" ", option=None):
    if (isinstance(text, str) == False):
        exit("Your text is not a text. A text works with letters. Dummy.")
    if (option == None):
        for word in text.split(sep):
            yield (word)
    elif (option == "shuffle"):
        reversed = random.shuffle(text.split(sep))
        print(reversed)
        for word in random.shuffle(text.split(sep)):
            yield (word)
    # elif (option == "ordered"):
    #     for



def shuffle_list(lst):

    for i in range(len(lst))
        

text = "Le Lorem Ipsum est simplement du faux texte."
i = 0
for word in generator(text, sep= " ", option="shuffle"):
    print(word)
    i += 1


lst = ['le', 'Lorem', 'Nopsum', 'Emma']


# for word in generator(text, sep=" ", option="shuffle"):
#     print(word)

# for word in generator(text, sep=" ", option="ordered"):
#     print(word)