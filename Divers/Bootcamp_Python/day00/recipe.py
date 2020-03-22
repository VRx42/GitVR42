

cookbook = {'sandwhich' :   {'ingredients' : ['ham', 'bread', 'cheese', 'tomatoes'],
                            'meal' : 'lunch',
                            'prep_time' : 10},
            'cake':         {'ingredients' : ['flour', 'sugar', 'eggs'],
                            'meal' : 'dessert',
                            'prep_time' : 10},
            'salad':        { 'ingredients' : ['avocado', 'arugula', 'tomatoes', 'arugula'],
                            'meal' : 'starter',
                            'prep_time' : 15}
            }

print (cookbook['sandwhich']['ingredients'][0])
#print ("dict['Age']: ", cookbook['Age'])


def     print_recipe(name):
    print("Les ingrédients à prévoir sont:", ','.join(cookbook[name]['ingredients']), '.')
    print("Faire cuire %d minutes." % cookbook[name]['prep_time'])
def     del_recipe(name):
    cookbook.pop(name)
def     add_recipe(name, ingredients, meal, prep_time):
    cookbook[name] = {'ingredients' : ingredients, 'meal' : meal, 'prep_time' : prep_time}
def     print_all_recipes():
    for i in cookbook:
        print_recipe(i)
        print('\n')


ans=True
while ans:
    print ("""
    1.Add a recipe
    2.Delete a recipe
    3.Print a recipe
    4.Print the cookbook
    5.Exit/Quit
    """)
    ans=input("What would you like to do? ") 
    if ans=="1":
        name = str(input("Name :"))
        ingredients = [input("Ingrédients avec virgules:")]
        meal = str(input("meal :"))
        prep_time = int(input("prep_time :"))
        add_recipe(name, ingredients, meal, prep_time)
        print("\n Recipe Added:")
        print_recipe(name)
    elif ans=="2":
        name = str(input("Name :"))
        del_recipe(name)
        print("\n Recipe Deleted")
    elif ans=="3":
        name = str(input("Name :"))
        print_recipe(name)
        print("\n Recipe printed") 
    elif ans=="4":
        print_all_recipes()
        print("\n Recipes printed") 
    elif ans !="":
        print("\n Not Valid Choice Try again") 


# print_recipe('sandwhich')
# del_recipe('sandwhich')
# print(cookbook)
# ingredients_eau = ['mineraux', 'O2', 'Amour']

# add_recipe('eau', ingredients_eau, 'lunch', 8)

# print_recipe('eau')
# print('\n')
# print_all_recipes()


# First, you will have to create a cookbook dictionary called cookbook. cookbook will store 3 recipes:
# • sandwich • cake
# • salad
# Each recipe will store 3 values:
# • ingredients: a list of ingredients
# • meal: type of meal
# • prep_time: preparation time in minutes
# Sandwich’s ingredients are ham, bread, cheese and tomatoes. It is a lunch and it takes 10 minutes of preparation. Cake’s ingredients are flour, sugar and eggs. It is a dessert and it takes 60 minutes of preparation.
# Salad’s ingredients are avocado, arugula, tomatoes and spinach. It is a lunch and it takes 15 minutes of preparation.

# 1. Get to know dictionaries. In the first place, try to print only the keys of the dictionary. Then only the values. And to conclude, all the items.
# 2. Write a function to print a recipe from cookbook. The function parameter will be: name of the recipe.
# 3. Write a function to delete a recipe from the dictionary. The function parameter will be: name of the recipe.
# 4. Write a function to add a new recipe to cookbook with its ingredients, its meal type and its preparation time. The function parameters will be: name of recipe, ingredients, meal and prep_time.
# 5. Write a function to print all recipe names from cookbook. Think about formatting the output.
# 6. Last but not least, make a program using the four functions you just created. The program will prompt the user to make a choice between printing the cookbook, printing only one recipe, adding a recipe, deleting a recipe or quitting the cookbook.
# It could look like the example below but feel free to organize it the way you want to: