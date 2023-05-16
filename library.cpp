#include "library.h"
void reader:: get_cont_from_directory(string name, container &cont){
        DIR *directory = opendir(name.c_str());
        if(!directory){
            // throw std::exception()
            throw directory_error("There is no such directory in examples_2");
        }
        int iffiles = 0;
        dirent* entry;
        lines_error errors;
        while ((entry = readdir(directory)) != NULL) {
            string filename = name;
            filename.append("\\");
            filename.append(entry->d_name);
            int key = filename.rfind(".csv");
            if(key != string::npos && key == filename.length() - 4){
                fillcont(filename, cont, errors);
                iffiles = 1;
            }
        }
        if(!errors.is_empty()){
            throw errors;
        }
        if(!iffiles){
            throw directory_error("There is no files in csv format in this directory");
        }
        closedir(directory);
}
void reader:: fillcont(string name, container& c, lines_error& er){
    ifstream file(name);
    string line;
    checker check;
    if(!getline(file,line)){
        string s = "File " + name + " is empty";
        throw directory_error(s);
    };
    int n = stoi(line);
    for(int i = 0; i < n; i++){
        if(!getline(file, line)){
            string s = "There is less than " + to_string(n) + " lines in file " + name;
            throw directory_error(s);
        }
        int j = 0;
        if(check.checkline(er, line, name, j, c)) c.add(line, j);
    }
    file.close();
}
void solver:: callculate(container& c){
    for(int i=0; i < c[0].getnum(); i++){
        c.sort_by(i);
        c.addmarks();
    }
}

void solver:: outp(container& c, string outname){
    c.sort_bymarks();
    ofstream file(outname);
    int n = 10 > c.getsize() ? c.getsize() : 10;
    file << n;
    for(int i = 0; i< 10; i++){
        file << endl << c[i].getcountry() << ',' << c[i].getmark();
    }
    file.close();
}

bool checker:: checkline(lines_error& er, string line, string name, int& j, container& c){
    bool r = true;
    int pos = 0, cell = 1;
    size_t k = line.find(',', pos);
    i++;
    if(k == string::npos){
        string s = "In file " + name + ", there is no coma at line " + to_string(i);
        er.addMessage(s);
        r = false;
    }
    if(k == 0){
        string s = "In file " + name + ", in line " + to_string(i) + " is an empty country";
        er.addMessage(s);
        r = false;
    }
        while(k != string:: npos ){
            j++;
            pos = k + 1;
            k = line.find(',',pos);
            if(k == pos){
                string s = "In file " + name + ", in line " + to_string(i) + " there is an empty cell number " + to_string(j);
                er.addMessage(s);
                r = false;
                cell = 0;
            }
            else{
                string l = line.substr(pos, k - pos);
                for(int k = 0; k < l.length(); k++){
                    if(!isdigit(l[k])){
                        string s = "In file " + name + ", in line " + to_string(i) + " there is a string in cell number " + to_string(j);
                        er.addMessage(s);
                        r = false;
                        cell = 0;
                    }
                }
            }
        }
    if(!c.is_empty() && j != c[0].getnum() && cell){
        string s = "In file " + name + ", in line " + to_string(i) + " is not enough number of votes";
        er.addMessage(s);
        r = false;
    }
    if(!c.is_empty() && c.is_already_here(line, pos)){
        string s = "There is two equal countries in this directory:\n 1. " + c[pos].gets() + "\n 2. " + line + '\n';
        er.addMessage(s);
        r = false;
    }
    return r;
}