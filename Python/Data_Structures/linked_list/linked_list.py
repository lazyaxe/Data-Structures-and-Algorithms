# LINKED LIST IN PYTHON:

#Creating Node the basic unit of storage
class Node:
    def __init__(self, value=None) -> None:
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self) -> None:
        self.nodes = 0
        self.head = None

    def __len__(self):
        return self.nodes

    def insert(self, value, index):
        new_node = Node(value)

        #if we insert node at the starting index or its head,
        #then we only need to reassign the it as a head node
        if index == 0:
            new_node.next = self.head
            self.head = new_node
        elif index > 0:
            cursor_node = self.head
            for _ in range(index - 1):
                cursor_node = cursor_node.next
            new_node.next  = cursor_node.next
            #objects in Python use pointer referencing by default
            #So if the "next" attribute changes in cursor_node,
            #it also changes in the linked node
            cursor_node.next = new_node
            self.nodes += 1

    def find(self, value):
        cursor_node = self.head
        index = 0
        while cursor_node.next is not None:
            if cursor_node.value == value:
                return index
            elif cursor_node.value != value:
                cursor_node = cursor_node.next
                index += 1
        return -1

    def display(self):
        cursor_node = self.head
        while cursor_node is not None:
            print(f"{cursor_node.value}-->", end="")
            cursor_node = cursor_node.next
        print("None")

    def _delete_with_index(self, index, cursor_node):
        #delete head and replace it second Node
        if index == 0:
            self.head = cursor_node.next
            cursor_node.next = None

        elif index > 0:
            for _ in range(index - 1):
                cursor_node = cursor_node.next
            deletion_node = cursor_node.next
            cursor_node.next = deletion_node.next
            deletion_node.next = None

    def _delete_with_value(self, value, cursor_node):
            #delete head and replace it second Node
            index = self.find(value=value)
            self._delete_with_index(index=index, cursor_node=cursor_node)

    def delete(self, value=None, index=None):
        cursor_node = self.head

        #delete head and replace it second Node
        if index is not None:
            self._delete_with_index(index=index, cursor_node=cursor_node)

        elif value is not None:
            self._delete_with_value(value=value, cursor_node=cursor_node)

if __name__ == "__main__":
    lt = LinkedList()
    lt.insert("Apple", 0)
    lt.insert("Banana", 1)
    lt.insert("Coconut", 2)
    lt.insert("Dragon Fruit", 1)
    lt.display()
    print(lt.find("Coconut"))
    lt.delete(index=2)
    lt.display()

    print(isinstance(lt, LinkedList))