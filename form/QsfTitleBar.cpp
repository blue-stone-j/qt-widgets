#include <QPixmap>
#include "QsfTitleBar.h"

QsfTitleBar::QsfTitleBar( QWidget *parent /*= NULL*/ )
:QWidget(parent)
{
 setStyleSheet("QLabel{background-color:transparent;border:1px solid red}");
    setAttribute(Qt::WA_TranslucentBackground);
    QWidget* backWidget = new QWidget;
    QHBoxLayout* backLayout = new QHBoxLayout;
    this->setLayout(backLayout);
    backLayout->addWidget(backWidget);
    backLayout->setMargin(0);
    backLayout->setSpacing(0);
    backWidget->setObjectName("TITLE_BACK_WIDGET");

    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);            //设置按钮组离边界的距离为5px
    layLeft = new QHBoxLayout;
    layLeft->setContentsMargins(0, 0, 0, 0);            //设置按钮组离边界的距离为5px

    layRight = new QHBoxLayout;
    layRight->setContentsMargins(0, 0, 0, 0);            //设置按钮组离边界的距离为5px
    layRight->setSpacing(0);

    m_titleLab = new QLabel;
    m_titleLab->setMouseTracking(false);
    backWidget->setLayout(m_layout);
    m_layout->addLayout(layLeft);
    m_layout->addStretch();
    m_layout->addWidget(m_titleLab);
    m_layout->addStretch();
    m_layout->addLayout(layRight);

    resize(parent->width(),20);

    pb1=new QPushButton();
    pb1->setText("pbone");
    addLeftAction(pb1);

    pb2=new QPushButton();
    pb2->setText("pbtwo");
    addRightAction(pb2);

    pb3=new QPushButton();
    pb3->setText("pbthree");
    addLeftAction(pb3);

    pb4=new QPushButton();
    pb4->setText("pbfour");
    addRightAction(pb4);

    setObjectName("QsfTitleBar");
}

QsfTitleBar::~QsfTitleBar()
{

}

void QsfTitleBar::setWindowTitle( QString title, Qt::Alignment tAlignment /*= Qt::AlignCenter*/ )
{
    m_titleLab->setText(title);
    m_titleLab->setAlignment(tAlignment);
}
void QsfTitleBar::addLeftAction( QPushButton* tAct )
{
    m_leftActions.append(tAct);
    layLeft->addWidget(tAct);
}

void QsfTitleBar::addRightAction( QPushButton* tAct )
{
    m_rightActions.append(tAct);
    layRight->addWidget(tAct);
}

QString QsfTitleBar::windowTitle()
{
    return m_titleLab->text();
}