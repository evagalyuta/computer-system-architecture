import math
from random import randint, uniform


# Class summarizing all shapes.
class Shape:

    # Initialization of shape.
    def __init__(self, density=0):
        self._density = density


# Sphere shape.
class Sphere(Shape):

    # Initialization of sphere.
    def __init__(self, radius=0, density=0):
        super().__init__(density)
        self.__radius = radius

    # Random input data.
    def in_rnd(self):
        self.__radius = randint(1, 20)
        self._density = uniform(0.01, 0.99)

    # Format output.
    def __str__(self):
        return "It is sphere: radius = {0}, density = {1}. Square = {2}" \
            .format(self.__radius, round(self._density, 5), round(self.get_square(), 5))

    # Get square of sphere.
    def get_square(self):
        return 4 * math.pi * self.__radius ** 2


# Parallelepiped.
class Parallelepiped(Shape):

    # Initialization of parallelepiped.
    def __init__(self, a=0, b=0, c=0, density=0):
        super().__init__(density)
        self.__a = a
        self.__b = b
        self.__c = c

    # Random input data.
    def in_rnd(self):
        self.__a = randint(1, 20)
        self.__b = randint(1, 20)
        self.__c = randint(1, 20)
        self._density = uniform(0.01, 0.99)

    # Format output.
    def __str__(self):
        return "It is parallelepiped: a = {0}, b = {1}, c = {2}, density = {3}. Square = {4}" \
            .format(self.__a, self.__b, self.__c, round(self._density, 5), round(self.get_square(), 5))

    # Get square of parallelepiped.
    def get_square(self):
        return 2 * (self.__a * self.__b + self.__a * self.__c + self.__b * self.__c)


# Tetrahedron.
class Tetrahedron(Shape):

    # Initialization of tetrahedron.
    def __init__(self, edge=0, density=0):
        super().__init__(density)
        self.__edge = edge

    # Format output.
    def __str__(self):
        return "It is tetrahedron: edge = {0}, density = {1}. Square = {2}" \
            .format(self.__edge, round(self._density, 5), round(self.get_square(), 5))

    # Random input data.
    def in_rnd(self):
        self.__edge = randint(1, 20)
        self._density = uniform(0.01, 0.99)

    # Get square of tetrahedron.
    def get_square(self):
        return (self.__edge ** 2 * 3 ** 0.5) / 4
