#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
     MainWindow();
    ~MainWindow();
    
protected slots:
    void on_AddChair_clicked();
    void on_DeleteButton_clicked(bool mode);

private:
    QGraphicsScene *scene;
    QAction *deleteButton;
};

#endif // MAINWINDOW_H
