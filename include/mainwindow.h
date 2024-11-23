#include <iostream>

#include <QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QDir>
#include <QVector>
#include "ui_mainwindow.h"

#include "widgets/widgets.h"

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  // 本质是一个已定义好的宏，所有需要“信号和槽”功能的组件都必须将 Q_OBJECT 作为 private 属性成员引入到类中
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);

  ~MainWindow();

private:
  Ui::MainWindow *ui; // UI界面

  QVector<QWidget*> widgets; 
  void addWidgets();

  void changeLanguage(const QString &languageCode);

private slots:
  bool openAbout();               // 打开About窗口
  void onComboBoxIndexChanged(int index);

private:
  void closeEvent(QCloseEvent *event); // 发生关闭窗口事件后需要执行的函数

};