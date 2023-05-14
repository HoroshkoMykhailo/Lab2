#include<exception>
#include <iostream>
#include <dirent.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;
class directory_error : public exception{
    string message;
public:
    directory_error(string);
    const char* what() const throw() override;
};
class lines_error: public exception{
    vector<string> messages;
public:
    void addMessage(string);
    const char* what() const throw() override;
    vector<string>& message();
    bool is_empty();
};