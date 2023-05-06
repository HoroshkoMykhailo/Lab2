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
        void add(string, int, int, string);
        bool is_already_here(string, int&);
        void replace(string, int, int, int, string);
        bool is_empty();
        void sort_by(int);
        void addmarks();
        void sort_bymarks();
};