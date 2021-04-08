#ifndef SWINDOW_H
#define SWINDOW_H

#include <QDialog>

namespace Ui {
class SWindow;
}

class SWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SWindow(QWidget *parent = nullptr);
    ~SWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SWindow *ui;
};

#endif // SWINDOW_H
