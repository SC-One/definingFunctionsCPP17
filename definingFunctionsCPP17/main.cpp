// Functions overloading
// Note:
//          1.The functions have different numbers of parameters.
//          2.At least one pair of corresponding parameters is of different types.
// when one of both occures , C++ will overloade that function.
// Caution: in return type differs you cant overload functions.

#include<iostream>
#include<vector>
using std::string;
using std::vector;

// Function prototypes:
double largest(const double data[], const size_t &count);
double largest(const vector<double>& data);
int largest(const vector<int>& data);
string largest(const vector<string>& words);
// int largest(const vector<string>& words); /* would not compile: overloaded functions must
//                                             differ in more than just their return type! */

int main()
{
      double values[] {1.5, 44.6, 13.7, 21.2, 6.7};
      vector<int> numbers {15, 44, 13, 21, 6, 8, 5, 2};
      vector<double> data{3.5, 5, 6, -1.2, 8.7, 6.4};
      vector<string> names {"Charles Dickens", "Emily Bronte", "Jane Austen","Henry James", "Arthur Miller"};
      std::cout << "The largest of values is " << largest(values, std::size(values)) << std::endl;
      std::cout << "The largest of numbers is " << largest(numbers) << std::endl;
      std::cout << "The largest of data is " << largest(data) << std::endl;
      std::cout << "The largest of names is " << largest(names) << std::endl;

    return 0;
}

double largest(const double data[], const size_t &count)
{
    if(count==1) return data[0];
    size_t maxIndex {0};
    for(size_t i{1};i<count;++i)
    {
        if(data[i]>data[maxIndex])
            maxIndex=i;
    }
    return data[maxIndex];
}
double largest(const vector<double>& data)
{
    if(data.size()==1) return data.at(0);
    double max{data.at(0)};
    for(const auto &arr:data)
        if(arr>max)
            max=arr;
    return max;
}
int largest(const vector<int>& data)
{
    if(data.size()==1) return data.at(0);
    int max{data.at(0)};
    for(const auto &arr:data)
        if(arr>max)
            max=arr;
    return max;

}
string largest(const vector<string>& words)
{
    if(words.size()==1) return words.at(0);
    string max{words.at(0)};
    for(const auto &arr:words)
        if(arr>max)
            max=arr;
    return max;
}
