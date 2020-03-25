#include<iostream>
auto getFirstLetter(std::string_view text)  // deduced return cant define as prototype ! IDK why Sorry!
{
    if (text.empty())
        return "Empty";       //should be one type return!
    else
        return text.substr(0, 1).data();               //should be one type return!
}

int main()
{
    std::cout<<getFirstLetter("")<<std::endl;
    return 0;
}
