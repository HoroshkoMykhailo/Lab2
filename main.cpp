#include "library.h"
int main(int argc, char* argv[]){
    try{
        string name = "C:\\Visual studio\\codes\\2\\examples_2\\";
        string s, out = "C:\\Visual studio\\codes\\2\\examples_2\\results.csv";
        name.append(argv[1]);
        reader r;
        solver solve;
        conteiner contein;
        r.get_cont_from_directory(name, contein);
        solve.callculate(contein);
        solve.outp(contein, out);
    }
    catch(const char* error){
        cout << "Error: " << error;
    }
    return 0;
}