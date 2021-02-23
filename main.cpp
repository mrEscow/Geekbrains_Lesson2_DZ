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
    static void play() {
        strs matrix(SIZE, str(SIZE, (char)Symbols::cross));
        print(matrix);
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print(strs &matrix) {

        str tire = { "----------" };

        for (size_t i = 0; i < SIZE; i++)
        {
            print_enter();

            for (size_t j = 0; j < SIZE; j++)
            {
                print_VERTICAL_LINE();
                print_element(matrix,i,j);
                
            }//for      

            print_VERTICAL_LINE();
            print_enter();
            if(i< SIZE-1) std::cout << tire;
        }//for
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print_element(strs& matrix, int i, int j) {
        str temp = matrix[i];
        std::cout << temp[j];
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print_enter() {
        std::cout << std::endl;
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print_VERTICAL_LINE() {
        std::cout << (char)Symbols::VERTICAL_LINE;
    }
    ///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){
    //Symbols a = Symbols::cross;


    //char button_1 = (char)Symbols::cross;
    //char button_2 = (char)Symbols::cross;
    //char button_3 = (char)Symbols::cross;
    //str pole1 = { '|',button_1,'|',button_2,'|',button_3,'|' };
    //str tire = {"----------"};
    //std::cout << pole1 << std::endl;
    //std::cout << tire << std::endl;
    //std::cout << pole1 << std::endl;
    //std::cout << tire << std::endl;
    //std::cout << pole1 << std::endl;

    //int a[3 * 3];

    Tic_Tac_Toe::play();

    for (;;)
    {
      // T_xs_and_os::play();
    }

    return 0;
}

