class Node:
    def __init__(self, value=None, next=None) -> None:
        self.value = value
        self.next = next

class HashTable:
    def __init__(self, size):
        """
            Resolution Method options: 'chaining'
        """
        self.size = size
        self.key_list: list = [i for i in range(self.size)]
        self.value_list: list[Node] = [Node(value=None) for _ in range(self.size)]

    def hash_function(self, value) -> int:
            if isinstance(value, int):
                return value % self.size
            elif isinstance(value, float):
                return round(value) % self.size
            elif isinstance(value, str):
                sum_of_all_chars = 0
                for char in value:
                    #ord helper function converts a char in the string to its corresponding ASCII value
                    sum_of_all_chars += ord(char)
                return sum_of_all_chars % self.size
            return -1

    def is_collision(self, index):
        if self.value_list[index].value is None:
            return False
        return True

    def add(self, value):
        key = self.hash_function(value=value)
        if self.is_collision(key):
            temp_node = Node(value=value)
            temp_node.next = self.value_list[key].next
            self.value_list[key].next = temp_node
        else:
            self.value_list[key].value = value

    def modify(self, value, new_value):
        key = self.hash_function(value)
        if self.value_list[key].value == value:
            self.value_list[key].value = new_value
        else:
            cursor_node = self.value_list[key]
            while self.value_list[key].next is not None:
                if cursor_node.value == value:
                    cursor_node.value = new_value
                    return
                cursor_node = cursor_node.next

    def find(self, value):
        key = self.hash_function(value)
        index = 0
        cursor_node = self.value_list[key]
        while self.value_list[key].next is not None:
            if cursor_node.value == value:
                break
            cursor_node = cursor_node.next
            index += 1
        return (key, index)

    def traverse_node(self, Node: Node) -> list:
        cursor_node = Node
        nodes = []
        while cursor_node is not None:
            nodes.append(cursor_node.value)
            cursor_node = cursor_node.next
        return nodes
    
    def display(self):
        for key, value in zip(self.key_list, self.value_list):
            print(f"{key} : {self.traverse_node(value)}")

if __name__ == "__main__":
    ht = HashTable(7)

    print(ht.key_list)
    print(ht.value_list)

    ht.add("A")
    print(ht.hash_function("A"), end="\n\n")

    ht.add("B")
    print(ht.hash_function("B"), end="\n\n")

    ht.add("C")
    print(ht.hash_function("C"), end="\n\n")

    ht.add("D")
    print(ht.hash_function("D"), end="\n\n")

    ht.add(48487)
    print(ht.hash_function(48487), end="\n\n")

    ht.add("E")
    print(ht.hash_function("E"), end="\n\n")

    ht.modify("F", "G")

    ht.add("H")
    print(ht.hash_function("H"), end="\n\n")

    print(ht.find("H"))

    ht.display()
    
    print(ht.key_list)
    print(ht.value_list)