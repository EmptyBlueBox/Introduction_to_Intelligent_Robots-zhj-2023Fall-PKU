#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("49944626");
    double speed = 2;
    Simulator *GPS = new Simulator("OGMexample_module","Sensor_GPS","GPS","config.xml",QTime(),speed);
    GPS->setOutputNodesName(QStringList()<<"Mapping;Mapshow");

    Simulator *Laser = new Simulator("OGMexample_module","Sensor_laser","Laser","config.xml",QTime(),speed);
    Laser->setOutputNodesName(QStringList()<<"Mapping");

    ProcessorMulti *Mapping = new ProcessorMulti("OGMexample_module", "Algor_Mapping", "Mapping", "config.xml");
    Mapping->setInputNodesName(QStringList()<<"Laser"<<"GPS");
    Mapping->setOutputNodesName(QStringList()<<"Mapshow");
    Mapping->connectExternalTrigger(1, PROCESSORSLOT);

    VisualizationMulti *Mapshow = new VisualizationMulti("OGMexample_module", "Show_LocationAndMap", "Mapshow", "config.xml");
    Mapshow->setInputNodesName(QStringList()<<"Mapping"<<"GPS");
    Mapshow->connectExternalTrigger(0, DRAINSLOT);

    edge.addNode(GPS,1,1);
    edge.addNode(Laser,1,1);
    edge.addNode(Mapping,1,1);
    edge.addNode(Mapshow,0,1);
    edge.connectAll();

    connect(ui->open, SIGNAL(clicked()), &edge, SLOT(openAllNodesSlot()));
    connect(ui->open, &QPushButton::clicked, this, [=]() {
        ui->open->setDisabled(true);
    });

    connect(ui->close, SIGNAL(clicked()), &edge, SLOT(closeAllNodesSlot()));
    connect(ui->close, &QPushButton::clicked, this, [=]() {
        ui->open->setDisabled(false);
    });

    connect(ui->set, SIGNAL(clicked()), this, SLOT(setSimuSlot()));
    connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), GPS, SLOT(setStartTimeSlot(QTime)));
    connect(this,SIGNAL(setSimuStartTimeSignal(QTime)), Laser, SLOT(setStartTimeSlot(QTime)));

    connect(ui->sync,SIGNAL(clicked()), GPS,SLOT(syncTimeTrackSlot()));
    connect(ui->sync,SIGNAL(clicked()), Laser,SLOT(syncTimeTrackSlot()));

    connect(ui->start, SIGNAL(clicked()), GPS, SLOT(startSimulatorSlot()));
    connect(ui->start, SIGNAL(clicked()), Laser, SLOT(startSimulatorSlot()));

    connect(ui->stop, SIGNAL(clicked()), GPS,SLOT(stopSimulatorSlot()));
    connect(ui->stop, SIGNAL(clicked()), Laser,SLOT(stopSimulatorSlot()));


    ui->tabWidget->addTab(&edge,"Monitor");
    QList<QWidget *> widgets;
    widgets= Mapshow->getVisualizationWidgets();
    ui->scrollArea->setWidget(widgets[0]);
    ui->scrollArea2->setWidget(widgets[1]);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setSimuSlot()
{
    emit setSimuStartTimeSignal(QTime::fromMSecsSinceStartOfDay(ui->lineEdit->text().toInt()));
}
