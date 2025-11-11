#include <unistd.h>
#include <orbis/libkernel.h>
#include "piscine.h"
#include "logger.h"
#include "libft.h"

//#include "../../_common/log.h"

// Logging
//std::stringstream debugLogStream;

int main(int argc, char** argv)
{
	ft_logger("DEBUG", test);
    //ft_logger("DEBUG", ft_strlen("Hello"));
    for (;;) {}
}
