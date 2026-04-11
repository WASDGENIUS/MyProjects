#include <iostream>
using namespace std;


struct Game{
    char name[20];
    int players;
};

void printgame(Game *g){
    cout << (*g).name << "\t" << (*g).players << endl;
};

int main(){
    int n = 10;
    Game *games = new Game[n]{
        {"sim of stone", 20000},
        {"gta5", 900000},
        {"zxczxc", 20000},
        {"sdfggsdsgfd", 900000},
        {"vsffavsfasv", 20000},
        {"vsasvfavfas", 900000},
        {" fgb dfgb ", 20000},
        {"df gb dfg", 900000},
        {" sav acdccacfds", 20000},
        {"gta5", 900000}
    };

    for (int i = 0; i < n; i++){

        printgame(&games[i]);

    }


    delete[] games;

    return 0;
}