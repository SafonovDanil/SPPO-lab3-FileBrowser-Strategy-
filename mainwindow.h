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
class QTableView;
class QItemSelection;
class QAbstractItemView;


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
    //QFileSystemModel *fileModel;
    Ui::MainWindow *ui;
    FilesModel* filesModel;
    QList<Entry> (*computeDataForModel)(const QString &path);

    ByFileType_CalculationStrategy* typeModel;
    ByFolder_CalculationStrategy* folderModel;
    CalculationStrategy *strategy;

    QWidget* view;

    QFileSystemModel *dirModel;
    QTreeView *treeView;
    QTableView *tableView;

    QString currentDir;
};

#endif // MAINWINDOW_H
