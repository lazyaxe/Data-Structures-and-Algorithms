#A simple hash table implementation
def my_hash(value):
    if isinstance(value, int):
        return value % 67
    elif isinstance(value, str):
        sum_of_all_chars = 0
        for char in value:
            #ord helper function converts a char in the string to its corresponding ASCII value
            sum_of_all_chars += ord(char)
        return sum_of_all_chars % 67
    else:
        return -1

my_list = [[] for _ in range(101)]

print(my_list)
def add_value(value):
    index = my_hash(value)
    my_list[index].append(value)

add_value("Harsh")
print(my_list)




# A better hash table implementation (w/ linear probing, quadratic probing and double hashing)
class HashTable:
    def __init__(self, size, resolution_method):
        """
            Resolution Method options: 'linear', 'quad', 'double'
        """
        self.size = size
        self.resolution_method = resolution_method
        self.key_list: list = [0 for _ in range(self.size)]
        self.value_list: list = [None for _ in range(self.size)]

    def first_hash(self, value):
            if isinstance(value, int):
                return value % self.size

            elif isinstance(value, str):
                sum_of_all_chars = 0
                for char in value:
                    #ord helper function converts a char in the string to its corresponding ASCII value
                    sum_of_all_chars += ord(char)
                return sum_of_all_chars % self.size

            else:
                return -1

    def second_hash(self, value):
        return abs(hash(value)) % self.size 

    def contains(self, value):
        index = self.first_hash(value)
        if self.value_list[index] == value:
            return True
        else:
            return False

    def is_collision(self, index):
        if self.value_list[index] is None:
            return False
        else:
            return True


    def linear_probing(self, index, value) -> None:
        for _ in range(self.size):
            if self.is_collision(index):
                print(f"index {index} was occupied, cannot place {value}")
                index = (index + 1) % self.size
            else:
                print(f"{value}  placed at index {index}")
                self.key_list[index] = index
                self.value_list[index] = value
                break

    def quad_probing(self, index, value) -> None:
        for i in range(self.size):
            if self.is_collision(index):
                print(f"index {index} was occupied, cannot place {value}")
                index = (index + 1 + i ** 2) % self.size
            else:
                print(f"{value}  placed at index {index}")
                self.key_list[index] = index
                self.value_list[index] = value
                break

    def add(self, value):
        index = self.first_hash(value)
        if self.resolution_method == "linear":
            self.linear_probing(index=index, value=value)

        elif self.resolution_method == "quad":
            self.quad_probing(index=index, value=value)

        elif self.resolution_method == "double":
            index  = abs(self.second_hash(value)) % self.size

            if self.is_collision(index):
                self.linear_probing(index=index, value=value)

    def find(self, value):
        index = self.first_hash(value)
        if self.value_list[index] == value:
            return index

        elif self.resolution_method == "linear" or self.resolution_method == "quad":
                for _ in range(self.size):
                    index = (index + 1) % self.size
                    if self.value_list[index] == value:
                        return index

        elif self.resolution_method == "double":
            index  = abs(self.second_hash(value)) % self.size
            for _ in range(self.size):
                if self.value_list[index] == value:
                    return index
                index = (index + 1) % self.size

        else:
            print(f"Couldn't find {value}")
            return -1

    def modify(self, value, new_value):
        if self.contains(value):
            index = self.first_hash(value)
            self.value_list[index] = None
            self.key_list[index] = None
            self.add(new_value)
        else:
            print(f"Can't modify as the value, {value} doesn't exist!")
    def display(self):
        for i in range(self.size):
            print(f"index: {i}: {self.key_list[i]} -> {self.value_list[i]}", end="\n")


ht = HashTable(7, resolution_method='quad')

ht.add("Python")
print(ht.first_hash("Python"), end="\n\n")

ht.add("Sukuna")
print(ht.first_hash("Sukuna"), end="\n\n")

ht.add("Megumi")
print(ht.first_hash("Megumi"), end="\n\n")

ht.add("Itadori")
print(ht.first_hash("Itadori"), end="\n\n")

ht.add(48487)
print(ht.first_hash(48487), end="\n\n")

ht.add("Jotaro")
print(ht.first_hash("DIO"), end="\n\n")

ht.modify("Itadori", "Itachi")
print(ht.first_hash("Itachi"), end="\n\n")

ht.add("Light")
print(ht.first_hash("Light"), end="\n\n")

ht.display()

print(ht.find("Light"))