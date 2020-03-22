# from book import Book
# from recipe import recipe
import datetime

class Recipe:
    def __init__(self,
                 name,
                 cooking_lvl,
                 cooking_time,
                 ingredients,
                 description,
                 recipe_type):
        if (isinstance(name, str) and str != ""):
            self.name = name
        else:
            print (name, "n'est pas un nom valide.")
            exit(1)

        if (int(cooking_lvl) <= 5
            and int(cooking_lvl) >= 1 ):
            self.cooking_lvl = cooking_lvl
        else:
            print (cooking_lvl, "n'est pas un lvl valide.")
            exit(1)

        if (int(cooking_time) >= 0):
            self.cooking_time = cooking_time
        else:
            print (cooking_time, "n'est pas un temps valide.")
            exit(1)

        if (isinstance(ingredients, list)):
            self.ingredients = ingredients
        else:
            print (ingredients, "n'est pas une liste valide.")
            exit(1)

        if (isinstance(description, str)):
            self.description = description
        else:
            print (description, "n'est pas une description valide.")
            exit(1)

        if (recipe_type == "starter"
            or recipe_type == "lunch"
            or recipe_type == "dessert"):
            self.recipe_type = recipe_type
        else:
            print (recipe_type, "n'est pas un type valide.")
            exit(1)
        
    def __str__(self):
        return("Recipe class")


class Book:
    def __init__(self,
                 name,
                 recipe_list):
        
        self.creation_date = datetime.datetime.now().strftime("%x %X")
        self.last_update = datetime.datetime.now().strftime("%x %X")

        if (isinstance(name, str) and str != ""):
            self.name = name
        else:
            print (name, "n'est pas un nom valide.")
            exit(1)

        if (isinstance(recipe_list, dict)):
            self.recipe_list = recipe_list
        else:
            print (recipe_list, "n'est pas un dictionnaire valide.")
            exit(1)
    
    def get_recipes_by_name(self, name):#on utilise une classe Book pour accéder à une sous-classe
        print()
        return (name)


    def add_recipe(self, recipe):#recipe est un objet de classe Recipe
        self.recipe_list[recipe.recipe_type].append(recipe.name)
        self.last_update = datetime.datetime.now().strftime("%x %X")

    def get_recipes_by_types(self, recipe_type):
        print(*self.recipe_list[recipe_type], sep=", ")

    def __str__(self):
        return("Book class")

recipe_list = {
            'starter' : ['Gazpacho', 'Oeufs-mayo'],
            'lunch':    ['pizza', 'pâtes', 'ratatouille'],
            'dessert':  ['chocolat', 'glace'],
             }

description = "La tourte doit se faire cuire."
tourte_obj = Recipe("tourte", 4, 15, ["creme", "lait"], description, "starter")
print(tourte_obj.name)
print(tourte_obj.cooking_lvl)
print(tourte_obj.cooking_time)
print(tourte_obj.ingredients)
print(tourte_obj.description)
print(tourte_obj.recipe_type)

print('\n')

book_obj = Book("Livre de recettes", recipe_list)
print(book_obj.name)
print(book_obj.creation_date)
print(book_obj.last_update)

print(book_obj.recipe_list)
print('\n')
print(book_obj.recipe_list['dessert'])

desc_cookie = "Faire fondre le chocolat dans de l'opium revenu aux petits oignons"
cookie = Recipe("cookie", 3, 30, ['lait', 'farine', 'chocolat'], desc_cookie, "dessert")
print(cookie.recipe_type)

Book.add_recipe(book_obj, cookie)

print(book_obj.recipe_list)

Book.get_recipes_by_types(book_obj, "dessert")

Book.get_recipes_by_name(book_obj, cookie)
