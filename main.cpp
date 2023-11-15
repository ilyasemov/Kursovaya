/**
* @file  main.h
* @author Автор
* @version 1.0
* @brief Описание классов, подключение библиотек и переменных
* @date дата
* @copyright ИБСТ ПГУ
*/
#include "mdfile.h"
int main(int argc, char *argv[]) {
    Server Server;
    while (true) {
        string* com = Server.comstr(argc, argv);
        int s = Server.self_addr(com[3], com[2], stoi(com[1]));
        int work_sock = Server.client_addr(s, com[3], com[2]);
        // Вызов функций autorized и math
        autorized(work_sock, com[0], com[2]);
        math(work_sock);
        delete[] com; // Освобождаем выделенную память
        return 0;
    }
    return 0;
}