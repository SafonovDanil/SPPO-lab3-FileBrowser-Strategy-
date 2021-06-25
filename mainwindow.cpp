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
    barAdapter = new BarChartAdapter(this,strategy->CalculationMethod(currentDir));
    pieAdapter = new PieChartAdapter(this,strategy->CalculationMethod(currentDir));
    barView = new QChartView(barAdapter->getChart());
    pieView = new QChartView(pieAdapter->getChart());


    ui->horizontalLayout_3->addWidget(barView,2);
    ui->horizontalLayout_3->addWidget(pieView,2);
    barView->hide();
    pieView->hide();


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
}

void MainWindow::displayTypeChanged(int display_id)
{
    view->hide();
    switch (display_id)
    {
    case 0:
        view = tableView;
        modelPtr = filesModel;
        modelPtr->updateModel(strategy->CalculationMethod(currentDir));
        break;
    case 1:

        view = pieView;
        modelPtr = pieAdapter;
        modelPtr->updateModel(strategy->CalculationMethod(currentDir));
        break;
    case 2:
        view = barView;
        modelPtr = barAdapter;
        modelPtr->updateModel(strategy->CalculationMethod(currentDir));
        break;
    }
    view->show();
}

void MainWindow::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    QModelIndexList indexs =  selected.indexes();
    if (indexs.count() >= 1) {
        QModelIndex ix =  indexs.constFirst();
        currentDir = dirModel->filePath(ix);
        this->statusBar()->showMessage("Выбранный путь : " + currentDir);
    }
    modelPtr->updateModel(strategy->CalculationMethod(currentDir));
}
