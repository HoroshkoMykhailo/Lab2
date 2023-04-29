#include "row.h"
class conteiner{
    private:
        int size;
        row *data;
    public:
        conteiner();
        ~conteiner();
        row& operator[](int);
        int getsize();
        void add(string);
        bool is_already_here(string, int&);
        void replace(string, int);
        void resize(int);
    //  void sort_by(int);
};