#ifndef __KEYWORD_H
#define __KEYWORD_H
#include <string>
#define KEYWORDMAX 73
const std::string KEYWORDS[] = { "__CLASS__", "__DIR__", "__FILE__", "__FUNCTION__", "__half_compiler", "__LINE__", 
                                 "__METHOD__", "__NAMESPACE__", "__TRAIT__", "abstract", "and", "array", 
                                 "as", "break", "callable", "case", "catch", "class", 
                                 "clone", "const", "continue", "declare", "defaut", "die", 
                                 "do", "echo", "else", "elseif", "empty", "enddeclare", 
                                 "endfor", "endforeach", "endif", "endswitch", "endwhile", "eval", 
                                 "exit", "extends", "final", "for", "foreach", "function", 
                                 "global", "goto", "if", "implements", "include", "include_once", 
                                 "instanceof", "insteadof", "interface", "isset", "list", "namespace", 
                                 "new", "or", "print", "private", "protected", "public", 
                                 "require", "require_once", "return", "static", "switch", "throw", 
                                 "trait", "try", "unset", "use", "var", "while", "xor"};
#endif
