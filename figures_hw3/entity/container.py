from entity.shape import Sphere, Parallelepiped, Tetrahedron
from random import randint


# Container based on list.
class Container:

    # Initialization of container.
    def __init__(self):
        self.__list = list()

    # Input container's data from file.
    def input(self, path):
        with open(path, 'r') as file:
            for shape in file:
                try:
                    line = shape.strip().split()
                    if line[0] == "1":
                        self.__list.append(Sphere(int(line[1]), float(line[2])))
                    elif line[0] == "2":
                        self.__list.append(Parallelepiped(int(line[1]), int(line[2]), int(line[3]), float(line[4])))
                    elif line[0] == "3":
                        self.__list.append(Tetrahedron(int(line[1]), float(line[2])))
                except Exception:
                    raise ValueError("Invalid argument")

    # Random input container's data.
    def in_rnd(self, size):
        while len(self.__list) < size:
            num = randint(1, 3)
            if num == 1:
                self.__list.append(Sphere())
            elif num == 2:
                self.__list.append(Parallelepiped())
            elif num == 3:
                self.__list.append(Tetrahedron())
            self.__list[-1].in_rnd()

    # Output container's data.
    def out(self, path):
        with open(path, 'w') as file:
            file.write("Container contains {0} elements.\n".format(len(self.__list)))
            for shape in self.__list:
                file.write(shape.__str__() + "\n")

    # Get sum of squares all figures.
    def square_sum(self):
        answer = 0.0
        for i in range(len(self.__list)):
            answer += self.__list[i]
        return answer

    # Shaker sort for container.
    def shaker_sort(self):
        swapped = True
        start = 0
        end = len(self.__list) - 1
        while swapped:
            swapped = False
            for i in range(start, end):
                if self.__list[i].get_square() > self.__list[i + 1].get_square():
                    self.__list[i], self.__list[i + 1] = self.__list[i + 1], self.__list[i]
                    swapped = True
            if not swapped:
                break
            swapped = False
            end -= 1
            for i in range(end - 1, start - 1, -1):
                if self.__list[i].get_square() > self.__list[i + 1].get_square():
                    self.__list[i], self.__list[i + 1] = self.__list[i + 1], self.__list[i]
                    swapped = True
            start += 1
