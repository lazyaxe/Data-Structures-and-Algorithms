# ARRAYS IN PYTHON

# Arrays are a linear homogenous data stucture.
# There is no native support to arrays in Python, unlike languages like C/C++, Java etc...
# Lists are the equivalent to arrays in Python.
# Lists are a collection of objects under a single object name.
# The syntax of lists is equivalent to arrays.
# Lists can also store objects of heterogenous(i.e. different) datatypes(or objects) but it's ineffiecient and not recommended in most cases.
# Lists can also be single and multi dimensional.
# The lenght of a lists can be change by declaration but length cannot be re-sized/modified.

#CREATING A LIST
number_list = [1, 2, 3, 4, 5, 6]

#PRINTING A 1D LIST
# method 0: Using print()
print(f"List: {number_list}")
print()

# method 1: Classic indexing
for i in range(len(number_list)):
    print(number_list[i], end=" ")
print()
print()


# method 2: For each loop
for number in number_list:
    print(number, end=" ")
print()
print()


# method 3: while loop
i = 0
while i < len(number_list):
    print(number_list[i], end=" ")
    i += 1
print()
print()


#PRINTING A Multi-Dimensional List
number_matrix = [[1, 2, 3], 
                 [4, 5, 6], 
                 [7, 8, 9],
                 [10, 11, 12]]

# method 1
for i in range(len(number_matrix)):
    for j in range(len(number_matrix[i])):
        print(number_matrix[i][j], end=" ")
    print()
print()

# method 2
i = 0
while i < len(number_matrix):
    j = 0
    while j < len(number_matrix[i]):
        print(number_matrix[i][j], end=" ")
        j += 1
    i += 1
    print()
print()

# method 3
for row in number_matrix:
    for number in row:
        print(number, end=" ")
    print()
print()