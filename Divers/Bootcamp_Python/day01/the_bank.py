

class Account(object):

    ID_COUNT = 1

    def __init__(self, name, **kwargs):
        self.id = self.ID_COUNT
        self.name = name
        self.__dict__.update(kwargs)
        if not hasattr(self, 'value'):
            self.value = 0
        Account.ID_COUNT += 1 #A chaque nouvel appel on update la variable statique

    def transfer(self, amount):#add money to account
        self.value += amount


class Bank(object):
    """The bank"""
    def __init__(self):
        self.account = []

    def add(self, account):
        self.account.append(account) #account: liste d'objets de classe Account

    def transfer(self, origin, dest, amount):
        if (amount < 0):
            print("Operation not valid: amount is negative")
            return (False)
        if (origin.value - amount < 0):
            print("Operation not valid: not enough money on origin")
            return (False)
        if (self.fix_account(origin) == False or self.fix_account(dest) == False):
                exit("One of the account is corrupted")
        origin.value -= amount
        dest.value += amount
        return (True)

    def fix_account(self, account):
        if (len(dir(account)) % 2 == 1):
            print("ERROR: Even number of attributes")
            return False
        for name in dir(account):
            if (name[0] == 'b'):
                print("ERROR: Attribute starting wit 'b'.")
                return False
        if ("name" not in dir(account)):
            print('ERROR: no account name')
            return False
        if ("value" not in dir(account)):
            print('ERROR: no account name')
            return False
        if ("id" not in dir(account)):
            print('ERROR: no account name')
            return False
        for name in dir(account):
            if (name == "zip" or name == "addr."):
                return True
        return False


"""TESTS
Maman = Account("Maman", value=1000, zip="75016")
Papa = Account("Papa", value=500, zip="75015")
bank1 = Bank()

print("%s : %d€" % (Maman.name, Maman.value))
print("%s : %d€" % (Papa.name, Papa.value))
# print(dir(Papa))

print("account valididty maman:", Bank().fix_account(Maman))
print("account valididty papa:", Bank().fix_account(Papa))

bank1.transfer(Maman, Papa, 500)

print("%s : %d€" % (Maman.name, Maman.value))
print("%s : %d€" % (Papa.name, Papa.value))
"""
