import sys

if len(sys.argv) == 1:
    sys.exit(1)

try:
    assert len(sys.argv) <= 2, "more than one argument is provided"
except AssertionError as e:
    print(f"AssertionError: {e}")
    sys.exit(1)

try:
    arg = int(sys.argv[1])
except ValueError:
    arg = sys.argv[1]
    pass

try:
    assert isinstance(arg, int), "argument is not an integer"
except AssertionError as e:
    print(f"AssertionError: {e}")
    sys.exit(1)

if arg % 2 == 0:
    print("I'm Even.")
else:
    print("I'm Odd.")
