def all_thing_is_obj(object: any) -> int:

    obj_type = type(object)

    if isinstance(object, list):
        print("List :", obj_type)
    elif isinstance(object, tuple):
        print("Tuple :", obj_type)
    elif isinstance(object, set):
        print("Set :", obj_type)
    elif isinstance(object, dict):
        print("Dict :", obj_type)
    elif isinstance(object, str):
        print(object, "is in the kitchen :", obj_type)
    else:
        print("Type not found")

    return 42
