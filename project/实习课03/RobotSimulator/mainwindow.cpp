#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MONITOR 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->starttime->setText("51856422");
    QString config = "config.xml";
    Simulator *xtion = new Simulator("Robot", "Sensor_xtion", "xtion", config, QTime(), 1);
    xtion->setOutputNodesName(QStringList() << "xtionVis;ProcessorCore");

    VisualizationMono *xtionVis = new VisualizationMono("Robot", "Sensor_xtion", "xtionVis", config);
    xtionVis->setInputNodesName(QStringList() << "xtion");
    xtionVis->connectExternalTrigger(0, DRAINSLOT);

    Simulator *urg = new Simulator("Robot", "Sensor_URG", "urg", config, QTime(), 1);
    urg->setOutputNodesName(QStringList() << "urgVis;ProcessorCore");

    VisualizationMono *urgVis = new VisualizationMono("Robot", "Sensor_URG", "urgVis", config);
    urgVis->setInputNodesName(QStringList() << "urg");
    urgVis->connectExternalTrigger(0, DRAINSLOT);

    Simulator *odom = new Simulator("Robot", "Sensor_EncoderIMU", "odom", config, QTime(), 1);
    odom->setOutputNodesName(QStringList() << "odomVis;ProcessorCore");

    VisualizationMono *odomVis = new VisualizationMono("Robot", "Sensor_EncoderIMU", "odomVis", config);
    odomVis->setInputNodesName(QStringList() << "odom");
    odomVis->connectExternalTrigger(0, DRAINSLOT);

    ProcessorMulti *ProcessorCore = new ProcessorMulti("Robot", "Processor_Core", "ProcessorCore", config);
    ProcessorCore->setInputNodesName(QStringList() << "odom" << "urg" << "xtion");
//    ProcessorCore->setOutputNodesName(QStringList() << "EncoderIMU");
    ProcessorCore->connectExternalTrigger(0, PROCESSORSLOT);

    edge.addNode(xtion, 1, 1);
    edge.addNode(xtionVis, 0, 0);
    edge.addNode(urg, 1, 1);
    edge.addNode(urgVis, 0, 0);
    edge.addNode(odom, 1, 1);
    edge.addNode(odomVis, 0, 0);
    edge.addNode(ProcessorCore, 1, 1);
    edge.connectAll();

    connect(ui->open, &QPushButton::clicked, &edge, &Edge::openAllNodesSlot);
    connect(ui->close, &QPushButton::clicked, &edge, &Edge::closeAllNodesSlot);
    connect(ui->start, &QPushButton::clicked, xtion, &Simulator::startSimulatorSlot);
    connect(ui->stop, &QPushButton::clicked, xtion, &Simulator::stopSimulatorSlot);
    connect(ui->start, &QPushButton::clicked, urg, &Simulator::startSimulatorSlot);
    connect(ui->stop, &QPushButton::clicked, urg, &Simulator::stopSimulatorSlot);
    connect(ui->start, &QPushButton::clicked, odom, &Simulator::startSimulatorSlot);
    connect(ui->stop, &QPushButton::clicked, odom, &Simulator::stopSimulatorSlot);

    QWidget *color = xtionVis->getVisualizationWidgets()[0];
    QWidget *depth = xtionVis->getVisualizationWidgets()[1];
    ui->area1->setWidget(color);
    ui->area2->setWidget(depth);
    QWidget *lidar = urgVis->getVisualizationWidgets()[0];
    ui->area3->setWidget(lidar);
    QWidget *pos = odomVis->getVisualizationWidgets()[0];
    ui->area4->setWidget(pos);

    if (MONITOR)
        ui->tabWidget->addTab(&edge, "Monitor");

    connect(ui->setvalue, &QPushButton::clicked, [=]() {
        int value = ui->starttime->text().toInt();
        xtion->setStartTimeSlot(QTime::fromMSecsSinceStartOfDay(value));
        urg->setStartTimeSlot(QTime::fromMSecsSinceStartOfDay(value));
        odom->setStartTimeSlot(QTime::fromMSecsSinceStartOfDay(value));
        ui->sync->setEnabled(true);
    });
    connect(ui->open, &QPushButton::clicked, [=]() {
       ui->open->setEnabled(false);
       ui->setvalue->setEnabled(true);
       ui->close->setEnabled(true);
    });
    connect(ui->close, &QPushButton::clicked, [=]() {
       ui->open->setEnabled(true);
       ui->setvalue->setEnabled(false);
       ui->sync->setEnabled(false);
       ui->start->setEnabled(false);
       ui->stop->setEnabled(false);
    });
    connect(ui->sync, &QPushButton::clicked, [=]() {
       xtion->syncTimeTrackSlot();
       urg->syncTimeTrackSlot();
       odom->syncTimeTrackSlot();
       ui->start->setEnabled(true);
    });
    connect(ui->start, &QPushButton::clicked, [=]() {
       ui->stop->setEnabled(true);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
