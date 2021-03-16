#ifndef SNOWMAN_H
#define SNOWMAN_H
#include <array>
#include <string>
using namespace std;
namespace ariel{
    const int DIGIT_COUNT = 8;
    const int PART_COUNT = 4;
    string snowman(int seq);
    bool check_currect(int seq);
    string get_base(int base,std::string const &left);
    string get_torso(int tor,std::string const &left,std::string const &right);
    string get_hat(int hat,std::string const &left);
    string get_eye(int eye);
    string get_nose(int nose);
    string get_parts(const std::array<int, DIGIT_COUNT> &arr);



}

#endif