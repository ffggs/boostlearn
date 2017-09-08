#include "StringTest.h"
//#include <boost/tokenizer.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/hex.hpp>
#include <boost/format.hpp>
#include <iostream>


using namespace std;
NAMESPACE_BEGIN(NSStringTest)

void test()
{

	/*
	//功能：字符串分割
	//split函数只需要包含<boost/algorithm/string.hpp> 头就可以
	//说明：参数3是一个返回bool值的函数，如果返回true则进行分割
	//参数4是如果两个挨着的项都返回true，则是否进行分割，默认是会进行分割。
	该参数是用于控制是否需要返回空字串，默认会，设置为boost::algorithm::token_compress_on就不会
	*/
	string strSplit = "hello;this;is;;;test";
	vector<string> vec,vec2;
	boost::algorithm::split(vec, strSplit, boost::is_any_of(";"));
	boost::algorithm::split(vec2, strSplit, boost::is_any_of(";"), boost::algorithm::token_compress_on);
	cout << "token_copress_off,result size:" << vec.size();
	cout << "token_copress_on,result size:" << vec2.size();

	/*
	字符串操作常用功能：
	cat，copy、replace,find,大小写转换，格式化
	*/
	//boost::format 兼容printf的输出格式，同时支持新的格式。
	//注意：format的最后一个参数为locale,如无特殊需求，建议将其设置为std::locale("C"),否则1234格式化为字符串可能变为 1,234
	/*
	符号 作用
	——————————————————————————
	%d 十进制有符号整数
	%u 十进制无符号整数
	%f 浮点数
	%s 字符串
	%c 单个字符
	%p 指针的值
	%e 指数形式的浮点数
	%x, %X 无符号以十六进制表示的整数
	%o 无符号以八进制表示的整数
	%g 自动选择合适的表示法
	%p 输出地址符 同%x
	━━━━━━━━━━━━━━━━━━━━━━━━━━
	说明:
	(1). 可以在"%"和字母之间插进数字表示最大场宽。
	例如: %3d 表示输出3位整型数, 不够3位右对齐。
	%9.2f 表示输出场宽为9的浮点数, 其中小数位为2, 整数位为6,
	小数点占一位, 不够9位右对齐。
	%8s 表示输出8个字符的字符串, 不够8个字符右对齐。
	如果字符串的长度、或整型数位数超过说明的场宽, 将按其实际长度输出。
	但对浮点数, 若整数部分位数超过了说明的整数位宽度, 将按实际整数位输出;
	若小数部分位数超过了说明的小数位宽度, 则按说明的宽度以四舍五入输出。
	另外, 若想在输出值前加一些0, 就应在场宽项前加个0。
	例如: %04d 表示在输出一个小于4位的数值时, 将在前面补0使其总宽度为4位。
	如果用浮点数表示字符或整型量的输出格式, 小数点后的数字代表最大宽度,
	小数点前的数字代表最小宽度。
	例如: %6.9s 表示显示一个长度不小于6且不大于9的字符串。若大于9, 则
	第9个字符以后的内容将被删除。
	(2). 可以在"%"和字母之间加小写字母l, 表示输出的是长型数。
	例如: %ld 表示输出long整数
		  %lf 表示输出double浮点数
	(3). 可以控制输出左对齐或右对齐, 即在"%"和字母之间加入一个"-" 号可说明输出为左对齐, 否则为右对齐。
	例如: %-7d 表示输出7位整数左对齐
		  %-10s 表示输出10个字符左对齐
	*/
	int iNum = 12345678;
	string strTmp1 = "12";
	boost::format fmt = boost::format("%s,%4d,%4x,%.4f,%-5d,%3.5s", std::locale("C")) % iNum % iNum % iNum % (float)iNum % iNum % strTmp1;
	string strTmp = fmt.str();
	fmt = boost::format("%1% %2% %3%",std::locale("C")) % 123 % 234 % "yess";
	strTmp = fmt.str();

	//std find.string本身的find不能进行区别大小写查找
	string strTestFind = "test1 lol hello string";
	size_t sz = strTestFind.find("llo");
	size_t sz2 = strTestFind.rfind("llo");

	//
	boost::iterator_range<string::iterator> itFind = boost::algorithm::find_first(strTestFind, "llo");
	if (itFind.empty())
	{
		cout << "find no item" << endl;
	}
	else{
		string strTmp(itFind.begin(),itFind.end());
		cout << "find rlt:" << strTmp<<endl;
	}

	string strHex = "TEST";
	string strRlt;
	strRlt.resize(strHex.size() * 2);
	boost::algorithm::hex(strHex, strRlt.begin());
	return;
}

NAMESPACE_END()