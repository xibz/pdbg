#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "scanner/header/tokenizer.h"

std::vector<std::string> readFile(std::string);

std::vector<std::string> readFile(char *filename)
{
   std::ifstream in;
   std::vector<std::string> lines;
   in.open(filename, std::ifstream::in);
   while(!in.eof())
   {
      std::string lineTemp;
      std::getline(in, lineTemp);
      lines.push_back(lineTemp);
   }
   in.close();
   return lines;
}

int main(int argc, char *argv[])
{
   if(argc < 2)
   {
      std::cout << "Error: expects a file\n";
      return -1;
   }
   std::vector<std::string> lines = readFile(argv[1]);
   Tokenizer tokenizer;
   tokenizer.setFilename(argv[1]);
   tokenizer.tokenize(lines);
   return 0;
}
