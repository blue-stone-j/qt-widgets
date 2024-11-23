﻿/************************************************************************
* 文件名称： QsfToolButton.cpp
************************************************************************/


#include "QsfToolButton.h"


QsfToolButton::QsfToolButton( QWidget * parent /*= 0 */ )
:QPushButton(parent)
{
    resize(16,16);
    setObjectName("RibbonToolButton");
}
QsfToolButton::~QsfToolButton()
{

}

void QsfToolButton::enterEvent( QEvent *event )
{
    QPushButton::setIcon(m_icon_hover);
    QPushButton::enterEvent(event);
}

void QsfToolButton::leaveEvent( QEvent * event)
{
    QPushButton::setIcon(m_icon);
    QPushButton::leaveEvent(event);
}

// void QsfToolButton::setIcon(QIcon icon)
// {
//     setIcon(icon, icon);
// }
// 
// void QsfToolButton::setIcon( QIcon icon1, QIcon icon2 )
// {
//     m_iconIn = icon1;
//     m_iconOut = icon2;
//     QPushButton::setIcon(m_iconOut);
// }
// 
// void QsfToolButton::setIcon( QPixmap iconIn, QPixmap iconOut )
// {
//     setIcon(QIcon(iconIn), QIcon(iconOut));
//     setIconSize(iconIn.size());
//     setFixedSize(iconIn.size());
// }
// 
// void QsfToolButton::setIcon( QString fileIn, QString fileOut )
// {
//     setIcon(QPixmap(fileIn), QPixmap(fileOut));
// }

void QsfToolButton::setIcon( QString icon, QString icon_hover, QString icon_pressed )
{
    m_icon = QIcon(icon);
    m_icon_hover = QIcon(icon_hover);
    m_icon_pressed = QIcon(icon_pressed);
    QPushButton::setIcon(m_icon);
}
// void QsfToolButton::setButtonIcon( QPushButton* tBtn, QString filename, bool asIconSize/*=true*/ )
// {
//     QPixmap pm(filename);
//     tBtn->setIcon(QIcon(pm));
//     tBtn->setIconSize(pm.size());
//     if(asIconSize)
//         tBtn->setFixedSize(pm.size());
// }

void QsfToolButton::mousePressEvent(QMouseEvent *e)
{
    QPushButton::setIcon(m_icon_pressed);
    QPushButton::mousePressEvent(e);
}

void QsfToolButton::mouseReleaseEvent(QMouseEvent *e)
{
    QPushButton::setIcon(m_icon);
    QPushButton::mouseReleaseEvent(e);
}