#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{

    //*****  METHOD 1 TO REPLACE SPECIFIC LINE IN A FILE.  *****

        string FILENAME = "testing.txt";
        int line_number = 3;
        string NEW_TEXT = "THREE";
        fstream READ_FILE(FILENAME);
        if (!READ_FILE)
        {
            cout << "Error: could not open file \""
                 << FILENAME << "\"" << endl;
        }
        string FILE_DATA;
        string line;
        int current_line_number = 1;
        while (getline(READ_FILE, line))
        {
            if (current_line_number == line_number)
            {
                FILE_DATA += NEW_TEXT + "\n";
            }
            else
            {
                FILE_DATA += line + "\n";
            }
            current_line_number++;
        }
        READ_FILE.close();
        ofstream WRITE_FILE(FILENAME);
        if (!WRITE_FILE)
        {
            cout << "Error: could not open file \""
                 << FILENAME << "\"" << endl;
        }
        WRITE_FILE << FILE_DATA;
        WRITE_FILE.close();

    //*****  METHOD 2 TO REPLACE SPECIFIC LINE IN A FILE.  *****

    string filename = "testing.txt";
    string text;
    int line_number;
    cout << "Text To Replace: ";
    getline(cin, text);
    cout << "Line Number: ";
    cin >> line_number;
    fstream read_file;
    read_file.open(filename);
    if (read_file.fail())
    {
        cout << "Error opening file." << endl;
    }
    vector<string> lines;
    string line;
    while (getline(read_file, line))
    {
        lines.push_back(line);
    }
    read_file.close();
    if (line_number > lines.size())
    {
        cout << "Line " << line_number
             << " does not exist " << endl
             << "File has " << lines.size()
             << " lines." << endl;
    }
    ofstream write_file;
    write_file.open(filename);
    if (write_file.fail())
    {
        cout << "Error opening file." << endl;
    }
    line_number--;
    for (int i = 0; i < lines.size(); i++)
    {
        if (i != line_number)
            write_file << lines[i] << endl;
        else
            write_file << text << endl;
    }
    write_file.close();
    

    return 0;
}
