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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_OI_WH;
    QPushButton *pushButton_convert;
    QProgressBar *progressBar;
    QGroupBox *groupBox_GA;
    QLabel *label_GA;
    QToolButton *toolButton_GA;
    QLabel *label_GA_i;
    QLabel *label_GA_h;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_GA_WH;
    QGroupBox *groupBox_ADJ;
    QGroupBox *groupBox_ADJ_TH;
    QSlider *horizontalSlider_ADJ_TH;
    QLCDNumber *lcdNumber_THRE;
    QLabel *label_4;
    QComboBox *comboBox_ADJ;
    QFrame *frame_ADJ_SA;
    QLabel *label_9;
    QFrame *frame_ADJ_SA_BC;
    QLabel *label_ADJ_SA_BC_B;
    QLabel *label_ADJ_SA_BC_C;
    QSlider *verticalSlider_ADJ_SA_BC_C;
    QSlider *verticalSlider_ADJ_SA_BC_B;
    QLCDNumber *lcdNumber_Bri;
    QLCDNumber *lcdNumber_CON;
    QFrame *frame_5;
    QLabel *label_13;
    QSlider *verticalSlider_2;
    QLCDNumber *lcdNumber_ES;
    QLabel *label_10;
    QPushButton *pushButton_ADJ_H;
    QPushButton *pushButton_RESET;
    QPushButton *pushButton_Run;
    QGroupBox *groupBox_GBA;
    QToolButton *toolButton_GBA;
    QLabel *label_GBA_i;
    QLabel *label_GBA_h;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *label_GBA_WH;
    QGroupBox *groupBox_GAA;
    QToolButton *toolButton_GAA;
    QLabel *label_GAA_i;
    QLabel *label_GAA_h;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_GAA_WH;
    QCheckBox *checkBox;
    QGroupBox *groupBox_GB;
    QLabel *label_GB;
    QToolButton *toolButton_GB;
    QLabel *label_GB_i;
    QLabel *label_GB_h;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLabel *label_GB_WH;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1580, 1059);
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
        widget = new QWidget(groupBox_OI);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(270, 465, 150, 38));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        label_OI_WH = new QLabel(widget);
        label_OI_WH->setObjectName(QStringLiteral("label_OI_WH"));
        label_OI_WH->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_OI_WH);

        pushButton_OI_CF->raise();
        label_OI_i->raise();
        toolButton_OI->raise();
        widget->raise();
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
        label_GA_h = new QLabel(groupBox_GA);
        label_GA_h->setObjectName(QStringLiteral("label_GA_h"));
        label_GA_h->setGeometry(QRect(25, 30, 380, 380));
        label_GA_h->setAutoFillBackground(true);
        widget_2 = new QWidget(groupBox_GA);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(270, 465, 150, 38));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        label_GA_WH = new QLabel(widget_2);
        label_GA_WH->setObjectName(QStringLiteral("label_GA_WH"));
        label_GA_WH->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_GA_WH);

        label_GA->raise();
        label_GA_i->raise();
        label_GA_h->raise();
        toolButton_GA->raise();
        widget_2->raise();
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
        lcdNumber_THRE = new QLCDNumber(groupBox_ADJ_TH);
        lcdNumber_THRE->setObjectName(QStringLiteral("lcdNumber_THRE"));
        lcdNumber_THRE->setGeometry(QRect(10, 30, 80, 25));
        lcdNumber_THRE->setAutoFillBackground(false);
        lcdNumber_THRE->setDigitCount(3);
        lcdNumber_THRE->setProperty("intValue", QVariant(1));
        label_4 = new QLabel(groupBox_ADJ);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 221, 17));
        comboBox_ADJ = new QComboBox(groupBox_ADJ);
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->addItem(QString());
        comboBox_ADJ->setObjectName(QStringLiteral("comboBox_ADJ"));
        comboBox_ADJ->setGeometry(QRect(245, 34, 241, 31));
        frame_ADJ_SA = new QFrame(groupBox_ADJ);
        frame_ADJ_SA->setObjectName(QStringLiteral("frame_ADJ_SA"));
        frame_ADJ_SA->setGeometry(QRect(20, 80, 391, 381));
        frame_ADJ_SA->setFrameShape(QFrame::StyledPanel);
        frame_ADJ_SA->setFrameShadow(QFrame::Raised);
        label_9 = new QLabel(frame_ADJ_SA);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 11, 201, 40));
        label_9->setWordWrap(true);
        frame_ADJ_SA_BC = new QFrame(frame_ADJ_SA);
        frame_ADJ_SA_BC->setObjectName(QStringLiteral("frame_ADJ_SA_BC"));
        frame_ADJ_SA_BC->setGeometry(QRect(10, 50, 201, 321));
        frame_ADJ_SA_BC->setFrameShape(QFrame::StyledPanel);
        frame_ADJ_SA_BC->setFrameShadow(QFrame::Raised);
        label_ADJ_SA_BC_B = new QLabel(frame_ADJ_SA_BC);
        label_ADJ_SA_BC_B->setObjectName(QStringLiteral("label_ADJ_SA_BC_B"));
        label_ADJ_SA_BC_B->setGeometry(QRect(15, 260, 80, 20));
        label_ADJ_SA_BC_B->setAlignment(Qt::AlignCenter);
        label_ADJ_SA_BC_C = new QLabel(frame_ADJ_SA_BC);
        label_ADJ_SA_BC_C->setObjectName(QStringLiteral("label_ADJ_SA_BC_C"));
        label_ADJ_SA_BC_C->setGeometry(QRect(110, 260, 80, 20));
        label_ADJ_SA_BC_C->setAlignment(Qt::AlignCenter);
        verticalSlider_ADJ_SA_BC_C = new QSlider(frame_ADJ_SA_BC);
        verticalSlider_ADJ_SA_BC_C->setObjectName(QStringLiteral("verticalSlider_ADJ_SA_BC_C"));
        verticalSlider_ADJ_SA_BC_C->setGeometry(QRect(110, 10, 80, 251));
        verticalSlider_ADJ_SA_BC_C->setMinimum(-100);
        verticalSlider_ADJ_SA_BC_C->setMaximum(100);
        verticalSlider_ADJ_SA_BC_C->setValue(0);
        verticalSlider_ADJ_SA_BC_C->setOrientation(Qt::Vertical);
        verticalSlider_ADJ_SA_BC_B = new QSlider(frame_ADJ_SA_BC);
        verticalSlider_ADJ_SA_BC_B->setObjectName(QStringLiteral("verticalSlider_ADJ_SA_BC_B"));
        verticalSlider_ADJ_SA_BC_B->setGeometry(QRect(20, 10, 80, 251));
        verticalSlider_ADJ_SA_BC_B->setMinimum(-100);
        verticalSlider_ADJ_SA_BC_B->setMaximum(100);
        verticalSlider_ADJ_SA_BC_B->setValue(0);
        verticalSlider_ADJ_SA_BC_B->setOrientation(Qt::Vertical);
        lcdNumber_Bri = new QLCDNumber(frame_ADJ_SA_BC);
        lcdNumber_Bri->setObjectName(QStringLiteral("lcdNumber_Bri"));
        lcdNumber_Bri->setGeometry(QRect(15, 280, 80, 25));
        lcdNumber_CON = new QLCDNumber(frame_ADJ_SA_BC);
        lcdNumber_CON->setObjectName(QStringLiteral("lcdNumber_CON"));
        lcdNumber_CON->setGeometry(QRect(110, 280, 80, 25));
        verticalSlider_ADJ_SA_BC_B->raise();
        label_ADJ_SA_BC_B->raise();
        label_ADJ_SA_BC_C->raise();
        verticalSlider_ADJ_SA_BC_C->raise();
        lcdNumber_Bri->raise();
        lcdNumber_CON->raise();
        frame_5 = new QFrame(frame_ADJ_SA);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setGeometry(QRect(220, 50, 161, 321));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(frame_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(-1, 260, 161, 20));
        label_13->setAlignment(Qt::AlignCenter);
        verticalSlider_2 = new QSlider(frame_5);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(5, 10, 151, 251));
        verticalSlider_2->setMinimum(1);
        verticalSlider_2->setMaximum(100);
        verticalSlider_2->setValue(50);
        verticalSlider_2->setOrientation(Qt::Vertical);
        lcdNumber_ES = new QLCDNumber(frame_5);
        lcdNumber_ES->setObjectName(QStringLiteral("lcdNumber_ES"));
        lcdNumber_ES->setGeometry(QRect(40, 280, 80, 25));
        label_10 = new QLabel(frame_ADJ_SA);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(220, 11, 161, 40));
        label_10->setWordWrap(true);
        pushButton_ADJ_H = new QPushButton(groupBox_ADJ);
        pushButton_ADJ_H->setObjectName(QStringLiteral("pushButton_ADJ_H"));
        pushButton_ADJ_H->setGeometry(QRect(420, 180, 251, 61));
        pushButton_RESET = new QPushButton(groupBox_ADJ);
        pushButton_RESET->setObjectName(QStringLiteral("pushButton_RESET"));
        pushButton_RESET->setGeometry(QRect(568, 394, 101, 31));
        pushButton_Run = new QPushButton(groupBox_ADJ);
        pushButton_Run->setObjectName(QStringLiteral("pushButton_Run"));
        pushButton_Run->setGeometry(QRect(450, 394, 101, 31));
        groupBox_GBA = new QGroupBox(Widget);
        groupBox_GBA->setObjectName(QStringLiteral("groupBox_GBA"));
        groupBox_GBA->setGeometry(QRect(1130, 550, 426, 470));
        toolButton_GBA = new QToolButton(groupBox_GBA);
        toolButton_GBA->setObjectName(QStringLiteral("toolButton_GBA"));
        toolButton_GBA->setGeometry(QRect(13, 408, 31, 25));
        label_GBA_i = new QLabel(groupBox_GBA);
        label_GBA_i->setObjectName(QStringLiteral("label_GBA_i"));
        label_GBA_i->setGeometry(QRect(13, 28, 400, 400));
        label_GBA_h = new QLabel(groupBox_GBA);
        label_GBA_h->setObjectName(QStringLiteral("label_GBA_h"));
        label_GBA_h->setGeometry(QRect(25, 35, 380, 380));
        label_GBA_h->setAutoFillBackground(true);
        widget_5 = new QWidget(groupBox_GBA);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(270, 430, 150, 38));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(widget_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_7);

        label_GBA_WH = new QLabel(widget_5);
        label_GBA_WH->setObjectName(QStringLiteral("label_GBA_WH"));
        label_GBA_WH->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_GBA_WH);

        label_GBA_i->raise();
        label_GBA_h->raise();
        toolButton_GBA->raise();
        widget_5->raise();
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
        label_GAA_h = new QLabel(groupBox_GAA);
        label_GAA_h->setObjectName(QStringLiteral("label_GAA_h"));
        label_GAA_h->setGeometry(QRect(25, 35, 380, 380));
        label_GAA_h->setAutoFillBackground(true);
        widget_3 = new QWidget(groupBox_GAA);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(270, 430, 150, 38));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_5);

        label_GAA_WH = new QLabel(widget_3);
        label_GAA_WH->setObjectName(QStringLiteral("label_GAA_WH"));
        label_GAA_WH->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_GAA_WH);

        label_GAA_i->raise();
        label_GAA_h->raise();
        toolButton_GAA->raise();
        widget_3->raise();
        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(449, 330, 92, 23));
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
        label_GB_h = new QLabel(groupBox_GB);
        label_GB_h->setObjectName(QStringLiteral("label_GB_h"));
        label_GB_h->setGeometry(QRect(25, 35, 380, 380));
        label_GB_h->setAutoFillBackground(true);
        widget_6 = new QWidget(groupBox_GB);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        widget_6->setGeometry(QRect(270, 465, 150, 38));
        horizontalLayout_7 = new QHBoxLayout(widget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(widget_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        label_GB_WH = new QLabel(widget_6);
        label_GB_WH->setObjectName(QStringLiteral("label_GB_WH"));
        label_GB_WH->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_GB_WH);

        label_GB->raise();
        label_GB_i->raise();
        label_GB_h->raise();
        toolButton_GB->raise();
        widget_6->raise();

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
        label->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_OI_WH->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        pushButton_convert->setText(QApplication::translate("Widget", "Convert it into a grayscale image.", nullptr));
        groupBox_GA->setTitle(QApplication::translate("Widget", "GRAY A.", nullptr));
        label_GA->setText(QApplication::translate("Widget", "Gray = ( R + G + B ) / 3.0", nullptr));
        toolButton_GA->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GA_i->setText(QString());
        label_GA_h->setText(QString());
        label_3->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GA_WH->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        groupBox_ADJ->setTitle(QApplication::translate("Widget", "Adjustment", nullptr));
        groupBox_ADJ_TH->setTitle(QApplication::translate("Widget", "Set the threshold value", nullptr));
        label_4->setText(QApplication::translate("Widget", "Choose the function you want: ", nullptr));
        comboBox_ADJ->setItemText(0, QApplication::translate("Widget", "Simple Adjustment", nullptr));
        comboBox_ADJ->setItemText(1, QApplication::translate("Widget", "Convert into binary image", nullptr));
        comboBox_ADJ->setItemText(2, QApplication::translate("Widget", "Histogram equalization", nullptr));

        label_9->setText(QApplication::translate("Widget", "Adjust the brightness and constrast.", nullptr));
        label_ADJ_SA_BC_B->setText(QApplication::translate("Widget", "Brightness", nullptr));
        label_ADJ_SA_BC_C->setText(QApplication::translate("Widget", "Constrast", nullptr));
        label_13->setText(QApplication::translate("Widget", "Enlarge & Shrink", nullptr));
        label_10->setText(QApplication::translate("Widget", "Adjust the spatial resolution.", nullptr));
        pushButton_ADJ_H->setText(QApplication::translate("Widget", "Histogram equalization", nullptr));
        pushButton_RESET->setText(QApplication::translate("Widget", "Reset", nullptr));
        pushButton_Run->setText(QApplication::translate("Widget", "Run", nullptr));
        groupBox_GBA->setTitle(QApplication::translate("Widget", "GRAY B. after adjust.", nullptr));
        toolButton_GBA->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GBA_i->setText(QString());
        label_GBA_h->setText(QString());
        label_7->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GBA_WH->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        groupBox_GAA->setTitle(QApplication::translate("Widget", "GRAY A. after adjust.", nullptr));
        toolButton_GAA->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GAA_i->setText(QString());
        label_GAA_h->setText(QString());
        label_5->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GAA_WH->setText(QApplication::translate("Widget", "0 x 0", nullptr));
        checkBox->setText(QApplication::translate("Widget", "Compare", nullptr));
        groupBox_GB->setTitle(QApplication::translate("Widget", "GRAY B.", nullptr));
        label_GB->setText(QApplication::translate("Widget", "GRAY = 0.299 * R + 0.587 * G + 0.114 * B", nullptr));
        toolButton_GB->setText(QApplication::translate("Widget", "\342\206\227 ", nullptr));
        label_GB_i->setText(QString());
        label_GB_h->setText(QString());
        label_8->setText(QApplication::translate("Widget", "W x H: ", nullptr));
        label_GB_WH->setText(QApplication::translate("Widget", "0 x 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
