#include "translate.h"



string Translate::morseEncode(char x){
    switch (x) {
     case ' ':
       return "  ";
     case 'a':
       return ".- ";
     case 'b':
       return "-... ";
     case 'c':
       return "-.-. ";
     case 'd':
       return "-.. ";
     case 'e':
       return ". ";
     case 'f':
       return "..-. ";
     case 'g':
       return "--. ";
     case 'h':
       return ".... ";
     case 'i':
       return ".. ";
     case 'j':
       return ".--- ";
     case 'k':
       return "-.- ";
     case 'l':
       return ".-.. ";
     case 'm':
       return "-- ";
     case 'n':
       return "-. ";
     case 'o':
       return "--- ";
     case 'p':
       return ".--. ";
     case 'q':
       return "--.- ";
     case 'r':
       return ".-. ";
     case 's':
       return "... ";
     case 't':
       return "- ";
     case 'u':
       return "..- ";
     case 'v':
       return "...- ";
     case 'w':
       return ".-- ";
     case 'x':
       return "-..- ";
     case 'y':
       return "-.-- ";
     case 'z':
       return "--.. ";
     }
}

string Translate::morseDecode(string x){
    if(x== "  ")
        return " ";
     if(x==".-")
       return "a";
      if(x=="-...")
       return "b";
      if(x=="-.-.")
       return "c";
      if(x=="-..")
       return "d";
      if(x==".")
       return "e";
      if(x=="..-.")
       return "f";
      if(x=="--.")
       return "g";
      if(x=="....")
       return "h";
      if(x=="..")
       return "i";
      if(x==".---")
       return "j";
      if(x=="-.-")
       return "k";
      if(x==".-..")
       return "l";
      if(x=="--")
       return "m";
      if(x=="-.")
       return "n";
      if(x=="---")
       return "o";
      if(x==".--.")
       return "p";
      if(x=="--.-")
       return "q";
      if(x==".-.")
       return "r";
      if(x=="...")
       return "s";
      if(x=="-")
       return "t";
      if(x=="..-")
       return "u";
      if(x=="...-")
       return "v";
      if(x==".--")
       return "w";
      if(x=="-..-")
       return "x";
      if(x=="-.--")
       return "y";
      if(x=="--..")
       return "z";

     }

QString Translate::morseCode(string s) {



    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string morseLetter = "";

    if (s[0] == '-' || s[0] == '.')        
      for (int i = 0; s[i]; i++) {
        if (s[i] == ' '&&s[i + 1] == ' ') {
          text += " ";
          i++;
        }
        else {
            if(s[s.length()]!=' ')
                        s=s+' ';
          while (s[i] != ' '&&i != s.length()) {
            morseLetter += s[i];
            i++;
          }
          text += morseDecode(morseLetter);
          morseLetter = "";
        }
      }
    else
      for (int i = 0; s[i]; i++)
        text += morseEncode(s[i]);
  QString qstr = QString::fromStdString(text);
  return qstr;
}

