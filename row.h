#include <iostream>
#include <dirent.h>
#include <sstream>
using namespace std;
class row{
    private:
        string country;
        int* votes;
        int mark;
        int num_of_votes;
    public:
        row(string, int);
        void addmark(int);
        int getvote(int);
        string getcountry();
        int getnum();
};