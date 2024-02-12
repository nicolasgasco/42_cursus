import sys

if len(sys.argv) == 1:
    sys.exit(1)

assert len(sys.argv) <= 2, "more than one argument is provided"

try:
    arg = int(sys.argv[1])
except:
    arg = sys.argv[1]
    pass

assert isinstance(arg, int), "argument is not an integer"

if arg % 2 == 0:
    print("I'm Even.")
else:
    print("I'm Odd.")
