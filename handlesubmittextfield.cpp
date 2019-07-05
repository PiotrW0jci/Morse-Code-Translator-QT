#include "handletextfield.h"
#include "translate.h"


using namespace  std;

/*
 * This class handles interactions with the text field
 */


HandleTextField::HandleTextField(QObject *parent) :
    QObject(parent)
{
}

void HandleTextField::handleSubmitTextField(const QString &in)
{
    qDebug() << "c++: HandleTextField::handleSubmitTextField:" << in;
    Translate translate;
    emit setTextField(QVariant(translate.morseCode(in.toStdString())));
}


