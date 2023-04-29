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
        while(k != string:: npos ){
            j++;
            pos = k + 1;
            k = line.find(',', pos);
        }
        if(i != 0 && j != c[0].getnum()){
            throw ("In file %s, in line %d is not enough number of votes", name, i++);
        }
        if(i!= 0 && c.is_already_here(line, pos)){
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
void printcon(conteiner c){
    for(int i = 0; i< c.getsize(); i++){
        cout<< c[i].gets()<< endl;
    }

}