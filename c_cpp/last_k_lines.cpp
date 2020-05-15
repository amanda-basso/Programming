/* This code implements a method that shows the last k lines of a file*/
#include<iostream>
#include<fstream>

using namespace std;

int main(int argc, char *argv[])
{
    //char *dados = new char[100];
    char dados[100];
    // Opens a file in read mode
    ifstream infile;
    infile.open(argv[1]);

    cout << "Informations on the file:" << endl;
    infile >> dados;

    // Prints the data
    cout << dados << endl;

    //Closes th file
    infile.close();

    //delete dados;
    return 0;
}
