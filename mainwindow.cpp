#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>
#include <QDebug>





QT_CHARTS_USE_NAMESPACE


MainWindow::MainWindow(QWidget *parent)
    : //QWidget(parent)
      QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    folderModel = new ByFolder_CalculationStrategy;
    typeModel = new ByFileType_CalculationStrategy;
    strategy = folderModel;

    currentDir = QDir::homePath();

    dirModel =  new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    currentDir = QDir::homePath();


    filesModel = new FilesModel(this, strategy->CalculationMethod(currentDir));

    modelPtr = filesModel;

    tableView = new QTableView(this);
    tableView->setModel(filesModel);

    view = tableView;

    ui->horizontalLayout_3->addWidget(tableView,2);
    adapter = new BarChartAdapter(this,strategy->CalculationMethod(currentDir));
    adapter2 = new PieChartAdapter(this,strategy->CalculationMethod(currentDir));
    //chartBar = adapter->dataBarChart();
    chartView = new QChartView(adapter->getChart());
    chartView2 = new QChartView(adapter2->getChart());


    ui->horizontalLayout_3->addWidget(chartView,2);
    ui->horizontalLayout_3->addWidget(chartView2,2);
    chartView->hide();
    chartView2->hide();

//    barChart->hide();
//    barChart->setModel(filesModel);
//    pieChart->hide();
//    pieChart->setModel(filesModel);

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(QDir::rootPath());

    ui->treeView->setModel(dirModel);

    connect(ui->treeView,SIGNAL(expanded(const QModelIndex &)),this,SLOT(treeViewCollapsedOrExpanded()));
    connect(ui->treeView,SIGNAL(collapsed(const QModelIndex &)),this,SLOT(treeViewCollapsedOrExpanded()));

    connect(ui->comboBox_action,SIGNAL(currentIndexChanged(int)),this,SLOT(actionChanged(int)));
    connect(ui->comboBox_display,SIGNAL(currentIndexChanged(int)),this,SLOT(displayTypeChanged(int)));

    QItemSelectionModel *selectionModel = ui->treeView->selectionModel();

    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(on_selectionChangedSlot(const QItemSelection &, const QItemSelection &)));
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::treeViewCollapsedOrExpanded()
{
    ui->treeView->resizeColumnToContents(0);
}

void MainWindow::actionChanged(int action_id)
{
    switch(action_id)
    {
    case 0:
        strategy = folderModel;
        break;
    case 1:
        strategy = typeModel;
        break;
    default:
        return;
    }
    modelPtr->updateModel(strategy->CalculationMethod(currentDir));
    ////filesModel->updateModel(strategy->CalculationMethod(currentDir));
}

void MainWindow::displayTypeChanged(int display_id)
{
    view->hide();
    switch (display_id)
    {
    case 0:
        view = tableView;
        modelPtr = filesModel;
        break;
    case 1:

        view = chartView2;
        modelPtr = adapter2;
        //view = pieChart;
        break;
    case 2:
        view = chartView;
        modelPtr = adapter;
        //view = barChart;
        break;
    }
    view->show();
}

void MainWindow::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    //Q_UNUSED(selected);
    Q_UNUSED(deselected);
    // QModelIndex index = treeView->selectionModel()->currentIndex();
    QModelIndexList indexs =  selected.indexes();
    //QString filePath = "";


    if (indexs.count() >= 1) {
        QModelIndex ix =  indexs.constFirst();
        currentDir = dirModel->filePath(ix);
        this->statusBar()->showMessage("Выбранный путь : " + currentDir);
    }
//    //calculaet list
//    filesModel->updateModel(strategy->CalculationMethod(currentDir));
//    //chartView->setChart(ChartAdapter(this, strategy->CalculationMethod(currentDir)).dataBarChart());
//    //chartView->setChart(ChartAdapter(this, strategy->CalculationMethod(currentDir)).dataBarChart());
//    //adapter zhret list
//    adapter->updateModel(strategy->CalculationMethod(currentDir));
 //   adapter2->updateModel(strategy->CalculationMethod(currentDir));
    modelPtr->updateModel(strategy->CalculationMethod(currentDir));
}
