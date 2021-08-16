#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<algorithm>
using namespace std;
template<typename T>
ostream& operator<<(ostream& os, const deque<T> dp) {
	for (auto e:dp)
	{
		os << e << " ";
	}
	os << endl;
	return os;
}
void test1() {
	//deque<数据类型> 变量名
	deque<int> dq;			//双端队列
	deque<int> dq2(10);		//初始化长度为10
	deque<int> dq3(10, 6);	// 6 6 6 6 6 6 6 6 6 6
	//使用初始化列表进行初始化
	deque<float> dq4{1.2, 10.45, 324, 43, 234.3};

	cout << dq4;
	//头部插入数据
	dq3.push_front(7);
	cout << dq3;
	dq3.push_back(45);
	cout << dq3;

	dq3.pop_back();
	cout << dq3;
	dq3.pop_front();
	cout << dq3;


}
void test2() {
	vector<short> vec;
	cout << vec.size() << endl;

	cout << vec.capacity() << endl;

	for (int i = 0; i < 20; i++)
	{
		vec.push_back(i);
		cout << "size:" << vec.size() << "\tcapacity:" << vec.capacity() << endl;
	}
	while (!vec.empty())
	{
		vec.pop_back();
		vec.shrink_to_fit();
		cout << "size:" << vec.size() << "\tcapacity:" << vec.capacity() << endl;
	}

	vec.resize(50);
	cout << "size:" << vec.size() << "\tcapacity:" << vec.capacity() << endl;

	for (int i = 0; i < 50; i++)
	{
		vec.push_back(i);
		cout << "size:" << vec.size() << "\tcapacity:" << vec.capacity() << endl;
	}
	vec.resize(20);
	cout << "size:" << vec.size() << "\tcapacity:" << vec.capacity() << endl;

	for (int i = 0; i < 50; i++)
	{
		vec.push_back(i);
		cout << "size:" << vec.size() << "\tcapacity:" << vec.capacity() << endl;
	}
}
void test3() {
	deque<int> dq = { 1,2,3,54,2,2,1,23,35,32,45,657,86,65 };
	
	//调用sort函数进行排序
	sort(dq.begin(), dq.end());
	cout << dq;
	
	auto e = find(dq.begin(), dq.end(), 54);
	cout << "[" << e - dq.begin() << "]" << "=" << *e << endl;

	deque<int>::iterator iter = dq.begin();
	for (auto i = dq.begin(); i != dq.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	//反向迭代器
	deque<int>::reverse_iterator riter;
	for (auto i = dq.rbegin(); i != dq.rend(); i++)
	{
		cout << *i << " ";
		//*i = 9;
		//cout << *i << " ";
		//cout << endl;
	}
	cout << endl;
	
	//常量迭代器
	deque<int>::const_iterator citer;
	for (auto i = dq.cbegin(); i != dq.cend(); i++)
	{
		
		cout << *i << " ";
	}
	cout << endl;

	//常量反向迭代器
	deque<double>::const_reverse_iterator criter;
	for (auto i = dq.crbegin(); i != dq.crend(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template<typename T>
ostream& operator<<(ostream& os, const list<T> dp) {
	for (auto e:dp)
	{
		os << e << " ";
	}
	os << endl;
	return os;
}
struct rom {
	char r[1024];
};
void test4() {
	list<int> li;      //双向链表的初始化
	list<int> li1(10);
	list<int> li2(10, 6);
	list<int> li3 = { 1,23,35,434,56,534,23,5 };

	cout << li3;
	li.push_back(32);
	li.push_front(23);
	cout << li;
	
	//list从中间删除数据的效率非常高
	list<rom> vec;
	int i;
	try
	{
		for (i = 0; i < 1 * 1024 * 1024; i++)
		{
			vec.push_back(rom());
			//cout << vec.size() << endl;
		}
	}
	catch (const std::exception&p)
	{
		cout << "i的值：" << i << endl;
		cout << p.what();
	}
	cout << "程序正常结束！" << endl;

}

bool _Istwo(int val) {
	//cout << val << "  ";
	return val / 10 == 2 || val % 2 == 0;
}
void test5() {
	//list不支持随机访问元素
	list<int> li = { 2,32,22,3,42,32,33,3,2,34,22,24,82,23,23,53,29 };
	//不支持下标随机访问元素
	//li[0];

	//list的迭代器也不能直接的进行加减操作
	auto it = li.begin();
	//it++;
	for (auto e:li)
	{
		cout << e << " ";
	}
	cout << endl;

	li.sort();				//list中的排序，必须使用其自带的排序函数
	cout << li;             //sort自带的排序功能，底层使用的是归并排序
	//list中排序能使用其自带的排序函数
	//sort(li.begin(), li.end());

	li.remove(2);//删除list中的所有的2
	cout << li;
	
	//可以填入一个适配器做参数
	//li.remove_if(_Istwo);
	//cout << li << endl;
	//去除连续重复的元素，不连续重复的数据不会被去除
	list<int> li2 = { 1,2,3,12,2,3,4,4,4,4,5,6,6,5,6,5,6,7 };
	li2.sort();
	li2.unique();
	cout << li2;
}

void test6() {
	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> vec2(vec.begin(), vec.begin() + 5);

	list<int> li(vec.begin(), vec.begin() + 5);
	cout << li;
	cout << endl;

	deque<int> dq(vec.rbegin() + 5, vec.rend());
	cout << dq;
	cout << endl;

}
int main() {
	//test1();
	//test3();
	//test2();
	test6();
	system("pause");
}