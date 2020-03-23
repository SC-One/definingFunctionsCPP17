#include<iostream>
void changeNumber(double &value);
int main()
{
    double value{100};
    std::cout<<"Before passing to function by refrence: "<<value<<std::endl;
    changeNumber(value);   // just need its name , not address!
    std::cout<<"After passing to function by refrence: "<<value<<std::endl;
    return 0;
}
void changeNumber(double &value) // same to passing by pointer !
{                                // but it have one advantage!
    value+=20;                   // we dont need pointer notation and when use it in main
    return;                      // dont need send its address! just name Of variable need.
}
