#ifndef __TOKEN_H
#define __TOKEN_H
#include <string>
class Token
{
   public:
      enum{ID, KEYWORD, VAR};
      Token()
      {
         lineNum = 0;
         tokenType = 0xFFFFFFFF;
         data = "";
      }
      Token(int n, int type, std::string data)
      {
         lineNum = n;
         tokenType = type;
         this->data = data;
      }
      void setLineNum(const int n) { lineNum = n; }
      void setTokenType(const int n) { tokenType = n; }
      void setData(std::string data) { this->data = data; }
   private:
      unsigned int lineNum;
      unsigned int tokenType;
      std::string data;
};
#endif
