/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox_OI;
    QPushButton *pushButton_OI_CF;
    QToolButton *toolButton_OI;
    QLabel *label_OI_i;
    QWidget *widget_OI_WH;
    QHBoxLayout *horizontalLayout;
    QLabel *label_OI_WH_SUBTITLE;
    QLabel *label_OI_WH_NUM;
    QPushButton *pushButton_convert;
    QProgressBar *progressBar;
    QGroupBox *groupBox_GA;
    QLabel *label_GA;
    QToolButton *toolButton_GA;
    QLabel *label_GA_i;
    QWidget *widget_GA_WH;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_GA_WH_SUBTITLE;
    QLabel *label_GA_WH_NUM;
    QWidget *widget_GA_h;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_GA_h;
    QGroupBox *groupBox_ADJ;
    QGroupBox *groupBox_ADJ_TH;
    QSlider *horizontalSlider_ADJ_TH;
    QLCDNumber *lcdNumber_ADJ_TH;
    QLabel *label_ADJ;
    QComboBox *comboBox_ADJ;
    QPushButton *pushButton_ADJ_H;
    QPushButton *pushButton_RESET;
    QWidget *widget_ADJ_SA;
    QLabel *label_ADJ_SA_BC;
    QFrame *frame_ADJ_SA_BC;
    QLabel *label_ADJ_SA_BC_B;
    QLabel *label_ADJ_SA_BC_C;
    QSlider *verticalSlider_ADJ_SA_BC_C;
    QSlider *verticalSlider_ADJ_SA_BC_B;
    QLCDNumber *lcdNumber_ADJ_SA_BC_B;
    QLCDNumber *lcdNumber_ADJ_SA_BC_C;
    QWidget *widget_ADJ_ES;
    QFrame *frame_ADJ_ES;
    QLabel *label_ADJ_ES_SUBTITLE;
    QSlider *verticalSlider_ADJ_ES;
    QLCDNumber *lcdNumber_ADJ_ES;
    QLabel *label_ADJ_ES_TITLE;
    QLabel *label_ADJ_ES_GS_TITLE;
    QComboBox *comboBox_ADJ_ES_GS;
    QGroupBox *groupBox_GBA;
    QToolButton *toolButton_GBA;
    QLabel *label_GBA_i;
    QWidget *widget_GBA_WH;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_GBA_WH_SUBTITLE;
    QLabel *label_GBA_WH_NUM;
    QWidget *widget_GBA_h;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_GBA_h;
    QGroupBox *groupBox_GAA;
    QToolButton *toolButton_GAA;
    QLabel *label_GAA_i;
    QWidget *widget_GAA_WH;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_GAA_WH_SUBTITLE;
    QLabel *label_GAA_WH_NUM;
    QWidget *widget_GAA_h;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_GAA_h;
    QCheckBox *checkBox_COMPARE;
    QGroupBox *groupBox_GB;
    QLabel *label_GB;
    QToolButton *toolButton_GB;
    QLabel *label_GB_i;
    QWidget *widget_GB_WH;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_GB_WH_SUBTITLE;
    QLabel *label_GB_WH_NUM;
    QWidget *widget_GB_h;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_GB_h;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1580, 1030);
        Widget->setMinimumSize(QSize(1580, 1030));
        groupBox_OI = new QGroupBox(Widget);
        groupBox_OI->setObjectName(QStringLiteral("groupBox_OI"));
        groupBox_OI->setGeometry(QRect(10, 10, 427, 505));
        pushButton_OI_CF = new QPushButton(groupBox_OI);
        pushButton_OI_CF->setObjectName(QStringLiteral("pushButton_OI_CF"));
        pushButton_OI_CF->setGeometry(QRect(13, 438, 400, 25));
        pushButton_OI_CF->setMinimumSize(QSize(400, 25));
        pushButton_OI_CF->setMouseTracking(false);
        toolButton_OI = new QToolButton(groupBox_OI);
        toolButton_OI->setObjectName(QStringLiteral("toolButton_OI"));
        toolButton_OI->setGeometry(QRect(13, 410, 31, 25));
        label_OI_i = new QLabel(groupBox_OI);
        label_OI_i->setObjectName(QStringLiteral("label_OI_i"));
        label_OI_i->setGeometry(QRect(13, 28, 400, 400));
        widget_OI_WH = new QWidget(groupBox_OI);
        widget_OI_WH->setObjectName(QStringLiteral("widget_OI_WH"));
        widget_OI_WH->setGeometry(QRect(270, 465, 150, 38));
        horizontalLayout = new QHBoxLayout(widget_OI_WH);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_OI_WH_SUBTITLE = new QLabel(widget_OI_WH);
        label_OI_WH_SUBTITLE->setObjectName(QStringLiteral("label_OI_WH_SUBTITLE"));
        label_OI_WH_SUBTITLE->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_OI_WH_SUBTITLE);

        label_OI_WH_NUM = new QLabel(widget_OI_WH);
        label_OI_WH_NUM->setObjectName(QStringLiteral("label_OI_WH_NUM"));
        label_OI_WH_NUM->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_OI_WH_NUM);

        pushButton_OI_CF->raise();
        label_OI_i->raise();
        toolButton_OI->raise();
        widget_OI_WH->raise();
        pushButton_convert = new QPushButton(Widget);
        pushButton_convert->setObjectName(QStringLiteral("pushButton_convert"));
        pushButton_convert->setGeometry(QRect(449, 209, 241, 81));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(460, 300, 211, 21));
        progressBar->setValue(0);
        groupBox_GA = new QGroupBox(Widget);
        groupBox_GA->setObjectName(QStringLiteral("groupBox_GA"));
        groupBox_GA->setGeometry(QRect(700, 10, 426, 505));
        groupBox_GA->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_GA->setFlat(true);
        label_GA = new QLabel(groupBox_GA);
        label_GA->setObjectName(QStringLiteral("label_GA"));
        label_GA->setGeometry(QRect(13, 446, 400, 17));
        label_GA->setMinimumSize(QSize(400, 0));
        label_GA->setAlignment(Qt::AlignCenter);
        toolButton_GA = new QToolButton(groupBox_GA);
        toolButton_GA->setObjectName(QStringLiteral("toolButton_GA"));
        toolButton_GA->setGeometry(QRect(13, 410, 31, 25));
        label_GA_i = new QLabel(groupBox_GA);
        label_GA_i->setObjectName(QStringLiteral("label_GA_i"));
        label_GA_i->setGeometry(QRect(13, 28, 400, 400));
        widget_GA_WH = new QWidget(groupBox_GA);
        widget_GA_WH->setObjectName(QStringLiteral("widget_GA_WH"));
        widget_GA_WH->setGeometry(QRect(270, 465, 150, 38));
        horizontalLayout_3 = new QHBoxLayout(widget_GA_WH);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_GA_WH_SUBTITLE = new QLabel(widget_GA_WH);
        label_GA_WH_SUBTITLE->setObjectName(QStringLiteral("label_GA_WH_SUBTITLE"));
        label_GA_WH_SUBTITLE->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_GA_WH_SUBTITLE);

        label_GA_WH_NUM = new QLabel(widget_GA_WH);
        label_GA_WH_NUM->setObjectName(QStringLiteral("label_GA_WH_NUM"));
        label_GA_WH_NUM->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_GA_WH_NUM);

        widget_GA_h = new QWidget(groupBox_GA);
        widget_GA_h->setObjectName(QStringLiteral("widget_GA_h"));
        widget_GA_h->setGeometry(QRect(10, 120, 410, 280));
        widget_GA_h->setAutoFillBackground(true);
        horizontalLayoutWidget = new QWidget(widget_GA_h);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 391, 261));
        horizontalLayout_GA_h = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_GA_h->setSpacing(6);
        horizontalLayout_GA_h->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_GA_h->setObjectName(QStringLiteral("horizontalLayout_GA_h"));
        horizontalLayout_GA_h->setContentsMargins(0, 0, 0, 0);
        label_GA->raise();
        label_GA_i->raise();
        toolButton_GA->raise();
        widget_GA_WH->raise();
        widget_GA_h->raise();
        groupBox_ADJ = new QGroupBox(Widget);
        groupBox_ADJ->setObjectName(QStringLiteral("groupBox_ADJ"));
        groupBox_ADJ->setGeometry(QRect(10, 550, 681, 470));
        groupBox_ADJ_TH = new QGroupBox(groupBox_ADJ);
        groupBox_ADJ_TH->setObjectName(QStringLiteral("groupBox_ADJ_TH"));
        groupBox_ADJ_TH->setGeometry(QRect(420, 80, 251, 91));
        horizontalSlider_ADJ_TH = new QSlider(groupBox_ADJ_TH);
        horizontalSlider_ADJ_TH->setObjectName(QStringLiteral("horizontalSlider_ADJ_TH"));
        horizontalSlider_ADJ_TH->setGeometry(QRect(9, 56, 191, 31));
        horizontalSlider_ADJ_TH->setMaximum(255);
        horizontalSlider_ADJ_TH->setOrientation(Qt::Horizontal);
        lcdNumber_ADJ_TH = new QLCDNumber(groupBox_ADJ_TH);
        lcdNumber_ADJ_TH->setObjectName(QStringLiteral("lcdNumber_ADJ_TH"));
        lcdNumber_ADJ_TH->setGeometry(QRect(10, 30, 80, 25));
        lcdNumber_ADJ_TH->setAutoFillBackground(false);
        lcdNumber_ADJ_TH->setDigitCount(3);
        lcdNumber_ADJ_TH->setProperty("intValue", QVariant(1));
        label_ADJ = new QLabel(groupBox_ADJ);
        label_ADJ->setObjectName(QStringLiteral("label_ADJ"));
        label_ADJ->setGeometry(QRect(20, 40, 221, 17));
        comboBox_ADJ = new QComboBox(groupBox_ADJ);
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->setObjectName(QStringLiteral("comboBox_ADJ"));
        comboBox_ADJ->setGeometry(QRect(245, 34, 241, 31));
        pushButton_ADJ_H = new QPushButton(groupBox_ADJ);
        pushButton_ADJ_H->setObjectName(QStringLiteral("pushButton_ADJ_H"));
        pushButton_ADJ_H->setGeometry(QRect(420, 180, 251, 61));
        pushButton_RESET = new QPushButton(groupBox_ADJ);
        pushButton_RESET->setObjectName(QStringLiteral("pushButton_RESET"));
        pushButton_RESET->setGeometry(QRect(568, 394, 101, 31));
        widget_ADJ_SA = new QWidget(groupBox_ADJ);
        widget_ADJ_SA->setObjectName(QStringLiteral("widget_ADJ_SA"));
        widget_ADJ_SA->setGeometry(QRect(9, 79, 221, 391));
        label_ADJ_SA_BC = new QLabel(widget_ADJ_SA);
        label_ADJ_SA_BC->setObjectName(QStringLiteral("label_ADJ_SA_BC"));
        label_ADJ_SA_BC->setGeometry(QRect(10, 0, 201, 40));
        label_ADJ_SA_BC->setWordWrap(true);
        frame_ADJ_SA_BC = new QFrame(widget_ADJ_SA);
        frame_ADJ_SA_BC->setObjectName(QStringLiteral("frame_ADJ_SA_BC"));
        frame_ADJ_SA_BC->setGeometry(QRect(10, 40, 201, 340));
        frame_ADJ_SA_BC->setFrameShape(QFrame::StyledPanel);
        frame_ADJ_SA_BC->setFrameShadow(QFrame::Raised);
        label_ADJ_SA_BC_B = new QLabel(frame_ADJ_SA_BC);
        label_ADJ_SA_BC_B->setObjectName(QStringLiteral("label_ADJ_SA_BC_B"));
        label_ADJ_SA_BC_B->setGeometry(QRect(15, 280, 80, 20));
        label_ADJ_SA_BC_B->setAlignment(Qt::AlignCenter);
        label_ADJ_SA_BC_C = new QLabel(frame_ADJ_SA_BC);
        label_ADJ_SA_BC_C->setObjectName(QStringLiteral("label_ADJ_SA_BC_C"));
        label_ADJ_SA_BC_C->setGeometry(QRect(110, 280, 80, 20));
        label_ADJ_SA_BC_C->setAlignment(Qt::AlignCenter);
        verticalSlider_ADJ_SA_BC_C = new QSlider(frame_ADJ_SA_BC);
        verticalSlider_ADJ_SA_BC_C->setObjectName(QStringLiteral("verticalSlider_ADJ_SA_BC_C"));
        verticalSlider_ADJ_SA_BC_C->setGeometry(QRect(110, 10, 80, 270));
        verticalSlider_ADJ_SA_BC_C->setMinimum(-50);
        verticalSlider_ADJ_SA_BC_C->setMaximum(50);
        verticalSlider_ADJ_SA_BC_C->setSingleStep(1);
        verticalSlider_ADJ_SA_BC_C->setPageStep(1);
        verticalSlider_ADJ_SA_BC_C->setValue(0);
        verticalSlider_ADJ_SA_BC_C->setOrientation(Qt::Vertical);
        verticalSlider_ADJ_SA_BC_B = new QSlider(frame_ADJ_SA_BC);
        verticalSlider_ADJ_SA_BC_B->setObjectName(QStringLiteral("verticalSlider_ADJ_SA_BC_B"));
        verticalSlider_ADJ_SA_BC_B->setGeometry(QRect(20, 10, 80, 270));
        verticalSlider_ADJ_SA_BC_B->setMinimum(-255);
        verticalSlider_ADJ_SA_BC_B->setMaximum(255);
        verticalSlider_ADJ_SA_BC_B->setPageStep(1);
        verticalSlider_ADJ_SA_BC_B->setValue(0);
        verticalSlider_ADJ_SA_BC_B->setOrientation(Qt::Vertical);
        lcdNumber_ADJ_SA_BC_B = new QLCDNumber(frame_ADJ_SA_BC);
        lcdNumber_ADJ_SA_BC_B->setObjectName(QStringLiteral("lcdNumber_ADJ_SA_BC_B"));
        lcdNumber_ADJ_SA_BC_B->setGeometry(QRect(15, 300, 80, 25));
        lcdNumber_ADJ_SA_BC_C = new QLCDNumber(frame_ADJ_SA_BC);
        lcdNumber_ADJ_SA_BC_C->setObjectName(QStringLiteral("lcdNumber_ADJ_SA_BC_C"));
        lcdNumber_ADJ_SA_BC_C->setGeometry(QRect(110, 300, 80, 25));
        verticalSlider_ADJ_SA_BC_B->raise();
        label_ADJ_SA_BC_B->raise();
        label_ADJ_SA_BC_C->raise();
        verticalSlider_ADJ_SA_BC_C->raise();
        lcdNumber_ADJ_SA_BC_B->raise();
        lcdNumber_ADJ_SA_BC_C->raise();
        widget_ADJ_ES = new QWidget(groupBox_ADJ);
        widget_ADJ_ES->setObjectName(QStringLiteral("widget_ADJ_ES"));
        widget_ADJ_ES->setGeometry(QRect(229, 79, 331, 391));
        frame_ADJ_ES = new QFrame(widget_ADJ_ES);
        frame_ADJ_ES->setObjectName(QStringLiteral("frame_ADJ_ES"));
        frame_ADJ_ES->setGeometry(QRect(10, 40, 160, 341));
        frame_ADJ_ES->setFrameShape(QFrame::StyledPanel);
        frame_ADJ_ES->setFrameShadow(QFrame::Raised);
        label_ADJ_ES_SUBTITLE = new QLabel(frame_ADJ_ES);
        label_ADJ_ES_SUBTITLE->setObjectName(QStringLiteral("label_ADJ_ES_SUBTITLE"));
        label_ADJ_ES_SUBTITLE->setGeometry(QRect(-1, 280, 161, 20));
        label_ADJ_ES_SUBTITLE->setAlignment(Qt::AlignCenter);
        verticalSlider_ADJ_ES = new QSlider(frame_ADJ_ES);
        verticalSlider_ADJ_ES->setObjectName(QStringLiteral("verticalSlider_ADJ_ES"));
        verticalSlider_ADJ_ES->setGeometry(QRect(5, 10, 151, 270));
        verticalSlider_ADJ_ES->setMinimum(1);
        verticalSlider_ADJ_ES->setMaximum(10);
        verticalSlider_ADJ_ES->setValue(1);
        verticalSlider_ADJ_ES->setOrientation(Qt::Vertical);
        lcdNumber_ADJ_ES = new QLCDNumber(frame_ADJ_ES);
        lcdNumber_ADJ_ES->setObjectName(QStringLiteral("lcdNumber_ADJ_ES"));
        lcdNumber_ADJ_ES->setGeometry(QRect(40, 300, 80, 25));
        label_ADJ_ES_TITLE = new QLabel(widget_ADJ_ES);
        label_ADJ_ES_TITLE->setObjectName(QStringLiteral("label_ADJ_ES_TITLE"));
        label_ADJ_ES_TITLE->setGeometry(QRect(10, 0, 161, 40));
        label_ADJ_ES_TITLE->setWordWrap(true);
        label_ADJ_ES_GS_TITLE = new QLabel(widget_ADJ_ES);
        label_ADJ_ES_GS_TITLE->setObjectName(QStringLiteral("label_ADJ_ES_GS_TITLE"));
        label_ADJ_ES_GS_TITLE->setGeometry(QRect(180, 190, 141, 40));
        label_ADJ_ES_GS_TITLE->setWordWrap(true);
        comboBox_ADJ_ES_GS = new QComboBox(widget_ADJ_ES);
        comboBox_ADJ_ES_GS->addItem(QString());
        comboBox_ADJ_ES_GS->addItem(QString());
        comboBox_ADJ_ES_GS->addItem(QString());
        comboBox_ADJ_ES_GS->addItem(QString());
        comboBox_ADJ_ES_GS->setObjectName(QStringLiteral("comboBox_ADJ_ES_GS"));
        comboBox_ADJ_ES_GS->setGeometry(QRect(180, 220, 86, 25));
        widget_ADJ_ES->raise();
        widget_ADJ_SA->raise();
        groupBox_ADJ_TH->raise();
        label_ADJ->raise();
        comboBox_ADJ->raise();
        pushButton_ADJ_H->raise();
        pushButton_RESET->raise();
        groupBox_GBA = new QGroupBox(Widget);
        groupBox_GBA->setObjectName(QStringLiteral("groupBox_GBA"));
        groupBox_GBA->setGeometry(QRect(1130, 550, 426, 470));
        toolButton_GBA = new QToolButton(groupBox_GBA);
        toolButton_GBA->setObjectName(QStringLiteral("toolButton_GBA"));
        toolButton_GBA->setGeometry(QRect(13, 408, 31, 25));
        label_GBA_i = new QLabel(groupBox_GBA);
        label_GBA_i->setObjectName(QStringLiteral("label_GBA_i"));
        label_GBA_i->setGeometry(QRect(13, 28, 400, 400));
        widget_GBA_WH = new QWidget(groupBox_GBA);
        widget_GBA_WH->setObjectName(QStringLiteral("widget_GBA_WH"));
        widget_GBA_WH->setGeometry(QRect(270, 430, 150, 38));
        horizontalLayout_6 = new QHBoxLayout(widget_GBA_WH);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_GBA_WH_SUBTITLE = new QLabel(widget_GBA_WH);
        label_GBA_WH_SUBTITLE->setObjectName(QStringLiteral("label_GBA_WH_SUBTITLE"));
        label_GBA_WH_SUBTITLE->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_GBA_WH_SUBTITLE);

        label_GBA_WH_NUM = new QLabel(widget_GBA_WH);
        label_GBA_WH_NUM->setObjectName(QStringLiteral("label_GBA_WH_NUM"));
        label_GBA_WH_NUM->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_GBA_WH_NUM);

        widget_GBA_h = new QWidget(groupBox_GBA);
        widget_GBA_h->setObjectName(QStringLiteral("widget_GBA_h"));
        widget_GBA_h->setGeometry(QRect(10, 120, 410, 280));
        widget_GBA_h->setAutoFillBackground(true);
        horizontalLayoutWidget_4 = new QWidget(widget_GBA_h);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(9, 9, 391, 261));
        horizontalLayout_GBA_h = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_GBA_h->setSpacing(6);
        horizontalLayout_GBA_h->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_GBA_h->setObjectName(QStringLiteral("horizontalLayout_GBA_h"));
        horizontalLayout_GBA_h->setContentsMargins(0, 0, 0, 0);
        label_GBA_i->raise();
        toolButton_GBA->raise();
        widget_GBA_WH->raise();
        widget_GBA_h->raise();
        groupBox_GAA = new QGroupBox(Widget);
        groupBox_GAA->setObjectName(QStringLiteral("groupBox_GAA"));
        groupBox_GAA->setGeometry(QRect(700, 550, 426, 470));
        groupBox_GAA->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_GAA->setFlat(true);
        toolButton_GAA = new QToolButton(groupBox_GAA);
        toolButton_GAA->setObjectName(QStringLiteral("toolButton_GAA"));
        toolButton_GAA->setGeometry(QRect(13, 407, 31, 25));
        label_GAA_i = new QLabel(groupBox_GAA);
        label_GAA_i->setObjectName(QStringLiteral("label_GAA_i"));
        label_GAA_i->setGeometry(QRect(13, 28, 400, 400));
        widget_GAA_WH = new QWidget(groupBox_GAA);
        widget_GAA_WH->setObjectName(QStringLiteral("widget_GAA_WH"));
        widget_GAA_WH->setGeometry(QRect(270, 430, 150, 38));
        horizontalLayout_4 = new QHBoxLayout(widget_GAA_WH);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_GAA_WH_SUBTITLE = new QLabel(widget_GAA_WH);
        label_GAA_WH_SUBTITLE->setObjectName(QStringLiteral("label_GAA_WH_SUBTITLE"));
        label_GAA_WH_SUBTITLE->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_GAA_WH_SUBTITLE);

        label_GAA_WH_NUM = new QLabel(widget_GAA_WH);
        label_GAA_WH_NUM->setObjectName(QStringLiteral("label_GAA_WH_NUM"));
        label_GAA_WH_NUM->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_GAA_WH_NUM);

        widget_GAA_h = new QWidget(groupBox_GAA);
        widget_GAA_h->setObjectName(QStringLiteral("widget_GAA_h"));
        widget_GAA_h->setGeometry(QRect(10, 120, 410, 280));
        widget_GAA_h->setAutoFillBackground(true);
        horizontalLayoutWidget_3 = new QWidget(widget_GAA_h);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(9, 9, 391, 261));
        horizontalLayout_GAA_h = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_GAA_h->setSpacing(6);
        horizontalLayout_GAA_h->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_GAA_h->setObjectName(QStringLiteral("horizontalLayout_GAA_h"));
        horizontalLayout_GAA_h->setContentsMargins(0, 0, 0, 0);
        label_GAA_i->raise();
        toolButton_GAA->raise();
        widget_GAA_WH->raise();
        widget_GAA_h->raise();
        checkBox_COMPARE = new QCheckBox(Widget);
        checkBox_COMPARE->setObjectName(QStringLiteral("checkBox_COMPARE"));
        checkBox_COMPARE->setGeometry(QRect(449, 330, 92, 23));
        groupBox_GB = new QGroupBox(Widget);
        groupBox_GB->setObjectName(QStringLiteral("groupBox_GB"));
        groupBox_GB->setGeometry(QRect(1130, 10, 426, 505));
        label_GB = new QLabel(groupBox_GB);
        label_GB->setObjectName(QStringLiteral("label_GB"));
        label_GB->setGeometry(QRect(13, 446, 400, 17));
        label_GB->setMinimumSize(QSize(400, 0));
        label_GB->setAlignment(Qt::AlignCenter);
        toolButton_GB = new QToolButton(groupBox_GB);
        toolButton_GB->setObjectName(QStringLiteral("toolButton_GB"));
        toolButton_GB->setGeometry(QRect(13, 410, 31, 25));
        label_GB_i = new QLabel(groupBox_GB);
        label_GB_i->setObjectName(QStringLiteral("label_GB_i"));
        label_GB_i->setGeometry(QRect(13, 28, 400, 400));
        widget_GB_WH = new QWidget(groupBox_GB);
        widget_GB_WH->setObjectName(QStringLiteral("widget_GB_WH"));
        widget_GB_WH->setGeometry(QRect(270, 465, 150, 38));
        horizontalLayout_7 = new QHBoxLayout(widget_GB_WH);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_GB_WH_SUBTITLE = new QLabel(widget_GB_WH);
        label_GB_WH_SUBTITLE->setObjectName(QStringLiteral("label_GB_WH_SUBTITLE"));
        label_GB_WH_SUBTITLE->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_GB_WH_SUBTITLE);

        label_GB_WH_NUM = new QLabel(widget_GB_WH);
        label_GB_WH_NUM->setObjectName(QStringLiteral("label_GB_WH_NUM"));
        label_GB_WH_NUM->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_GB_WH_NUM);

        widget_GB_h = new QWidget(groupBox_GB);
        widget_GB_h->setObjectName(QStringLiteral("widget_GB_h"));
        widget_GB_h->setGeometry(QRect(10, 120, 410, 280));
        widget_GB_h->setAutoFillBackground(true);
        horizontalLayoutWidget_2 = new QWidget(widget_GB_h);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 9, 391, 261));
        horizontalLayout_GB_h = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_GB_h->setSpacing(6);
        horizontalLayout_GB_h->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_GB_h->setObjectName(QStringLiteral("horizontalLayout_GB_h"));
        horizontalLayout_GB_h->setContentsMargins(0, 0, 0, 0);
        label_GB_i->raise();
        label_GB->raise();
        toolButton_GB->raise();
        widget_GB_WH->raise();
        widget_GB_h->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox_OI->setTitle(QApplication::translate("Widget", "Oringinal Image", nullptr));
        pushButton_OI_CF->setText(QApplication::translate("Widget", "Choose your Image.", nullptr));
        toolButton_OI->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_OI_i->setText(QString());
        label_OI_WH_SUBTITLE->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_OI_WH_NUM->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        pushButton_convert->setText(QApplication::translate("Widget", "Convert it into a grayscale image.", nullptr));
        groupBox_GA->setTitle(QApplication::translate("Widget", "GRAY A.", nullptr));
        label_GA->setText(QApplication::translate("Widget", "Gray = ( R + G + B ) / 3.0", nullptr));
        toolButton_GA->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GA_i->setText(QString());
        label_GA_WH_SUBTITLE->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GA_WH_NUM->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        groupBox_ADJ->setTitle(QApplication::translate("Widget", "Adjustment", nullptr));
        groupBox_ADJ_TH->setTitle(QApplication::translate("Widget", "Set the threshold value", nullptr));
        label_ADJ->setText(QApplication::translate("Widget", "Choose the function you want: ", nullptr));
        comboBox_ADJ->setItemText(0, QApplication::translate("Widget", "Brightness & Constrast Adjustment", nullptr));
        comboBox_ADJ->setItemText(1, QApplication::translate("Widget", "Convert into binary image", nullptr));
        comboBox_ADJ->setItemText(2, QApplication::translate("Widget", "Histogram equalization", nullptr));
        comboBox_ADJ->setItemText(3, QApplication::translate("Widget", "Enlarge or Shrink & Grayscale", nullptr));

        pushButton_ADJ_H->setText(QApplication::translate("Widget", "Histogram equalization", nullptr));
        pushButton_RESET->setText(QApplication::translate("Widget", "Reset", nullptr));
        label_ADJ_SA_BC->setText(QApplication::translate("Widget", "Adjust the brightness and constrast.", nullptr));
        label_ADJ_SA_BC_B->setText(QApplication::translate("Widget", "Brightness", nullptr));
        label_ADJ_SA_BC_C->setText(QApplication::translate("Widget", "Constrast", nullptr));
        label_ADJ_ES_SUBTITLE->setText(QApplication::translate("Widget", "Enlarge & Shrink", nullptr));
        label_ADJ_ES_TITLE->setText(QApplication::translate("Widget", "Adjust the spatial resolution.", nullptr));
        label_ADJ_ES_GS_TITLE->setText(QApplication::translate("Widget", "Grayscale", nullptr));
        comboBox_ADJ_ES_GS->setItemText(0, QApplication::translate("Widget", "8 bits", nullptr));
        comboBox_ADJ_ES_GS->setItemText(1, QApplication::translate("Widget", "4 bits", nullptr));
        comboBox_ADJ_ES_GS->setItemText(2, QApplication::translate("Widget", "2 bits", nullptr));
        comboBox_ADJ_ES_GS->setItemText(3, QApplication::translate("Widget", "1 bits", nullptr));

        groupBox_GBA->setTitle(QApplication::translate("Widget", "GRAY B. after adjust.", nullptr));
        toolButton_GBA->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GBA_i->setText(QString());
        label_GBA_WH_SUBTITLE->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GBA_WH_NUM->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        groupBox_GAA->setTitle(QApplication::translate("Widget", "GRAY A. after adjust.", nullptr));
        toolButton_GAA->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GAA_i->setText(QString());
        label_GAA_WH_SUBTITLE->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GAA_WH_NUM->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        checkBox_COMPARE->setText(QApplication::translate("Widget", "Compare", nullptr));
        groupBox_GB->setTitle(QApplication::translate("Widget", "GRAY B.", nullptr));
        label_GB->setText(QApplication::translate("Widget", "GRAY = 0.299 * R + 0.587 * G + 0.114 * B", nullptr));
        toolButton_GB->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GB_i->setText(QString());
        label_GB_WH_SUBTITLE->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GB_WH_NUM->setText(QApplication::translate("Widget", "0 x 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
