#include "except_classes.h"
directory_error:: directory_error(string m): message(m){
}
const char* directory_error:: what() const throw(){
    return message.c_str();
}
void lines_error:: addMessage(string s){
    messages.push_back(s);
}
const char* lines_error:: what() const throw(){
    return "Lines error: ";
}
vector<string>& lines_error::  message(){
    return messages;
}
bool lines_error:: is_empty(){
    return messages.empty();
}