/**
* @file  mdfile.h
* @author Автор
* @version 1.0
* @brief Описание классов, подключение библиотек и переменных
* @date дата
* @copyright ИБСТ ПГУ
*/
#include <netinet/in.h>
#include <iostream>
#include <cassert>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <cryptopp/cryptlib.h>
#include <iostream>
#include <vector>
#include <tuple>
#include <getopt.h>
#include <cryptopp/hex.h> // HexEncoder
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
using namespace CryptoPP;
using namespace std;
#include <cryptopp/md5.h> // MD%, для другого алгоритма - другой заголовочный файл

std::string MD(std::string sah);

void errors(string error, string file_name, string file_error);

void msgsend(int work_sock, string mess);

int autorized(int work_sock, string file_name, string file_error);

int math(int work_sock);

///@brief Класс для обработки ошибок возникающих при работе сервера
class error_server:
    public invalid_argument
{
public:
    explicit error_server (const string& what_arg):
        std::invalid_argument(what_arg){}
    explicit error_server (const char* what_arg):
        std::invalid_argument(what_arg){}
};

/// @brief Класс в котором находятся переменные и функция для подключения сервера к клиенту
class Server{
private:

public:
int port;
string file_name; 
string file_error;
string error;
string error_name;
string* comstr(int argc, char *argv[]);
int self_addr(string error, string file_error, int port);
int client_addr(int s, string error, string file_error);
};


