#include "library.h"

void fillcont(string name, conteiner& c){
    ifstream file(name);
    string line;
    getline(file,line);
    int n = stoi(line);
    for(int i = 0; i < n; i++){
        getline(file, line);
        int j = 0, pos = 0;
        size_t k = line.find(',', pos);
        if(k == 0){
            string s = "In file " + name + ", in line " + to_string(++i) + " is an empty country";
            throw (s.c_str());
        }
        while(k != string:: npos ){
            if(k == pos){
                string s = "In file " + name + ", in line " + to_string(++i) + " there is an empty cell number " + to_string(j);
            throw (s.c_str());
            }
            j++;
            pos = k +1;
            k = line.find(',',pos);
        }
        if(!c.is_empty() && j != c[0].getnum()){
            string s = "In file " + name + ", in line " + to_string(++i) + " is not enough number of votes";
            throw (s.c_str());
        }
        if(!c.is_empty() && c.is_already_here(line, pos)){
            cout << "There is two equal countries in directory " << name << ":\n";
            cout<< "1. " << c[pos].gets() << endl;
            cout<< "2. " << line << endl;
            cout << "What line would you like to consider: ";
            cin >> k;
            if(k == 2){
                c.replace(line, pos, j);
            }
        }
        else c.add(line, j);
    }
}
void callculate(conteiner& c){
    for(int i=0; i < c[0].getnum(); i++){
        c.sort_by(i);
        c.addmarks();
    }
}
void outp(conteiner& c, string outname){
    c.sort_bymarks();
    ofstream file(outname);
    file << "10" << endl;
    for(int i = 0; i< 10; i++){
        file << c[i].getcountry() << ',' << c[i].getmark() << endl;
    }
    file.close();
}