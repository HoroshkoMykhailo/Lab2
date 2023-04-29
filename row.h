#include <iostream>
#include <dirent.h>
#include <sstream>
#include <fstream>
#include <string>
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
        row(string, int);
        void addmark(int);
        int getvote(int);
        string gets();
        string getcountry();
        int getnum();
};