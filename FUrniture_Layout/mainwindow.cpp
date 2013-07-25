#include "mainwindow.h"
#include "item.h"

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QAction>
#include <QToolBar>

MainWindow::MainWindow()
{
    setWindowTitle("Yout chair's layout");
    setGeometry(100,100,800, 500);
    scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,500);
    view->show();
    setCentralWidget(view);
    scene->setBackgroundBrush(Qt::yellow);
    rectPen = QPen(Qt::black);
    rectPen.setWidth(2);
    scene->addLine(50,50,50,450,rectPen);
    scene->addLine(50,50,450,50,rectPen);
    scene->addLine(450,50,450,450,rectPen);
    scene->addLine(50,450,450,450,rectPen);
    QToolBar *toolBar = addToolBar(tr("Menu"));
    addToolBar(Qt::BottomToolBarArea, toolBar);
    toolBar->setMovable(false);
    QAction *addbutton = toolBar->addAction("Add chair");
    addbutton->setIcon(QIcon (":\chair.png"));
    connect(addbutton, SIGNAL(triggered()), SLOT(on_AddChair_clicked()));
    toolBar->addSeparator();
    deleteButton = toolBar->addAction("Delete chair");
    deleteButton->setIcon(QIcon(":\deletechair"));
    deleteButton->setCheckable(true); //the button have the switch's status
    connect(deleteButton,SIGNAL(toggled(bool)), SLOT(on_DeleteButton_clicked(bool)));
}


void MainWindow::on_AddChair_clicked()
{
    QPixmap *pixmap = new QPixmap(":\chair.png");

    if (!deleteButton->isChecked())
    {
        item *chair = new item(*pixmap, false);
        scene->addItem(chair);
        chair->setPos(50,50);

    }
    else
    {
        item *chair = new item(*pixmap, true);
        scene->addItem(chair);
        chair->setPos(50,50);
    }

}

void MainWindow::on_DeleteButton_clicked(bool mode)
{
    foreach (QGraphicsItem *item1, scene->items())
    {
        static_cast<item *>(item1)->setDeleteMode(mode);
    }
}

MainWindow::~MainWindow()
{
}

