#include <iostream>
#include <string>
#include <vector>
#include "best.cpp"
///////////////////////////////////////////////////////////////////////////////
typedef std::string str;
typedef std::vector<str> strs;
///////////////////////////////////////////////////////////////////////////////
enum class Symbols{
    cross ='X',
    zero = 'O',
    space = ' ',
    VERTICAL_LINE = '|'
};
///////////////////////////////////////////////////////////////////////////////
struct Tic_Tac_Toe{
    ///////////////////////////////////////////////////////////////////////////////
    static const int SIZE = 3;
    ///////////////////////////////////////////////////////////////////////////////
    void play() {
        strs matrix(SIZE, str(SIZE, (char)Symbols::cross));
    }
    ///////////////////////////////////////////////////////////////////////////////
    void print(strs &matrix) {
        for (size_t i = 0; i < SIZE; i++)
        {
            for (size_t j = 0; j < SIZE; j++)
            {
                std::cout << (char)Symbols::VERTICAL_LINE << std::endl;
                std::cout << matrix[j] << std::endl;
            }//for
        }//for
    }
    ///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
    //Symbols a = Symbols::cross;


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

