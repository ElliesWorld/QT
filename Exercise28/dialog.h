#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void onDivideClicked();
    void onMultiplyClicked();
    void onSubtractClicked();
    void onAddClicked();

private:
    QLineEdit *lineEditFirstNumber;
    QLineEdit *lineEditSecondNumber;
    QLineEdit *lineEditResult;
    QPushButton *btnDivide;
    QPushButton *btnMultiply;
    QPushButton *btnSubtract;
    QPushButton *btnAdd;
};

#endif // DIALOG_H
