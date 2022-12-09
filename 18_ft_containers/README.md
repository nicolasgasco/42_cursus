# ft_containers
> The multiple available containers in C++ all have very different usage. To make sure you understand them, let’s re-implement them!

The aim of this project is re-implementing as close as possible to the respective original:
- `std::vector` (without `vector<bool>` specialization 😮‍💨)
- `std::stack` (using the re-implemented `vector` as underlying container)
- `std::map`
- `iterators_traits`, `reverse_iterator`, `enable_if`, `is_integral`, `equal`/`lexicographical_compare`, `std::pair`, `std::make_pair`


## Testers
The project was tested as much as possible with unit tests. To execute them:
```sh
sh unit_tests/run_tests.sh
```
