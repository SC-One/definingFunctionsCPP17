#include<iostream>
#include<iomanip>
double customePowMath(double x,int y);
int main()
{
    for(int i{-3};i<3;++i)
    {
        std::cout<<std::setw(12)<<customePowMath(8,i);
        if(i%2==0)
            std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}


double customePowMath(double x,int y)
{
    if(y==0) return 1.0;
    if(y>0) return x*(customePowMath(x,y-1));
    if(y<0) return 1/(customePowMath(x,-y));
}
