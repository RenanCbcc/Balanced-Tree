from Digimon import Digimon
from Stack import Stack
from Node import Node

class Tree:
    def __init__(self):
        self.root = None

    # ----------------------------------------------------------------------#
    def find(self, key):
        current = self.root
        while key != self.current.get_object():
            if current is None:
                return None
            elif key < self.current.get_object():
                current = self.current.get_left()
            else:
                current = self.current.get_right()
        return current

    def insert_llrb(self, diginom ):
        if self.find(diginom) is not None:
            print("Duplicate key is not allowed")
            return
        else:
            parent = self.insert(diginom)

        if parent.get_right().get_colour()== "RED" and parent.get_left().get_colour()== "BLACK":
            parent = self.__left_rotation(parent)

        if parent.get_left().get_colour()== "RED" and parent.get_left().get_left().get_colour()== "RED":
            parent = self.__right_rotation(parent)

        if parent.get_left().get_colour()== "RED" and parent.get_right().get_colour()== "RED":
            self.__change_colour(parent)

    # ----------------------------------------------------------------------#
    def insert(self,diginom):
        node = Node(diginom)
        node.set_colour("RED")
        if self.root is None:
            self.root = node
            self.root.set_colour("BLACK")

        else:
            current = self.root
            while True:
                parent = current  # parent sempre aponta para um nível acima
                if node.get_object() < current.get_object():  # vai para esquerda?
                    current = current.get_left()
                    if current is None:
                        parent.set_left(node)  # insira na esquerda
                        return parent
                else:
                    current = current.get_right()  # vai para direita?
                    if current is None:
                        parent.set_right(node)
                        return parent

    # ----------------------------------------------------------------------#
    def delete(self, key):
        current = self.root
        isleftChild = True
        # se node for encontrado, sair do laço com o node a ser deletado
        while (current.get_object().get_xp() is not key):
            parent = current
            if key < current.get_object().get_xp():  # vai pra esquerda?
                isleftChild = True
                current = current.get_left()
            else:
                isleftChild = False
                current = current.get_right()

            if current is None:
                return False  # node não encontrado
        # fim do while

        ################################
        # Caso 1: o Node não tem filhos#
        ################################

        if current.is_leaf():

            if current is self.root:
                current = None  # árvore está vazia
            elif isleftChild:
                parent.set_left(None)
            else:
                parent.set_right(None)

        ############################################
        # Caso 2: o Node a ser deletado tem um filho#
        ############################################

        # se sem filho a direita, subustituir por subarvore da esquerda
        elif current.get_right() is None:
            if current is self.root:
                self.root = current.get_left()
            elif isleftChild:  # filho à esquerda do Node parent
                parent.set_left(current.get_left())
            else:
                parent.set_right(current.get_left())

        # se sem filho a esquerda, subustituir por subarvore da direita
        elif current.get_left() is None:
            if current is self.root:
                self.root = current.get_right()
            elif isleftChild:  # filho a esquerda de Node parent
                parent.set_left(current.get_right())
            else:
                parent.setDireita(current.get_right())

        ###############################################
        # Caso 3: o Node a ser deletado tem dois filho#
        ###############################################

        # para deletar um Node com dois filhos substitua o Node pelo seu successor se suscessor ehFolha
        # função successor() faz isso
        else:
            successor = self.successor(current)
            # conecta parent de current ao invéz de successor
            if current is self.root:
                root = successor
            elif isleftChild:
                parent.set_left(successor)
            else:
                parent.setDireita(successor)

            # conecta successor ao filho da esquerda do current
            successor.set_left(current.get_left())
        return True  # Fim delete()

    # ----------------------------------------------------------------------#
    def quantity_of_nodes(self, no):
        if no is None:
            return 0
        quantity_left = self.quantity_nodes(no.get_left())
        quantity_right = self.quantity_nodes(no.get_right())
        return quantity_right + quantity_left + 1

    # ----------------------------------------------------------------------#
    def in_order(self, root):  # visita os nos em ordem crescente
        if root is not None:
            self.in_order(root.get_left())
            print(root) # Or could be root.get_object() for mor details
            self.in_order(root.get_right())

    # ----------------------------------------------------------------------#
    def minimum(self):
        print("Minimum value:")
        current = self.root
        while current is not None:
            parent = current
            current = current.get_left()
        print(parent)

    # ----------------------------------------------------------------------#
    def maximum(self):
        print("Maximum value:")
        current = self.root
        while current is not None:
            parent = current
            current = current.get_right()
        print(parent)

    # ----------------------------------------------------------------------#
    def get_successor(self, node):
        successor_parent = node
        successor = node
        current = node.get_right()
        while (current is not None):
            successor_parent = successor
            successor = current
            current = current.get_left()
            if successor is not node.get_right():
                successor_parent.set_left(successor_parent.get_right())
                successor.setDireita(node.get_right())

        return successor

    # ----------------------------------------------------------------------#
    def __left_rotation(self,node):
        aux = node.get_right()
        node.set_right(aux.get_left())
        aux.set_left(node)
        aux.set_colour(node.get_colour())
        node.set_colour("RED")
        return aux

    # ----------------------------------------------------------------------#
    def __right_rotation(self,node):
        aux = node.get_left()
        node.set_left(aux.get_right())
        aux.set_right(node)
        aux.set_colour(node.get_colour())
        node.set_colour("RED")
        return aux

    # ----------------------------------------------------------------------#
    def __change_colour(self,node):
        pass

    # ----------------------------------------------------------------------#
    def __move_red_node_to_left(self,node):
        if node.get_right().get_left().get_colour() == "RED":
            node.set_right(self.__right_rotation(node))
            node = self.left_rotation(node)
            self.__change_colour(node)
        return node

    # ----------------------------------------------------------------------#
    def __move_red_node_to_right(self, node):
        if node.get_left().get_left().get_colour() == "RED":
            node = self.left_rotation(node)
            self.__change_colour(node)
        return node

    # ----------------------------------------------------------------------#
    def balance(self,node):
        if node.get_colour() == "RED":
            node = self.__left_rotation(node)
        if node.get_left() != None and node.get_right() == "RED" and node.get_left().get_left().get_colour() == "RED":
            node = self.__right_rotation(node)
        if node.get_left().get_colour() == "RED" and node.get_right().get_colour() == "RED":
            self.__change_colour(node);
        return node

    # ----------------------------------------------------------------------#
    def display_tree(self): # Work very well in Java, but not here ;(
        global_stack = Stack()
        global_stack.push(self.root)
        n_blanks = 32
        is_row_empty = False
        print("# ----------------------------------------------------------------------#")
        while not is_row_empty:
            local_stack = Stack()
            is_row_empty = True

            for i in range(n_blanks):
                print('')

            while not global_stack.isEmpty():
                temp = global_stack.pop()
                if temp is not None:
                    print(temp)
                    local_stack.push(temp.get_left())
                    local_stack.push(temp.get_right())

                    if temp.get_left() is not None or temp.get_right() is not None:
                        is_row_empty = False
                else:
                    print("--")
                    local_stack.push(None)
                    local_stack.push(None)

                for i in range(n_blanks):
                    print('')

            print("\n")
            n_blanks //= 2

            while not local_stack.isEmpty():
                global_stack.push(local_stack.pop())

        print("# ----------------------------------------------------------------------#")


    # ----------------------------------------------------------------------#
tree = Tree()
tree.insert(Digimon('Metal Greymon', 32))
tree.insert(Digimon('Greymon', 22))
tree.insert(Digimon('Tentomon', 8))
tree.insert(Digimon('Garurumon', 20))
tree.insert(Digimon('Agumon', 10))
tree.insert(Digimon('War Greymon', 55))
tree.insert(Digimon('Kabuterimon', 18))
tree.insert(Digimon('Atlur Kabuterimon', 32))
tree.insert(Digimon('Gabumon', 9))
tree.insert(Digimon('Were Garurumon', 31))
tree.insert(Digimon('Metal Garurumon', 50))

tree.display_tree()