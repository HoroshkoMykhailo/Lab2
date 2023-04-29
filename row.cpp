#include "row.h"
row:: row(){
    s = "";
    country = "";
    votes = nullptr;
    mark = 0;
    num_of_votes = 0;
}
row:: row(string line, int n){
    stringstream ss(line);
    s = line;
    votes = new int [n];
    mark = 0;
    string word;
    num_of_votes = n;
    int i = 0;
    if(!getline(ss, word, ',')){
        throw "File is emty";
    }
    country = word;
    while(getline(ss, word, ',')){
        votes[i] = stoi(word);
        i++;
    }
}
void row:: addmark(int n){
    mark += n;
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