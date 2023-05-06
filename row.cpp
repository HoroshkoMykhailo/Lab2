#include "row.h"
row:: row(){
    s = "";
    country = "";
    votes = nullptr;
    mark = 0;
    num_of_votes = 0;
}
row:: row(string line, int n, int numline, string filename){
    stringstream ss(line);
    s = line;
    votes = new int [n];
    mark = 0;
    string word;
    num_of_votes = n;
    int i = 0;
    getline(ss, word, ',');
    country = word;
    try{
    while(getline(ss, word, ',')){
        votes[i] = stoi(word);
        i++;
    }
    }catch(const invalid_argument){
        string s = "In file " + filename + ", in line " + to_string(++numline) + " there is a string in cell number " + to_string(++i);
        throw(s.c_str());
    }
}
row:: ~row(){
    delete[] votes;
}
void row:: addmark(int n){
    mark += n;
}
int row:: getmark(){
    return mark;
}
int row:: getvote(int n){
    return(votes[n]);
}
string row:: getcountry(){
    return country;
}
string row:: gets(){
    return s;
}
int row:: getnum(){
    return num_of_votes;
}