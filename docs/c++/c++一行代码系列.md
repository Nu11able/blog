# c++一行代码系列
`用于记录学习c++过程中的一些骚操作(主要是stl的使用)，当然也不一定非得是一行代码`

## 一行代码实现不定量数据的输入输出
```cpp
#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>

int main() {
    vector<int> con;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(con));
    copy(con.begin(), con.end(), ostream_iterator<int>(cout, " "));
    copy(con.begin(), con.end(), ostream_iterator<int>(cout, "-"));
    return 0;
}
/* 运行样例
输入：1 2 3 4 5 6^D
输出：1 2 3 4 5 6 1-2-3-4-5-6-
*/
```


## 一行代码实现特定数据的统计
```cpp
#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>
#include<functional>

using namespace std;

int main() {
    vector<int> con{12, 20, 40, 23, 28, 17, 65, 88, 25, 23};
    
    cout << "Count of 23: " << count(con.begin(), con.end(), 23) << endl;
    cout << "Count if value > 23: " << count_if(con.begin(), con.end(), bind(greater<int>(), placeholders::_1, 23)) << endl; // c++11
    cout << "Count if value > 23: " << count_if(con.begin(), con.end(), bind2nd(greater<int>(), 23)) << endl; // c++99
    // 输出所有奇数
    cout << "All odd numbers: ";
    copy_if(con.begin(), con.end(), ostream_iterator<int>(cout, " "), bind(modulus<int>(), placeholders::_1, 2));
    cout << endl;

    // 输出所有偶数
    cout << "All even numbers: ";
    copy_if(con.begin(), con.end(), ostream_iterator<int>(cout, " "), bind(logical_not<int>(), bind(modulus<int>(), placeholders::_1, 2)));
    cout << endl;

    // 输出所有大于20小于50的数
    cout << "All numbers between 20 and 50: ";
    copy_if(con.begin(), con.end(), ostream_iterator<int>(cout, " "), 
        bind(logical_and<bool>(), bind(greater<int>(), placeholders::_1, 20), bind(less<int>(), placeholders::_1, 50)));
    cout << endl;

    // 输出所有大于23的奇数
    cout << "All odd numbers which is grater than 23: ";
    copy_if(con.begin(), con.end(), ostream_iterator<int>(cout, " "), 
        bind(logical_and<bool>(), bind(modulus<int>(), placeholders::_1, 2), bind(greater<int>(), placeholders::_1, 23)));
    cout << endl;

    // 输出所有大于23的偶数
    cout << "All even numbers which is grater than 23: ";
    copy_if(con.begin(), con.end(), ostream_iterator<int>(cout, " "), 
        bind(logical_and<bool>(), bind(logical_not<int>(), bind(modulus<int>(), placeholders::_1, 2)), bind(greater<int>(), placeholders::_1, 23)));
    cout << endl;
    return 0;
}
/* 运行样例
输出:
Count of 23: 2
Count if value > 23: 5
Count if value > 23: 5
All odd numbers: 23 17 65 25 23
All even numbers: 12 20 40 28 88
All numbers between 20 and 50: 40 23 28 25 23
All odd numbers which is grater than 23: 65 25
All even numbers which is grater than 23: 40 28 88
*/
```

## 一行代码遍历容器并做相应的修改
```cpp
#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>
#include<functional>
#include<string>

using namespace std;

template<typename T = int, typename containerType = vector<T>>
void PrintHelper(const char *str, containerType &container) {
    cout << str << ": ";
    copy(container.begin(), container.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

template<typename T = int>
void PrintHelper(const char *str, const T &value) {
    cout << str << ": " << value << endl;
}

int main() {
    vector<int> container1{12, 20, 40, 23, 28, 17, 65, 88, 25, 23};
    vector<int> container2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintHelper("Container1(x1)", container1);
    PrintHelper("Container2(x2)", container2);

    // 将container1中的每个数字翻倍
    transform(container1.begin(), container1.end(), container1.begin(), bind2nd(multiplies<int>(), 2));
    PrintHelper("After (x1*2)", container1);
    
    // 将container1和container2中相同下标的数字相除
    vector<float> temp(container1.size()); // 通过阅读transform源码保存结果的数组大小需要提前开辟好
    // transfrom中指定的计算长度中container1 <= container2
    transform(container1.begin(), container1.end(), container2.begin(), temp.begin(), divides<int>());
    PrintHelper<float>("After (x1/x2)", temp);
    transform(container1.begin(), container1.end(), container2.begin(), temp.begin(), divides<float>());
    PrintHelper<float>("After (x1/x2)", temp);
    return 0;
}
/* 运行样例
Container1(x1): 12 20 40 23 28 17 65 88 25 23 
Container2(x2): 1 2 3 4 5 6 7 8 9 10 
After (x1*2): 24 40 80 46 56 34 130 176 50 46 
After (x1/x2): 24 20 26 11 11 5 18 22 5 4 
After (x1/x2): 24 20 26.6667 11.5 11.2 5.66667 18.5714 22 5.55556 4.6
*/
```