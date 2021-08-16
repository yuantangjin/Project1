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
	//deque<��������> ������
	deque<int> dq;			//˫�˶���
	deque<int> dq2(10);		//��ʼ������Ϊ10
	deque<int> dq3(10, 6);	// 6 6 6 6 6 6 6 6 6 6
	//ʹ�ó�ʼ���б���г�ʼ��
	deque<float> dq4{1.2, 10.45, 324, 43, 234.3};

	cout << dq4;
	//ͷ����������
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
	
	//����sort������������
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

	//���������
	deque<int>::reverse_iterator riter;
	for (auto i = dq.rbegin(); i != dq.rend(); i++)
	{
		cout << *i << " ";
		//*i = 9;
		//cout << *i << " ";
		//cout << endl;
	}
	cout << endl;
	
	//����������
	deque<int>::const_iterator citer;
	for (auto i = dq.cbegin(); i != dq.cend(); i++)
	{
		
		cout << *i << " ";
	}
	cout << endl;

	//�������������
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
	list<int> li;      //˫������ĳ�ʼ��
	list<int> li1(10);
	list<int> li2(10, 6);
	list<int> li3 = { 1,23,35,434,56,534,23,5 };

	cout << li3;
	li.push_back(32);
	li.push_front(23);
	cout << li;
	
	//list���м�ɾ�����ݵ�Ч�ʷǳ���
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
		cout << "i��ֵ��" << i << endl;
		cout << p.what();
	}
	cout << "��������������" << endl;

}

bool _Istwo(int val) {
	//cout << val << "  ";
	return val / 10 == 2 || val % 2 == 0;
}
void test5() {
	//list��֧���������Ԫ��
	list<int> li = { 2,32,22,3,42,32,33,3,2,34,22,24,82,23,23,53,29 };
	//��֧���±��������Ԫ��
	//li[0];

	//list�ĵ�����Ҳ����ֱ�ӵĽ��мӼ�����
	auto it = li.begin();
	//it++;
	for (auto e:li)
	{
		cout << e << " ";
	}
	cout << endl;

	li.sort();				//list�е����򣬱���ʹ�����Դ���������
	cout << li;             //sort�Դ��������ܣ��ײ�ʹ�õ��ǹ鲢����
	//list��������ʹ�����Դ���������
	//sort(li.begin(), li.end());

	li.remove(2);//ɾ��list�е����е�2
	cout << li;
	
	//��������һ��������������
	//li.remove_if(_Istwo);
	//cout << li << endl;
	//ȥ�������ظ���Ԫ�أ��������ظ������ݲ��ᱻȥ��
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