


#include    <cstdio>
#include    <vector>
#include    <thread>



struct Test {
    ~Test()
    {
        std::printf("~Test %p\n", this); fflush(stdout);
        
        // "Msvc" will stop. That is correct.
        // "g++" does not stop. That is dangerous.
        *static_cast<int*>(nullptr) = 0;
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
    return 0;
}
