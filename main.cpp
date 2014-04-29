#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <vector>

//book title, <section, text>
std::map<std::string, std::map<std::string, std::string> > text;

void printRandomPassage()
{
    std::map<std::string, std::map<std::string, std::string> >::iterator book = text.begin();
    std::advance(book, std::rand() % text.size());

    std::map<std::string, std::string>::iterator passage = book->second.begin();
    std::advance(passage, std::rand() % book->second.size());

    std::cout << passage->second << std::endl; 



}

int main(void)
{
    std::srand(time(NULL));
    std::ifstream file("./tao-of-programming.txt");
    std::string current_book; 
    std::string current_section;
    bool invalid_section = true;

    for(std::string line; std::getline(file, line);)
    {
        if(line.find("Book ") != std::string::npos)
        {
            current_book = line;
            invalid_section = true;
        }
        else if(line.find("section") != std::string::npos)
        {
            current_section = line;
            invalid_section = false;
        }
        else if(!invalid_section)
        {
                text[current_book][current_section].append(line + "\n");
        }
    }

    printRandomPassage();
    return 0;
}
