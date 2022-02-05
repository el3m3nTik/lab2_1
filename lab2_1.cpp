#include<iostream>
#include <chrono>
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
uint64_t factorial(int n)
{
	uint64_t F = 1;
	for (int i = 1; i <= n; i++)
		F *= i;
	return F;

}
int main()
{
	int n;
	std::cin >> n;
	Timer t;
	std::cout << factorial(n) << std::endl;
	std::cout << "Time elapsed:" << t.elapsed() << std::endl;
}
