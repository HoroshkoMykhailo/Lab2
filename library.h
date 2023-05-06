#include "conteiner.h"
class reader
{   void fillcont(string, conteiner&);
public:
    void get_cont_from_directory(string, conteiner&);
};
class solver{
    public:
    void callculate(conteiner&);
    void outp(conteiner&, string);
};