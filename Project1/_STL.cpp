#include<iostream>         //��׼��
#include<stdio.h>          //�Ǳ�׼��
#include<typeinfo>
#include"windows.h"        //�Ǳ�׼��
#include<array>			   //˳����ʹ��
#include<stack>
#include<queue>
#include<functional>        //�º���
#include<algorithm>			//�㷨��
#include<memory>			//����ָ��
#include<tuple>
#include<optional>
#include<span>

using namespace std;
void test() {
	auto a = 'k';          //a�Ƶ���char����
	auto b = 3.12;         //double
	auto c = 10.2f;        //float
	auto d = { 1,2,3,4,5,6 };
	//���ֻ����û�и�ֵ�Ļ��Ͳ��ܽ����Ƶ�
	//auto d;
	//new int  ��ʶ���ָ������
	auto pa = new int[10];

	//c++��̬����ʶ��
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(pa).name() << endl;
	cout << typeid(d).name() << endl;

	delete[] pa;
}
//�����ʹ��
void out(int* arr, int n) {
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test2() {
	//C���Ե�����
	int arr[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	//C++������     #include<array>
	array<int, 10> Arr = { 1,2,3,4,5,6,7,8,9,10 };
	arr[0] = 99;
	out(arr, 12);

	//C++����ֱ�ӻ�ȡ���鳤��
	for (size_t i = 0; i < Arr.size(); i++)
	{
		cout << i << " ";
	}
	cout << endl;
}
//ջ�Ͷ���
void test4() {
	//ջ   ����ȳ����Ƚ���� 
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
	//����  �Ƚ��ȳ���������
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
//��������ʹ��
void test5() {
	print({ 1,2,3,4,5,6,7,8,9,10,9,123,89,34,37,56 });


	//�㷨��   #include<algorithm>

	//��������������ֵ
	int a = 15;
	int b = 20;
	int t = a;
	a = b;
	b = t;
	cout << "a=" << a << "	b=" << b << endl;
	//��򽻻�
	a ^= b;
	b ^= a;
	a ^= b;
	cout << "a=" << a << "	b=" << b << endl;
	//ʹ���㷨���еĽ����㷨
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
	cout << "���Ǻ���ָ��Ľ��:" << a - b << endl;
}
//�º���     ����ʵ������fun(��һ��ʵ�����Ķ���)
//function ����fun��ʹ�ü������������Գ�Ϊ�º���
void test6() {
	function<int(int, int)> fun;
	if (!bool(fun))
	{
		cout << "û��ָ���κ����ݣ�" << endl;
	}
	fun = add;
	cout << fun(20, 30) << endl;
	if (bool(fun))
	{
		cout << "��ָ������ݣ�" << endl;
	}

	//����ָ��
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