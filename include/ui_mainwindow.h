
#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

#include "form/QsfTitleBar.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QAction *menuabout;
    QMenu *menuhelp;

    QsfTitleBar *titleBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
         {   MainWindow->setObjectName(QString::fromUtf8("widgets_browser"));}
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 201, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuabout = new QAction(menubar);
        menuabout->setObjectName(QString::fromUtf8("menuabout"));
        menuhelp = new QMenu(menubar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuhelp->menuAction());
        menubar->addAction(menuabout);

        titleBar = new QsfTitleBar(MainWindow);
        titleBar->move(0,400);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Widgets Browser", nullptr));

        menuabout->setText(QApplication::translate("MainWindow", "about", nullptr));
        menuhelp->setTitle(QApplication::translate("MainWindow", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
