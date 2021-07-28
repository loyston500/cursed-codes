#include <iostream>
#include <string>

typedef struct {
    std::string Letter_H;
    std::string Letter_E;
    std::string Letter_L;
    std::string Letter_O;
    std::string Letter_W;
    std::string Letter_R;
    std::string Letter_D;
} Letters;

template <typename Letters>

Letters Hello_World(Letters letter){
    return letter;
}

int main()
{
    Letters L;
    L.Letter_H = "H";
    L.Letter_E = "e";
    L.Letter_L = "l";
    L.Letter_O = "o";
    L.Letter_W = "W";
    L.Letter_R = "r";
    L.Letter_D = "d";

    std::cout << Hello_World(L.Letter_H) << Hello_World(L.Letter_E)
    << Hello_World(L.Letter_L) << Hello_World(L.Letter_L) << Hello_World(L.Letter_O)
    << ", " << Hello_World(L.Letter_W) << Hello_World(L.Letter_O)
    << Hello_World(L.Letter_R) << Hello_World(L.Letter_L)
    << Hello_World(L.Letter_D) << "!";
}

