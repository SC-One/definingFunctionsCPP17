#include<iostream>
const double *findSmallest(const double array[] ,size_t count);
double *shiftArr(double array[],size_t count,double delta);
int main()
{
    double samples[]{-1,-2,0,1,2,10};
    const size_t counter{sizeof (samples)/ sizeof (samples[0])};
    shiftArr(samples,counter, -(*(findSmallest(samples,counter))));
    for(auto &x:samples)
        std::cout<<x<<std::endl;
    return 0;
}

const double *findSmallest(const double array[] ,size_t count)
{
    if (!count) return nullptr;
    size_t minIndex{};
    for(size_t i{1};i<count;i++)
        if(array[i]<array[minIndex])
            minIndex=i;
    return &array[minIndex];
}

double *shiftArr(double array[],size_t count,double delta)
{
    for(size_t i{};i<count;i++)
        array[i]+=delta;
    return array;
}
