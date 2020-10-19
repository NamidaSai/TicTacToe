#include "Player.hpp"
#include <iostream>

using namespace std;

Player::Player()
{
    cin >> _name;
}

void Player::SetToken()
{
    cout << "Choose a token for " << _name << endl;
    cin >> _token;
}

char Player::GetToken()
{
    return _token;
}

string Player::GetName()
{
    return _name;
}