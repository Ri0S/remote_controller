#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qstring.h>
#include <map>
#include "wiringpi.cpp"

using namespace std;
map<QString, int> irset;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LEDLabel("Select_LED_WHITE");
    //IRLabel("WHITE_LED");
    irset.insert(pair<QString, int>("Select", 0xff));
    irset.insert(pair<QString, int>("Right_Arm_Up", 0x01));
    irset.insert(pair<QString, int>("Right_Arm_Down", 0x04));
    irset.insert(pair<QString, int>("Right_Arm_In", 0x05));
    irset.insert(pair<QString, int>("Right_Arm_Out", 0x02));
    irset.insert(pair<QString, int>("Tilt_Body_Right", 0x03));
    irset.insert(pair<QString, int>("Left_Arm_Up", 0x09));
    irset.insert(pair<QString, int>("Left_Arm_Down", 0x0c));
    irset.insert(pair<QString, int>("Left_Arm_In", 0x0d));
    irset.insert(pair<QString, int>("Left_Arm_Out", 0x0a));
    irset.insert(pair<QString, int>("Tilt_Body_Left", 0x0b));
    irset.insert(pair<QString, int>("Walk_Forward", 0x06));
    irset.insert(pair<QString, int>("Walk_Backward", 0x07));
    irset.insert(pair<QString, int>("Turn_Right", 0x00));
    irset.insert(pair<QString, int>("Turn_Left", 0x08));
    irset.insert(pair<QString, int>("Stop", 0x0e));
    irset.insert(pair<QString, int>("Right_Sensor_Program", 0x12));
    irset.insert(pair<QString, int>("Sonic_Sensor_Program", 0x14));
    irset.insert(pair<QString, int>("Left_Sensor_Program", 0x13));
    irset.insert(pair<QString, int>("Master_Command_Program", 0x10));
    irset.insert(pair<QString, int>("Program_Play", 0x11));


    ////////////////////////////////////////////////////////////////////////Background
    QImage img_Background("./icon/Background");
    QPixmap pixmap_Background = QPixmap::fromImage(img_Background);
    ui->Background->setPixmap(pixmap_Background);
    ui->Background->resize(pixmap_Background.width(), pixmap_Background.height());
    ui->Background->show();
    ////////////////////////////////////////////////////////////////////////Right_Arm_Up
    QPixmap pixmap_Right_Arm_Up("./icon/Right_Arm_Up.png");
    const QIcon icon_Right_Arm_Up(pixmap_Right_Arm_Up);
    const QSize size_Right_Arm_Up(pixmap_Right_Arm_Up.width(), pixmap_Right_Arm_Up.height());
    ui->Right_Arm_Up->setIcon(icon_Right_Arm_Up);
    ui->Right_Arm_Up->setIconSize(size_Right_Arm_Up);
    ui->Right_Arm_Up->setGeometry(ui->Right_Arm_Up->geometry().x(), ui->Right_Arm_Up->geometry().y(), pixmap_Right_Arm_Up.width(), pixmap_Right_Arm_Up.height());
    ui->Right_Arm_Up->setFlat(true);
    ui->Right_Arm_Up->show();
    ////////////////////////////////////////////////////////////////////////Right_Arm_Down
    QPixmap pixmap_Right_Arm_Down("./icon/Right_Arm_Down.png");
    const QIcon icon_Right_Arm_Down(pixmap_Right_Arm_Down);
    const QSize size_Right_Arm_Down(pixmap_Right_Arm_Down.width(), pixmap_Right_Arm_Down.height());
    ui->Right_Arm_Down->setIcon(icon_Right_Arm_Down);
    ui->Right_Arm_Down->setIconSize(size_Right_Arm_Down);
    ui->Right_Arm_Down->setGeometry(ui->Right_Arm_Down->geometry().x(), ui->Right_Arm_Down->geometry().y(), pixmap_Right_Arm_Down.width(), pixmap_Right_Arm_Down.height());
    ui->Right_Arm_Down->setFlat(true);
    ui->Right_Arm_Down->show();
    ////////////////////////////////////////////////////////////////////////Right_Arm_In
    QPixmap pixmap_Right_Arm_In("./icon/Right_Arm_In.png");
    const QIcon icon_Right_Arm_In(pixmap_Right_Arm_In);
    const QSize size_Right_Arm_In(pixmap_Right_Arm_In.width(), pixmap_Right_Arm_In.height());
    ui->Right_Arm_In->setIcon(icon_Right_Arm_In);
    ui->Right_Arm_In->setIconSize(size_Right_Arm_In);
    ui->Right_Arm_In->setGeometry(ui->Right_Arm_In->geometry().x(), ui->Right_Arm_In->geometry().y(), pixmap_Right_Arm_In.width(), pixmap_Right_Arm_In.height());
    ui->Right_Arm_In->setFlat(true);
    ui->Right_Arm_In->show();
    ////////////////////////////////////////////////////////////////////////Right_Arm_Out
    QPixmap pixmap_Right_Arm_Out("./icon/Right_Arm_Out.png");
    const QIcon icon_Right_Arm_Out(pixmap_Right_Arm_Out);
    const QSize size_Right_Arm_Out(pixmap_Right_Arm_Out.width(), pixmap_Right_Arm_Out.height());
    ui->Right_Arm_Out->setIcon(icon_Right_Arm_Out);
    ui->Right_Arm_Out->setIconSize(size_Right_Arm_Out);
    ui->Right_Arm_Out->setGeometry(ui->Right_Arm_Out->geometry().x(), ui->Right_Arm_Out->geometry().y(), pixmap_Right_Arm_Out.width(), pixmap_Right_Arm_Out.height());
    ui->Right_Arm_Out->setFlat(true);
    ui->Right_Arm_Out->show();
    ////////////////////////////////////////////////////////////////////////Tilt_Body_Right
    QPixmap pixmap_Tilt_Body_Right("./icon/Tilt_Body_Right.png");
    const QIcon icon_Tilt_Body_Right(pixmap_Tilt_Body_Right);
    const QSize size_Tilt_Body_Right(pixmap_Tilt_Body_Right.width(), pixmap_Tilt_Body_Right.height());
    ui->Tilt_Body_Right->setIcon(icon_Tilt_Body_Right);
    ui->Tilt_Body_Right->setIconSize(size_Tilt_Body_Right);
    ui->Tilt_Body_Right->setGeometry(ui->Tilt_Body_Right->geometry().x(), ui->Tilt_Body_Right->geometry().y(), pixmap_Tilt_Body_Right.width(), pixmap_Tilt_Body_Right.height());
    ui->Tilt_Body_Right->setFlat(true);
    ui->Tilt_Body_Right->show();
    ////////////////////////////////////////////////////////////////////////Left_Arm_Up
    QPixmap pixmap_Left_Arm_Up("./icon/Left_Arm_Up.png");
    const QIcon icon_Left_Arm_Up(pixmap_Left_Arm_Up);
    const QSize size_Left_Arm_Up(pixmap_Left_Arm_Up.width(), pixmap_Left_Arm_Up.height());
    ui->Left_Arm_Up->setIcon(icon_Left_Arm_Up);
    ui->Left_Arm_Up->setIconSize(size_Left_Arm_Up);
    ui->Left_Arm_Up->setGeometry(ui->Left_Arm_Up->geometry().x(), ui->Left_Arm_Up->geometry().y(), pixmap_Left_Arm_Up.width(), pixmap_Left_Arm_Up.height());
    ui->Left_Arm_Up->setFlat(true);
    ui->Left_Arm_Up->show();
    ////////////////////////////////////////////////////////////////////////Left_Arm_Down
    QPixmap pixmap_Left_Arm_Down("./icon/Left_Arm_Down.png");
    const QIcon icon_Left_Arm_Down(pixmap_Left_Arm_Down);
    const QSize size_Left_Arm_Down(pixmap_Left_Arm_Down.width(), pixmap_Left_Arm_Down.height());
    ui->Left_Arm_Down->setIcon(icon_Left_Arm_Down);
    ui->Left_Arm_Down->setIconSize(size_Left_Arm_Down);
    ui->Left_Arm_Down->setGeometry(ui->Left_Arm_Down->geometry().x(), ui->Left_Arm_Down->geometry().y(), pixmap_Left_Arm_Down.width(), pixmap_Left_Arm_Down.height());
    ui->Left_Arm_Down->setFlat(true);
    ui->Left_Arm_Down->show();
    ////////////////////////////////////////////////////////////////////////Left_Arm_In
    QPixmap pixmap_Left_Arm_In("./icon/Left_Arm_In.png");
    const QIcon icon_Left_Arm_In(pixmap_Left_Arm_In);
    const QSize size_Left_Arm_In(pixmap_Left_Arm_In.width(), pixmap_Left_Arm_In.height());
    ui->Left_Arm_In->setIcon(icon_Left_Arm_In);
    ui->Left_Arm_In->setIconSize(size_Left_Arm_In);
    ui->Left_Arm_In->setGeometry(ui->Left_Arm_In->geometry().x(), ui->Left_Arm_In->geometry().y(), pixmap_Left_Arm_In.width(), pixmap_Left_Arm_In.height());
    ui->Left_Arm_In->setFlat(true);
    ui->Left_Arm_In->show();
    ////////////////////////////////////////////////////////////////////////Left_Arm_Out
    QPixmap pixmap_Left_Arm_Out("./icon/Left_Arm_Out.png");
    const QIcon icon_Left_Arm_Out(pixmap_Left_Arm_Out);
    const QSize size_Left_Arm_Out(pixmap_Left_Arm_Out.width(), pixmap_Left_Arm_Out.height());
    ui->Left_Arm_Out->setIcon(icon_Left_Arm_Out);
    ui->Left_Arm_Out->setIconSize(size_Left_Arm_Out);
    ui->Left_Arm_Out->setGeometry(ui->Left_Arm_Out->geometry().x(), ui->Left_Arm_Out->geometry().y(), pixmap_Left_Arm_Out.width(), pixmap_Left_Arm_Out.height());
    ui->Left_Arm_Out->setFlat(true);
    ui->Left_Arm_Out->show();
    ////////////////////////////////////////////////////////////////////////Tilt_Body_Left
    QPixmap pixmap_Tilt_Body_Left("./icon/Tilt_Body_Left.png");
    const QIcon icon_Tilt_Body_Left(pixmap_Tilt_Body_Left);
    const QSize size_Tilt_Body_Left(pixmap_Tilt_Body_Left.width(), pixmap_Tilt_Body_Left.height());
    ui->Tilt_Body_Left->setIcon(icon_Tilt_Body_Left);
    ui->Tilt_Body_Left->setIconSize(size_Tilt_Body_Left);
    ui->Tilt_Body_Left->setGeometry(ui->Tilt_Body_Left->geometry().x(), ui->Tilt_Body_Left->geometry().y(), pixmap_Tilt_Body_Left.width(), pixmap_Tilt_Body_Left.height());
    ui->Tilt_Body_Left->setFlat(true);
    ui->Tilt_Body_Left->show();
    ////////////////////////////////////////////////////////////////////////Walk_Forward
    QPixmap pixmap_Walk_Forward("./icon/Walk_Forward.png");
    const QIcon icon_Walk_Forward(pixmap_Walk_Forward);
    const QSize size_Walk_Forward(pixmap_Walk_Forward.width(), pixmap_Walk_Forward.height());
    ui->Walk_Forward->setIcon(icon_Walk_Forward);
    ui->Walk_Forward->setIconSize(size_Walk_Forward);
    ui->Walk_Forward->setGeometry(ui->Walk_Forward->geometry().x(), ui->Walk_Forward->geometry().y(), pixmap_Walk_Forward.width(), pixmap_Walk_Forward.height());
    ui->Walk_Forward->setFlat(true);
    ui->Walk_Forward->show();
    ////////////////////////////////////////////////////////////////////////Turn_Right
    QPixmap pixmap_Turn_Right("./icon/Turn_Right.png");
    const QIcon icon_Turn_Right(pixmap_Turn_Right);
    const QSize size_Turn_Right(pixmap_Turn_Right.width(), pixmap_Turn_Right.height());
    ui->Turn_Right->setIcon(icon_Turn_Right);
    ui->Turn_Right->setIconSize(size_Turn_Right);
    ui->Turn_Right->setGeometry(ui->Turn_Right->geometry().x(), ui->Turn_Right->geometry().y(), pixmap_Turn_Right.width(), pixmap_Turn_Right.height());
    ui->Turn_Right->setFlat(true);
    ui->Turn_Right->show();
    ////////////////////////////////////////////////////////////////////////Stop
    QPixmap pixmap_Stop("./icon/Stop.png");
    const QIcon icon_Stop(pixmap_Stop);
    const QSize size_Stop(pixmap_Stop.width(), pixmap_Stop.height());
    ui->Stop->setIcon(icon_Stop);
    ui->Stop->setIconSize(size_Stop);
    ui->Stop->setGeometry(ui->Stop->geometry().x(), ui->Stop->geometry().y(), pixmap_Stop.width(), pixmap_Stop.height());
    ui->Stop->setFlat(true);
    ui->Stop->show();
    ////////////////////////////////////////////////////////////////////////Turn_Left
    QPixmap pixmap_Turn_Left("./icon/Turn_Left.png");
    const QIcon icon_Turn_Left(pixmap_Turn_Left);
    const QSize size_Turn_Left(pixmap_Turn_Left.width(), pixmap_Turn_Left.height());
    ui->Turn_Left->setIcon(icon_Turn_Left);
    ui->Turn_Left->setIconSize(size_Turn_Left);
    ui->Turn_Left->setGeometry(ui->Turn_Left->geometry().x(), ui->Turn_Left->geometry().y(), pixmap_Turn_Left.width(), pixmap_Turn_Left.height());
    ui->Turn_Left->setFlat(true);
    ui->Turn_Left->show();
    ////////////////////////////////////////////////////////////////////////Walk_Backward
    QPixmap pixmap_Walk_Backward("./icon/Walk_Backward.png");
    const QIcon icon_Walk_Backward(pixmap_Walk_Backward);
    const QSize size_Walk_Backward(pixmap_Walk_Backward.width(), pixmap_Walk_Backward.height());
    ui->Walk_Backward->setIcon(icon_Walk_Backward);
    ui->Walk_Backward->setIconSize(size_Walk_Backward);
    ui->Walk_Backward->setGeometry(ui->Walk_Backward->geometry().x(), ui->Walk_Backward->geometry().y(), pixmap_Walk_Backward.width(), pixmap_Walk_Backward.height());
    ui->Walk_Backward->setFlat(true);
    ui->Walk_Backward->show();
    ////////////////////////////////////////////////////////////////////////Select
    QPixmap pixmap_Select("./icon/Select.png");
    const QIcon icon_Select(pixmap_Select);
    const QSize size_Select(pixmap_Select.width(), pixmap_Select.height());
    ui->Select->setIcon(icon_Select);
    ui->Select->setIconSize(size_Select);
    ui->Select->setGeometry(ui->Select->geometry().x(), ui->Select->geometry().y(), pixmap_Select.width(), pixmap_Select.height());
    ui->Select->setFlat(true);
    ui->Select->show();
    ////////////////////////////////////////////////////////////////////////Right_Sensor_Program
    QPixmap pixmap_Right_Sensor_Program("./icon/Right_Sensor_Program.png");
    const QIcon icon_Right_Sensor_Program(pixmap_Right_Sensor_Program);
    const QSize size_Right_Sensor_Program(pixmap_Right_Sensor_Program.width(), pixmap_Right_Sensor_Program.height());
    ui->Right_Sensor_Program->setIcon(icon_Right_Sensor_Program);
    ui->Right_Sensor_Program->setIconSize(size_Right_Sensor_Program);
    ui->Right_Sensor_Program->setGeometry(ui->Right_Sensor_Program->geometry().x(), ui->Right_Sensor_Program->geometry().y(), pixmap_Right_Sensor_Program.width(), pixmap_Right_Sensor_Program.height());
    ui->Right_Sensor_Program->setFlat(true);
    ui->Right_Sensor_Program->show();
    ////////////////////////////////////////////////////////////////////////Sonic_Sensor_Program
    QPixmap pixmap_Sonic_Sensor_Program("./icon/Sonic_Sensor_Program.png");
    const QIcon icon_Sonic_Sensor_Program(pixmap_Sonic_Sensor_Program);
    const QSize size_Sonic_Sensor_Program(pixmap_Sonic_Sensor_Program.width(), pixmap_Sonic_Sensor_Program.height());
    ui->Sonic_Sensor_Program->setIcon(icon_Sonic_Sensor_Program);
    ui->Sonic_Sensor_Program->setIconSize(size_Sonic_Sensor_Program);
    ui->Sonic_Sensor_Program->setGeometry(ui->Sonic_Sensor_Program->geometry().x(), ui->Sonic_Sensor_Program->geometry().y(), pixmap_Sonic_Sensor_Program.width(), pixmap_Sonic_Sensor_Program.height());
    ui->Sonic_Sensor_Program->setFlat(true);
    ui->Sonic_Sensor_Program->show();
    ////////////////////////////////////////////////////////////////////////Left_Sensor_Program
    QPixmap pixmap_Left_Sensor_Program("./icon/Left_Sensor_Program.png");
    const QIcon icon_Left_Sensor_Program(pixmap_Left_Sensor_Program);
    const QSize size_Left_Sensor_Program(pixmap_Left_Sensor_Program.width(), pixmap_Left_Sensor_Program.height());
    ui->Left_Sensor_Program->setIcon(icon_Left_Sensor_Program);
    ui->Left_Sensor_Program->setIconSize(size_Left_Sensor_Program);
    ui->Left_Sensor_Program->setGeometry(ui->Left_Sensor_Program->geometry().x(), ui->Left_Sensor_Program->geometry().y(), pixmap_Left_Sensor_Program.width(), pixmap_Left_Sensor_Program.height());
    ui->Left_Sensor_Program->setFlat(true);
    ui->Left_Sensor_Program->show();
    ////////////////////////////////////////////////////////////////////////Program_Play
    QPixmap pixmap_Program_Play("./icon/Program_Play.png");
    const QIcon icon_Program_Play(pixmap_Program_Play);
    const QSize size_Program_Play(pixmap_Program_Play.width(), pixmap_Program_Play.height());
    ui->Program_Play->setIcon(icon_Program_Play);
    ui->Program_Play->setIconSize(size_Program_Play);
    ui->Program_Play->setGeometry(ui->Program_Play->geometry().x(), ui->Program_Play->geometry().y(), pixmap_Program_Play.width(), pixmap_Program_Play.height());
    ui->Program_Play->setFlat(true);
    ui->Program_Play->show();
    ////////////////////////////////////////////////////////////////////////Master_Command_Program
    QPixmap pixmap_Master_Command_Program("./icon/Master_Command_Program.png");
    const QIcon icon_Master_Command_Program(pixmap_Master_Command_Program);
    const QSize size_Master_Command_Program(pixmap_Master_Command_Program.width(), pixmap_Master_Command_Program.height());
    ui->Master_Command_Program->setIcon(icon_Master_Command_Program);
    ui->Master_Command_Program->setIconSize(size_Master_Command_Program);
    ui->Master_Command_Program->setGeometry(ui->Master_Command_Program->geometry().x(), ui->Master_Command_Program->geometry().y(), pixmap_Master_Command_Program.width(), pixmap_Master_Command_Program.height());
    ui->Master_Command_Program->setFlat(true);
    ui->Master_Command_Program->show();
    ////////////////////////////////////////////////////////////////////////////GPIO connect
    QObject::connect(ui->GPIO0, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO1, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO2, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO3, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO4, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO5, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO6, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO7, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO8, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO9, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO10, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO11, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO12, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO13, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO14, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO15, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO16, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO21, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO22, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO23, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO24, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO25, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO26, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO27, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO28, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO29, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO30, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));
    QObject::connect(ui->GPIO31, SIGNAL(clicked(bool)), this, SLOT(on_GPIO_clicked(bool)));

    ////////////////////////////////////////////////////////////////////////////////////Button clicked
    QObject::connect(ui->Right_Arm_Up, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Right_Arm_Down, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Right_Arm_In, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Right_Arm_Out, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Tilt_Body_Right, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Tilt_Body_Right, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Left_Arm_Up, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Left_Arm_Down, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Left_Arm_In, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Left_Arm_Out, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Tilt_Body_Left, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Walk_Forward, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Turn_Right, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Stop, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Turn_Left, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Walk_Backward, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Right_Sensor_Program, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Sonic_Sensor_Program, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Left_Sensor_Program, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Master_Command_Program, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Program_Play, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));
    QObject::connect(ui->Select, SIGNAL(clicked(bool)), this, SLOT(on_Button_clicked(bool)));

    //////////////////////////////////////////////////////////////////////////////////////Label Connection
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GPIO_clicked(bool){
    checkDisable();
    QCheckBox* checkBox = dynamic_cast<QCheckBox*>(sender());
    int pinNum = checkBox->text().at(5).cell() - '0';
    if(checkBox->text().length() == 7){
        pinNum *= 10;
        pinNum += checkBox->text().at(6).cell() - '0';
    }
    if(checkBox->isChecked()){
        writepinList.push_back(pinNum);
        pinMode(pinNum, OUTPUT);
    }
    else{
        writepinList.remove(pinNum);
        pinMode(pinNum, INPUT);
    }
    checkEnable();
}

