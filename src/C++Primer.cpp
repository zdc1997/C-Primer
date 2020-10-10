#include <iostream>
#include "Chapter one/Sales_item.h"

using namespace std;

int main_1_6()
{
	Sales_item total;               //保存下一条交易记录的变量

	//读取第一天交易记录，并确保有数据可以处理
	if(std::cin >> total)
	{
		Sales_item trans;           //保存和的变量

		while(std::cin >> trans)
		{
			//如果我们仍在处理相同的书
			if(total.isbn() == trans.isbn())
			{
				total += trans;     //更新总销售额
			}
			else
			{
				//打印前一本书的结果
				std::cout << total << std::endl;
				total = trans;      //total 现在表示下一本书的销售额
			}
		}

		std::cout << total << std::endl;    //打印最后一本书的结果
	}
	else
	{
		//！没有输入，警告读者
		std::cout << " No data?! " << std::endl;    //打印最后一本书的结果
		return -1;                    //表示失败
	}

	return 0;
}

int main_1_5_2()
{
	Sales_item item1, item2;
	std::cin >> item1 >> item2;

	//首先检测item1 和item2 是否表示相同的书
	if(item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return 0;           //表示成功
	}
	else
	{
		std::cout << "Data must refer to same ISBN" << std::endl;
		return -1;           //表示失败
	}
}

int main_1_5_11()
{
	Sales_item item1, item2;

	//读取一堆交易记录
	std::cin >> item1 >> item2;

	//打印它们的和
	std::cout << item1 + item2 << std::endl;

	return 0;
}

int main_1_5_1()
{
	Sales_item book;

	//读入ISBN 号、售出的册数以及销售价格
	std::cin >> book;

	//写入ISBN、售出的册数、总销售额和平均价格
	std::cout << book << std::endl;

	return 0;
}

int main_1_4_4()
{
	//currVal 是我们正在统计的数；我们将读入的新值存入val
	int currVal = 0, val = 0;

	//读取第一个数，并确保确实有数据可以处理
	if(std::cin >> currVal)
	{
		int cnt = 1;            //保存我们正在处理的当前值的个数

		//读取剩余的数
		while(std::cin >> val)
		{
			//如果值相同
			if(val == currVal)
			{
				//将cnt + 1
				++cnt;
			}
			//否则，打印前一个值的个数
			else
			{
				std::cout << currVal << " occurs "
						  << cnt << " times " << std::endl;

				currVal = val;  //记住新值
				cnt = 1;        //重置计数器
			}
		}//while 循环在这里结束

		//记住打印文件中最后一个值的个数
		std::cout << currVal << " occurs "
				  << cnt << " times " << std::endl;
	}//最外层的if 语句在这里结束

	return 0;
}

int main_1_4_3()
{
	int sum = 0, value = 0;

	//读取数据直到遇到文件尾，计算所有读入的值的和
	while(std::cin >> value)
	{
		sum += value;
	}

	std::cout << "Sum is " << sum << std::endl;

	return 0;
}

int main_1_4_2()
{
	int sum = 0;

	//从1 加到10
	for(int val = 1; val <= 10; ++val)
	{
		sum += val;
	}

	std::cout << "Sum of 1 to 10 inclusive is "
			  << sum << std::endl;

	return 0;
}

int main_1_4_1()
{
	int sum = 0, val = 1;

	//只要va1 的值小于等于10，whlie 循环就会持续执行
	while(val <= 10)
	{
		sum += val;         //将sum + val 赋予sum
		++val;              //将val +1
	}

	std::cout << "Sum of 1 to 10 inclusive is "
			  << sum << std::endl;

	return 0;
}

/*
 *  简单主函数：
 *  读取两个数，求它们的和
 */
int main1_3()
{
	//提示用户输入两个数
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;         //保存我们读入的输入数据的变量
	std::cin >> v1 >> v2;       //读取输入数据
	std::cout << "The sum of" << v1 << " and " << v2
			  << " is " << v1 + v2 << std::endl;

	return 0;
}

int main_1_8_test()
{

	std::cout << "/*";
	std::cout << "*/";
	std::cout << /* "/*" */1;
	std::cout << /* "*/" /* "/*" */;

	return 0;
}


//////////////练习题///////////////////

int main_1_21()
{
	Sales_item item1, item2;
	cin >> item1 >> item2;

	if(item1.isbn() == item2.isbn())
	{
		cout << item1 + item2 << endl;
	}
	else
	{
		cerr << "Different ISBN." << endl;
	}

	return 0;
}

int main_1_22()
{
	Sales_item total;

	if(std::cin >> total)
	{
		Sales_item trans;

		while(std::cin >> trans)
		{
			if(total.isbn() == trans.isbn())
			{
				total += trans;
			}
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
		}

		std::cout << total << std::endl;
	}
	else
	{
		std::cerr << "No data?!" << std::endl;
		return -1;
	}

	return 0;
}

int main_1_23()
{
	Sales_item currItem, valItem;

	if(std::cin >> currItem)
	{
		int cnt = 1;

		while(std::cin >> valItem)
		{
			if(valItem.isbn() == currItem.isbn())
			{
				++cnt;
			}
			else
			{
				std::cout << currItem << " occurs " << cnt << " times " << std::endl;
				currItem = valItem;
				cnt = 1;
			}
		}

		std::cout << currItem << " occurs " << cnt << " times " << std::endl;
	}

	return 0;
}