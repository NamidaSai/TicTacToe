#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
    public:
        Player();
        void SetToken();
        char GetToken();
        std::string GetName();

    private:
        std::string _name;
        char _token;
};


#endif /* PLAYER_HPP */