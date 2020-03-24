#include<iostream>
using std::cout;
using std::endl;
void changeIt(double& it);
void printIt(const double& it);

int main()
{
    double doub{1379.1};
    changeIt(doub);
    printIt(doub);
    int integ{1379};
//    changeIt(integ);          //It occure an error : no matching for call of changeIt
    printIt(integ);
    return 0;
}

void changeIt(double& it)
{
    it-=4;
}

void printIt(const double& it)
{
    cout<<it<<endl;
}
