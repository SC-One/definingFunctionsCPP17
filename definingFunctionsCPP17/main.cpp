#include<iostream>
const double &largerBoth(const double& s1,const double &s2);
int main()
{
    std::cout<<largerBoth(10,20)<<std::endl;
    return 0;
}

const double &largerBoth(const double& s1,const double &s2)
{
    return (s1>s2?s1:s2);
}
