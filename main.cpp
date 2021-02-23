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
struct t_char {
    char chrtr;
    int is_100 : 1; 
    int is_010 : 1;
    int is_001 : 1;
    int is_dig : 1;
    int is_spc : 1;
};
struct Tic_Tac_Toe {
    ///////////////////////////////////////////////////////////////////////////////
    static const int SIZE = 3;
    static const int M_SIZE = SIZE * SIZE;
    //static char player;
    ///////////////////////////////////////////////////////////////////////////////
    static void play() {
        system("cls");

        print_new_game_msg();

        strs matrix(SIZE, str(SIZE, (char)Symbols::space));
        print(matrix);



        for (int i = 0; i < M_SIZE; i++)
        {
            print_enter();
            print_number_of_stroke(i);
            print_enter();
            char player = select_player(i);
            change_matrix(player,input_number(player), matrix );
            
            system("cls");
            print_enter();
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
        //str temp = matrix[i];
        //std::cout << temp[j];
        std::cout << matrix[i][j];
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print_new_game_msg() {
        std::cout << "  NEW GAME  "<<std::endl;
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void print_number_of_stroke(int &i) {
        std::cout
            << "number of stroke : "
            << i + 1 
            << std::endl;
    }
    ///////////////////////////////////////////////////////////////////////////////
    static char select_player(int i) {
        //char player;
        //if (i % 2 == 0) { 
        //    player = (char)Symbols::cross;
        //}
        //else {
        //    player = (char)Symbols::zero;
        //}
        //return player;
        return i % 2 == 0 ? (char)Symbols::cross : (char)Symbols::zero;
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
    static int  input_number(char player) {
        int number;
        do
        {           
            std::cout 
                << "Player "
                << player
                << " enter number (1...9) : ";  

            std::cin >> number;
            
        } while (number>9 || number<1); 

        return number;
    }
    ///////////////////////////////////////////////////////////////////////////////
    static void  change_matrix(char &player,int number, strs& matrix) {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){  
                if (number == (i * SIZE + j +1)){
                    //str temp = matrix[SIZE - 1 - i];
                    //temp[j] = player;
                    matrix[SIZE - 1 - i][j] = player;
                }

            }//for            
        }//for
    }
    ///////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv){

    for (;;){
        Tic_Tac_Toe::play();
    }

    return 0;
}

