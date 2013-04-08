#ifndef __ERROR_H
#define __ERROR_H
#include <string>
#include <iostream>
class Error
{
   public:
   static void errMsg(std::string fileName, const int lineNum, const int colNum, std::string msg)
   {
      std::cout << fileName << ":" << lineNum << ":" << colNum << " " << msg << std::endl;
   }
};
#endif
