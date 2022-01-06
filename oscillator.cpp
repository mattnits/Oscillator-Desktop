#include "oscillator.h"
#include "ui_oscillator.h"


Oscillator::Oscillator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Oscillator)
{
    ui->setupUi(this);
    ui->songTable->horizontalHeader()->setStretchLastSection(true);
    ui->songTable->setColumnWidth(0, 190);
    ui->songTable->setColumnWidth(1, 190);
    ui->songTable->setColumnWidth(2, 30);
    ui->songTable->setColumnWidth(3, 30);
}

Oscillator::~Oscillator()
{
    delete ui;
}

void Oscillator::on_dbFileButton_clicked()

{
    std::vector<Song> songList;
    std::cout << "clicked";
    QString fileText = ui->dbFileText->text();
    QByteArray arr = fileText.toLocal8Bit();
    char *fname = arr.data();
    songList = parseCrate(fname);
    addSongsToTable(songList);
}



void Oscillator::on_dbOpenFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Serato DB File", "C://");
    ui->dbFileText->setText(filename);
}

void Oscillator::addSongsToTable(std::vector<Song> songList) {
    std::cout << songList.size();
    for (int i=0; i < songList.size(); i++) {
        ui->songTable->insertRow(ui->songTable->rowCount());
        ui->songTable->setItem(ui->songTable->rowCount()-1, 0, new QTableWidgetItem(QString::fromStdString(songList.at(i).getSongName())));
        ui->songTable->setItem(ui->songTable->rowCount()-1, 1, new QTableWidgetItem(QString::fromStdString(songList.at(i).getArtistName())));
        ui->songTable->setItem(ui->songTable->rowCount()-1, 2, new QTableWidgetItem(QString::number(songList.at(i).getSongBpm())));
        ui->songTable->setItem(ui->songTable->rowCount()-1, 3, new QTableWidgetItem(QString::fromStdString(songList.at(i).getSongKey())));
    }
}
