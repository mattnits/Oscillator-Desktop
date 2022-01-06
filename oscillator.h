#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "parseCrate.h"

namespace Ui {
class Oscillator;
}

class Oscillator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Oscillator(QWidget *parent = 0);
    ~Oscillator();
    void addSongsToTable(std::vector<Song> songList);

private slots:
    void on_dbFileButton_clicked();
    void on_dbOpenFile_clicked();

private:
    Ui::Oscillator *ui;
};

#endif // OSCILLATOR_H
