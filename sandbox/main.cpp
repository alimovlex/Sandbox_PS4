#include <sstream>
#include "tcp_server.hpp"
#include "text_drawer.hpp"

std::stringstream debugLogStream;

int main()
{
    start_tcp_server();
    //drawSampleText();
    return 0;
}


