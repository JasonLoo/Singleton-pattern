#include <iostream>

using namespace std;

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
public:
	static Singleton& getInstance(void)
	{
		if (!s_instance)
			s_instance = new Singleton;
		return *s_instance;
	}
};

Singleton* Singleton::s_instance = NULL;

int main(int argc,const char * argv[])
{
	Singleton& a = Singleton::getInstance();
	cout << hex << &a << endl;
	Singleton& b = Singleton::getInstance();
	cout << hex << &b << endl;

	return 0;
}