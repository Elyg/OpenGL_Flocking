/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *s_GLWindowGridLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *BehavioursBox;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *SepDist;
    QFrame *line;
    QFrame *line_13;
    QFrame *line_15;
    QFrame *line_3;
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line_14;
    QLabel *label_2;
    QFrame *line_19;
    QFrame *line_23;
    QFrame *line_16;
    QFrame *line_17;
    QFrame *line_24;
    QLabel *label_3;
    QDoubleSpinBox *CohesionVal;
    QDoubleSpinBox *CohDist;
    QDoubleSpinBox *AllignmentVal;
    QDoubleSpinBox *SeperationVal;
    QDoubleSpinBox *SeekVal;
    QLabel *Allignment;
    QLabel *Seperation;
    QLabel *Seek;
    QLabel *Cohesion;
    QFrame *line_31;
    QFrame *line_30;
    QFrame *line_32;
    QFrame *line_20;
    QLabel *label_4;
    QFrame *line_11;
    QDoubleSpinBox *wanderTrash;
    QGroupBox *BoidsBox;
    QGridLayout *gridLayout_4;
    QCheckBox *Drawbox;
    QFrame *line_21;
    QFrame *line_6;
    QLabel *label_5;
    QFrame *line_10;
    QFrame *line_5;
    QFrame *line_22;
    QFrame *line_8;
    QSpinBox *timerVal;
    QSpinBox *BoidNumb;
    QDoubleSpinBox *MaxVelocityVal;
    QLabel *label;
    QLabel *MaxVelocity;
    QDoubleSpinBox *MaxAccelVal;
    QLabel *MaxAcceleration;
    QLabel *BoidCount;
    QFrame *line_29;
    QDoubleSpinBox *targetVal;
    QFrame *line_34;
    QFrame *line_28;
    QFrame *line_33;
    QLabel *label_6;
    QFrame *line_25;
    QFrame *line_7;
    QFrame *line_9;
    QFrame *line_27;
    QDoubleSpinBox *scaleBoid;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *rotToggle;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *writeButton;
    QPushButton *readTest;
    QPushButton *readButton;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1582, 1065);
        MainWindow->setMaximumSize(QSize(1920, 1080));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setMouseTracking(false);
        centralWidget->setFocusPolicy(Qt::NoFocus);
        s_GLWindowGridLayout = new QGridLayout(centralWidget);
        s_GLWindowGridLayout->setObjectName(QString::fromUtf8("s_GLWindowGridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_GLWindowGridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        BehavioursBox = new QGroupBox(centralWidget);
        BehavioursBox->setObjectName(QString::fromUtf8("BehavioursBox"));
        BehavioursBox->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(BehavioursBox);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        SepDist = new QDoubleSpinBox(BehavioursBox);
        SepDist->setObjectName(QString::fromUtf8("SepDist"));
        SepDist->setMinimum(0.050000000000000);
        SepDist->setSingleStep(0.100000000000000);
        SepDist->setValue(2.000000000000000);

        gridLayout_5->addWidget(SepDist, 6, 2, 1, 1);

        line = new QFrame(BehavioursBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line, 4, 0, 1, 1);

        line_13 = new QFrame(BehavioursBox);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_13, 1, 1, 1, 1);

        line_15 = new QFrame(BehavioursBox);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_15, 5, 1, 1, 1);

        line_3 = new QFrame(BehavioursBox);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_3, 7, 0, 1, 1);

        line_2 = new QFrame(BehavioursBox);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_2, 4, 2, 1, 1);

        line_4 = new QFrame(BehavioursBox);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_4, 7, 2, 1, 1);

        line_14 = new QFrame(BehavioursBox);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_14, 2, 1, 1, 1);

        label_2 = new QLabel(BehavioursBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 2, 0, 1, 1);

        line_19 = new QFrame(BehavioursBox);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_19, 11, 1, 1, 1);

        line_23 = new QFrame(BehavioursBox);
        line_23->setObjectName(QString::fromUtf8("line_23"));
        line_23->setFrameShape(QFrame::HLine);
        line_23->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_23, 0, 0, 1, 1);

        line_16 = new QFrame(BehavioursBox);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_16, 6, 1, 1, 1);

        line_17 = new QFrame(BehavioursBox);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_17, 8, 1, 1, 1);

        line_24 = new QFrame(BehavioursBox);
        line_24->setObjectName(QString::fromUtf8("line_24"));
        line_24->setFrameShape(QFrame::HLine);
        line_24->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_24, 0, 2, 1, 1);

        label_3 = new QLabel(BehavioursBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 6, 0, 1, 1);

        CohesionVal = new QDoubleSpinBox(BehavioursBox);
        CohesionVal->setObjectName(QString::fromUtf8("CohesionVal"));
        CohesionVal->setDecimals(3);
        CohesionVal->setMaximum(1000.000000000000000);
        CohesionVal->setSingleStep(0.010000000000000);
        CohesionVal->setValue(0.100000000000000);

        gridLayout_5->addWidget(CohesionVal, 1, 2, 1, 1);

        CohDist = new QDoubleSpinBox(BehavioursBox);
        CohDist->setObjectName(QString::fromUtf8("CohDist"));
        CohDist->setMinimum(0.100000000000000);
        CohDist->setMaximum(200.000000000000000);
        CohDist->setSingleStep(0.100000000000000);
        CohDist->setValue(4.000000000000000);

        gridLayout_5->addWidget(CohDist, 2, 2, 1, 1);

        AllignmentVal = new QDoubleSpinBox(BehavioursBox);
        AllignmentVal->setObjectName(QString::fromUtf8("AllignmentVal"));
        AllignmentVal->setDecimals(3);
        AllignmentVal->setMaximum(1000.000000000000000);
        AllignmentVal->setSingleStep(0.010000000000000);
        AllignmentVal->setValue(0.100000000000000);

        gridLayout_5->addWidget(AllignmentVal, 8, 2, 1, 1);

        SeperationVal = new QDoubleSpinBox(BehavioursBox);
        SeperationVal->setObjectName(QString::fromUtf8("SeperationVal"));
        SeperationVal->setDecimals(3);
        SeperationVal->setMaximum(1000.000000000000000);
        SeperationVal->setSingleStep(0.010000000000000);
        SeperationVal->setValue(0.100000000000000);

        gridLayout_5->addWidget(SeperationVal, 5, 2, 1, 1);

        SeekVal = new QDoubleSpinBox(BehavioursBox);
        SeekVal->setObjectName(QString::fromUtf8("SeekVal"));
        SeekVal->setDecimals(3);
        SeekVal->setMinimum(0.000000000000000);
        SeekVal->setMaximum(1000.000000000000000);
        SeekVal->setSingleStep(0.100000000000000);
        SeekVal->setValue(0.000000000000000);

        gridLayout_5->addWidget(SeekVal, 11, 2, 1, 1);

        Allignment = new QLabel(BehavioursBox);
        Allignment->setObjectName(QString::fromUtf8("Allignment"));

        gridLayout_5->addWidget(Allignment, 8, 0, 1, 1);

        Seperation = new QLabel(BehavioursBox);
        Seperation->setObjectName(QString::fromUtf8("Seperation"));

        gridLayout_5->addWidget(Seperation, 5, 0, 1, 1);

        Seek = new QLabel(BehavioursBox);
        Seek->setObjectName(QString::fromUtf8("Seek"));

        gridLayout_5->addWidget(Seek, 11, 0, 1, 1);

        Cohesion = new QLabel(BehavioursBox);
        Cohesion->setObjectName(QString::fromUtf8("Cohesion"));

        gridLayout_5->addWidget(Cohesion, 1, 0, 1, 1);

        line_31 = new QFrame(BehavioursBox);
        line_31->setObjectName(QString::fromUtf8("line_31"));
        line_31->setFrameShape(QFrame::HLine);
        line_31->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_31, 12, 2, 1, 1);

        line_30 = new QFrame(BehavioursBox);
        line_30->setObjectName(QString::fromUtf8("line_30"));
        line_30->setFrameShape(QFrame::HLine);
        line_30->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_30, 12, 0, 1, 1);

        line_32 = new QFrame(BehavioursBox);
        line_32->setObjectName(QString::fromUtf8("line_32"));
        line_32->setFrameShape(QFrame::VLine);
        line_32->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_32, 10, 1, 1, 1);

        line_20 = new QFrame(BehavioursBox);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setFrameShape(QFrame::HLine);
        line_20->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_20, 9, 2, 1, 1);

        label_4 = new QLabel(BehavioursBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 10, 0, 1, 1);

        line_11 = new QFrame(BehavioursBox);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_11, 9, 0, 1, 1);

        wanderTrash = new QDoubleSpinBox(BehavioursBox);
        wanderTrash->setObjectName(QString::fromUtf8("wanderTrash"));
        wanderTrash->setMaximum(1000.000000000000000);
        wanderTrash->setSingleStep(0.010000000000000);
        wanderTrash->setValue(0.100000000000000);

        gridLayout_5->addWidget(wanderTrash, 10, 2, 1, 1);


        s_GLWindowGridLayout->addWidget(BehavioursBox, 1, 2, 1, 1);

        BoidsBox = new QGroupBox(centralWidget);
        BoidsBox->setObjectName(QString::fromUtf8("BoidsBox"));
        BoidsBox->setAlignment(Qt::AlignCenter);
        BoidsBox->setFlat(false);
        gridLayout_4 = new QGridLayout(BoidsBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        Drawbox = new QCheckBox(BoidsBox);
        Drawbox->setObjectName(QString::fromUtf8("Drawbox"));
        Drawbox->setChecked(true);

        gridLayout_4->addWidget(Drawbox, 14, 2, 1, 1);

        line_21 = new QFrame(BoidsBox);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setFrameShape(QFrame::HLine);
        line_21->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_21, 1, 0, 1, 1);

        line_6 = new QFrame(BoidsBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_6, 10, 2, 1, 1);

        label_5 = new QLabel(BoidsBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 14, 0, 1, 1);

        line_10 = new QFrame(BoidsBox);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_10, 11, 1, 1, 1);

        line_5 = new QFrame(BoidsBox);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 10, 0, 1, 1);

        line_22 = new QFrame(BoidsBox);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setFrameShape(QFrame::HLine);
        line_22->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_22, 1, 2, 1, 1);

        line_8 = new QFrame(BoidsBox);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_8, 5, 1, 1, 1);

        timerVal = new QSpinBox(BoidsBox);
        timerVal->setObjectName(QString::fromUtf8("timerVal"));
        timerVal->setMinimum(1);
        timerVal->setMaximum(10000);
        timerVal->setSingleStep(1);
        timerVal->setValue(300);
        timerVal->setDisplayIntegerBase(10);

        gridLayout_4->addWidget(timerVal, 11, 2, 1, 1);

        BoidNumb = new QSpinBox(BoidsBox);
        BoidNumb->setObjectName(QString::fromUtf8("BoidNumb"));
        BoidNumb->setKeyboardTracking(true);
        BoidNumb->setMaximum(10000);

        gridLayout_4->addWidget(BoidNumb, 2, 2, 1, 1);

        MaxVelocityVal = new QDoubleSpinBox(BoidsBox);
        MaxVelocityVal->setObjectName(QString::fromUtf8("MaxVelocityVal"));
        MaxVelocityVal->setDecimals(3);
        MaxVelocityVal->setMinimum(0.200000000000000);
        MaxVelocityVal->setMaximum(10000.000000000000000);
        MaxVelocityVal->setSingleStep(0.010000000000000);
        MaxVelocityVal->setValue(1.000000000000000);

        gridLayout_4->addWidget(MaxVelocityVal, 5, 2, 1, 1);

        label = new QLabel(BoidsBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_4->addWidget(label, 11, 0, 1, 1);

        MaxVelocity = new QLabel(BoidsBox);
        MaxVelocity->setObjectName(QString::fromUtf8("MaxVelocity"));

        gridLayout_4->addWidget(MaxVelocity, 5, 0, 1, 1);

        MaxAccelVal = new QDoubleSpinBox(BoidsBox);
        MaxAccelVal->setObjectName(QString::fromUtf8("MaxAccelVal"));
        MaxAccelVal->setDecimals(3);
        MaxAccelVal->setMinimum(0.001000000000000);
        MaxAccelVal->setMaximum(10000.000000000000000);
        MaxAccelVal->setSingleStep(0.010000000000000);
        MaxAccelVal->setValue(0.010000000000000);

        gridLayout_4->addWidget(MaxAccelVal, 8, 2, 1, 1);

        MaxAcceleration = new QLabel(BoidsBox);
        MaxAcceleration->setObjectName(QString::fromUtf8("MaxAcceleration"));

        gridLayout_4->addWidget(MaxAcceleration, 8, 0, 1, 1);

        BoidCount = new QLabel(BoidsBox);
        BoidCount->setObjectName(QString::fromUtf8("BoidCount"));

        gridLayout_4->addWidget(BoidCount, 2, 0, 1, 1);

        line_29 = new QFrame(BoidsBox);
        line_29->setObjectName(QString::fromUtf8("line_29"));
        line_29->setFrameShape(QFrame::HLine);
        line_29->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_29, 15, 2, 1, 1);

        targetVal = new QDoubleSpinBox(BoidsBox);
        targetVal->setObjectName(QString::fromUtf8("targetVal"));
        targetVal->setMinimum(0.100000000000000);
        targetVal->setMaximum(1000.000000000000000);
        targetVal->setSingleStep(0.200000000000000);

        gridLayout_4->addWidget(targetVal, 12, 2, 1, 1);

        line_34 = new QFrame(BoidsBox);
        line_34->setObjectName(QString::fromUtf8("line_34"));
        line_34->setFrameShape(QFrame::VLine);
        line_34->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_34, 12, 1, 1, 1);

        line_28 = new QFrame(BoidsBox);
        line_28->setObjectName(QString::fromUtf8("line_28"));
        line_28->setFrameShape(QFrame::HLine);
        line_28->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_28, 15, 0, 1, 1);

        line_33 = new QFrame(BoidsBox);
        line_33->setObjectName(QString::fromUtf8("line_33"));
        line_33->setFrameShape(QFrame::VLine);
        line_33->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_33, 14, 1, 1, 1);

        label_6 = new QLabel(BoidsBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 12, 0, 1, 1);

        line_25 = new QFrame(BoidsBox);
        line_25->setObjectName(QString::fromUtf8("line_25"));
        line_25->setFrameShape(QFrame::HLine);
        line_25->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_25, 13, 0, 1, 1);

        line_7 = new QFrame(BoidsBox);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_7, 2, 1, 1, 1);

        line_9 = new QFrame(BoidsBox);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_9, 8, 1, 1, 1);

        line_27 = new QFrame(BoidsBox);
        line_27->setObjectName(QString::fromUtf8("line_27"));
        line_27->setFrameShape(QFrame::HLine);
        line_27->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_27, 13, 2, 1, 1);

        scaleBoid = new QDoubleSpinBox(BoidsBox);
        scaleBoid->setObjectName(QString::fromUtf8("scaleBoid"));
        scaleBoid->setMaximum(100.000000000000000);
        scaleBoid->setSingleStep(0.500000000000000);
        scaleBoid->setValue(2.000000000000000);

        gridLayout_4->addWidget(scaleBoid, 3, 2, 1, 1);

        label_7 = new QLabel(BoidsBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        label_8 = new QLabel(BoidsBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 4, 0, 1, 1);

        rotToggle = new QCheckBox(BoidsBox);
        rotToggle->setObjectName(QString::fromUtf8("rotToggle"));
        rotToggle->setChecked(true);

        gridLayout_4->addWidget(rotToggle, 4, 2, 1, 1);


        s_GLWindowGridLayout->addWidget(BoidsBox, 0, 2, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        writeButton = new QPushButton(groupBox);
        writeButton->setObjectName(QString::fromUtf8("writeButton"));

        gridLayout->addWidget(writeButton, 3, 0, 1, 1);

        readTest = new QPushButton(groupBox);
        readTest->setObjectName(QString::fromUtf8("readTest"));

        gridLayout->addWidget(readTest, 5, 0, 1, 1);

        readButton = new QPushButton(groupBox);
        readButton->setObjectName(QString::fromUtf8("readButton"));

        gridLayout->addWidget(readButton, 4, 0, 1, 1);


        s_GLWindowGridLayout->addWidget(groupBox, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1582, 22));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(BoidNumb, SIGNAL(valueChanged(int)), BoidNumb, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QT Flocking System", nullptr));
        BehavioursBox->setTitle(QApplication::translate("MainWindow", "Behaviours", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Coh Dist", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Sep Dist", nullptr));
        Allignment->setText(QApplication::translate("MainWindow", "Allignment:", nullptr));
        Seperation->setText(QApplication::translate("MainWindow", "Seperation", nullptr));
        Seek->setText(QApplication::translate("MainWindow", "Seek:", nullptr));
        Cohesion->setText(QApplication::translate("MainWindow", "Cohesion:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Wander", nullptr));
        BoidsBox->setTitle(QApplication::translate("MainWindow", "Boids", nullptr));
        Drawbox->setText(QApplication::translate("MainWindow", "ON/OFF", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Draw BBX", nullptr));
        label->setText(QApplication::translate("MainWindow", "Seek Timer Freq.", nullptr));
        MaxVelocity->setText(QApplication::translate("MainWindow", "MAX Velocity", nullptr));
        MaxAcceleration->setText(QApplication::translate("MainWindow", "MAX Acceleration", nullptr));
        BoidCount->setText(QApplication::translate("MainWindow", "Boid count", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Seek target range", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Rotations", nullptr));
        rotToggle->setText(QApplication::translate("MainWindow", "ON/OFF", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Read/Write", nullptr));
        writeButton->setText(QApplication::translate("MainWindow", "Save User Values", nullptr));
        readTest->setText(QApplication::translate("MainWindow", "Load Defaults", nullptr));
        readButton->setText(QApplication::translate("MainWindow", "Read User Values", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
