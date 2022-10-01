
#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *a, unsigned int len, void func(T &)) {
    for (unsigned int i = 0; i < len; i++) {
        func(a[i]);
    }
}

template <typename T>
void outputArrayValue(T value) {
    std::cout << "- " << value << std::endl;
}

#endif
