#include<iostream>
double changeValueOutSide(double valueToChange);
int main()
{
    double n{1.0},result{};
    std::cout<<"n before exec function: "<<n<<std::endl;
    changeValueOutSide(n);
    std::cout<<"n after exec function: "<<n<<std::endl; // when by value function exec
                                                        // that dont change values. (copy passed to function)


    result=changeValueOutSide(n);
    std::cout<<"result of function: "<<result<<std::endl;


    return 0;
}

double changeValueOutSide(double value)
{
    value+=100;
    return value;
}
