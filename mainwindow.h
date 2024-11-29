#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QVector>
#include <QPointF>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setPath(const QVector<QPointF> &newPath);
    void doSweep();

private:
    QVector<QPointF> path;
    QLabel *label;
};

#endif // MAINWINDOW_H
