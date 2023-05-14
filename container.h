#include "row.h"
class container{
    private:
        int size;
        row *data;
    public:
        container();
        ~container();
        row& operator[](int);
        int getsize();
        void add(string, int);
        bool is_already_here(string, int&);
        bool is_empty();
        void sort_by(int);
        void addmarks();
        void sort_bymarks();
};