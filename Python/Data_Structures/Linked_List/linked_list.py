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

    def display(self):
        cursor_node = Node(0)
        cursor_node = self.head
        while cursor_node is not None:
            print(f"{cursor_node.value}-->", end="")
            cursor_node = cursor_node.next
        print("None", end="")
        print()

    def delete(self, value, index):
        cursor = self.head
        if index == 0:
            self.head = cursor.next
            cursor.next = None
        if index > 0:
            for _ in range(index - 1):
                cursor = cursor.next
            deletion = cursor.next
            cursor.next = deletion.next
            deletion.next = None

lt = LinkedList()
lt.insert("Apple", 0)
lt.insert("Banana", 1)
lt.insert("Coconut", 2)
lt.insert("Dragon Fruit", 1)
lt.display()
