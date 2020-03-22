


class GotCharacter():
    def __init__(self, first_name):
        self.first_name = first_name
        self.is_alive = True

class Stark(GotCharacter):
    def __init__(self, first_name):
        super().__init__(first_name)
        self.house = "Stark"
        self.motto = "Winter is coming"
    
    def print_house_words(self):
        print(self.motto)

    def die(self):
        self.is_alive = False


Arya = Stark("Arya")

print(Arya.first_name)
print(Arya.is_alive)
print(Arya.house)

Arya.print_house_words()

Arya.die()

print(Arya.is_alive)

print(Arya.__dict__)
