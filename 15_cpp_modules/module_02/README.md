# CPP 02

**Topics covered**:

1. Ad-hoc polymorphism
   - Function overload: same function declared several times with different parameters (e.g. once with `int` and another time with `char`)
1. Operator overload

   - Customized operators functionalities
   - `+(1, 1)` vs `1 + 1` vs `1 1 +`
   - `operator` keyword
   - First parameter of operator overloads is always `this`, even if not visible
   - If current istance is not modified by operator (e.g. `+`), use `const`
   - Return current instance to be able to chain operators (e.g. `a = b = c = d`)

     ```
     // Chaining possible
     Integer & operator=(Integer const & rhs);

     Integer Interger::operator=(Integer const & rhs) {
         this->_n = rhs.getValue();
         return *this;
     }

     // Chaining not possible
     Integer operator+(Integer const & rhs) const;

     Integer Integer::operator+(Integer const & rhs) const {
         return (Integer(this->-n + rhs.getValue());
     }
     ```

   - Overflow `<<` operator

     ```
     // Overflowing << operator with chaining
     std::ostream & operator<<(std::ostream & o, Integer const & rhs);

     std::ostream & operator <<(std::ostream & o, Integer const & rhs) {
         o << rhs.getValue();
         return o;
     }
     ```

   - Three rules:
     1. Must be not against nature of operator
     1. Respect the syntax of operator
     1. Don't use it if you can avoid it

1. Canonical form
   - Good practice, but unclear definition
   - A class must have
     - Default constructor (`private`)
     - Copy constructor
     - Destructor
     - `=` operator overload
