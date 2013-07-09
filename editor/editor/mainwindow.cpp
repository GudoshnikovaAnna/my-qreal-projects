#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openButton_clicked()
{
  openFile();
}

void MainWindow::openFile()
{
    QString FileName = QFileDialog::getOpenFileName(this,tr("Open File"), "", tr ("Files(*.*)"));
    QFile inputFile(FileName);
    inputFile.open(QIODevice::ReadOnly);

      QTextStream in(&inputFile);
      QString line = in.readAll();
      inputFile.close();

      ui->textEdit->setPlainText(line);
      QTextCursor cursor = ui->textEdit->textCursor();
      cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}



void MainWindow::on_SaveButton_clicked()
{
  //  QString line = ui->textEdit->;
  //  QTextStream out(&line);
    QString FileName1 = QFileDialog::getSaveFileName(this,tr("Save File"),"", tr(".txt"));
    QFile outFile(FileName1);
    outFile.open((QIODevice::WriteOnly));
    outFile.write(ui->textEdit->toPlainText().toUtf8());
    outFile.close();

}

void MainWindow::saveFile(){
}

