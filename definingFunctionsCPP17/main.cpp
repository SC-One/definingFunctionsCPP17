#include<iostream>
int *larger(int *a ,int *b);
int main()
{
    int i{100},j{99};
    std::cout<<&i<<std::endl<<&j<<std::endl;
    std::cout<<(larger(&i,&j))<<std::endl;
    std::cout<<*(larger(&i,&j))<<std::endl;
    return 0;
}

int *larger(int *a ,int *b)
{
    if(*a>*b)
        return a;
    else
        return b;

}
