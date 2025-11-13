#include <unistd.h>
#include <string.h>
//#include <sstream>

int testLibraryFunction(char *buf, size_t buf_size, int num)
{
    write(1, buf, buf_size);
    write(1, "\n", 1);
    return 0;
}
