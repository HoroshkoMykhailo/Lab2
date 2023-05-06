#include <iostream>
#include <dirent.h>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
class row{
    private:
        string s;
        string country;
        int* votes;
        int mark;
        int num_of_votes;
    public:
        row();
        row(string, int, int, string);
        void addmark(int);
        int getmark();
        int getvote(int);
        string gets();
        string getcountry();
        int getnum();
};