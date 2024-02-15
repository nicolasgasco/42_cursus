def NULL_not_found(object: any) -> int:

    obj_type = type(object)

    if object is None:
        print("Nothing:", object, obj_type)
    elif isinstance(object, float):
        print("Cheese:", object, obj_type)
    elif isinstance(object, bool):
        print("Fake:", object, obj_type)
    elif isinstance(object, int):
        print("Zero:", object, obj_type)
    elif isinstance(object, str) and len(object) == 0:
        print("Empty:", obj_type)
    else:
        print("Type not Found")
        return 1

    return 0
