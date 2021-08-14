#include<iostream>         //标准库
#include<stdio.h>          //非标准库
#include<typeinfo>
#include"windows.h"        //非标准库
#include<array>			   //顺序表的使用
#include<stack>
#include<queue>
#include<functional>        //仿函数
#include<algorithm>			//算法库
#include<memory>			//智能指针
#include<tuple>
#include<optional>
#include<span>

using namespace std;
void test() {
	auto a = 'k';          //a推导成char类型
	auto b = 3.12;         //double
	auto c = 10.2f;        //float
	auto d = { 1,2,3,4,5,6 };
	//如果只定义没有赋值的话就不能进行推导
	//auto d;
	//new int  会识别成指针类型
	auto pa = new int[10];

	//c++动态类型识别
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(pa).name() << endl;
	cout << typeid(d).name() << endl;

	delete[] pa;
}
//数组的使用
void out(int* arr, int n) {
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2() {
	//C语言的数据
	int arr[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	//C++的数组     #include<array>
	array<int, 10> Arr = { 1,2,3,4,5,6,7,8,9,10 };
	arr[0] = 99;
	out(arr, 12);

	//C++可以直接获取数组长度
	for (size_t i = 0; i < Arr.size(); i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
//栈和队列
void test4() {
	//栈   后进先出，先进后出 
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	cout << "-----------------------------------------" << endl;
	//队列  先进先出，后进后出
	queue<int> que;
	que.push(10);
	que.push(20);
	que.push(30);
	while (!que.empty())
	{
		cout << que.front() << endl;
		que.pop();
	}
	cout << "-----------------------------------------" << endl;
}
void print(initializer_list<int> init) {
	for (auto i = init.begin(); i != init.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

template<typename T, int T1>
void outArr(array<T,T1> Arr) {
	for (auto i:Arr)
	{
		cout << i << " ";
	}
}
//迭代器的使用
void test5() {
	print({ 1,2,3,4,5,6,7,8,9,10,9,123,89,34,37,56 });


	//算法库   #include<algorithm>

	//交换两个变量的值
	int a = 15;
	int b = 20;
	int t = a;
	a = b;
	b = t;
	cout << "a=" << a << "	b=" << b << endl;
	//异或交换
	a ^= b;
	b ^= a;
	a ^= b;
	cout << "a=" << a << "	b=" << b << endl;
	//使用算法库中的交换算法
	swap(a, b);
	cout << "a=" << a << "	b=" << b << endl;

	int arr[10] = { 12,53,21,29,865,34,235,56,122224,23 };
	sort(arr, arr + 10);
	//for (auto i = arr; i < arr+10; i++)
	//{
	//	cout << *i << " ";
	//}
	//cout << endl;
	out(arr, 10);

	array<int, 10> Arr = { 12,343,545,3,2,75,34,23,432,21 };
	sort(Arr.begin(), Arr.end());
	outArr(Arr);
}

int add(int a, int b) {
	return a + b;
}
void funytj(int a, int b) {
	cout << "这是函数指针的结果:" << a - b << endl;
}
//仿函数     对象实例化：fun(是一个实例化的对象)
//function 对象fun的使用极其像函数，所以称为仿函数
void test6() {
	function<int(int, int)> fun;
	if (!bool(fun))
	{
		cout << "没有指向任何内容！" << endl;
	}
	fun = add;
	cout << fun(20, 30) << endl;
	if (bool(fun))
	{
		cout << "有指向的内容！" << endl;
	}

	//函数指针
	void (*func)(int,int);
	func=funytj;
	func(50, 20);
}
void test7() {

}
int main() {
	//test();
	//printf("hello world");
	//std::cout << "Hello World!\n";
	//test2();
	//test4();

	test6();
	//std::vector<int> srce{ 1, 2, 3, 4 };
	//std::deque<int> dest{ 5, 6, 7, 8 };
	//std::move(std::begin(srce), std::end(srce), std::back_inserter(dest));
	//std::vector<int> data{ 1, 2, 3, 4, 5, 6, 7, 8 };
	//std::move(std::begin(data) + 2, std::end(data), std::begin(data));
	//data.erase(std::end(data) - 2, std::end(data)); // Erase moved elements
	//std::copy(std::begin(data), std::end(data), std::ostream_iterator<int> {std::cout, " "});
	//std::cout << std::endl;
	// 3, 4, 5, 6, 7, 8
}