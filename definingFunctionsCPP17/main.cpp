#include<iostream>
const auto &largerBoth(const double& s1,const double &s2) // compiler dont use const auto & , you should explicitly write it!
{
    return (s1>s2?s1:s2);
}

int main()
{
    std::cout<<largerBoth(10,20)<<std::endl;
    return 0;
}
