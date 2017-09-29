/*
shared_ptr test
*/

#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

struct Base {
    Base()
    {
        std::cout << "	Base::Base()\n";
    }
    ~Base()
    {
        std::cout << "	Base::~Base()\n";
    }
};

struct Derived : public Base {
    Derived() : Base()
    {
        std::cout << "	Derived::Derived()\n";
    }
    ~Derived()
    {
        std::cout << "	Derived::~Derived()\n";
    }
};
void thr(std::shared_ptr<Base> p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::shared_ptr<Base> lp = p;
    {
        static std::mutex io_mutex;
        std::lock_guard<std::mutex> lk(io_mutex);
        std::cout << "local pointer in a thread:\n"
                  << " lp.get() = " << lp.get()
                  << ",lp.use_count() = " << lp.use_count() << "\n";
    }
}
int main()
{
    std::shared_ptr<Base> p = std::make_shared<Derived>();

    std::cout << "Created a shared Derived (as a pointer to Base)\n"
              << " p.get() = " << p.get()
              << ",p.use_count() = " << p.use_count() << "\n";
    std::thread t1(thr, p), t2(thr, p), t3(thr, p);
    p.reset();
    std::cout << "Shared ownership between 3 thread and released\n"
              << "ownership from main:"
              << " p.get() = " << p.get()
              << ",p.use_count() = " << p.use_count() << "\n";
    t1.join();
    t2.join();
    t3.join();
    std::cout
        << "All threads completed,the last one deleted one deleted Derived\n";

    return 0;
}
