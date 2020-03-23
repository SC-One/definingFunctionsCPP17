#include<iostream>
void changeNumberByRefrence(double &value);
void changeNumberByPointer(double *value);
int main()
{
    double value{100};
    std::cout<<"Before passing to function by refrence: "<<value<<std::endl;
    changeNumberByRefrence(value);
    std::cout<<"After passing to function by refrence: "<<value<<std::endl;


    value=100;
    std::cout<<"Before passing to function by pointer: "<<value<<std::endl;
    changeNumberByPointer(&value);
    std::cout<<"After passing to function by pointer: "<<value<<std::endl;


    // no diffrence between them. just pointer notation
    // in "By pointer" is superflous.
    return 0;
}
void changeNumberByRefrence(double &value)
{
    value+=20;
    return;
}

void changeNumberByPointer(double *value)
{
    (*value)+=20;
    return;
}
