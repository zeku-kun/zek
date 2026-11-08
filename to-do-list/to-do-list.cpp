#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void take_return(vector<string> &list, string input);

int main(){
    bool running = true;
    vector<string> to_do = {};

    while(running){
        string input;

        cout << "Add to-do: ";
        getline(cin, input);
        system("cls");

        if(input == "quit"){
            running = false;
            continue;
        }

        take_return(to_do, input);

        cout<<"---To Do List---\n";
        for(size_t i = 0; i < to_do.size(); i++){
            cout<< i + 1 << ". " << to_do[i] << "\n";
        }
    }

    return 0;
}

void take_return(vector<string> &list, string input){
    list.emplace_back(input);
}

