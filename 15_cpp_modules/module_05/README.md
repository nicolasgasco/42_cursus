# CPP 05

**Topics covered**:

- Nested classes
  - You can declare a class inside another class, as if it were some sort of `namespace`
  - You can use `::` to reference it
- Exceptions
  - You can use `try... catch` blocks to capture exceptions
  - You can also manually `throw` an exception
  - You can create a custom exception by inheriting `std::exception`
  - `virtual const char *foo() const throw() { return ("error")}` to make an exception
  - You can have several `catch` blocks to catch different types of exceptions
  - If you have several `catch` blocks, you should order them from more specific to less specific
