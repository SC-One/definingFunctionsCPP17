#include<iostream>
int main(int argc,char *argv[])
{
    for (int i=0;i<argc;i++)
    {
        std::cout<<argv[i]<<std::endl;
    }
    // you can run in linux:
    // ./nameOfProgram.o argc1 argc2 argc3 ...
    std::cout<<std::endl;
    return 0;
}
