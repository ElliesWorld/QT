#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
      lineEditFirstNumber(new QLineEdit(this)),
      lineEditSecondNumber(new QLineEdit(this)),
      lineEditResult(new QLineEdit(this)),
      btnDivide(new QPushButton("Divide", this)),
      btnMultiply(new QPushButton("Multiply", this)),
      btnSubtract(new QPushButton("Subtract", this)),
      btnAdd(new QPushButton("Add", this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    formLayout->addRow("First number", lineEditFirstNumber);
    formLayout->addRow("Second number", lineEditSecondNumber);
    formLayout->addRow("Result", lineEditResult);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btnDivide);
    buttonLayout->addWidget(btnMultiply);
    buttonLayout->addWidget(btnSubtract);
    buttonLayout->addWidget(btnAdd);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
    setWindowTitle("Calculator");

    connect(btnDivide, &QPushButton::clicked, this, &Dialog::onDivideClicked);
    connect(btnMultiply, &QPushButton::clicked, this, &Dialog::onMultiplyClicked);
    connect(btnSubtract, &QPushButton::clicked, this, &Dialog::onSubtractClicked);
    connect(btnAdd, &QPushButton::clicked, this, &Dialog::onAddClicked);
}

Dialog::~Dialog()
{
}

void Dialog::onDivideClicked()
{
    bool ok1, ok2;
    double num1 = lineEditFirstNumber->text().toDouble(&ok1);
    double num2 = lineEditSecondNumber->text().toDouble(&ok2);
    if (ok1 && ok2)
    {
        if (num2 != 0)
        {
            double result = num1 / num2;
            lineEditResult->setText(QString::number(result));
        }
        else
        {
            QMessageBox::warning(this, "Math Error", "Division by zero is not allowed.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Input Error", "Please enter valid numbers.");
    }
}

void Dialog::onMultiplyClicked()
{
    bool ok1, ok2;
    double num1 = lineEditFirstNumber->text().toDouble(&ok1);
    double num2 = lineEditSecondNumber->text().toDouble(&ok2);
    if (ok1 && ok2)
    {
        double result = num1 * num2;
        lineEditResult->setText(QString::number(result));
    }
    else
    {
        QMessageBox::warning(this, "Input Error", "Please enter valid numbers.");
    }
}

void Dialog::onSubtractClicked()
{
    bool ok1, ok2;
    double num1 = lineEditFirstNumber->text().toDouble(&ok1);
    double num2 = lineEditSecondNumber->text().toDouble(&ok2);
    if (ok1 && ok2)
    {
        double result = num1 - num2;
        lineEditResult->setText(QString::number(result));
    }
    else
    {
        QMessageBox::warning(this, "Input Error", "Please enter valid numbers.");
    }
}

void Dialog::onAddClicked()
{
    bool ok1, ok2;
    double num1 = lineEditFirstNumber->text().toDouble(&ok1);
    double num2 = lineEditSecondNumber->text().toDouble(&ok2);
    if (ok1 && ok2)
    {
        double result = num1 + num2;
        lineEditResult->setText(QString::number(result));
    }
    else
    {
        QMessageBox::warning(this, "Input Error", "Please enter valid numbers.");
    }
}
