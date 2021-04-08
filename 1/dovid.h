#ifndef DOVID_H
#define DOVID_H

#include <QDialog>

namespace Ui {
class Dovid;
}

class Dovid : public QDialog
{
    Q_OBJECT

public:
    explicit Dovid(QWidget *parent = nullptr);
    ~Dovid();

private:
    Ui::Dovid *ui;
};

#endif // DOVID_H
