
// Example from: 
// https://docs.microsoft.com/fr-fr/visualstudio/profiling/quickstart-cpu-usage-native?view=vs-2019

#include <iostream>
#include <limits>
#include <mutex>
#include <random>
#include <functional>

//.cpp file code:

static constexpr int MIN_ITERATIONS = std::numeric_limits<int>::max() / 1000;
static constexpr int MAX_ITERATIONS = MIN_ITERATIONS + 10000;

long long m_totalIterations = 0;
std::mutex m_totalItersLock;

int getNumber()
{

    std::uniform_int_distribution<int> num_distribution(MIN_ITERATIONS, MAX_ITERATIONS);
    std::mt19937 random_number_engine; // pseudorandom number generator
    auto get_num = std::bind(num_distribution, random_number_engine);
    int random_num = get_num();

    auto result = 0;
    {
        std::lock_guard<std::mutex> lock(m_totalItersLock);
        m_totalIterations += random_num;
    }
    // we're just spinning here
    // to increase CPU usage
    for (int i = 0; i < random_num; i++)
    {
        result = get_num();
    }
    return result;
}

void doWork()
{
    std::wcout << L"The doWork function is running on another thread." << std::endl;

    auto x = getNumber();
}

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 10; ++i) {

        threads.push_back(std::thread(doWork));
        std::cout << "The Main() thread calls this after starting the new thread" << std::endl;
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}