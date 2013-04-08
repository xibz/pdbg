#include "header/tokenizer.h"
#include "header/token.h"
#include "header/error.h"
#include <string>
#include <ctype.h>
#include "../keywords.h"

/*
   @function std::vector<Token> Tokenizer::tokenize(const std::vector<std::string> &lines)
      This function will tokenize the file
      @param
         std::vector<std::string> lines 
            each line of the file
      @return std::vecto<Token>
         return a string of tokens
*/
std::vector<Token> Tokenizer::tokenize(const std::vector<std::string> &lines)
{
   std::vector<Token> tokens;
   for(int i = 0; i < lines.size(); ++i)
   {
      for(int j = 0; j < lines[i].length(); ++j)
      {
         if(isalpha(lines[i][j]))
         {
            std::string word = getString(lines[i], j, i);
            int type = (isKeyword(word))? Token::KEYWORD:Token::ID;
            Token token(i, type , word);
            tokens.push_back(token);
         }
         else if(lines[i][j] == '$')
         {
           Token token(i, Token::VAR, getVariable(lines[i], j, i));
           tokens.push_back(token);
         }
         else if(lines[i][j] == '<')
         {
            if(j+4 < lines[i].length())
            {
               if(lines[i][j+1] == '?' && lines[i][j+2] == 'p' &&
                  lines[i][j+3] == 'h' && lines[i][j+4] == 'p')
               {
                  //Check for php init, <?php
                  Token token(i, Token::KEYWORD, "<?php");
                  j+=4;
               }
               else
               {
                  //Check for <, <=, <<
               }
            }
         }
      }
   }
   return tokens;
}

/*
   @function std::string Tokenizer::getVariable(std::string line, int &j, const int lineNum)
      will grab the variable string
      @param
         std::string line
            a line within the file 
         int j
            column index within the line
         const int lineNum
            current line number of the file
      @return std::string
         returns the variable string name
*/
std::string Tokenizer::getVariable(std::string line, int &j, const int lineNum)
{
   if(isdigit(line[j]))
   {
      Error::errMsg(fileName, lineNum, j, "Error: Variable must start with an alphabet letter");
      error = true;
   }
   std::string data = "";
   while(j < line.length() && isalnum(line[j]) || line[j] == '_') data += line[j++];
   if(j < line.length() && line[j] != ' ' && line[j] != ';')
   {
      Error::errMsg(fileName, lineNum, j, "Error: Variable cannot contain a "+line[j]); 
      while(j < line.length() && line[j] != ' ' && line[j] != ';') ++j;
      error = true;
   }
   return data;
}

/*
   @function std::string Tokenizer::getString(std::string line, int &j, const int lineNum)
      will grab a string within the file
      @param
         std::string line
            a line within the file
         int j
            column index within the line
         const int lineNum
            current line number of the file
      @return std::string
         returns a string id
*/
std::string Tokenizer::getString(std::string line, int &j, const int lineNum)
{
   std::string data = "";
   while(j < line.length() && isalpha(line[j]) || line[j] == '_') data += line[j++];
   return data;
}

/*
   @function bool Tokenizer::isKeyword(std::string word)
      function will check to see whether or not a string is a keyword
      @param
         word
            a word within the file
      @return bool
         if it is a keyword return true, else false
*/
bool Tokenizer::isKeyword(std::string word)
{
   for(int i = 0; i < KEYWORDMAX; ++i)
      if(word == KEYWORDS[i]) return true;
   return false;
}
