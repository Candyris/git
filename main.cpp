#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void worker (std::promise<int> resultPromise)
{
    std::cout << "Worker: Doing some work..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    int result = 42;
    std::cout << "worker: work done!, setting result";
    resultPromise.set_value(result);
}

int main()
{
    std::promise<int> myPromise;
    std::future<int> myFuture = myPromise.get_future();

    std::thread t(worker, std::move(myPromise));

    std::cout << "Main Waiting for result..." << std::endl;
    int value = myFuture.get();
    std::cout << "Result: " << value  << std::endl;

    t.join();

}