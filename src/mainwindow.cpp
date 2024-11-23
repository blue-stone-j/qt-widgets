
#include "mainwindow.h"
#include <QApplication>
#include <QSvgRenderer>  // For QSvgRenderer
#include <QPixmap>       // For QPixmap
#include <QIcon>         // For QIcon
#include <QPainter>      // For QPainter
#include <QSize>         // For QSize

#include <QTranslator>

QIcon loadSvgIcon(const QString &svgFilePath, const QSize &size) {
    QSvgRenderer svgRenderer(svgFilePath);
    QPixmap pixmap(size);
    pixmap.fill(Qt::transparent);  // Ensure the background is transparent

    QPainter painter(&pixmap);
    svgRenderer.render(&painter);

    return QIcon(pixmap);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{

  ui->setupUi(this); // 创建界面
  this->setWindowIcon(loadSvgIcon("../assets/logo.svg",QSize(200,200)));

addWidgets();
  //(按钮,点击,this,需要执行的函数)
  connect(ui->menuabout, SIGNAL(triggered()), this, SLOT(openAbout()));

  connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxIndexChanged);

onComboBoxIndexChanged(0); 

}

void MainWindow::changeLanguage(const QString &languageCode) {
    static QTranslator translator;
    QApplication::removeTranslator(&translator);

    if (translator.load("../translations/" + languageCode + ".qm")) {
        QApplication::installTranslator(&translator);
    }

    // Re-translate UI elements
    ui->retranslateUi(this);
}

void MainWindow::onComboBoxIndexChanged(int index)
{
  for(const auto& widget:widgets)
  {widget->hide();}
  
  if(index<0||index>=widgets.size())
  {std::cout<<index<<":"<< widgets.size()<<std::endl;return;}
  widgets[index]->show();
}

#include "add_widgets.cpp"

MainWindow::~MainWindow()
{
delete ui;
}


// 关闭窗口前会先处理该事件函数
void MainWindow::closeEvent(QCloseEvent *event)
{
}

bool MainWindow::openAbout()
{
  QString text = "This is an example to display qt widgets.";
  QMessageBox::about(this, "about qt-widgets", text);
  return true;
}


