#include<iostream>
#include<map>			//ʹ�ù���ʽ����
using namespace std;

template<typename T1,typename T2>
ostream& operator<< (ostream& os, const map<T1, T2> mp) {
	if (mp.empty())
	{
		os << "map�����ǿյ�" << endl;
	}
	for (auto e:mp)
	{
		os << e.first << "\t" << e.second << endl;
	}
	/*os << endl;*/
	return os;
}

template<typename T>
void out(T mm) {
	for (auto p:mm)
	{
		cout << p.first << "	" << p.second << endl;
	}

}
//map������ʹ��
void test() {
	//map<ģ�����1��ģ�����2>  ������
	map<int, string> m;

	//����һ������
	//m.insert()
	pair<int, string> p(144, "С��Į");
	//cout << p.first << endl;
	//cout << p.second << endl;

	m.insert(p);
	cout << m;
	m.insert(pair<int, string>(87, "�wо"));
	cout << m;

	m.insert(make_pair(98, "��ŭС��"));
	cout << m;
	cout << "------------------------------------------------------------------" << endl;

	//ʹ�÷�Χforѭ������map�ڵ�����
	for (auto p:m)
	{
		cout << p.first << "	" << p.second /*<< endl*/<<"	";
	}
	cout << endl;

	cout << "------------------------------------------------------------------" << endl;
	cout << m;

	m.insert({ 48,"��ԧ" });
	cout << m;

	m.insert({ 48,"Ԭ�ý�" });
	cout << m;
	cout << "�Զ���ĺ�����\n";
	out(m);
}

void test2() {
	//ʹ�ó�ʼ���б���г�ʼ��
	map<string, int> m = {
		{"alpha",9},{"beta",233},{"gamma",26}
	};
	out(m);
	cout /*<< endl*/ << "______________________________________" << endl;
	cout /*<< endl*/ << m /*<< endl*/;
	cout << "--------------------------------------" << endl;
	for (auto e:m )
	{
		cout << e.first << "\t" << e.second << endl;
	}
	cout << "--------------------------------------" << endl;

	m["234"] = 456;
	m["alpha"] = 89;
	cout << m;
	try
	{
		m.at("234") = 989;
		cout << m;
		m.at("ytj") = 8848;
		cout << m;
	}
	catch (const std::exception&p)
	{
		cout << p.what() << endl;
	}

}

void test3() {
	map<int, string> m = {
		{41,"��ԧ"},
		{42,"С����"},
		{144,"С��Į"},
		{19,"����"},
		{87,"�wо"},
		{140,"���"}
	};
	cout << m << endl;
	m.insert({ 126,"С��" });
	cout << m << endl;
	m.erase(40);
	cout << m << endl;

	auto iter = m.find(87);
	//find����ͨ��key��ֵѰ�ҵ������������ڷ���end��
	if (iter==m.end())
	{
		cout << "��key��ֵ������" << endl;
		return;
	}
	else
	{
		cout << iter->first << " " << iter->second << endl;
	}
	try
	{
		m.at(141);
	}
	catch (const std::exception&p)
	{
		cout << p.what() << endl;
	}
}
void test4() {
	map<int, string> m{
		{0,"��"},{1,"һ"},{2,"��"},{3,"��"},{4,"��"}
	};
	auto iter = m.begin();
	cout << iter->first << " " << iter->second << endl;
	
	for (auto i = m.rbegin(); i !=m.rend(); i++)
	{
		cout << i->first << ":" << i->second << endl;
	}
}
int main() {
	test4();
	system("pause");
	return 0;
}