/********************************************************************************
** Form generated from reading UI file 'mandalaman.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANDALAMAN_H
#define UI_MANDALAMAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mandalaman
{
public:
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSave_as;
    QAction *actionQuit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *upperToolBar;
    QHBoxLayout *horizontalLayout;
    QLabel *sliceLabel;
    QSlider *sliceSlider;
    QSpinBox *sliceSpinBox;
    QCheckBox *mirrorCheckBox;
    QComboBox *resolutionDropDownList;
    QPushButton *clearBtn;
    QCheckBox *checkBox;
    QSlider *gridOpacitySlider;
    QWidget *futurCanevasLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lineWidthLabel;
    QSlider *lineWidthSlider;
    QPushButton *colorBtn;
    QPushButton *rainbowColorBtn;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Mandalaman)
    {
        if (Mandalaman->objectName().isEmpty())
            Mandalaman->setObjectName(QString::fromUtf8("Mandalaman"));
        Mandalaman->resize(903, 574);
        actionUndo = new QAction(Mandalaman);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(Mandalaman);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionSave_as = new QAction(Mandalaman);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionQuit = new QAction(Mandalaman);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(Mandalaman);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Mandalaman);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        upperToolBar = new QWidget(centralWidget);
        upperToolBar->setObjectName(QString::fromUtf8("upperToolBar"));
        upperToolBar->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setUnderline(false);
        upperToolBar->setFont(font);
        upperToolBar->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(upperToolBar);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        sliceLabel = new QLabel(upperToolBar);
        sliceLabel->setObjectName(QString::fromUtf8("sliceLabel"));

        horizontalLayout->addWidget(sliceLabel);

        sliceSlider = new QSlider(upperToolBar);
        sliceSlider->setObjectName(QString::fromUtf8("sliceSlider"));
        sliceSlider->setMinimum(1);
        sliceSlider->setMaximum(20);
        sliceSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliceSlider);

        sliceSpinBox = new QSpinBox(upperToolBar);
        sliceSpinBox->setObjectName(QString::fromUtf8("sliceSpinBox"));
        sliceSpinBox->setMinimum(1);
        sliceSpinBox->setMaximum(20);

        horizontalLayout->addWidget(sliceSpinBox);

        mirrorCheckBox = new QCheckBox(upperToolBar);
        mirrorCheckBox->setObjectName(QString::fromUtf8("mirrorCheckBox"));

        horizontalLayout->addWidget(mirrorCheckBox);

        resolutionDropDownList = new QComboBox(upperToolBar);
        resolutionDropDownList->setObjectName(QString::fromUtf8("resolutionDropDownList"));

        horizontalLayout->addWidget(resolutionDropDownList);

        clearBtn = new QPushButton(upperToolBar);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));

        horizontalLayout->addWidget(clearBtn);

        checkBox = new QCheckBox(upperToolBar);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        horizontalLayout->addWidget(checkBox);

        gridOpacitySlider = new QSlider(upperToolBar);
        gridOpacitySlider->setObjectName(QString::fromUtf8("gridOpacitySlider"));
        gridOpacitySlider->setSliderPosition(99);
        gridOpacitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(gridOpacitySlider);


        verticalLayout->addWidget(upperToolBar);

        futurCanevasLayout = new QWidget(centralWidget);
        futurCanevasLayout->setObjectName(QString::fromUtf8("futurCanevasLayout"));
        futurCanevasLayout->setCursor(QCursor(Qt::CrossCursor));

        verticalLayout->addWidget(futurCanevasLayout);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setEnabled(true);
        widget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineWidthLabel = new QLabel(widget);
        lineWidthLabel->setObjectName(QString::fromUtf8("lineWidthLabel"));

        horizontalLayout_2->addWidget(lineWidthLabel);

        lineWidthSlider = new QSlider(widget);
        lineWidthSlider->setObjectName(QString::fromUtf8("lineWidthSlider"));
        lineWidthSlider->setMinimum(1);
        lineWidthSlider->setMaximum(10);
        lineWidthSlider->setPageStep(3);
        lineWidthSlider->setSliderPosition(5);
        lineWidthSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(lineWidthSlider);

        colorBtn = new QPushButton(widget);
        colorBtn->setObjectName(QString::fromUtf8("colorBtn"));

        horizontalLayout_2->addWidget(colorBtn);

        rainbowColorBtn = new QPushButton(widget);
        rainbowColorBtn->setObjectName(QString::fromUtf8("rainbowColorBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../rainbowBtnImg.png"), QSize(), QIcon::Normal, QIcon::Off);
        rainbowColorBtn->setIcon(icon);
        rainbowColorBtn->setAutoRepeat(false);

        horizontalLayout_2->addWidget(rainbowColorBtn);


        verticalLayout->addWidget(widget);

        Mandalaman->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mandalaman);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 903, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Mandalaman->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mandalaman);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Mandalaman->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mandalaman);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Mandalaman->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuHelp->addAction(actionAbout);

        retranslateUi(Mandalaman);
        QObject::connect(sliceSlider, SIGNAL(valueChanged(int)), sliceSpinBox, SLOT(setValue(int)));
        QObject::connect(sliceSpinBox, SIGNAL(valueChanged(int)), sliceSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Mandalaman);
    } // setupUi

    void retranslateUi(QMainWindow *Mandalaman)
    {
        Mandalaman->setWindowTitle(QApplication::translate("Mandalaman", "Mandalaman", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("Mandalaman", "Undo", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("Mandalaman", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("Mandalaman", "Redo", 0, QApplication::UnicodeUTF8));
        actionRedo->setShortcut(QApplication::translate("Mandalaman", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("Mandalaman", "Save as ...", 0, QApplication::UnicodeUTF8));
        actionSave_as->setShortcut(QApplication::translate("Mandalaman", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("Mandalaman", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("Mandalaman", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Mandalaman", "About", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("Mandalaman", "F1", 0, QApplication::UnicodeUTF8));
        sliceLabel->setText(QApplication::translate("Mandalaman", "Slice", 0, QApplication::UnicodeUTF8));
        mirrorCheckBox->setText(QApplication::translate("Mandalaman", "Mirror", 0, QApplication::UnicodeUTF8));
        resolutionDropDownList->clear();
        resolutionDropDownList->insertItems(0, QStringList()
         << QApplication::translate("Mandalaman", "400x400", 0, QApplication::UnicodeUTF8)
        );
        clearBtn->setText(QApplication::translate("Mandalaman", "Clear", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("Mandalaman", "Grid", 0, QApplication::UnicodeUTF8));
        lineWidthLabel->setText(QApplication::translate("Mandalaman", "Line width", 0, QApplication::UnicodeUTF8));
        colorBtn->setText(QApplication::translate("Mandalaman", "Color", 0, QApplication::UnicodeUTF8));
        rainbowColorBtn->setText(QString());
        menuFile->setTitle(QApplication::translate("Mandalaman", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("Mandalaman", "Edit", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("Mandalaman", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Mandalaman: public Ui_Mandalaman {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANDALAMAN_H
