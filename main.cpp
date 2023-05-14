#include "library.h"
int main(int argc, char* argv[]){
    try{
        string name = "C:\\Visual studio\\codes\\2\\examples_2\\";
        string out = "C:\\Visual studio\\codes\\2\\examples_2\\results.csv";
        name.append(argv[1]);
        reader r;
        solver solve;
        container contain;
        r.get_cont_from_directory(name, contain);
        solve.callculate(contain);
        solve.outp(contain, out);
    }
    catch(const directory_error& error){
        cerr << "Error: " << error.what();
    }
    catch(lines_error& errors){
        for(int i = 0; i < errors.message().size(); i++){
            cerr << errors.what() << errors.message()[i] << endl;
        }
    }
    return 0;
}