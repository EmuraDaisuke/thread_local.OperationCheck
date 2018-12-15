


#include <cstdio>
#include <vector>
#include <thread>



#define DESTRUCT    0



struct Test {
    ~Test()
    {
        std::printf("~Test %p\n", this); fflush(stdout);
        
        #if DESTRUCT//[
        // "gcc version 8.2.0 (Rev3, Built by MSYS2 project)" does not stop. That is dangerous.
        *static_cast<int*>(nullptr) = 0;
        #endif//]
    }
    
    Test()
    {
        std::printf("Test %p\n", this); fflush(stdout);
    }
    
    void Func()
    {
        std::printf("Func %p\n", this); fflush(stdout);
    }
};

thread_local Test v;



int main(int argc, char* argv[])
{
    std::vector<std::thread> at(std::thread::hardware_concurrency());
    for (auto& t : at) t = std::thread([]{ v.Func(); });
    for (auto& t : at) t.join();
    std::printf("*******\n"); fflush(stdout);
    return 0;
}
