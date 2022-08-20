# CPP 02 - ex 00

## Floating point values

- Integers are accurate but not precise, floating points are precise but not accurate
- IEEE-754 is one of the most widespread standards:
  - Sign bit for positive or negative
  - Exponent with order of magnitude
  - Mantissa: actual digits of the number
- Value of number in mantissa is `2^exponent`, so it's binary fractions
- `1.m` notation: implicit 1 always on the left of mantissa
- Zero is special case: all bits (sign not relevant) are 0
- `0 vs 1.0`: exponent is "shift-127 encoded (exponent is `eeeeee - 127`), so that `127` is an exponent of zero.
- Special cases: 0, positive and negative infinity (eveyr bit of exponent set), NaN (every bit of exponent and mantissa are set)
- Limits:

  | Property                                 | Value for float | Value for double        |
  | ---------------------------------------- | --------------- | ----------------------- |
  | Largest representable number             | 3.402823466e+38 | 1.7976931348623157e+308 |
  | Smallest number without losing precision | 1.175494351e-38 | 2.2250738585072014e-308 |
  | Smallest representable number(\*)        | 1.401298464e-45 | 5e-324                  |
  | Mantissa bits                            | 23              | 52                      |
  | Exponent bits                            | 8               | 11                      |

- Comparing equality of FPs is difficult. One common practice is checking if two values are close enough
- A more solid is approach is thinking how many significant digits you want to match
- Most CPUs set a flag bit when an operation overflows
- FPs use negative and positive infinity for overflows and can be used as reference for overflows (e.g. do calculation with `double`, compare result with e.g. INT_MAX and cast back to `int`)
- Subtracting very close quantities results in a big loss of precision
- A float gradually gets "corrupted" as you do more and more operations on it

## Fixed point values

- Binary point: divider between the integer and the fractional part of a binary number

  ```
  11010.1
  1 * 2^4 + 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 + 1 * 2^-1

  110101 = 53
  11010.1 = 26.5
  ```

- Shifting a binary number `>> 1` is equal to diving the number by 2, `<< 1` multiplies by 2
- To define a fixed point type number:
  - width of the number (bits)
  - binary point position within the number (from the least significant bit)
  ```
  fixed<8,3>
  00010.110
  1 * 2^1 + 2^-1 + 1 * 2^-2 = 2.75
  ```
- For negative numbers, we use 2's complement:

  ```
  00001 // 1
  11111 // -1
  ```

- `>> 1` to divide by 2 a negative number
- Much faster than working with `float`s
