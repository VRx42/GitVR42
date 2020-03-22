

class Matrix():       
    def __init__(self, data):
        if (isinstance(data[0], list)):
            for line in data:
                if len(line) != len(data[0]):
                    exit("One of the line doesn't have the same length")
                if isinstance(line, list) == False:
                    exit("One of the line is not a list")
            self.data = data
            self.shape = (len(data), len(data[0]))
        elif (isinstance(data, tuple)):
            self.shape = data
            x = data[0]
            y = data[1]
            self.data = [[0]*y for line in range(x)]
        column = []
        for j in range (self.shape[1]):
            column.append([self.data[i][j] for i in range(self.shape[0])])
        self.column = column

    def __str__(self):
        string = "["
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                if (j == self.shape[1]-1):
                    string += str(self.__getxy__(i+1, j+1))
                else: string += str(self.__getxy__(i+1, j+1)) + ", "
                if (j == self.shape[1]-1 and i != self.shape[0]-1):
                    string += str('\n ')
        string += "]"
        return (string)

    def __repr__(self):
        return str(self.data)

    def __validity__(self):
        if (isinstance(self.data[0], list) == False):
            return (False)
        if (self.shape < (1, 1)):
            return (False)
        for line in self.data:
            if len(line) != len(self.data[0]):
                print("One of the line doesn't have the same length")
                return (False)
            if isinstance(line, list) == False:
                exit("One of the line is not a list")
                return (False)
        print("Matrix is valid")
        return (True)

    def __getline__(self, idx):#x pour line
        return self.data[idx]

    def __getxy__(self, idx, idy):
        if idx > self.shape[0]:
            exit("x coordinate in input not in range")
        if idy > self.shape[1]:
            exit("y coordinate in input not in range")
        return self.data[idx-1][idy-1]

    def __setitemxy__(self, idx, idy, item):
        self.data[idx-1][idy-1] = item
    """ce setitem a besoin qu'on lui rentre les valeurs des maths et pas l'indice info
    """

    def __add__(self, other):
        if (isinstance(other, int)):
            added = []
            for i in range(self.shape[0]):
                added.append([a + other for a in self.data[i]])
            return Matrix(added)
        elif (isinstance(other.data[0], list)):
            if (self.shape != other.shape):
                exit("Shapes don't fit for addition")
            added = []
            for i in range(self.shape[0]):
                added.append([a + b for a, b in zip(self.data[i], other.data[i])])
            return Matrix(added)
    
    def __radd__(self, other):
        return Matrix.__add__(self, other)

    def __sub__(self, other):
        if (isinstance(other, int)):
            added = []
            for i in range(self.shape[0]):
                added.append([a - other for a in self.data[i]])
            return Matrix(added)
        elif (isinstance(other.data[0], list)):
            if (self.shape != other.shape):
                exit("Shapes don't fit for addition")
            added = []
            for i in range(self.shape[0]):
                added.append([a - b for a, b in zip(self.data[i], other.data[i])])
            return Matrix(added)

    def __rsub__(self, other):
        return Matrix.__sub__(self, other)

    def __truediv__(self, other):
        if (isinstance(other, int) == False and isinstance(other, float) == False):
            exit("Division by scalars only: int or float")
        if (other == 0):
            exit("Division par 0 impossible")
        divided = []
        for i in range(self.shape[0]):
            divided.append([a / other for a in self.data[i]])
        return Matrix(divided)

    def __rtruediv__(self, other):
        return Matrix.__truediv__(self, other)

    def __mult__(self, other):
        if (isinstance(other, int)):
            multiplied = []
            for i in range(self.shape[0]):
                multiplied.append([a * other for a in self.data[i]])
            return Matrix(multiplied)
        elif (isinstance(other.data[0], list)):
            if (self.shape[1] != other.shape[0]):
                exit("Number of columns of matrix#1 \
                      doesn't fit the columns of matrix#2 for multiplication")
            multiplied = Matrix((self.shape[0], other.shape[1]))
            for i in range(self.shape[0]):
                for j in range(other.shape[1]):
                    item = sum([x * y for x, y in zip(self.data[i], other.column[j])])
                    multiplied.__setitemxy__(i+1, j+1, item)
            return (multiplied)

    def __rmul__(self, other):
        return Matrix.__mult__(self, other)


"""TESTS DIVERS
#(5:2)
m1 = Matrix([[8.0, 4.0],
             [2.0, 1.0],
             [1.0, 1.0],
             [1.0, 4.0],
             [4.0, 5.0]])

#(4:2)
m2 = Matrix([[1.0, 11.0],
             [2.0, 3.0],
             [3.0, 5.0],
             [6.0, 10.0]])
#(2:3)
m3 = Matrix([[4.0, 3.0, 4.0, 5.0],
             [1.0, 5.0, 1.0, 6.2]])

m4 = Matrix((4, 2))



print(m2.data)
print(m2.shape)
print(m2.column)

mult= Matrix.__mult__(m2, m3)
print(m3.column)
print(mult.data)

print(m3.__str__())
"""