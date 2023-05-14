#include"container.h"
class reader
{   void fillcont(string, container&, lines_error&);
public:
    void get_cont_from_directory(string, container&);
};
class solver{
    public:
    void callculate(container&);
    void outp(container&, string);
};
class checker{
    int i = 0;
    public:
        bool checkline(lines_error&, string, string, int&, container&);
};
