# computorv1

This project aims to make you code a simple equation solving program. It will take polynomial equations into account. These equations will only require exponents. No complex V◊function. The program will have to display its solution(s)

The idea is to get you (back) in touch with the manipulation of elementary mathematic
tools you will be able to use in seveal 42 subjects. The idea is not to "just make maths".
This exercise will allow you to approach exercises that will require these skills and knowledge with a restful mind.

## Execute

```
$ docker compose up -d
$ docker exec -it -w /computorv1 30_computorv1-app-1 bash
$ make
$ ./computor
```

## Example prompts

The parser expects terms in the form `coefficient * X^exponent`.

### Degree 0

```text
5 * X^0 = 0
0 * X^0 = 0
5 * X^0 = 5 * X^0
5 * X^0 = 8 * X^0
0 * X^0 + 0 * X^1 + 0 * X^2 = 0
```

### Degree 1

```text
5 * X^0 + 4 * X^1 = 0
5 * X^0 + 4 * X^1 = 4 * X^0
0 * X^0 + 4 * X^1 + 0 * X^2 = 0
8 * X^0 - 6 * X^1 + 3 * X^3 = 3 * X^3
5 * X^0 + 0 * X^1 = 0
```

### Degree 2

```text
1 * X^0 + 2 * X^1 + 5 * X^2 = 0
1 * X^0 - 2 * X^1 + 1 * X^2 = 0
4 * X^0 + 12 * X^1 + 3 * X^2 = 0
5 * X^0 + 0 * X^1 + 1 * X^2 = 0
5 * X^0 + 3 * X^1 + 3 * X^2 = 1 * X^0 + 0 * X^1
0.9999999999999999 * X^0 + 2 * X^1 + 1 * X^2 = 0
```

### Degree 3

```text
1 * X^0 + 2 * X^1 + 0 * X^2 + 4 * X^3 = 0
8 * X^0 - 6 * X^1 + 0 * X^2 + 3 * X^3 = 3 * X^3
8 * X^0 - 6 * X^1 + 1 * X^2 + 3 * X^3 = 3 * X^3
0 * X^0 + 0 * X^1 + 0 * X^2 + 0 * X^3 = 0
```

The first degree-3 example has a non-zero cubic coefficient and must be rejected as unsupported. The next two cancel their cubic terms during reduction and should be solved as degree 1 and degree 2 respectively. The final example is the zero polynomial and should be treated as degree 0.
