/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *PvP;
    QPushButton *PvC;
    QPushButton *CvP;
    QTextEdit *first;
    QTextEdit *second;
    QLabel *label;
    QLabel *label_2;
    QPushButton *printChessStep;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(793, 650);
        PvP = new QPushButton(Widget);
        PvP->setObjectName(QString::fromUtf8("PvP"));
        PvP->setGeometry(QRect(650, 20, 101, 23));
        PvC = new QPushButton(Widget);
        PvC->setObjectName(QString::fromUtf8("PvC"));
        PvC->setGeometry(QRect(650, 70, 101, 23));
        CvP = new QPushButton(Widget);
        CvP->setObjectName(QString::fromUtf8("CvP"));
        CvP->setGeometry(QRect(650, 120, 101, 23));
        first = new QTextEdit(Widget);
        first->setObjectName(QString::fromUtf8("first"));
        first->setGeometry(QRect(650, 450, 101, 31));
        second = new QTextEdit(Widget);
        second->setObjectName(QString::fromUtf8("second"));
        second->setGeometry(QRect(650, 520, 101, 31));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(650, 430, 81, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(650, 500, 81, 16));
        printChessStep = new QPushButton(Widget);
        printChessStep->setObjectName(QString::fromUtf8("printChessStep"));
        printChessStep->setGeometry(QRect(650, 570, 101, 23));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 610, 101, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        PvP->setText(QApplication::translate("Widget", "PvP", nullptr));
        PvC->setText(QApplication::translate("Widget", "PvC", nullptr));
        CvP->setText(QApplication::translate("Widget", "CvP", nullptr));
        label->setText(QApplication::translate("Widget", "\345\205\210\346\211\213\351\230\237\344\274\215\345\220\215", nullptr));
        label_2->setText(QApplication::translate("Widget", "\345\220\216\346\211\213\351\230\237\344\274\215\345\220\215", nullptr));
        printChessStep->setText(QApplication::translate("Widget", "\351\273\221\346\243\213\350\203\234", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\347\231\275\346\243\213\350\203\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
