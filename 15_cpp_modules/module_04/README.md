# CPP 04

**Topics covered**:
- Subtyping polymorphism
    - When a class inherit from another one, you can initialize the child class as a pointer using as a type either the parent or child class
    - You can't initialize a parent class as a pointer using the child class as a type
    - If you initialize a child class as pointer using the parent class as a type, all methods refer then to the parent
    - Adding `virtual` to a function definition in the parent class, in the case above, the function of the child class will be executed
- Abstact classes and interfaces
    - A pure method is `virtual` and `= 0`
    - When a class is abstract, the convention is adding an `A` to the class name
    - It's a way to define behaviors
    - An interface (name starting with `I`) is a "contract" between the parent class and child classes, a way to force methods on child classes