void MainWindow::checkEnable(){
    ui->GPIO0->setEnabled(true);
    ui->GPIO1->setEnabled(true);
    ui->GPIO2->setEnabled(true);
    ui->GPIO3->setEnabled(true);
    ui->GPIO4->setEnabled(true);
    ui->GPIO5->setEnabled(true);
    ui->GPIO6->setEnabled(true);
    ui->GPIO7->setEnabled(true);
    ui->GPIO8->setEnabled(true);
    ui->GPIO9->setEnabled(true);
    ui->GPIO10->setEnabled(true);
    ui->GPIO11->setEnabled(true);
    ui->GPIO12->setEnabled(true);
    ui->GPIO13->setEnabled(true);
    ui->GPIO14->setEnabled(true);
    ui->GPIO15->setEnabled(true);
    ui->GPIO16->setEnabled(true);
    ui->GPIO21->setEnabled(true);
    ui->GPIO22->setEnabled(true);
    ui->GPIO23->setEnabled(true);
    ui->GPIO24->setEnabled(true);
    ui->GPIO25->setEnabled(true);
    ui->GPIO26->setEnabled(true);
    ui->GPIO27->setEnabled(true);
    ui->GPIO28->setEnabled(true);
    ui->GPIO29->setEnabled(true);
    ui->GPIO30->setEnabled(true);
    ui->GPIO31->setEnabled(true);
}
void MainWindow::checkDisable(){
    ui->GPIO0->setDisabled(true);
    ui->GPIO1->setDisabled(true);
    ui->GPIO2->setDisabled(true);
    ui->GPIO3->setDisabled(true);
    ui->GPIO4->setDisabled(true);
    ui->GPIO5->setDisabled(true);
    ui->GPIO6->setDisabled(true);
    ui->GPIO7->setDisabled(true);
    ui->GPIO8->setDisabled(true);
    ui->GPIO9->setDisabled(true);
    ui->GPIO10->setDisabled(true);
    ui->GPIO11->setDisabled(true);
    ui->GPIO12->setDisabled(true);
    ui->GPIO13->setDisabled(true);
    ui->GPIO14->setDisabled(true);
    ui->GPIO15->setDisabled(true);
    ui->GPIO16->setDisabled(true);
    ui->GPIO21->setDisabled(true);
    ui->GPIO22->setDisabled(true);
    ui->GPIO23->setDisabled(true);
    ui->GPIO24->setDisabled(true);
    ui->GPIO25->setDisabled(true);
    ui->GPIO26->setDisabled(true);
    ui->GPIO27->setDisabled(true);
    ui->GPIO28->setDisabled(true);
    ui->GPIO29->setDisabled(true);
    ui->GPIO30->setDisabled(true);
    ui->GPIO31->setDisabled(true);
}
void MainWindow::on_Button_clicked(bool){
    checkDisable();
    QPushButton* Button = dynamic_cast<QPushButton*>(sender());
    std::string ButtonName = Button->objectName().toStdString();

    if(irset[Button->objectName()] == 0xff){
        switch(selectcolor){
        case 0:
            LEDLabel("Select_LED_GREEN");
            selectcolor++;
            break;
        case 1:
            LEDLabel("Select_LED_RED");
            selectcolor++;
            break;
        case 2:
            LEDLabel("Select_LED_WHITE");
            selectcolor=0;
            break;
        default:
            return;
        }
        checkEnable();
        return;
    }
    else{
        send(irset[Button->objectName()] + selectcolor * 0x20);
        LEDLabel("Select_LED_WHITE");
    }

    /*if(irset[Button->objectName()] == 0){
        //  if(!ButtonName.compare("Select")){
        switch(selectcolor){
        case 0:
            LEDLabel("Select_LED_GREEN");
            selectcolor++;
            break;
        case 1:
            LEDLabel("Select_LED_RED");
            selectcolor++;
            break;
        case 2:
            LEDLabel("Select_LED_WHITE");
            selectcolor=0;
            break;
        default:
            return;
        }
        checkEnable();
        return;
    }
    //blink(500);
*/
    selectcolor = 0;
    checkEnable();
}
/*void MainWindow::IRLabel(QString name){
    QString str = "./icon/";
    str.append(name);
    QImage img(str);
    QPixmap pixmap = QPixmap::fromImage(img);
    ui->IRLED->setPixmap(pixmap);
    ui->IRLED->resize(pixmap.width(), pixmap.height());
    ui->IRLED->show();
}*/

void MainWindow::LEDLabel(QString name){
    QString str = "./icon/";
    str.append(name);
    QImage img(str);
    QPixmap pixmap = QPixmap::fromImage(img);
    ui->Select_LED->setPixmap(pixmap);
    ui->Select_LED->resize(pixmap.width(), pixmap.height());
    ui->Select_LED->show();
}

/*void MainWindow::on_RightArmUp_clicked()
{
    checkDisable();
    int command = 1;
    if(selectcolor == GREEN)
        command = 2;
    else if(selectcolor == RED)
        command = 3;
    send(command);
    selectcolor = 0;
    checkEnable();
}*/
