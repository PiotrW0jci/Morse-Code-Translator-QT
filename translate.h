#ifndef TRANSLATE_H
#define TRANSLATE_H
#include <QObject>
#include <algorithm>
#include <string>

using namespace std;


class Translate{
public:
    QString morseCode(string s);
    string morseEncode(char x);
    string morseDecode(string x);
    void choseLanguage(char x);
    string text;

};

#endif // TRANSLATE_H
