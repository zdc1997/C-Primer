#include <string>
#include <vector>
#include <list>
#include <limits>
#include <assert.h>
#include <iostream>

using namespace std;

class TimeUsedGuard
{
public:
	TimeUsedGuard(const std::string& msg)
		: m_msg(msg)
		, m_time(msg)
	{
	}
	~TimeUsedGuard()
	{
		cout << m_msg.c_str() << "use time:" << m_time.c_str() << "ms";
	}

private:
	std::string     m_msg;
	std::string     m_time;
};

template <typename T>
T useData(T val)
{
	return std::sqrt(val);
}

template <typename _Container>
void normalForLoop(const _Container& datas)
{
	TimeUsedGuard timeUsedGuard(__FUNCTION__);
	size_t i = 0;

	for(; i < datas.size(); ++i)
	{
		useData(datas[i]);
	}
}

template <typename _Container>
void normalForLoopCallSizeOnce(const _Container& datas)
{
	TimeUsedGuard timeUsedGuard(__FUNCTION__);
	size_t i = 0;
	size_t size = datas.size();

	for(; i < size; ++i)
	{
		useData(datas[i]);
	}
}

template <typename _Container>
void iteratorTest(const _Container& datas)
{
	TimeUsedGuard timeUsedGuard(__FUNCTION__);
	auto pos = datas.cbegin();

	for(; pos != datas.cend(); ++pos)
	{
		useData(*pos);
	}
}

template <typename _Container>
void iteratorCallCEndOnce(const _Container& datas)
{
	TimeUsedGuard timeUsedGuard(__FUNCTION__);
	auto pos = datas.cbegin();
	auto end = datas.cend();

	for(; pos != end; ++pos)
	{
		useData(*pos);
	}
}

// template <typename _Container>
// void qtForeach(const _Container& datas)
// {
//  TimeUsedGuard timeUsedGuard(__FUNCTION__);
//
//  foreach(auto data , datas)
//  {
//      useData(data);
//  }
// }

// template <typename _Container>
// void stdForeach(const _Container& datas)
// {
//  TimeUsedGuard timeUsedGuard(__FUNCTION__);
//  std::for_each(datas.cbegin(), datas.cend(), useData<typename _Container::value_type>);
// }

template <typename _Container>
void rangeForLoop(const _Container& datas)
{
	TimeUsedGuard timeUsedGuard(__FUNCTION__);

	for(auto data : datas)
	{
		useData(data);
	}
}

template <typename _Container>
void rangeForLoopReference(const _Container& datas)
{
	TimeUsedGuard timeUsedGuard(__FUNCTION__);

	for(auto& data : datas)
	{
		useData(data);
	}
}

class CycleTimeTst
{
public:
	CycleTimeTst();
};

CycleTimeTst g_CycleTimeTst;
CycleTimeTst::CycleTimeTst()
{
	constexpr unsigned long MAX_AMOUNT = 100 * 1000 * 1000;

	// std::vector<int> datas;
	// for (unsigned long i = 1; i < MAX_AMOUNT; ++i)
	// {
	//     datas.push_back(i);
	// }
	std::list<double> datas;
	double d = 1.0;

	for(unsigned long i = 1; i < MAX_AMOUNT / 10; ++i)
	{
		datas.push_back(d);
	}

	// normalForLoop(datas);
	// normalForLoopCallSizeOnce(datas);
	iteratorTest(datas);
	iteratorCallCEndOnce(datas);
	//qtForeach(datas);
	//stdForeach(datas);
	rangeForLoop(datas);
	rangeForLoopReference(datas);
	// vector<int> 100 * 1000 * 1000 times, debug & release:
	// normalForLoop use time: 1096 ms                   normalForLoop use time: 113 ms
	// normalForLoopCallSizeOnce use time: 926 ms        normalForLoopCallSizeOnce use time: 106 ms
	// iterator use time: 1941 ms                        iterator use time: 103 ms
	// iteratorCallCEndOnce use time: 1473 ms            iteratorCallCEndOnce use time: 101 ms
	// qtForeach use time: 1846 ms                       qtForeach use time: 262 ms
	// stdForeach use time: 1488 ms                      stdForeach use time: 120 ms
	// rangeForLoop use time: 1527 ms                    rangeForLoop use time: 101 ms
	// rangeForLoopReference use time: 1551 ms           rangeForLoopReference use time: 102 ms

	// list<double> 10 * 1000 * 1000 times, debug & release:
	// iterator use time: 206 ms                         iterator use time: 27 ms
	// iteratorCallCEndOnce use time: 183 ms             iteratorCallCEndOnce use time: 26 ms
	// qtForeach use time: 1493 ms                       qtForeach use time: 743 ms
	// stdForeach use time: 182 ms                       stdForeach use time: 27 ms
	// rangeForLoop use time: 186 ms                     rangeForLoop use time: 26 ms
	// rangeForLoopReference use time: 186 ms            rangeForLoopReference use time: 27 ms
}

int main_CycleTimeTst()
{
	// vector支持随机访问, 但无通用性, 当采用list后, 就不能再使用了, 不可取.
	// 迭代器与范围for循环所用时间无明显差异, qt提供的foreach显然是最差的方法, std算法for_each也还可以接受, 但范围for循环好看得多, 更好用啊!
	// 在循环中调用调用cend方法, 会频繁创建一个新的迭代器(不停的构造与析构), 另外还有函数调用开销.
	// 在debug版本结果来看似乎确实有一定的影响, 但在realease版本下所花时间几乎相等, 也许编译器有优化吧!
	CycleTimeTst cycleTimeTst;
	return 0;
}