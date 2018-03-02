# class Node
class Node:
    def __init__(self, digimon):
        self.__object = digimon
        self.__left = None  # left child
        self.__right = None  # right child
        self.__color = None

    def get_colour(self):
        return self.__color

    def set_colour(self,colour):
        self.__color = colour

    def get_left(self):
        return self.__left

    def set_left(self, node):
        self.__left = node

    def get_right(self):
        return self.__right

    def set_right(self, node):
        self.__right = node

    def get_object(self):
        return self.__object

    def is_leaf(self):
        if self.get_left() is None and self.get_right() is None:
            return True
        else:
            return False

    def __str__(self):
        return "%i %s" % (self.__object.get_xp(), self.__object.get_name())
