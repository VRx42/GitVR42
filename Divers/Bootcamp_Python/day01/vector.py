












class Vector():
    def __init__(self, arr):
        if (isinstance(arr, list)):
            self.arr = arr
        if (isinstance(arr, int)):
            self.arr = [float(x) for x in range(arr)]
        if (isinstance(arr, tuple)):
            self.arr = [float(x) for x in range(arr[0], arr[1])]
        self.size = len(self.arr)

    def __str__(self):
        string = "["
        for i in range(0, self.size):
            if (i < self.size-1):
                string += str(self.get(i)) + ", "
            else:
                string += str(self.get(i)) + "]"
        return (string)

    def __repr__(self):
        return str(self.arr)

    def equals(self, other):
        if(self.size != other.size):
            return False
        for i in range(0, self.size):
            if(self.get(i) != other.get(i)):
                return False
        return True

    def get(self, index):
        """ Returns l'index de la matrice
        """
        return self.arr[index]

    def __add__(self, other):
        if (type(self) == type (other)):
            summed = [a + b for a, b in zip(self.arr, other.arr)]
            return Vector(summed)
        if (isinstance(other, int) or isinstance(other, float)):
            summed = [a + other for a in self.arr]
            return Vector(summed)

    def __radd__(self, other):
        return self.__add__(other)

    def inner(self, other):
        """ Returns the dot product (inner product) of self and other vector
        """
        if (self.size == other.size):
            return sum(a * b for a, b in zip(self.arr, other.arr))
        else: exit(1)
    
    def __mul__(self, other):
        """ Returns the dot product of self and other if multiplied
            by another Vector.  If multiplied by an int or float,
            multiplies each component by other.
        """
        if type(other) == type(self):
            return self.inner(other)
        elif (isinstance(other, int)) or (isinstance(other, float)):
            product = [a * other for a in self.arr]
            return Vector(product)

    def __rmul__(self, other):
        """ Called if 4*self for instance """
        return self.__mul__(other)
    
    def __truediv__(self, other):
        if (other == 0):exit("Division par 0 impossible")
        if (isinstance(other, int)) or (isinstance(other, float)):
            divided = [a / other for a in self.arr]
            return Vector(divided)


#v1 = Vector(3)
#v1 = Vector([0.0, 1.0, 2.0, 3.0])
v1 = Vector((10,15))
v2 = Vector((0, 5))

print(v1)
print(v2)
print(Vector.__add__(v1,v2))

#v3 = Vector.inner(v1, v2)
#v3 = Vector.__mul__(v1, 2)