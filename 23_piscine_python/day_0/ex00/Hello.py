ft_list = ["Hello", "tata!"]
ft_list[1] = "World!"

# Tuples are immutable, so we need to convert it to a list,
# then change the value, and then convert it back to a tuple
ft_tuple = ("Hello", "toto!")
ft_tuple = list(ft_tuple)
ft_tuple[1] = "Spain!"
ft_tuple = tuple(ft_tuple)

# Sets are mutable, but we can't change the value of an element,
# so we need to remove the element and add a new one
# Order is not guaranteed
ft_set = {"Hello", "tutu!"}
ft_set.remove("tutu!")
ft_set.add("Bilbao!")
ft_set = set(ft_set)

ft_dict = {"Hello": "titi!"}
ft_dict["Hello"] = "42Urduliz!"


# your code here
print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)
