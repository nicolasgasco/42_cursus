# CPP 07

**Topics covered**:

- Parametric macros (from C)
  - A solution to functions with the same logic, but flexible enough to accept differnt types (e.g. `max` function that works with `int`, `float`, `double`...)
  - `#define max(x, y) ( ((x)>=(y)) ? (x) : (y) )`
  - You can substitute placeholder with anything, even functions
- Templates

  - Function templates
    - Use a placeholder for any type, e.g. `T max(T x, T y)` where `T` simply stands for a placeholder type
    - To declare a function template, you have to write before `template<typename T>`
    - You can pass/return the template type by reference too
    - A function template can be instantiated both implicitly and explicitly
      - Explicit: `max<int>(a, b)`
      - Implicit: `max(a, b)`
  - Template structures and classes
    - Same syntax as functions: `template<typename T>`
    - Reference the type inside the class as `ClassName<T>`
    - It is even possible to have more than one dimension if you in your `main` use the template in a nested fashion, e.g. `List<List<int>>foo(bar)`
    - There can be more than one type inside chevrons
  - Standard library makes vast use of templates

- Default types

  - It is possible to establish a default type, e.g. `template<typename T = float>`
  - `.tpp` is the extension for class template
  - If default constructor is private, it is not possible to explicitly instanciate a class with the default constructor
  - If there is a default value, there's no need to establish a type when instantiating, e.g. `Class<>`

- Specialization
