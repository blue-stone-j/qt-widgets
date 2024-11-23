#ifndef BAR_H
#define BAR_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QPainter>
#include <QString>
#include <QDebug>

/*
This Bar is consisted by background and changeable bar. Background is lower layer.
*/

class Bar : public QWidget
{
  Q_OBJECT
 public:
  Bar();
  Bar(QWidget *parent);
  ~Bar();
  bool updateValue(float valueIn = 30);
  void setRange(float minIn = 0, float maxIn = 100);
  void resize(int w, int h ); // change size of bar 

 private:
  void setCurrValue(float valueIn = 30);
  void draw();
  
  QLabel *background, *colorbar; // background color; bar col0r
  int currPentcent; // calculate current/range to get width of bar
  float min, max, range;

};
#endif // BAR_H
