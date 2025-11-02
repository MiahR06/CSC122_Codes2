#include <iostream>
#include <string>
#include <set>
#include <exception>
using namespace std;

class Unicorn {
public:
    string uniName;
    static set<string> names;

    Unicorn(const string& uniName){
        if (names.find(uniName) != names.end()){
            throw exception();
        }
        this->uniName = uniName;
        names.insert(uniName);
        cout << "Welcome, " << uniName << "!\n";
    }
    
    ~Unicorn(){
        names.erase(uniName);
        cout << "Rest in peace, " << uniName << "...\n";
    }
};

set<string> Unicorn::names;

int main() {
    try{
        Unicorn u1("Stardust");
        Unicorn u2("Fantasy");
        Unicorn u3("Wonder");
        Unicorn u4("Fantasy");
    }catch (const exception& n){
        cerr << "Error: This name is taken!" << endl;
    }

    return 0;
}


// https://www.w3schools.com/CPP/cpp_sets.asp