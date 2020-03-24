
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
    elif (option == "ordered"):
        split_text = text.split(sep)
        (split_text).sort()
        for word in split_text:
            yield (word)


"""" le .sort et le .shuffle effectuent l'operation sans renvoyer d'objet (listes)
"""
""" TEST 
text = "Le Lorem Ipsum est simplement du faux texte."

i = 0
for word in generator(text, sep= " ",):
    print(word)
    i += 1
print("\n")
for word in generator(text, sep=" ", option="shuffle"):
    print(word)
print("\n")
for word in generator(text, sep=" ", option="ordered"):
    print(word)
"""