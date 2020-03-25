#include<iostream>

inline const int &larger(const int &m,const int &n)
{
    return (m>n?m:n);
}

int main()
{
    int a{10},b{20};
    std::cout<<larger(a,b)<<std::endl;
    std::cout<<larger(20,30)<<std::endl;
    return 0;
}
