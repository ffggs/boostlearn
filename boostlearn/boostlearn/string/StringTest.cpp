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
	//���ܣ��ַ����ָ�
	//split����ֻ��Ҫ����<boost/algorithm/string.hpp> ͷ�Ϳ���
	//˵��������3��һ������boolֵ�ĺ������������true����зָ�
	//����4������������ŵ������true�����Ƿ���зָĬ���ǻ���зָ
	�ò��������ڿ����Ƿ���Ҫ���ؿ��ִ���Ĭ�ϻᣬ����Ϊboost::algorithm::token_compress_on�Ͳ���
	*/
	string strSplit = "hello;this;is;;;test";
	vector<string> vec,vec2;
	boost::algorithm::split(vec, strSplit, boost::is_any_of(";"));
	boost::algorithm::split(vec2, strSplit, boost::is_any_of(";"), boost::algorithm::token_compress_on);
	cout << "token_copress_off,result size:" << vec.size();
	cout << "token_copress_on,result size:" << vec2.size();

	/*
	�ַ����������ù��ܣ�
	cat��copy��replace,find,��Сдת������ʽ��
	*/
	//boost::format ����printf�������ʽ��ͬʱ֧���µĸ�ʽ��
	//ע�⣺format�����һ������Ϊlocale,�����������󣬽��齫������Ϊstd::locale("C"),����1234��ʽ��Ϊ�ַ������ܱ�Ϊ 1,234
	/*
	���� ����
	����������������������������������������������������
	%d ʮ�����з�������
	%u ʮ�����޷�������
	%f ������
	%s �ַ���
	%c �����ַ�
	%p ָ���ֵ
	%e ָ����ʽ�ĸ�����
	%x, %X �޷�����ʮ�����Ʊ�ʾ������
	%o �޷����԰˽��Ʊ�ʾ������
	%g �Զ�ѡ����ʵı�ʾ��
	%p �����ַ�� ͬ%x
	����������������������������������������������������
	˵��:
	(1). ������"%"����ĸ֮�������ֱ�ʾ��󳡿�
	����: %3d ��ʾ���3λ������, ����3λ�Ҷ��롣
	%9.2f ��ʾ�������Ϊ9�ĸ�����, ����С��λΪ2, ����λΪ6,
	С����ռһλ, ����9λ�Ҷ��롣
	%8s ��ʾ���8���ַ����ַ���, ����8���ַ��Ҷ��롣
	����ַ����ĳ��ȡ���������λ������˵���ĳ���, ������ʵ�ʳ��������
	���Ը�����, ����������λ��������˵��������λ���, ����ʵ������λ���;
	��С������λ��������˵����С��λ���, ��˵���Ŀ�����������������
	����, ���������ֵǰ��һЩ0, ��Ӧ�ڳ�����ǰ�Ӹ�0��
	����: %04d ��ʾ�����һ��С��4λ����ֵʱ, ����ǰ�油0ʹ���ܿ��Ϊ4λ��
	����ø�������ʾ�ַ����������������ʽ, С���������ִ��������,
	С����ǰ�����ִ�����С��ȡ�
	����: %6.9s ��ʾ��ʾһ�����Ȳ�С��6�Ҳ�����9���ַ�����������9, ��
	��9���ַ��Ժ�����ݽ���ɾ����
	(2). ������"%"����ĸ֮���Сд��ĸl, ��ʾ������ǳ�������
	����: %ld ��ʾ���long����
		  %lf ��ʾ���double������
	(3). ���Կ�������������Ҷ���, ����"%"����ĸ֮�����һ��"-" �ſ�˵�����Ϊ�����, ����Ϊ�Ҷ��롣
	����: %-7d ��ʾ���7λ���������
		  %-10s ��ʾ���10���ַ������
	*/
	int iNum = 12345678;
	string strTmp1 = "12";
	boost::format fmt = boost::format("%s,%4d,%4x,%.4f,%-5d,%3.5s", std::locale("C")) % iNum % iNum % iNum % (float)iNum % iNum % strTmp1;
	string strTmp = fmt.str();
	fmt = boost::format("%1% %2% %3%",std::locale("C")) % 123 % 234 % "yess";
	strTmp = fmt.str();

	//std find.string�����find���ܽ��������Сд����
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