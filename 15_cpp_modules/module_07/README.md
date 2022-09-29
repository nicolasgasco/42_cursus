# CPP 07

**Topics covered**:

- Templates

  - Template functions
    - Use a placeholder for any type, e.g. `T max(T x, T y)` where `T` simply stands for a placeholder type
    - To declare a template function, you have to write before `template<typename T>`
    - You can pass/return the template type by reference too
    - A template function can be instantiated both implicitly and explicitly
      - Explicit: `max<int>(a, b)`
      - Implicit: `max(a, b)`
  - Template structures and classes
    - Same syntax as functions: `template<typename T>`
    - Reference the type inside the class as `ClassName<T>`
    - It is even possible to have more than one dimension if you in your `main` use the template in a nested fashion, e.g. `List<List<int>>foo(bar)`
    - There can be more than one type inside chevrons
  - Standard library makes vast use of templates

- Parametric macros (from C)
- Default types
- Specialization
