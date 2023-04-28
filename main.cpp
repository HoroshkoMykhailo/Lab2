#include <conteiner.h>
int main(int argc, char* argv[]){
    string name = "C:\\Visual studio\\codes\\2\\examples_2\\";
    name.append(argv[1]);
    DIR *directory = opendir(name.c_str());
    if(!directory){
        cout << "There is no such directory in examples_2";
    }
    else{
        dirent* entry = nullptr;
        while ((entry = readdir(directory)) != nullptr) {
            cout << entry->d_name << endl;
        }
    }
    closedir(directory);
    return 0;
}