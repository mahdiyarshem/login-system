#include <iostream>
#include <string>

class User {
public:
    std::string username;
    std::string password;
    std::string skin;
    int playtime; // زمان بازی به ساعت

    User(std::string uname, std::string pwd, std::string skn, int pt)
        : username(uname), password(pwd), skin(skn), playtime(pt)) {}
};