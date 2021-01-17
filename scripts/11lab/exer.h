#ifndef EXER_H
#define EXER_H

#include <QDialog>

namespace Ui {
class Exer;
}

class Exer : public QDialog
{
    Q_OBJECT

public:
    explicit Exer(QWidget *parent = nullptr);
    ~Exer();

private:
    Ui::Exer *ui;
};

#endif // EXER_H
