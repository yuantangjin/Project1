#include<iostream>
#include<map>			//使用关联式容器
using namespace std;

template<typename T1,typename T2>
ostream& operator<< (ostream& os, const map<T1, T2> mp) {
	if (mp.empty())
	{
		os << "map里面是空的" << endl;
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
//map容器的使用
void test() {
	//map<模板参数1，模板参数2>  变量名
	map<int, string> m;

	//插入一个数据
	//m.insert()
	pair<int, string> p(144, "小冷漠");
	//cout << p.first << endl;
	//cout << p.second << endl;

	m.insert(p);
	cout << m;
	m.insert(pair<int, string>(87, "眞芯"));
	cout << m;

	m.insert(make_pair(98, "愤怒小鑫"));
	cout << m;
	cout << "------------------------------------------------------------------" << endl;

	//使用范围for循环遍历map内的数据
	for (auto p:m)
	{
		cout << p.first << "	" << p.second /*<< endl*/<<"	";
	}
	cout << endl;

	cout << "------------------------------------------------------------------" << endl;
	cout << m;

	m.insert({ 48,"翼鸳" });
	cout << m;

	m.insert({ 48,"袁堂金" });
	cout << m;
	cout << "自定义的函数：\n";
	out(m);
}

void test2() {
	//使用初始化列表进行初始化
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
int main() {
	test2();
	system("pause");
	return 0;
}