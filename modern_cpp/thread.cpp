#include <iostream>
#include <thread>
#include <mutex>
#include <future>

int v = 0;

// void critical_section_lock_guard(int change_v)
// {
//     static std::mutex mtx; // Static mutex, not re-initialized across function calls
//     std::lock_guard<std::mutex> lock(mtx); // Unique lock used here
//     v = change_v;
//     std::cout << "Changing v to " << change_v << std::endl;
//     std::cout << "Exiting critical section with v = " << v << std::endl;
// }

void critical_section(int change_v)
{
    static std::mutex mtx; // Static mutex, not re-initialized across function calls
    std::unique_lock<std::mutex> lock(mtx); // Unique lock is open to std::condition_variable
    v = change_v;
    std::cout << "Changing v to " << change_v << std::endl;
    // lock can be unlocked manually if needed before the end of the scope
    lock.unlock();
    
    // Some other non-critical section code can go here

    // Re-locking the mutex before exiting the function (if needed)
    lock.lock();
    v = 2 * change_v;
    std::cout << "Doubling v to " << 2 * change_v << std::endl;
    std::cout << "Exiting critical section with v = " << v << std::endl;
}

int main()
{
    std::thread t([](){ std::cout << "Hello from thread!\n"; });
    t.join();
    std::cout << "Hello from main!\n";
    std::cout << "----------------------------------------" << std::endl;
    
    std::cout << "Initial value: v = " << v << std::endl;
    std::thread t1(critical_section, 1), t2(critical_section, 2);
    t1.join();
    t2.join(); // core dumped if not joined
    std::cout << "Final value: v = " << v << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::packaged_task<int()> task_return7([](){ return 7; });
    std::future<int> result_from_task_return7 = task_return7.get_future();
    std::thread(std::move(task_return7)).detach();
    std::cout << "Waiting...";
    result_from_task_return7.wait();
    std::cout << "Done!\nResult is " << result_from_task_return7.get() << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}


// g++ -std=c++2a modern.cpp -o ~/thread -lpthread && ~/thread
