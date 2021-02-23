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
struct Tic_Tac_Toe {
    ///////////////////////////////////////////////////////////////////////////////
    static const int SIZE = 3;
    ///////////////////////////////////////////////////////////////////////////////
    static void play() {
        strs matrix(SIZE, str(SIZE, (char)Symbols::space));
        print(matrix);

        for (int i = 0; i < SIZE * SIZE; i++)
        {
            if (input_number() == 1) {
                change_matrix();
            };
            system("cls");
            print(matrix);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print(strs& matrix) {

        for (int i = 0; i < SIZE; i++)
        {
            print_tire();
            print_enter();
            for (int j = 0; j < SIZE; j++)
            {
                print_VERTICAL_LINE();
                print_space();
                print_element(matrix, i, j);
                print_space();

            }//for      

            print_VERTICAL_LINE();
            print_enter();

        }//for

        print_tire();
        print_enter();
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print_element(strs& matrix, int& i, int& j) {
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
    static void print_tire() {
        str tire = { "-------------" };
        std::cout << tire;
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void  print_space() {

        std::cout << ' ';
    }
    ///////////////////////////////////////////////////////////////////////////////
    static char  input_number() {
        char number;
        std::cin >> number;
        return number;
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void  change_matrix() {

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

