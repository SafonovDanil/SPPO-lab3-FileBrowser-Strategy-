#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <calculationstrategy.h>
#include "entry.h"
#include "filesmodel.h"
#include "byfiletype_calculationstrategy.h"
#include "byfolder_calculationstrategy.h"

#include "barchartadapter.h"
#include "piechartadapter.h"
class QTableView;
class QItemSelection;
class QAbstractItemView;

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCore/QTime>
#include <QtCharts/QBarCategoryAxis>



QT_BEGIN_NAMESPACE
class QComboBox;
class QCheckBox;
QT_END_NAMESPACE

QT_CHARTS_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE

//class ByFileType_CalculationStrategy;
//class ByFolder_CalculationStrategy;

namespace Ui { class MainWindow; }
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void treeViewCollapsedOrExpanded();
    void actionChanged(int action_id);
    void displayTypeChanged(int display_id);
    void on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected);
signals:
    void updateModel(QList<Entry> model);
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    FilesModel* filesModel;

    ByFileType_CalculationStrategy* typeModel;
    ByFolder_CalculationStrategy* folderModel;
    CalculationStrategy *strategy;

    QWidget* view;

    QFileSystemModel *dirModel;
    QTreeView *treeView;
    QTableView *tableView;

    QString currentDir;

    BarChartAdapter* barAdapter;
    PieChartAdapter* pieAdapter;
    QChartView *barView;
    QChartView *pieView;


     FilesModel * modelPtr;

};

#endif // MAINWINDOW_H
