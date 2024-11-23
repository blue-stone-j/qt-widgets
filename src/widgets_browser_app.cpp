
#include <QtWidgets/QApplication>

#include "mainwindow.h"
#include <QTranslator>
#include <QLocale>

#include "form/QsrRibbonCore.h"
#include "form/uiOffice2016.h"
// #include "form/QsfMainWindow.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  QString locale = QLocale::system().name(); // Detect system locale
  // locale= QLocale::system().nativeLanguageName();
  // locale= QLocale::system().NauruLanguage;
  qDebug() << locale;
  QTranslator translator;
  if (translator.load("../translations/cn.qm"))
  {
    app.installTranslator(&translator);
  }
  MainWindow w;
  w.show();

  // QtbMainWindow qw;
  // qw.show();

  // uiTEST_MainWindow qw;
  // qw.show();

  // uiOffice2016 qw2;
  // qw2.show();

  return app.exec();
}
