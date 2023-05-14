#include "except_classes.h"
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
        int getmark();
        int getvote(int);
        string gets();
        string getcountry();
        int getnum();
};