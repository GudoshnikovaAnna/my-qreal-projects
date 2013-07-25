#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("BROWSER");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    loadUrl();
}

void MainWindow::loadUrl()
{
    ui->webView->load(QUrl(ui->lineEdit->text()));
}


