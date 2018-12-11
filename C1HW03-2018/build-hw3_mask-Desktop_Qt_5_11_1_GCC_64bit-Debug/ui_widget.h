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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QListWidget *listWidget_ImageList;
    QPushButton *pushButton_ChooseFolder;
    QGroupBox *groupBox;
    QLabel *label_ori;
    QLabel *label_ImageList;
    QGroupBox *groupBox_2;
    QLabel *label_aft;
    QGroupBox *groupBox_3;
    QLabel *label_step1;
    QSlider *horizontalSlider_MaskSize;
    QLabel *label_step2;
    QTabWidget *tabWidget_CreateMask;
    QWidget *tab_Linear;
    QRadioButton *radioButton_GKernal;
    QRadioButton *radioButton_BoxKernal;
    QWidget *tab_Nonlinear;
    QRadioButton *radioButton_MinFilter;
    QRadioButton *radioButton_MaxFilter;
    QRadioButton *radioButton_MedFilter;
    QWidget *tab_Custom;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QTableWidget *tableWidget;
    QWidget *tab;
    QRadioButton *radioButton;
    QSlider *horizontalSlider;
    QRadioButton *radioButton_2;
    QLCDNumber *lcdNumber_2;
    QLabel *label_step3;
    QPushButton *pushButton_Run;
    QLCDNumber *lcdNumber;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(768, 925);
        Widget->setAutoFillBackground(false);
        listWidget_ImageList = new QListWidget(Widget);
        listWidget_ImageList->setObjectName(QStringLiteral("listWidget_ImageList"));
        listWidget_ImageList->setGeometry(QRect(10, 80, 331, 351));
        pushButton_ChooseFolder = new QPushButton(Widget);
        pushButton_ChooseFolder->setObjectName(QStringLiteral("pushButton_ChooseFolder"));
        pushButton_ChooseFolder->setGeometry(QRect(10, 20, 220, 30));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(370, 30, 380, 400));
        label_ori = new QLabel(groupBox);
        label_ori->setObjectName(QStringLiteral("label_ori"));
        label_ori->setGeometry(QRect(10, 30, 360, 360));
        label_ImageList = new QLabel(Widget);
        label_ImageList->setObjectName(QStringLiteral("label_ImageList"));
        label_ImageList->setGeometry(QRect(10, 60, 220, 20));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(370, 450, 380, 400));
        label_aft = new QLabel(groupBox_2);
        label_aft->setObjectName(QStringLiteral("label_aft"));
        label_aft->setGeometry(QRect(10, 30, 360, 360));
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 450, 331, 461));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        groupBox_3->setFont(font);
        label_step1 = new QLabel(groupBox_3);
        label_step1->setObjectName(QStringLiteral("label_step1"));
        label_step1->setGeometry(QRect(10, 30, 201, 21));
        QFont font1;
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label_step1->setFont(font1);
        horizontalSlider_MaskSize = new QSlider(groupBox_3);
        horizontalSlider_MaskSize->setObjectName(QStringLiteral("horizontalSlider_MaskSize"));
        horizontalSlider_MaskSize->setGeometry(QRect(10, 55, 151, 16));
        horizontalSlider_MaskSize->setMinimum(3);
        horizontalSlider_MaskSize->setMaximum(50);
        horizontalSlider_MaskSize->setSingleStep(2);
        horizontalSlider_MaskSize->setPageStep(2);
        horizontalSlider_MaskSize->setOrientation(Qt::Horizontal);
        label_step2 = new QLabel(groupBox_3);
        label_step2->setObjectName(QStringLiteral("label_step2"));
        label_step2->setGeometry(QRect(10, 70, 201, 21));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_step2->setFont(font2);
        tabWidget_CreateMask = new QTabWidget(groupBox_3);
        tabWidget_CreateMask->setObjectName(QStringLiteral("tabWidget_CreateMask"));
        tabWidget_CreateMask->setGeometry(QRect(20, 100, 300, 291));
        tab_Linear = new QWidget();
        tab_Linear->setObjectName(QStringLiteral("tab_Linear"));
        radioButton_GKernal = new QRadioButton(tab_Linear);
        radioButton_GKernal->setObjectName(QStringLiteral("radioButton_GKernal"));
        radioButton_GKernal->setGeometry(QRect(10, 30, 170, 20));
        radioButton_BoxKernal = new QRadioButton(tab_Linear);
        radioButton_BoxKernal->setObjectName(QStringLiteral("radioButton_BoxKernal"));
        radioButton_BoxKernal->setGeometry(QRect(10, 10, 170, 20));
        tabWidget_CreateMask->addTab(tab_Linear, QString());
        tab_Nonlinear = new QWidget();
        tab_Nonlinear->setObjectName(QStringLiteral("tab_Nonlinear"));
        radioButton_MinFilter = new QRadioButton(tab_Nonlinear);
        radioButton_MinFilter->setObjectName(QStringLiteral("radioButton_MinFilter"));
        radioButton_MinFilter->setGeometry(QRect(10, 50, 171, 21));
        radioButton_MaxFilter = new QRadioButton(tab_Nonlinear);
        radioButton_MaxFilter->setObjectName(QStringLiteral("radioButton_MaxFilter"));
        radioButton_MaxFilter->setGeometry(QRect(10, 30, 171, 21));
        radioButton_MedFilter = new QRadioButton(tab_Nonlinear);
        radioButton_MedFilter->setObjectName(QStringLiteral("radioButton_MedFilter"));
        radioButton_MedFilter->setGeometry(QRect(10, 10, 171, 21));
        tabWidget_CreateMask->addTab(tab_Nonlinear, QString());
        tab_Custom = new QWidget();
        tab_Custom->setObjectName(QStringLiteral("tab_Custom"));
        label_8 = new QLabel(tab_Custom);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 10, 200, 20));
        label_8->setFont(font1);
        label_9 = new QLabel(tab_Custom);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(25, 30, 200, 17));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_9->setFont(font3);
        label_10 = new QLabel(tab_Custom);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 70, 91, 51));
        label_11 = new QLabel(tab_Custom);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 70, 51, 51));
        label_12 = new QLabel(tab_Custom);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 50, 101, 17));
        label_12->setFont(font3);
        label_13 = new QLabel(tab_Custom);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(150, 50, 101, 17));
        label_13->setFont(font3);
        label_14 = new QLabel(tab_Custom);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(25, 130, 200, 17));
        label_14->setFont(font3);
        tableWidget = new QTableWidget(tab_Custom);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(35, 150, 131, 101));
        tableWidget->setRowCount(3);
        tableWidget->setColumnCount(3);
        tableWidget->horizontalHeader()->setDefaultSectionSize(20);
        tableWidget->verticalHeader()->setDefaultSectionSize(20);
        tabWidget_CreateMask->addTab(tab_Custom, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(10, 10, 141, 23));
        horizontalSlider = new QSlider(tab);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(39, 40, 231, 20));
        horizontalSlider->setMaximum(5000);
        horizontalSlider->setOrientation(Qt::Horizontal);
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 60, 141, 23));
        lcdNumber_2 = new QLCDNumber(tab);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(150, 10, 61, 23));
        lcdNumber_2->setDigitCount(4);
        tabWidget_CreateMask->addTab(tab, QString());
        label_step3 = new QLabel(groupBox_3);
        label_step3->setObjectName(QStringLiteral("label_step3"));
        label_step3->setGeometry(QRect(10, 400, 201, 21));
        label_step3->setFont(font2);
        pushButton_Run = new QPushButton(groupBox_3);
        pushButton_Run->setObjectName(QStringLiteral("pushButton_Run"));
        pushButton_Run->setGeometry(QRect(20, 425, 89, 25));
        lcdNumber = new QLCDNumber(groupBox_3);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(163, 52, 31, 21));
        lcdNumber->setDigitCount(2);
        lcdNumber->setProperty("value", QVariant(3));
        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(370, 880, 381, 21));
        progressBar->setValue(0);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(620, 900, 80, 20));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(710, 900, 20, 20));

        retranslateUi(Widget);

        tabWidget_CreateMask->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "hw3_mask", nullptr));
        pushButton_ChooseFolder->setText(QApplication::translate("Widget", "Choose your image folder.", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "Original Image", nullptr));
        label_ori->setText(QString());
        label_ImageList->setText(QApplication::translate("Widget", "Image list:", nullptr));
        groupBox_2->setTitle(QApplication::translate("Widget", "Image(after)", nullptr));
        label_aft->setText(QString());
        groupBox_3->setTitle(QApplication::translate("Widget", "Set your mask.", nullptr));
        label_step1->setText(QApplication::translate("Widget", "Step1: Adjust mask's size.", nullptr));
        label_step2->setText(QApplication::translate("Widget", "Step2: Create a mask.", nullptr));
        radioButton_GKernal->setText(QApplication::translate("Widget", "Gaussion kernal", nullptr));
        radioButton_BoxKernal->setText(QApplication::translate("Widget", "Box kernel", nullptr));
        tabWidget_CreateMask->setTabText(tabWidget_CreateMask->indexOf(tab_Linear), QApplication::translate("Widget", "Linear", nullptr));
        radioButton_MinFilter->setText(QApplication::translate("Widget", "Min filter", nullptr));
        radioButton_MaxFilter->setText(QApplication::translate("Widget", "Max filter", nullptr));
        radioButton_MedFilter->setText(QApplication::translate("Widget", "Median filter", nullptr));
        tabWidget_CreateMask->setTabText(tabWidget_CreateMask->indexOf(tab_Nonlinear), QApplication::translate("Widget", "Non-linear", nullptr));
        label_8->setText(QApplication::translate("Widget", "Type your custom mask.", nullptr));
        label_9->setText(QApplication::translate("Widget", "Example:", nullptr));
        label_10->setText(QApplication::translate("Widget", "1 2 3\n"
"4 5 6          -> \n"
"7 8 9", nullptr));
        label_11->setText(QApplication::translate("Widget", "1,2,3\n"
"4,5,6\n"
"7,8,9", nullptr));
        label_12->setText(QApplication::translate("Widget", "Mask type:", nullptr));
        label_13->setText(QApplication::translate("Widget", "Input type:", nullptr));
        label_14->setText(QApplication::translate("Widget", "Input:", nullptr));
        tabWidget_CreateMask->setTabText(tabWidget_CreateMask->indexOf(tab_Custom), QApplication::translate("Widget", "Custom", nullptr));
        radioButton->setText(QApplication::translate("Widget", "LoG, threshold = ", nullptr));
        radioButton_2->setText(QApplication::translate("Widget", "Sobel", nullptr));
        tabWidget_CreateMask->setTabText(tabWidget_CreateMask->indexOf(tab), QApplication::translate("Widget", "Edge", nullptr));
        label_step3->setText(QApplication::translate("Widget", "Step3: Run!", nullptr));
        pushButton_Run->setText(QApplication::translate("Widget", "Run!", nullptr));
        label->setText(QApplication::translate("Widget", "0", nullptr));
        label_2->setText(QApplication::translate("Widget", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
