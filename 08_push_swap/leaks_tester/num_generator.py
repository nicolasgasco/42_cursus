import random
for i in range(2, 100):
    for x in range (0, 3):
        for y in range(0, i):
            if y != i - 1:
                print(random.randint(-2147483648,2147483647), end=", ") # prints: -1, 1, 3, 
            else:
                print(random.randint(-2147483648,2147483647), end="") # prints: -1, 1, 3, 
        print("")