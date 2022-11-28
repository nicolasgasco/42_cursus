#include "../Vector.hpp"

// Values provided by 42
#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
    int idx;
    char buff[BUFFER_SIZE];
};
#define COUNT (MAX_RAM / (int)sizeof(Buffer))