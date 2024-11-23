/************************************************************************
* 文件名称： QsfTitleBar.h
* 内容摘要： 自定义界面标题栏类
* 其它说明： 自定义界面的标题栏，按照Office Ribbon的扁平化策略实现了一个左侧按钮+中间标题+用户文本+右侧按钮 的布局
************************************************************************/

#ifndef QSF_TITLEBAR_H
#define QSF_TITLEBAR_H

#include <QtCore/QString>

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QHBoxLayout>

class      QsfTitleBar : public QWidget
{
    Q_OBJECT

public:
    QsfTitleBar(QWidget *parent = NULL);
    ~QsfTitleBar();

    /** @brief  设置窗口标题.
    *
    *  @details 设置窗口标题.
    *  @param   title 窗口的标题.
    *  @return  .
    */
    void setWindowTitle(QString title, Qt::Alignment tAlignment = Qt::AlignCenter);
    QString windowTitle();

    void addLeftAction(QPushButton* tAct);
    void addRightAction(QPushButton* tAct);

private:
    QLabel* m_titleLab;
    QIcon* m_icon;

    QPushButton* pb1;
    QPushButton*pb2;
    QPushButton*pb3;
    QPushButton*pb4;

    QList<QPushButton*> m_leftActions;
    QList<QPushButton*> m_rightActions;

    QHBoxLayout* m_layout, *layLeft, *layRight;

};

#endif //QSF_TITLEBAR_H