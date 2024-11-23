#include "bar.h"

Bar::Bar() : QWidget() {}
Bar::Bar(QWidget *parent) : QWidget(parent)
{
  background = new QLabel(this);
  background->setStyleSheet("QLabel{background-color:transparent;border:1px solid gray}"); // You can also use a picture
  colorbar = new QLabel(this);
  setRange();

  QWidget::resize(500,50);
  background->setGeometry(0,0,width(),height());
  colorbar->setGeometry(1,1,width()-2,height()-2);
  colorbar->setAutoFillBackground(true);

  updateValue();

  update();
}

Bar::~Bar()
{
  delete background;
  delete colorbar;
}

void Bar::resize(int w, int h)
{
  QWidget::resize(w,h);

  background->resize(width(), height());
  draw();
}


bool Bar::updateValue(float valueIn)
{
  setCurrValue(valueIn);
  draw();
  return true;
}

void Bar::setCurrValue(float valueIn)
{
  if (valueIn > min && valueIn < max)
  {
    currPentcent = (valueIn - min)/range*100;
  }
  else if (valueIn < min)
  {
    currPentcent = 0;
  }
  else if (valueIn > max)
  {
    currPentcent = 100;
  }
}

void Bar::draw()
{
  colorbar->resize(currPentcent*width()/100, height()-2);
  // display different color
  QPalette pa;
  QColor cur_color;
  if (currPentcent > 40)
  {
    cur_color=QColor(255*(100-currPentcent)/(100-40),255,0);

  }
  else if (currPentcent > 15)
  {
    cur_color= QColor(255,255*(currPentcent-15)/(40-15),0);
  }
  else
  {
    cur_color=QColor(255,0,0);
  }
  pa.setColor(QPalette::Window, cur_color);
  colorbar->setPalette(pa);

//  QPalette bg_pa=background->palette();
//  bg_pa.setColor(QPalette::WindowText, cur_color);
//  background->setPalette(bg_pa);
}

void Bar::setRange(float minIn, float maxIn)
{
  if(maxIn - minIn < 0.0001) // make sure input right range
  {
    min = 0;
    max = 100;
    range = 100;
    return;
  }
  min = minIn;
  max = maxIn;
  range = max - min;
}
