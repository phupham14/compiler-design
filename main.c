#include "lexer.h"
#include "parser.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }

    init_lexer(argv[1]); // Mở file và khởi tạo lexer
    advance();           // Đọc token đầu tiên
    parse_program();     // Gọi parser
    close_lexer();       // Đóng file sau khi parse xong

    return 0;
}