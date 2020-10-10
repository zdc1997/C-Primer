/*!
 * \file timetest.h
 * \date 2020/09/19 16:11
 * \author Zdec
 * \contact liup@southgnss.com;
 *
 * \brief 测试算法时间复杂度;
 *
 * TODO: to test the time consuming of the algorithm;
 *
 * \note
 */

#ifndef _TIMETEST_H_
#define _TIMETEST_H_

#include <time.h>
#include <limits.h>
#include <string>

using namespace std;
/*!
 * \class QuickTest
 * \date 2018/09/19 16:19
 * \author LiuPei
 * \contact liup@southgnss.com;
 *
 * \brief 声明并定义时间复杂度测试类;
 *
 * TODO: We put the code for timing a test in a test fixture called
 * "QuickTest".  QuickTest is intended to be the super fixture that
 * other fixtures derive from, therefore there is no test case with
 * the name "QuickTest".  This is OK.
 *
 * \note
 */

class QuickTest
{
public:
	void setLimitTime(int millisecond);
private:
	//time_t _starttime;
	clock_t _starttime;
	int _limitTime = 1000;
protected:
	virtual void SetUp();
	virtual void TearDown();

public:
	clock_t _processTimer;
	/*!
	 * \brief:重新启动过程计时器
	 */
	virtual void startProcessTimmer();
	/*!
	* \brief:输出耗时
	*/
	virtual int outPutTimeConsuming(const string &description, string & normal_time);
};
#endif //!_TIMETEST_H_