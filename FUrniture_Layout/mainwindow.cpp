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
    setFixedSize(800,500);
    /*Первый параметр задает координату левого верхнего угла по оси х, второй - по оси у
     *Третий задает ширину, четвертый - высоту.  Метод изменяет расположение и размеры виджета
     *одновремнно*/
    scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);
    //scene->setSceneRect(100,100,800,500);
    //view->setSceneRect(100,100,800,500);

    view->show();
    setCentralWidget(view);
    /*установка рабочей области в главном окне виджетаустанавливается этим методом*/
    scene->setBackgroundBrush(Qt::yellow);
    QToolBar *toolBar = addToolBar(tr("Menu"));
    addToolBar(Qt::BottomToolBarArea, toolBar);
    toolBar->setMovable(false);
    QAction *addbutton = toolBar->addAction("Add chair");
    addbutton->setIcon(QIcon (":\chair.png"));
    connect(addbutton, SIGNAL(triggered()), SLOT(on_AddChair_clicked()));
    toolBar->addSeparator();
    deleteButton = toolBar->addAction("Delete chair");
    deleteButton->setIcon(QIcon(":\deletechair"));
    deleteButton->setCheckable(true); //кнопка имеет статус выклчателя
    connect(deleteButton,SIGNAL(toggled(bool)), SLOT(on_DeleteButton_clicked(bool)));
}


void MainWindow::on_AddChair_clicked()
{
    QPixmap *pixmap = new QPixmap(":\chair.png");

    if (!deleteButton->isChecked())
    {
        item *chair = new item(*pixmap, false);
        scene->addItem(chair);
    }
    else
    {
        item *chair = new item(*pixmap, true);
        scene->addItem(chair);
    }

}

void MainWindow::on_DeleteButton_clicked(bool mode)
{
    foreach (QGraphicsItem *item1, scene->items())
    {
        static_cast<item*>(item1)->setDeleteMode(mode);
    }
}

MainWindow::~MainWindow()
{
}

