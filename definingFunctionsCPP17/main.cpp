#include<iostream>
void changeValueOutSide(double *valueToChange); // prototype function
int main()
{
    double n{9.0};
    changeValueOutSide(&n);     // pass paramter by pointer
                                // it send copy of &n
                                // and we work on that address
                                // thus we change original value
    std::cout<<"result of function: "<<n<<std::endl;
    return 0;
}

void changeValueOutSide(double *value) //function header
{
    *value+=100;
    return;
}
