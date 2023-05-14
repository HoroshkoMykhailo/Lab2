#include "container.h"
container:: container():size(0), data(nullptr){
}
container::~container(){
    delete[] data;
}
row& container:: operator[](int index){
    return data[index];
}
int container:: getsize(){
    return size;
}
void container:: add(string line, int n){
    row* d = new row[size + 1];
    for(int i = 0; i< size; i++){
        d[i] = data[i];
    }
    d[size] = row(line, n);
    delete[] data;
    data = d;
    size++;
}
bool container:: is_already_here(string line, int& n){
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
bool container:: is_empty(){
    return size == 0;
}
void container:: sort_by(int n){
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
void container:: addmarks(){
    data[0].addmark(12);
    data[1].addmark(10);
    int j = 8;
    for(int i = 2; i<10; i++){
        data[i].addmark(j);
        j--;
    }
}
void container:: sort_bymarks(){
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