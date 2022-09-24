# CPP 06

**Topics covered**:

- C-type conversions:

  - There are implicit and explicit casts
  - `int a = 42` + `double b = a` is possible thanks to implicit conversion. It would be `double b = (double)a` with explicit cast
  - There is a hierarchy among types, dending on precision
  - With some implicit conversions, there can be a loss of precision if the new type has less precision (e.g. `double` casted to `int`)
  - It is safer to do explicit conversion when the types are different
