// Preet Panchal
// 100707094
// CSCI1061U - LAB03
// LAB CRN: 73921 - SEC: 005
// February 06, 2021

// part2.cpp - handles multiple files using IO REDIRECTION

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //to utilize setw()

using namespace std; 

int main(int argc, char* argv[]) {
    
    // variables hold total number of lines, words and bytes for all files inputted
    int totalLineCount = 0;
    int totalWordCount = 0; 
    int totalByteCount = 0; 

    // code remains same as in 'word count part 1' but it can handle multiple files
    // it loops through each file based on number of arguments it reads from commandline
    for (int i=1; i<argc; ++i) {
        // for each argument (ie. file), it will display number of lines, words
        //and bytes for each file respectively
        int lineCount = 0;
        int wordCount = 0; 
        int byteCount = 0; 

        string filename = argv[i]; 
        ifstream inf; 
        inf.open(filename.c_str()); 

        string word; 
        if (inf.is_open()) {
            while (inf >> word) {
                wordCount++; 
                totalWordCount++; 
            }
            inf.clear(); 
            inf.seekg(0, ios::beg); 
            string line; 
            while (getline(inf, line)) {
                lineCount++; 
                totalLineCount++; 
                byteCount += (line.length() + 1); 
                totalByteCount += (line.length() + 1); 
            }
        }
        inf.close(); 

        // displaying using setw to ensure accurate spacing btw numbers for each file
        cout << setw(8) << lineCount 
             << setw(8) << wordCount
		     << setw(8) << byteCount << ' ' << argv[i] << endl;
    }
    // displaying total for all numbers 
    cout << setw(8) << totalLineCount 
         << setw(8) << totalWordCount
         << setw(8) << totalByteCount << ' ' << "total" << endl;
    
    return 0; 
}

