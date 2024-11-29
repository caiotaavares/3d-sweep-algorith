#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainterPath>
#include <QVector>
#include <QPointF>

class Canvas : public QWidget {
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    QVector<QPointF> getPath() const;

signals:
    void pathChanged(const QVector<QPointF> &path);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    int brushSize;
    QColor brushColor;
    QPainterPath painterPath;
    QVector<QPointF> path;
};

#endif // CANVAS_H
