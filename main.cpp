#include <iostream>
#include <string>
#include <vector>
#include "best.cpp"
///////////////////////////////////////////////////////////////////////////////
typedef std::string str;
typedef std::vector<str> strs;
///////////////////////////////////////////////////////////////////////////////
static const int SIZE = 3;
///////////////////////////////////////////////////////////////////////////////
enum class Symbols{
    cross ='X',
    zero = 'O',
    space = ' '
};
///////////////////////////////////////////////////////////////////////////////
struct Tic_Tac_Toe{


};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
    //Symbols a = Symbols::cross;

    strs matrix(SIZE, str(SIZE, (char)Symbols::space));

    for (size_t i = 0; i < matrix.size(); i++)
    {
        std::cout << matrix[i] << std::endl;
    }
    char button_1 = (char)Symbols::cross;
    char button_2 = (char)Symbols::cross;
    char button_3 = (char)Symbols::cross;
    str pole1 = { '|',button_1,'|',button_2,'|',button_3,'|' };
    str tire = {"----------"};
    std::cout << pole1 << std::endl;
    std::cout << tire << std::endl;
    std::cout << pole1 << std::endl;
    std::cout << tire << std::endl;
    std::cout << pole1 << std::endl;

    //int a[3 * 3];



    for (;;)
    {
      // T_xs_and_os::play();
    }

    return 0;
}

