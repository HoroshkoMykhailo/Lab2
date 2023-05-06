#include "conteiner.h"
conteiner:: conteiner():size(0), data(nullptr){
}
conteiner::~conteiner(){
    delete[] data;
}
row& conteiner:: operator[](int index){
    return data[index];
}
int conteiner:: getsize(){
    return size;
}
void conteiner:: add(string line, int n, int linenum, string filename){
    row* d = new row[size + 1];
    for(int i = 0; i< size; i++){
        d[i] = data[i];
    }
    d[size] = row(line, n, linenum, filename);
    delete[] data;
    data = d;
    size++;
}
bool conteiner:: is_already_here(string line, int& n){
    for(int i = 0; i<size; i++){
        string country = data[i].getcountry();
        if(line[0] == country[0]){
            string s = line.substr(0, country.length());
            if(s == country){
                n = i;
                return true;
            }
        }
    }
    return false;
}
void conteiner:: replace(string l, int p, int n, int numline, string filename){
    data[p] = row(l, n, numline, filename);
}
bool conteiner:: is_empty(){
    return size == 0;
}
void conteiner:: sort_by(int n){
    for(int i = 0; i<size; i++){
        for(int j = i + 1; j < size; j++){
            if(data[i].getvote(n) < data[j].getvote(n)){
                row temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}
void conteiner:: addmarks(){
    data[0].addmark(12);
    data[1].addmark(10);
    int j = 8;
    for(int i = 2; i<10; i++){
        data[i].addmark(j);
        j--;
    }
}
void conteiner:: sort_bymarks(){
        for(int i = 0; i<size; i++){
        for(int j = i + 1; j < size; j++){
            if(data[i].getmark() < data[j].getmark()){
                row temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}