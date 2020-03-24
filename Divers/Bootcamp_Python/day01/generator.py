
import random

def generator(text, sep=" ", option=None):
    if (isinstance(text, str) == False):
        exit("Your text is not a text. A text works with letters. Dummy.")
    if (option == None):
        for word in text.split(sep):
            yield (word)
    elif (option == "shuffle"):
        split_text = text.split(sep)
        random.shuffle(split_text)
        for word in split_text:
            yield (word)
    # elif (option == "ordered"):
    #     ordered = 

# def order(lst)
#     for word in list
#         for i in word
#             if 
        

text = "Le Lorem Ipsum est simplement du faux texte."
i = 0
for word in generator(text, sep= " ", option="shuffle"):
    print(word)
    i += 1


# lst = ['le', 'Lorem', 'Nopsum', 'Emma']


# for word in generator(text, sep=" ", option="shuffle"):
#     print(word)

# for word in generator(text, sep=" ", option="ordered"):
#     print(word)