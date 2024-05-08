#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString config = "config.xml";
    SensorTimer *pathReader = new SensorTimer("testLib", "test_Source", "pathReader", config, 100);
    pathReader->setOutputNodesName(QStringList() << "processor");

    ProcessorMono *dirCheck = new ProcessorMono("testLib", "test_Processor", "processor", config);
    dirCheck->setInputNodesName(QStringList() << "pathReader");
    dirCheck->setOutputNodesName(QStringList() << "showMap");
    dirCheck->connectExternalTrigger(0, PROCESSORSLOT);

    VisualizationMono *showMap = new VisualizationMono("testLib", "test_Drain", "showMap", config);
    showMap->setInputNodesName(QStringList() << "processor");
    showMap->connectExternalTrigger(0, DRAINSLOT);

    edge.addNode(pathReader, 1, 1);
    edge.addNode(dirCheck, 1, 1);
    edge.addNode(showMap, 0, 0);
    edge.connectAll();

    QWidget *widget = showMap->getVisualizationWidgets().front();
    ui->tabWidget->addTab(widget, "Map");
    ui->tabWidget->addTab(&edge, "Monitor");

    connect(ui->pushButton_open, &QPushButton::clicked, &edge, &Edge::openAllNodesSlot);
    connect(ui->pushButton_close, &QPushButton::clicked, &edge, &Edge::closeAllNodesSlot);

    connect(ui->pushButton_start, &QPushButton::clicked, pathReader, &SensorTimer::startTimerSlot);
    connect(ui->pushButton_stop, &QPushButton::clicked, pathReader, &SensorTimer::stopTimerSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}
