#include <iostream>
class Singleton
{
private:
	Singleton(void)
	{
	}
	Singleton(Singleton const& that)
	{
	}
	static Singleton* s_instance;
	static pthread_mutex_t s_mutex;
public:
	static Singleton& getInstance(void)
	{
		if (!s_instance)
		{
			pthread_mutex_lock(&s_mutex);
			if (!s_instance)
				s_instance = new Singleton;
			pthread_mutex_unlock(&s_mutex);
		}
		return *s_instance;
	}
};
Singleton* Singleton::s_instance = NULL;
pthread_mutex_t Singleton::s_mutex = PTHREAD_MUTEX_INITIALIZER; _
int main(int argc, const char * argv[])
{


	Singleton& a = Singleton::getInstance();
	std::cout << std::hex << &a << std::endl;
	Singleton& b = Singleton::getInstance();
	std::cout << std::hex << &b << std::endl;

	return 0;
}