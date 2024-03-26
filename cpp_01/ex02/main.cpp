#include <iostream>

int main (void) {

	std::string str = "HI THIS IS BRAIN";
	std::string& ref = str;
	std::string* ptr = &str;

	std::cout << "str value : " << str << std::endl;
	std::cout << "ref value : " << ref << std::endl;
	std::cout << "ptr value : " << *ptr << std::endl;

	std::cout << "str adress : " << &str << std::endl;
	std::cout << "ref adress : " << &ref << std::endl;
	std::cout << "ptr adress : " << ptr << std::endl;

	ref = "LOL";

	std::cout << "str value : " << str << std::endl;
	std::cout << "ref value : " << ref << std::endl;
	std::cout << "ptr value : " << *ptr << std::endl;
}