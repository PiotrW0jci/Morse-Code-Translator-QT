#ifndef HANDLETEXTFIELD_H
#define HANDLETEXTFIELD_H

#include <QObject>
#include <QDebug>

class HandleTextField : public QObject
{
    Q_OBJECT
public:
    explicit HandleTextField(QObject *parent = 0);

public slots:
    void handleSubmitTextField(const QString& in);
signals:
  void setTextField(QVariant text);


};


#endif // HANDLETEXTFIELD_H
