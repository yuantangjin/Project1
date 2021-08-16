#include <iostream>
#include<vector>
using namespace std;

//C语言输出
void outArr(int* arr, int n) {
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
    if (vec.empty())
    {
        os << "[]" << endl;
        return os;
    }
    os << "[";
    for (auto e:vec )
    {
        os << e << " ";
    }
    os << "\b]" << endl;
}
//初始化vector
void test() {
    vector<int> vec6;
    cout << vec6;
    //初始化一个vector容器
    vector<int> vec;

    //初始化vector容器，并赋予长度10
    vector<int> vec2(10);
    cout << vec2[0] << endl;
    //输出重载
    vector<int> vec4 = { 1,23,13,35,23,32,64,23,57,7 };
    cout << vec4;

    vector<int> vec5(10,3);
    cout << vec5;
    //通过初始化列表进行初始化
    vector<int> vec3 = { 1,23,13,35,23,32,64,23,57,7 };
    //范围for循环，将容器中的每一个元素都遍历一次
    for (auto e:vec3)
    {
        cout << e <<" ";
    }
    cout << endl;

    //数组的初始化
    int arr[10];
    cout << arr[0] << endl;

    int arr2[10] = { 1,23,13,35,23,32,64,23,57,7 };
    outArr(arr2, 10);
}

void test2() {
    const int n = 10;
    int arr[n];         //数组必须填入一个常量来进行初始化

    //int size;
    //cin >> size;
    //vector<int> vec(size);         //可以通过变量来决定初始化的长度
    //cout << vec << endl;

    vector<int> vec;    //默认长度是0
    vec.push_back(10);
    cout << vec;
    vec.push_back(20);
    cout << vec;
    vec.push_back(30);
    cout << vec;
    cout << "size=" << vec.size() << endl;
    for (auto i=vec.size();!vec.empty();i--)
    {
        cout << vec;
        vec.pop_back();
    }
    vec.resize(10, 5);
    cout << vec;
    vec.resize(5);
    cout << vec;
    vec.resize(10);
    cout << vec;
}
class ABC {
public:
    char c;
    float f32;
    int i32;
};
//迭代器的使用
void test3() {
    int arr[10] = { 1,23,34,53,23,12,32,45,2,31 };
    //指针可以指向一个数组的首地址
    int* parr = arr;
    *parr = 99;
    //for (int i = 0; i < 10; i++)
    //{
    //    cout << parr[i] << " ";
    //}
    //cout << endl;
    outArr(parr, 10);
    cout << endl;
    
    vector<int> vec(10);
    //声明一个迭代器，指向vector的首地址
    vector<int>::iterator iter = vec.begin();
    //迭代器解引用
    *iter = 99;

    cout << vec;
    iter[1] = 100;
    cout << vec;

    //迭代器的偏移操作
    iter += 5;
    *iter = 555;
    //迭代器的遍历
    for (auto it = vec.begin(); it < vec.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    vector<ABC> v(3);
    v[1].c = 'a';
    v[1].f32 = 3.1415;
    v[1].i32 = 12345;

    auto it = v.begin();
    it->c = 'A';
    it->f32 = 10.12;
    it->i32 = 123;

}
//使用vector容器来兼容C语言
void test4() {
    //声明了一个C语言数组
    int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };

    //首地址，尾地址
    vector<int> vec(arr, arr + 10);
    cout << vec;

    //vector 容器返回C语言指针
    vector<int> vec2 = { 9,8,7,6,5,4,3,2,1,0 };
    int* p = vec2.data();
    outArr(p, vec2.size());
}

//使用二维vector
void test5() {
    //创建一个二维的vector，二维的vector可以每个vector的长度不一样
    vector<vector<int>> v2;
    //使用匿名构造插入一个vector
    v2.push_back(vector<int>(10));
    v2.push_back(vector<int>(5));
    //cout << v2;
    for ( auto e:v2)
    {
        for (auto i:e)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;


    //二维数组的初始化
    vector<vector<int>> vec22(10,vector<int>(10,8));
    for (auto e : vec22)
    {
        for (auto i : e)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void test6() {
    vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
    vec.push_back(8);
    cout << vec;
    vec.pop_back();
    cout << vec;

    //从指定位置插入一个元素
    cout << "迭代器初始位置的值：" << *vec.begin();
    vec.insert(vec.begin() + 3, 99);
    cout << endl;
    cout << vec;
    //cout << endl;
}
int main()
{
    test6();
    //test2();
}


