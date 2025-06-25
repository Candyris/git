#include <iostream>
#include <thread>
#include <future>
#include <chrono>

int add(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return a + b;
}

int main()
{
    std::future<int> futureValue = std::async(std::launch::async, add, 1,2);
    std::cout << "I am going!" << std::endl;
    std::cout << futureValue.get() << std::endl;

}