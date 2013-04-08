#ifndef __TOKENIZER_H
#define __TOKENIZER_H
#include <vector>
#include <string>
#include "token.h"
#define isWhiteSpace(A) (A == ' ' || A == '\n')  
class Tokenizer
{
   public:
      Tokenizer()
      {
         error = false;
         fileName = "";
      }
      std::vector<Token> tokenize(const std::vector<std::string> &);
      std::string getVariable(std::string, int &, const int);
      std::string getString(std::string, int &, const int);
      void setFilename(std::string fileName) { this->fileName = fileName; }
      bool isKeyword(std::string);
   private:
      bool error;
      std::string fileName;
};
#endif
