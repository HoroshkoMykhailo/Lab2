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
        void add(string, int);
        bool is_already_here(string, int&);
        void replace(string, int, int);
        bool is_empty();
    //  void sort_by(int);
};