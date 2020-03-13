from random import randrange

nb_game = randrange(100)
game = True
tried = 0
while (game):
    nb_player = int(input("Entrer un nombre:"))
    if (nb_player > nb_game):
        print("Trop haut")
        tried += 1 
    elif (nb_player < nb_game):
        print("Trop bas")
        tried += 1 
    elif (nb_player == nb_game):
        print("Bien joué. Nombre d'essais:", tried)
        exit(1)