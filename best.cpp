#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
///////////////////////////////////////////////////////////////////////////////
typedef std::string                     T_str;
typedef std::vector     < T_str     >   T_strings;
typedef T_strings                       T_field_matr;
///////////////////////////////////////////////////////////////////////////////
class   T_xs_and_os
{
    //-------------------------------------------------------------------------
    static  const   int     FIELD_DIM = 3;

    static  const   int     FIELD_SIZE = FIELD_DIM
        * FIELD_DIM;

    static  const   int     FIRST_CELL_NUM = 1;
    static  const   int     LAST_CELL_NUM = FIELD_SIZE;

    static  const   char    GAME_SYMB_FIRST = 'X';
    static  const   char    GAME_SYMB_SECOND = 'O';
    static  const   char    ZERO_SYMB = '0';

    static  const   char    SPACE_SYMB = ' ';
    static  const   char    MINUS_SYMB = '-';
    static  const   char    VERTICAL_LINE_SYMB = '|';
    //-------------------------------------------------------------------------
public:
    //-------------------------------------------------------------------------
    static
        void    play()
    {
        T_field_matr    field_matr
        (
            FIELD_DIM,

            T_str(
                FIELD_DIM,
                SPACE_SYMB
            )
        );

        print_new_game_message();
        print_field_matr(field_matr);

        for (
            int
            moves_counter{};
            moves_counter < FIELD_SIZE;
            ++moves_counter
            )
        {
            auto    cur_symb = get_cur_symb(moves_counter);

            input_move
            (
                cur_symb,
                field_matr
            );

            print_empty_line();
            print_field_matr(field_matr);

            if (
                symb_won_in_matr
                (
                    cur_symb,
                    field_matr
                )
                )
            {
                print_win_message_for_symb(cur_symb);
                return;
            }//if
        }//for

        print_draw_message();
    }
    //-------------------------------------------------------------------------
private:
    //-------------------------------------------------------------------------
    static
        void    print_empty_line()
    {
        std::cout << std::endl;
    }
    //-------------------------------------------------------------------------
    static
        void    print_new_game_message()
    {
        std::cout << "\n\n\n\n\n\n\n\n\n"
            << "NEW GAME:"
            << std::endl;
    }
    //-------------------------------------------------------------------------
    static
        char    get_cur_symb(int   moves_counter)
    {
        return  moves_counter % 2 == 0
            ? GAME_SYMB_FIRST
            : GAME_SYMB_SECOND;
    }
    //-------------------------------------------------------------------------
    static
        void    input_move
        (
            char                symb,
            T_field_matr& field_matr
        )
    {
        int     i{};
        int     j{};

        do
        {
            for_symb_input_field_matr_indexes
            (
                symb,
                i,
                j
            );
        } while (
            field_matr[i][j]
            != SPACE_SYMB
            );

        field_matr[i][j] = symb;
    }
    //-------------------------------------------------------------------------
    static
        bool    symb_won_in_matr
        (
            char                        symb,
            T_field_matr    const& field_matr
        )
    {
        T_field_matr    rotated_matr{ field_matr };
        transp(rotated_matr);
        reverse_strings(rotated_matr);

        return      symb_won_in_row_or_main_diag_of_matr
        (
            symb,
            field_matr
        )

            || symb_won_in_row_or_main_diag_of_matr
            (
                symb,
                rotated_matr
            );
    }
    //-------------------------------------------------------------------------
    static
        bool    symb_won_in_row_or_main_diag_of_matr
        (
            char                        symb,
            T_field_matr    const& field_matr
        )
    {
        T_str   winning_str
        (
            FIELD_DIM,
            symb
        );

        return          std::find
        (
            field_matr.begin(),
            field_matr.end(),
            winning_str
        )

            != field_matr.end()

            || winning_str

            == T_str{
                            field_matr[0][0],
                            field_matr[1][1],
                            field_matr[2][2]
        };
    }
    //-------------------------------------------------------------------------
    static
        void    reverse_strings(T_field_matr& field_matr)
    {
        std::reverse
        (
            field_matr.begin(),
            field_matr.end()
        );
    }
    //-------------------------------------------------------------------------
    static
        void    transp(T_field_matr& field_matr)
    {
        for (size_t i{}; i < field_matr.size() - 1; ++i)
        {
            for (size_t j{ i + 1 }; j < field_matr.size(); ++j)
            {
                std::swap
                (
                    field_matr[i][j],
                    field_matr[j][i]
                );
            }//for
        }//for
    }
    //-------------------------------------------------------------------------
    static
        void    print_win_message_for_symb(char    symb)
    {
        std::cout << "'"
            << symb
            << "'"
            << " won."
            << std::endl;
    }
    //-------------------------------------------------------------------------
    static
        void    print_draw_message()
    {
        std::cout << "Draw."
            << std::endl;
    }
    //-------------------------------------------------------------------------
    static
        void    print_field_matr(T_field_matr  const& field_matr)
    {
        for (size_t i{}; i < field_matr.size(); ++i)
        {
            print_field_row_of_matr_with_ind
            (
                field_matr,
                i
            );
        }//for
    }
    //-----------------------------------------------------------------------------------
    static
        void    print_field_row_of_matr_with_ind
        (
            T_field_matr    const& field_matr,
            int                         i
        )
    {
        const   int     SPACES_COUNT_BETWEEN_CELL_BORDER_AND_SYMBOL = 1;

        int             border_horiz_len

            = (SPACES_COUNT_BETWEEN_CELL_BORDER_AND_SYMBOL + 1)
            * 2
            * field_matr.size()
            + 1;

        T_str   border_horiz = T_str(
            border_horiz_len,
            MINUS_SYMB
        );

        if (i == 0)
        {
            std::cout << border_horiz
                << std::endl;
        }

        auto& field_row = field_matr[i];

        for (size_t j{}; j < field_row.size(); ++j)
        {
            print_field_cell_of_row_with_ind
            (
                field_row,
                j,
                SPACES_COUNT_BETWEEN_CELL_BORDER_AND_SYMBOL
            );
        }//for

        std::cout << std::endl
            << border_horiz
            << std::endl;
    }
    //-----------------------------------------------------------------------------------
    static
        void    print_field_cell_of_row_with_ind
        (
            T_str   const& field_row,
            int                 j,
            size_t              spaces_count_between_cell_border_and_symbol
        )
    {
        T_str   spaces_line(
            spaces_count_between_cell_border_and_symbol,
            SPACE_SYMB
        );

        if (j == 0)
        {
            std::cout << VERTICAL_LINE_SYMB;
        }

        std::cout << spaces_line
            << field_row[j]
            << spaces_line
            << VERTICAL_LINE_SYMB;
    }
    //-----------------------------------------------------------------------------------
    static
        void    for_symb_input_field_matr_indexes
        (
            char        symb,
            int& i,
            int& j
        )
    {
        int     move_cell_num{};
        char    digit_symb{};

        for (;;)
        {
            print_move_prompt_for_symb(symb);
            std::cin >> digit_symb;

            if (
                std::isdigit(digit_symb)
                )
            {
                move_cell_num = digit_symb
                    - ZERO_SYMB;

                if (
                    move_cell_num >= FIRST_CELL_NUM
                    && move_cell_num <= LAST_CELL_NUM
                    )
                {
                    break;
                }//if
            }//if
        }//for

        //Так как строки матрицы цифровой клавиатуры расположены по убыванию индекса строки,
        //а матрицы игрового поля - по возрастанию, то делаем реверс по индексу строки
        //матрицы.

        int     ind_from_num = move_cell_num
            - FIRST_CELL_NUM;

        int     i_from_num = ind_from_num
            / FIELD_DIM;

        i = FIELD_DIM
            - 1
            - i_from_num;

        j = ind_from_num
            % FIELD_DIM;
    }
    //-------------------------------------------------------------------------
    static
        void    print_move_prompt_for_symb(char    symb)
    {
        std::cout << "Move '"
            << symb
            << "'."
            << std::endl
            << "Enter cell number "
            << FIRST_CELL_NUM
            << ".."
            << LAST_CELL_NUM
            << " on numeric keypad: ";
    }
    //-------------------------------------------------------------------------
};
///////////////////////////////////////////////////////////////////////////////