#include<iostream>
#include<string_view>
#include<iomanip>

///////////////////////////////////////////////// prototype functions //////////////////////////////////////////////////////

const double *findSmallest(const double array[] ,const size_t &count);
double *shiftArr(double array[],const size_t count,const double &delta);
const double *findLargest(const double array[], const size_t &count);
double *scaleArr(double arr[],const size_t &count, const double &div);
double *normalizeArr(double arr[], const size_t &count);
void showData(const double arr[],const size_t count ,std::string_view title ,const size_t width,const size_t perLine);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////// Main function ///////////////////////////////////////////////
int main()
{
    double samples[] {11.0,  23.0,  13.0,  4.0,57.0,  36.0, 317.0, 88.0,9.0, 100.0, 121.0, 12.0};
    const size_t counter{sizeof (samples)/ sizeof (samples[0])};
    showData(samples,counter,"Original values",15,5);
    showData(normalizeArr(samples,counter),counter,"Values after normalize",15,5);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////// Header functions ////////////////////////////////////////////////////////
const double *findSmallest(const double array[] ,const size_t &count)
{
    if (!count) return nullptr;
    size_t minIndex{};
    for(size_t i{1};i<count;i++)
        if(array[i]<array[minIndex])
            minIndex=i;
    return &array[minIndex];
}

double *shiftArr(double array[],const size_t count,const double &delta)
{
    for(size_t i{};i<count;i++)
        array[i]+=delta;
    return array;
}

const double *findLargest(const double array[],const size_t &count)
{
    if (!count) return nullptr;
    size_t maxIndex{};
    for(size_t i{1};i<count;i++)
        if(array[i]>array[maxIndex])
            maxIndex=i;
    return &array[maxIndex];

}

double *scaleArr(double arr[],const size_t &count, const double &div)
{
    if(!count) return arr;
    for(size_t i=0;i<count;i++)
        arr[i]/=div;
    return arr;
}

double *normalizeArr(double arr[], const size_t &count)
{
    shiftArr(arr,count,-(*findSmallest(arr,count)));
    double max{*findLargest(arr,count)};
    return scaleArr(arr,count,max);
}

void showData(const double arr[],const size_t count =1 , std::string_view title = "Data Values",size_t width = 10, size_t perLine = 5)
{
    size_t goNextLine{};
    std::cout<<title<<":\n";
    for(size_t i{};i<count;i++)
    {
        std::cout<<std::setw(static_cast<int>(width))<<arr[i];
        if(++goNextLine%perLine==0)
            std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
