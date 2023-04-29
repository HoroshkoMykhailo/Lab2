#include "row.h"
class conteiner{
    private:
        int size;
        row *data;
    public:
        conteiner();
        ~conteiner();
        row& operator[](int);
        void add(string);
        bool is_already_here(string, int&);
        void replace(int, string);
        void sort_by(int);
};