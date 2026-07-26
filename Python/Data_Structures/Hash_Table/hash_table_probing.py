
#A simple hash function
def my_hash(value_):
    if isinstance(value_, int):
        return value_ % 67
    elif isinstance(value_, str):
        sum_of_all_chars = 0
        for char in value_:
            #ord helper function converts a char in the string to its corresponding ASCII value
            sum_of_all_chars += ord(char)
        return sum_of_all_chars % 67
    else:
        return "NaN"

my_list = [[] for _ in range(101)]

print(my_list)
def add_value(value):
    index = my_hash(value)
    my_list[index].append(value)

add_value("Harsh")
print(my_list)


# A better hash table(w/ linear probing)
class HashTable:
    def __init__(self, size):
        self.size = size
        self.keyslots: list = [0 for _ in range(self.size)]
        self.valueslots: list = [None for _ in range(self.size)]

    def hash(self, value):
        return abs(hash(value)) % self.size 

    def contains(self, value):
        index = abs(hash(value)) % self.size
        if self.valueslots[index] == value:
            return True
        else:
            return False

    def hash_is_occupied(self, index):
        if self.valueslots[index] is None:
            return False
        else:
            return True

    def add(self, value):
        index = abs(hash(value)) % self.size
        for _ in range(self.size):
                if self.hash_is_occupied(index):
                    print(f"index {index} was occupied, cannot place {value}")
                    index = (index + 1) % self.size
                else:
                    print(f"{value}  placed at index {index}")
                    self.keyslots[index] = index
                    self.valueslots[index] = value
                    break

    def modify(self, value, new_value):
        if self.contains(value):
            index = abs(hash(value)) % self.size
            self.valueslots[index] = None
            self.keyslots[index] = None
            self.add(new_value)
        else:
            print(f"Can't modify as the value, {value} doesn't exist!")
    def display(self):
        for i in range(self.size):
            print(f"index: {i}: {self.keyslots[i]} -> {self.valueslots[i]}", end="\n")


ht = HashTable(7)

ht.add("Python")
print(ht.hash("Python"))

ht.add("Sukuna")
print(ht.hash("Sukuna"))

ht.add("Megumi")
print(ht.hash("Megumi"))

ht.add("Itadori")
print(ht.hash("Itadori"))

ht.add(48487)
print(ht.hash(48487))

ht.add(878.8788)
print(ht.hash(878.8788))

ht.modify("Itadori", "Itachi")
print(ht.hash("Itachi"))

ht.add("🫣")
print(ht.hash("🫣"))

ht.display()