#include <iostream>
#include <list>

using namespace std;

void test(int *i)
{
	int a = 1;
	// i：此时为地址
	// *i:此时为地址的值
	*i += 1;
	cout << "i:" << *i << endl;
}

int main_test()
{
	return 0;
}

int main_2_1()
{
	//C++ 规定 short 和 int 至少16位，long 至少32位，long long 至少64位。
	//带符号类型能够表示正数、负数和 0 ;
	//而无符号类型只能够表示 0 和正整数

	return 0;
}

int main_2_2()
{
	//使用double。需要进行浮点计算。

	return 0;
}

int main_2_3()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl;
	std::cout << u - u2 << std::endl;
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;
	std::cout << i - i2 << std::endl;
	std::cout << i - u << std::endl;
	std::cout << u - i << std::endl;

	return 0;
}

int main_2_8()
{
	std::cout << 2 << "\115\012";
	std::cout << 2 << "\t\115\012";
	return 0;
}

int main_2_34()
{
	int i = 0, &r = i;
	auto a = r;   // a是一个整数（r是i的别名，而i是以一个整数）

	const int ci = i, &cr = ci;
	auto b = ci; // b是一个整数（ci的顶层const特性被忽略掉了）
	auto c = cr; // c是一个整数（cr是ci的别名，ci本身是一个顶层const）
	auto d = &i; // d是一个整型指针（整数的地址就是指向整数的指针）
	auto e = &ci; // e是一个指向整数常量的指针（对常量对象去地址是一种底层const）

	const auto f = ci; // ci的推演类型是int，f是const int
	auto &g = ci; // g是一个整型常量引用，绑定到ci

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << g << std::endl;
	std::cout << "--------------" << std::endl;
	a = 42;
	b = 42;
	c = 42; //d = 42; e = 42; g = 42;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << g << std::endl;

	return 0;
}




