#include<iostream>
double aroundRect(const double &width, const double &length);
int main()
{
    double a,b;
    std::cout<<"Insert width and length: ";
    std::cin>>a>>b;
    std::cout<<"Result: "<<aroundRect(a,b)<<std::endl;
    return 0;
}
double aroundRect(const double &width, const double &length)    // three advantage in this func:
{                                                               // 1.you can use const in parameters (too) when using that function!
    double result{2*width+2*length};                            // 2.when you dont modify arguments then const is better
    return result;                                              // 3.dont need copy paramters ! save memory and time
}
