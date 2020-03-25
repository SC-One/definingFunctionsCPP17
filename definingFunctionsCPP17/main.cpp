#include<iostream>
auto getFirstLetter(std::string_view text)  // deduced return cant define as prototype ! IDK why Sorry!
{
    if (text.empty())
        return std::string_view("Empty");       //should be one type return!
    else
        return text.substr(0, 1);               //should be one type return!
}

int main()
{
    std::cout<<getFirstLetter("")<<std::endl;
    return 0;
}
