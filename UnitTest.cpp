#include <UnitTest++/UnitTest++.h>
#include "mdfile.h"
using namespace std;

struct things_fixture{
    Server * pointer;
    things_fixture(){
        pointer = new Server();
    }
    ~things_fixture(){
        delete pointer;
    }
};

SUITE(PROVERKI)
{
    TEST_FIXTURE(things_fixture, Wrong_Port){
        pointer->port = 33333;
        pointer->file_name = "base.txt";
		pointer->error_name = "error";
        CHECK(true);
    }

    TEST_FIXTURE(things_fixture, Wrong_SA_E){
        pointer->port = 33333;
		pointer->error_name = "error.txt";
        CHECK_THROW(pointer->self_addr("123y", "error.tx",  213123142),error_server);
    }

    TEST_FIXTURE(things_fixture, Wrong_SA_I){
        pointer->port = 33333;
		pointer->file_error = "error.txt";
        CHECK_THROW(pointer->self_addr("123y", "error.tx",  213123142),error_server);
    }

    TEST_FIXTURE(things_fixture, Wrong_CA_Sock){
        pointer->port = 33333;
		pointer->file_error = "error.txt";
        CHECK_THROW(pointer->client_addr(-2, "err", "errtxt"),error_server);
    }


}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
/*
g++ -Wall -Ofast UnitTest.cpp mdfile.cpp -o Test -lcrypto++ -lUnitTest++

g++ -Wall -Ofast main.cpp mdfile.cpp  -o main -lcrypto++*/