#include "doctest.h"
#include "mat.hpp"
#include <string>
using namespace ariel;
// using namespace std;

const int NUM_OF_ITERATION = 100;
const int JUNP_SIZE = 2;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("small goood mats")
{
    CHECK((mat(3, 1, '@', '-')) == nospaces("@@@"));
    CHECK((mat(1, 3, '@', '-')) == nospaces("@@@"));
    CHECK((mat(3, 3, '@', '-')) == nospaces("@@@\n@-@\n@@@"));
    CHECK((mat(3, 5, '@', '-')) == nospaces("@@@\n@-@\n@-@\n@-@\n@@@"));
    CHECK((mat(5, 3, '@', '-')) == nospaces("@@@@@\n@---@\n@@@@@"));
    CHECK((mat(5, 5, '@', '-')) == nospaces("@@@@@\n@---@\n@-@-@\n@---@\n@@@@@"));
    CHECK((mat(7, 5, '@', '-')) == nospaces("@@@@@@@\n@-----@\n@-@@@-@\n@-----@\n@@@@@@@"));
    CHECK((mat(5, 7, '@', '-')) == nospaces("@@@@@\n@---@\n@-@-@\n@-@-@\n@-@-@\n@---@\n@@@@@"));
    CHECK((mat(7, 7, '@', '-')) == nospaces("@@@@@@@\n@-----@\n@-@@@-@\n@-@-@-@\n@-@@@-@\n@-----@\n@@@@@@@"));
    CHECK((mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
    CHECK((mat(5, 13, '@', '-')) == nospaces("@@@@@@---@@-@-@@-@-@@-@-@@-@-@@-@-@@-@-@@-@-@@-@-@@-@-@@---@@@@@@"));
    CHECK((mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@@-----------@@-@@@@@@@@@-@@-----------@@@@@@@@@@@@@@"));
    
}

TEST_CASE("good general mats")
{
    for(int i = 0; i < NUM_OF_ITERATION; i+=JUNP_SIZE){
        string general_mat = nospaces(mat(3*i+1, 2*i+1, '@', '-'));
        int size = general_mat.size();
        CHECK((general_mat[size/2]) == ('@'));

    }
    for(int i = 0; i < NUM_OF_ITERATION; i+=JUNP_SIZE){
        string general_mat = nospaces(mat(2*i+3, 5*i+3, '@', '-'));
        int size = general_mat.size();
        CHECK((general_mat[size/2]) == ('-'));
    }

}

TEST_CASE("Bad input one is even and the other is odd") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    for(int i = 0 ; i < 50 ; i +=JUNP_SIZE){
        CHECK_THROWS(mat(i, i*2+5, '$', '%'));
    }
}

TEST_CASE("Bad input one negetive and the other is odd") {
    CHECK_THROWS(mat(-11, 5, '$', '%'));
    for(int i = 0; i <50 ; i++){
        CHECK_THROWS(mat(-i, i*2+5, '$', '%'));
    }
}

TEST_CASE("Bad input one negetive and the other is even") {
    CHECK_THROWS(mat(-11, 6, '$', '%'));
    for(int i = 0; i <50 ; i++){
        CHECK_THROWS(mat(-i, i*2, '$', '%'));
    }
}

TEST_CASE("Bad input two even") {
    CHECK_THROWS(mat(10, 6, '$', '%'));
    for(int i = 0; i <50 ; i+=JUNP_SIZE){
        CHECK_THROWS(mat(i, i*2, '$', '%'));
    }
}

TEST_CASE("Bad input two negative") {
    CHECK_THROWS(mat(-10, -6, '$', '%'));
    for(int i = 0; i <50 ; i++){
        CHECK_THROWS(mat(-i, -i*2, '$', '%'));
    }
}






