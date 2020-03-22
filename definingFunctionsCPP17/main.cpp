#include<iostream>
#define secondDemonsionSizeOfMarks 5
double sumMarks(const double numbers[][secondDemonsionSizeOfMarks],const size_t *sizeMarks);
int main()
{
    double marks[][secondDemonsionSizeOfMarks] {
                                                 {1,2,3,4,5}
                                                ,{6,7,8,9,10}
                                                ,{11,12,13,14,15}
                                               };
    size_t row =  sizeof marks / sizeof marks[0];
    size_t col = sizeof marks[0] / sizeof(marks[0][0]);
    size_t size{row*col};
    std::cout<<sumMarks(marks,&size)<<std::endl;
    return 0;
}


double sumMarks(const double numbers[][secondDemonsionSizeOfMarks],const size_t *sizeMarks)
{
    double sum{};
    for(size_t i=0;i<((*sizeMarks)/(secondDemonsionSizeOfMarks));i++)
        for(size_t j=0;j<secondDemonsionSizeOfMarks;j++)
            sum+=numbers[i][j];
    return sum;
}
