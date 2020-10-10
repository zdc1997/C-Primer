#include "testtime.h"
#include <iostream>
#include <stdlib.h>

void QuickTest::setLimitTime(int millisecond)
{
	if(millisecond > 0)
	{
		_limitTime = millisecond;
	}
	else
	{
		_limitTime = 1;
	}
}

/*!
 * \brief SetUp 获取测试起始时间;
 *
 * \return void
 *
 * \author LiuPei
 * \date 2018/09/19 16:39
 * \note
 *
 */
void QuickTest::SetUp()
{
	//_starttime = time(NULL);
	_starttime = clock();
	_processTimer = _starttime;
}

/*!
 * \brief TearDown 计算起始时间与终止时间之差;
 *
 * \return void
 *
 * \author LiuPei
 * \date 2018/09/19 16:40
 * \note 若时间大于5毫秒，则给出相关断言;
 *
 */
void QuickTest::TearDown()
{
	//const time_t _endtime = time(NULL);
	const clock_t _endtime = clock();

	_endtime - _starttime <= _limitTime;

	cout << "the time is too long and exceed " << _limitTime << " millisecond!" << endl;
}

void QuickTest::startProcessTimmer()
{
	_processTimer = clock();
}

int QuickTest::outPutTimeConsuming(const string &description, string &normal_time)
{

	const clock_t _endtime = clock();
	int totals = _endtime - _processTimer;
	int totals_clocks = totals;
	long millisecond = totals % 1000;
	totals = totals / 1000;
	long second = totals % 60;
	long minute = totals / 60;

	cout << description << ",Total time :" << minute << " minute " << second << " second " << millisecond << " millisecond \r\n";

//  char secondString;
//  itoa(second, &secondString, 10);
//  char millisecondString;
//  itoa(millisecond, &millisecondString, 10);
//
//  normal_time = minute + "minutes";
//  normal_time.append(&secondString);
//  normal_time += "second";
//  normal_time.append(&millisecondString);
//  normal_time += "millisecond";

	return totals_clocks;
}


int main()
{
	string test;
	QuickTest t;
	t.outPutTimeConsuming("now", test);
}