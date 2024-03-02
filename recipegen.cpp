/*
Team: Syntax Samurai
Dalton Weiland, Jakob Clark, Zachary Bluhm
03/2/24
Trash Taste
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct ingrediant {
    string name;
    int min;
    int max;
    bool isWet;
    bool isDry;
    string tags;
};

void openFile(ifstream &inFile, string filename);
void initarr(ifstream &inFile);
void print_input(int cat);
void initList();
void selectf(int cat);

string * desert;
string * appetizer;
string * entree;
int dSize;
int aSize;
int eSize;
unordered_map<string, ingrediant> list;


int main(int argv, char* argc[]) {
    srand (time(NULL));
    desert = new string[100];
    dSize = 0;
    appetizer = new string[100];
    aSize = 0;
    entree = new string[100];
    eSize = 0;
    ifstream inFile;
    openFile(inFile, "cat.txt");
    initarr(inFile);
    print_input(stoi(argc[argv - 1]));

    initList();
    cout << "list initialized" << endl;

    selectf(1);

    return 0;
}

void openFile(ifstream &inFile, string filename){
    inFile.open(filename);
    if (inFile.is_open()){
        //cout << "Opened File" << endl;
    } else {
        cout << "No Open File" << endl;
        exit(-1);
    }
}

void initarr(ifstream &inFile){
    string input;
    int cat;
    inFile >> input;
    while(!inFile.eof()) {
        if(input == "Desert") {
          //  printf("Desert found\n");
            cat = 1;
        } else if (input == "Appetizer") {
            cat = 3;
        } else if (input == "Entree") {
            cat = 2;
        } else {
          //  cout <<"Added " << input << " to an arr\n";
            if(cat == 1) {
                desert[dSize] = input;
                dSize++;
            } else if(cat == 2) {
                entree[eSize] = input;
                eSize++;
            } else if(cat == 3) {
                appetizer[aSize] = input;
                aSize++;
            }
        }
        inFile >> input;
    }
}

void print_input(int cat) {
    if(cat == 1) {
        for(int i = 0; i < dSize; i++) {
            cout << desert[i] << endl;
        }
    } else if(cat == 2) {
        for(int i = 0; i < eSize; i++) {
            cout << entree[i] << endl;
        }
    } else if(cat == 3) {
        for(int i = 0; i < aSize; i++) {
            cout << appetizer[i] << endl;
        }
    }
}

void initList() {
    string input;
    int min;
    int max;
    string tag;
    ifstream inFile;

    openFile(inFile, "ingrediants.txt");
    inFile >> input;
    while(!inFile.eof()) {
        ingrediant ingred;
        ingred.name = input;
        inFile >> min;
        inFile >> max;
        inFile >> tag;
        ingred.tags = tag;
        ingred.min = min;
        ingred.max = max;
        list[ingred.name] = ingred;

        inFile >> input;
    }
}

void selectf(int cat) { // 1 Desert, 2 Entree, 3 Appetizer
    int rannum;
    string food;
    string input;
    ifstream foodfile;
    if(cat == 1) {
        rannum = rand() % dSize;
        // Debug Code
        rannum = 0;
        food = desert[rannum];
    } else if(cat == 2) {
        rannum = rand() % eSize;
        food = entree[rannum];
    } else if (cat == 3) {
        rannum = rand() % aSize;
        food = appetizer[rannum];
    }
    food +=".txt";
    openFile(foodfile,food);


    // Init ingrediant arr from 'food'.txt
    int iSize = 0;
    string iarr[100];
    foodfile >> input;
    while(!foodfile.eof()) {
        iarr[iSize] = input;
        iSize++;
        foodfile >> input;
    }

    // Each Catagorie has a min and max on the number of ingrediants it can pull.
    int dMin = 2;
    int dMax = 5;
    int eMin = 4;
    int eMax = 12;
    int aMin = 1;
    int aMax = 3;

    for(int i = (rand() % (dMax - dMin + 1) + dMin); i > 0; i--) {
        rannum = rand() % iSize;
        string in1 = iarr[rannum];
        cout << in1 << endl;
    }

    //test hashmap
    string intest = "Sugar";

    ingrediant ingtest = list[intest];

    cout << "Add " << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " <unit> of " << ingtest.name << endl;

}