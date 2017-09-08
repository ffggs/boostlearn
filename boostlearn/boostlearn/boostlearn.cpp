// boostlearn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string\StringTest.h"

#include <boost/random.hpp>
#include <time.h>
#include <windows.h>
int randomInt()
{
	Sleep(1000 * 2);
	boost::mt19937 randomGen(time(NULL));
	boost::uniform_int<> randomHours(0, 100);
	return randomHours(randomGen);
}

int _tmain(int argc, _TCHAR* argv[])
{
// 	int iRlt = randomInt();
// 	int iRlt2 = randomInt();
// 	int iRlt3 = randomInt();
// 	int iRlt4 = randomInt();

	int iNum = 12;
	float fNum = 12.3;
	char* pTest = "hello test";
	char szBuff[MAX_PATH] = {};

	sprintf_s(szBuff, "%%d %d \n%%05d %05d \n%%-05d %-05d\n%%x %x\n%%5X %5X \n%%.5f %.5f", iNum,iNum,iNum,iNum,iNum,fNum);


	NSStringTest::test();
	return 0;
}

