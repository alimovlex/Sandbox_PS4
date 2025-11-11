#include <sstream>
#include <thread>
#include <mutex>
#include "tcp_server.hpp"
#include "text_drawer.hpp"

std::stringstream debugLogStream;

int main()
{
    std::mutex mtx;
    //mtx.lock();
    //mtx.unlock();
    std::thread t1(start_tcp_server);
    std::thread t2(drawSampleText, "Echo Server by alimovlex");
    t2.join();  
    t1.join();
    return 0;
}


