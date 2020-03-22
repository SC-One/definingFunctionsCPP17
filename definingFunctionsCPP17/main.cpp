#include<iostream>

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Prototype functions @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
double powerMath(double value,int exponent); // function prototype
// does not matter what's these names :: Value and Exponent


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Main function      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int main()
{
    std::cout<<powerMath(2,2)<<std::endl;
    std::cout<<powerMath(2,-3)<<std::endl;
    std::cout<<powerMath(-2,2)<<std::endl;
    std::cout<<powerMath(-2,3)<<std::endl;
    std::cout<<powerMath(-1000,0)<<std::endl;
    return 0;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@ function's Header @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
double powerMath(double x,int n)
{
    double result{1};
    if(n<0)
    {
        x=(1/x);
        n*=-1;
    }
    else if(n==0)
    {
        return 1.0;
    }
    for(int i=0;i<n;i++)
        result*=x;
    return result;
}
