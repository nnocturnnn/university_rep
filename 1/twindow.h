#ifndef TWINDOW_H
#define TWINDOW_H

#include <QDialog>

namespace Ui {
class TWindow;
}

class TWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TWindow(QWidget *parent = nullptr);
    ~TWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TWindow *ui;
};

#endif // TWINDOW_H
