#include<iostream>
#include<iomanip>
#include<memory>
#include<string>
#include<vector>
#include<string_view>
#include<optional>
using std::optional;
using Words= std::vector<std::shared_ptr<std::string>>;

void swap(Words& words, size_t first, size_t second);
void sort(Words& words);
void sort(Words& words,size_t start, size_t end);
void extractWords(Words& words, std::string_view text,std::string_view seprators);
void showWords(const Words& words, size_t perLine=8);
optional<size_t> maxWordLength(const Words& words);


int main()
{
    Words words;
    std::string text;
    const auto seprators{" ,.!?\"\n"};
    std::cout<<"Insert a Text that terminated by \"*\""<<std::endl;
    std::getline(std::cin,text,'*');
    extractWords(words,text,seprators);
    if(words.empty())
    {
        std::cout<<"No words in text.\n";
        return 0;
    }
    sort(words);
    showWords(words);
    return 0;
}


void extractWords(Words& words, std::string_view text,std::string_view seprators)
{
    size_t start{text.find_first_not_of(seprators)};
    size_t end{};
    while(start!=std::string_view::npos)
    {
        end=text.find_first_of(seprators,start+1);
        if(end==std::string_view::npos)
            end=text.length();
        words.push_back(std::make_shared<std::string>(text.substr(start,end-start)));
        start=text.find_first_not_of(seprators,end+1);
    }
}
void swap(Words& words, size_t first, size_t second)
{
    auto temp{words.at(first)};
    words.at(first)=words.at(second);
    words.at(second)=temp;
}
void sort(Words& words,size_t start, size_t end)
{
    if(!(start<end))    return;
    swap(words,start,(start+end)/2);
    size_t current{start};
    for(size_t i{start+1};i<=end;i++)
    {
        if(*words[i]<*words[start])
            swap(words,++current,i);
    }
    swap(words,start,current);
    if (current>start)  sort(words,start,current-1);
    if (end>current+1)  sort(words,current+1,end);
}
void sort(Words& words)
{
    if(!(words.empty()))
        sort(words,0,words.size()-1);
}

optional<size_t> maxWordLength(const Words& words)
{
    if(words.empty())   return std::nullopt;
    size_t maxIndex{0};
    for(size_t i{1};i<words.size();i++)
        if(words[i]->length() > words[maxIndex]->length())
            maxIndex=i;
    return words[maxIndex]->length();
}

void showWords(const Words& words, size_t perLine)
{
    const size_t fieldWidth{maxWordLength(words).value()};
    std::cout<<std::left<<std::setw(fieldWidth)<<*words[0];
    size_t wordsInLine{};
    for(size_t i{1};i<words.size();++i)
    {
        if((*words[i])[0]!=(*words[i-1])[0]|| ++wordsInLine==perLine)
        {
            wordsInLine=0;
            std::cout<<std::endl;
        }
        std::cout<<std::setw(fieldWidth)<<*words[i];
    }
    std::cout<<std::endl;
}


/////////////////////////////////// Input:
/*

  It was the best of times, it was the worst of times, it was the age of wisdom, it was the age of foolishness, it was the epoch of belief, it was the epoch of incredulity, it was the season of Light, it was the season of Darkness, it was the spring of hope, it was the winter of despair, we had everything before us, we had nothing before us, we were all going direct to Heaven, we were all going direct the other way—in short, the period was so far like the present period, that some of its noisiest authorities insisted on its being received, for good or for evil, in the superlative degree of comparison only.*

 */

/////////////////////////////////// Output:
/*
Darkness
Heaven
It
Light
age        age        all        all        authorities
before     before     being      belief     best
comparison
degree     despair    direct     direct
epoch      epoch      everything evil
far        foolishnessfor        for
going      going      good
had        had        hope
in         incredulityinsisted   it         it         it         it         it
it         it         it         it         its        its
like
noisiest   nothing
of         of         of         of         of         of         of         of
of         of         of         of         on         only       or         other
period     period     present
received
season     season     short      so         some       spring     superlative
that       the        the        the        the        the        the        the
the        the        the        the        the        the        the        times
times      to
us         us
was        was        was        was        was        was        was        was
was        was        was        way—in   we         we         we         we
were       were       winter     wisdom     worst
 */
