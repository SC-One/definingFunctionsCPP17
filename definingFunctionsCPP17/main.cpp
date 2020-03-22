#include<iostream>
double averageNumbers(const double array[],const size_t lengthNumbers);
int main()
{
    double marks[] {1,2,3,4,5,6,7,8,9,10};
    size_t size=sizeof (marks)/sizeof (marks[0]);
    std::cout<<averageNumbers(marks,size)<<std::endl;
    return 0;
}

double averageNumbers(const double array[],const size_t lengthNumbers)
{
    double sum{};
    for (size_t i=0;i<lengthNumbers;i++)
    {
        sum+=array[i];
    }
    sum/=lengthNumbers;
    return sum;
}
