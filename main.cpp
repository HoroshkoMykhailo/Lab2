#include "library.h"
int main(int argc, char* argv[]){
    try{
        string name = "C:\\Visual studio\\codes\\2\\examples_2\\";
        string s;
        name.append(argv[1]);
        DIR *directory = opendir(name.c_str());
        if(!directory){
            throw "There is no such directory in examples_2";
        }
        int iffiles = 0;
        dirent* entry;
        conteiner cont;
        while ((entry = readdir(directory)) != NULL) {
            string filename = name;
            filename.append("\\");
            filename.append(entry->d_name);
            int key = filename.rfind(".csv");
            if(key != string::npos && key == filename.length() - 4){
                fillcont(filename, cont);
                iffiles = 1;
            }
        }
        if(!iffiles){
            throw "There is no files in csv format in this directory";
        }
        closedir(directory);
        printcon(cont);
    }
    catch(const char* error){
        cout << "Error: " << error;
    }
    return 0;
}