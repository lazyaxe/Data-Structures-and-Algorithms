#A simple hash table implementation
def my_hash(value):
    if isinstance(value, int):
        return value % 10
    elif isinstance(value, str):
        sum_of_all_chars = 0
        for char in value:
            #ord helper function converts a char in the string to its corresponding ASCII value
            sum_of_all_chars += ord(char)
        return sum_of_all_chars % 10
    else:
        return -1

key_list = [0 for _ in range(10)]
value_list = [None for _ in range(10)]

print(value_list)
def add_value(value):
    index = my_hash(value)
    print(f"Index {index} of {value}")
    key_list[index] = index
    value_list[index] = value

add_value("Harsh")
for key, value in zip(key_list, value_list):
    print(f"{key} : {value}")




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

    def hash(self, value):
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
        index = self.hash(value)
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
                return
        print(f"Couldn't place {value}, no spots left")

    def quad_probing(self, index, value) -> None:
        for i in range(self.size):
            if self.is_collision(index):
                print(f"index {index} was occupied, cannot place {value}")
                index = (index + 1 + i ** 2) % self.size
            else:
                print(f"{value}  placed at index {index}")
                self.key_list[index] = index
                self.value_list[index] = value
                return
        print(f"Couldn't place {value}, no spots left")

    def add(self, value):
        index = self.hash(value)
        if self.resolution_method == "linear":
            self.linear_probing(index=index, value=value)

        elif self.resolution_method == "quad":
            self.quad_probing(index=index, value=value)

        elif self.resolution_method == "double":
            index  = abs(self.second_hash(value)) % self.size

            if self.is_collision(index):
                self.linear_probing(index=index, value=value)

    def find(self, value):
        index = self.hash(value)
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
            index = self.hash(value)

            #removing the old key:value pair
            self.value_list[index] = None
            self.key_list[index] = 0

            print(f"Modified {value} to {new_value}")
            self.add(new_value)

        else:
            print(f"Can't modify as value, {value} as it doesn't exist!")

    def display(self):
        print("{", end="")
        for key, value in zip(self.key_list, self.value_list):
            print(f"[{key} : {value}]")
        print("}", end="")
        print()

if __name__ == "__main__":
    ht = HashTable(7, resolution_method='quad')

    ht.add("Python")
    print(ht.hash("Python"), end="\n\n")

    ht.add("Sukuna")
    print(ht.hash("Sukuna"), end="\n\n")

    ht.add("Megumi")
    print(ht.hash("Megumi"), end="\n\n")

    ht.add("Itadori")
    print(ht.hash("Itadori"), end="\n\n")

    ht.add(48487)
    print(ht.hash(48487), end="\n\n")

    ht.add("Jotaro")
    print(ht.hash("DIO"), end="\n\n")

    ht.add("Light")
    print(ht.hash("Light"), end="\n\n")

    ht.modify("Itadori", "Itachi")
    print(ht.hash("Itachi"), end="\n\n")

    ht.display()

    #trying to place an value after Table is full
    ht.add("Harsh")
    print(ht.hash("Harsh"), end="\n\n")

    ht.display()

    print(ht.find("Light"))