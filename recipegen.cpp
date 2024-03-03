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
    string unit;
    int min;
    int max;
    bool isUsed;
    bool isWet;
    bool isDry;
};

void openFile(ifstream &inFile, string filename); // Open file. Exit if not found
void initarr(ifstream &inFile); // Input data into desert[], appetizer[], entree[]
void print_input(int cat); // Depreicated
void initList(string fname, unordered_map<string, ingrediant> &test1, bool isSpecial); // Input data into unordered map
void selectf(int cat); // Select a food from a category and randomly select ingrediants. Grab data from list
void loadSpecial(string addSpecial);

string * desert;
string * appetizer;
string * entree;
string * special;
int dSize;
int aSize;
int eSize;
int sSize;

unordered_map<string, ingrediant> list;
unordered_map<string, ingrediant> listSpecial;

int main(int argv, char* argc[]) {
    srand (time(NULL));
    desert = new string[100];
    dSize = 0;
    appetizer = new string[100];
    aSize = 0;
    entree = new string[100];
    eSize = 0;
    special = new string[100];
    sSize = 0;
    ifstream inFile;
    openFile(inFile, "cat.txt");
    initarr(inFile);
    // print_input(stoi(argc[argv - 1]));

    initList("ingrediants.txt", list, false); // Init list from txt file
    initList("special.txt", listSpecial, true); // Init list from txt file
    // cout << "list initialized" << endl;

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

void initList(string fname, unordered_map<string, ingrediant> &test1, bool isSpecial) {
    string input;
    int min;
    int max;
    string tag;
    ifstream inFile;

    openFile(inFile, fname);
    inFile >> input;
    while(!inFile.eof()) {
        string foodReal = input;
        ingrediant ingred;
        for(int i = 0; i <input.size(); i++) {
            if(input.at(i) == '_') {
                input.at(i) = ' ';
            }
        }
        ingred.name = input;
        inFile >> min;
        inFile >> max;
        ingred.min = min;
        ingred.max = max;
        ingred.isUsed = false;
        inFile >> tag;

        while(tag != ";") {
            if (tag == "dry") {
                ingred.isDry = true;
            } else if(tag == "wet") {
                ingred.isWet = true;
            }
            inFile >> tag;
        }
        if(isSpecial) {
            loadSpecial(foodReal);
        }
        test1[foodReal] = ingred;

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
        rannum = 0; // REMOVE THIS
        food = desert[rannum];
    } else if(cat == 2) {
        rannum = rand() % eSize;
        food = entree[rannum];
    } else if (cat == 3) {
        rannum = rand() % aSize;
        food = appetizer[rannum];
    }
    // Print food
    cout << food << " Recipe:\n";
    // Create stringName to Open
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

    // Each Catagory has a min and max on the number of ingrediants it can pull.
    int dMin = 2;
    int dMax = 5;
    int eMin = 4;
    int eMax = 12;
    int aMin = 1;
    int aMax = 3;

    int sMin = 2; // Special ingrediants
    int sMax = 2;

    // Regular Ingrediants
    int i = (rand() % (dMax - dMin + 1) + dMin);
    while(i > 0) {
        rannum = rand() % iSize;
        string in1 = iarr[rannum];
       // cout << in1 << " ";
       // Check to see if it is used
        if(list[in1].isUsed) {
        } else {
            list[in1].isUsed = true;
            ingrediant ingtest = list[in1];
            cout << "Add " << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " <unit> of " << ingtest.name << endl;
            i--;
        }
    }

    // Special Ingrediants

    rannum = rand() % sSize;
    string in2 = special[rannum];
    ingrediant ingtest = listSpecial[in2];
    cout << "Add " << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " <unit> of " << ingtest.name << endl;
    /*
    //test hashmap
    string intest = "Sugar";

    ingrediant ingtest = list[intest];
    if(ingtest.isDry) {
        cout << "Sugar is dry\n";
    }
    if (ingtest.isWet) {
        cout << "Sugar is wet\n";
    }
    cout << "Add " << (rand() % (ingtest.max - ingtest.min + 1) + ingtest.min) << " <unit> of " << ingtest.name << endl;
    */

   
}

void loadSpecial(string addSpecial) {
    special[sSize] = addSpecial;
    sSize++;
    return;
}