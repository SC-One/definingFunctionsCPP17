#include<iostream>
#define secondDemonsionSizeOfMarks 5
double sumMarks(const double numbers[][secondDemonsionSizeOfMarks],const size_t *row);
int main()
{
    double marks[][secondDemonsionSizeOfMarks] {
                                                 {1,2,3,4,5}
                                                ,{6,7,8,9,10}
                                                ,{11,12,13,14,15}
                                               };
    size_t row =  sizeof marks / sizeof marks[0];
    std::cout<<sumMarks(marks,&row)<<std::endl;
    return 0;
}


double sumMarks(const double numbers[][secondDemonsionSizeOfMarks],const size_t *row)
{
    double sum{};
    for(size_t i=0;i<(*row);i++)
        for(auto& val:numbers[i])
            sum+=val;
    return sum;
}
