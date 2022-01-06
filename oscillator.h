#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <QMainWindow>

namespace Ui {
class Oscillator;
}

class Oscillator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Oscillator(QWidget *parent = 0);
    ~Oscillator();

private slots:
    void on_dbFileButton_clicked();

private:
    Ui::Oscillator *ui;
};

#endif // OSCILLATOR_H
