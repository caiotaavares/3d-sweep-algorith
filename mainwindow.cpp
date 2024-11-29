#include "mainwindow.h"
#include "canvas.h"
#include "sweep.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Varredura rotacional");

    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);

    QHBoxLayout *layout = new QHBoxLayout();
    widget->setLayout(layout);

    Canvas *drawingArea = new Canvas(this);
    connect(drawingArea, &Canvas::pathChanged, this, &MainWindow::setPath);
    layout->addWidget(drawingArea);

    QPushButton *btn = new QPushButton("🡆", this);
    QFont font;
    font.setPointSize(20);
    btn->setFont(font);
    connect(btn, &QPushButton::clicked, this, &MainWindow::doSweep);
    layout->addWidget(btn);

    label = new QLabel(this);
    label->setFixedSize(401, 400);
    layout->addWidget(label);
}

MainWindow::~MainWindow() {}

void MainWindow::setPath(const QVector<QPointF> &newPath) {
    path = newPath;
}

void MainWindow::doSweep() {
    if (path.isEmpty()) return;

    Sweep sweep(QSize(401, 400));
    QImage img = sweep.applySweep(path);

    label->setPixmap(QPixmap::fromImage(img));
}
