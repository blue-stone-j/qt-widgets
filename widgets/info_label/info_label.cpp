#include "info_label.h"

InfoLabel::InfoLabel(QWidget *parent) : QWidget(parent)
{
  lab=new QLabel(this);
  lab->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
  info=new QLabel(this);
  info->setStyleSheet("QLabel{background-color:transparent;border:1px solid gray}");
  resize(170,30);
  setLab();
  setInfo();
}
void InfoLabel::resize(int w, int h)
{
  QWidget::resize( w,  h);
  lab->setGeometry(0,0,width()/3,height());
  info->setGeometry(width()/3+5,0,width()-5-width()/3,height());
}

void InfoLabel::setLab(QString txt)
{
  lab->setText(txt);
  return;
}

bool InfoLabel::setInfo(QString txt)
{
  info->setText(txt);
  return true;
}
