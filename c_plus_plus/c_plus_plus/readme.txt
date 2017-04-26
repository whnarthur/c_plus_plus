在使用g++编译时会出现如下错误：
test.cpp: In function ‘int main()’:
test.cpp:28: 错误：将 ‘const A’ 作为 ‘std::string A::ToString()’ 的 ‘this’ 实参时丢弃了类型限定
出现错误的原因是因为STL在指向set的内容时为const类型（是不可更改的），所以strset.begin()其实对应的是一个const A类型，而ToString()方法不能保证这strset.begin()所指向的内容不被改变。因此，应当将此ToString()方法显式声明为const方法，通知编译器此方法不会改变A的内容。修改后的class A:
class A
{
public:
string m_str;
A(string str){m_str = str;}
string ToString() const {return m_str;}
bool operator<(const A &rhs) const {return true;}
};

