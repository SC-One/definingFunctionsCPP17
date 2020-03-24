#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
void findWordsInText(const std::string& text, const std::string& delims,std::vector<std::string> &words);
size_t findMaxSizeWords(const std::vector<std::string> &words);
void printListWords(const std::vector<std::string> &words,const size_t &max);
int main()
{
    std::string text;
    std::cout<<"Insert text that terminated by '*': ";
    std::getline(std::cin,text,'*');
    std::cout<<std::endl;
    std::vector<std::string> words;
    const std::string separators{" ,;:.\"!?'\n"};
    findWordsInText(text,separators,words);
    printListWords(words,findMaxSizeWords(words));
    return 0;
}
void findWordsInText(const std::string& text, const std::string& delims,std::vector<std::string> &words)
{
    size_t start{text.find_first_not_of(delims)};
    size_t end{};
    while(start!=std::string::npos)
    {
        end = text.find_first_of(delims,start+1);
        if(end==std::string::npos)
        {
            end=text.size();
        }
        words.push_back(text.substr(start,end-start));
        start=text.find_first_not_of(delims,end+1);
    }
    return;
}


size_t findMaxSizeWords(const std::vector<std::string> &words)
{
    size_t max{};
    for(const auto &x:words)
    {
        if(x.length()>max)
            max=x.length();
    }
    return max;
}

void printListWords(const std::vector<std::string> &words,const size_t &max)
{
    size_t count{};
    for(const auto &x:words)
    {
        std::cout<<std::left<<std::setw(max+3)<<x;
        if(++count%5==0)
            std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return;
}

