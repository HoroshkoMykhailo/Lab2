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
void conteiner:: add(string line, int n){
    row* d = new row[size + 1];
    for(int i = 0; i< size; i++){
        d[i] = data[i];
    }
    d[size] = row(line, n);
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
void conteiner:: replace(string l, int p, int n){
    data[p] = row(l, n);
}
bool conteiner:: is_empty(){
    return size == 0;
}