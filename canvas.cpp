#include "canvas.h"
#include <QPainter>
#include <QMouseEvent>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), brushSize(1), brushColor(Qt::black) {
    setFixedSize(401, 400);
}

QVector<QPointF> Canvas::getPath() const {
    return path;
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(brushColor, brushSize, Qt::SolidLine));
    painter.drawPath(painterPath);
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        painterPath = QPainterPath();
        painterPath.addRect(event->pos().x(), event->pos().y(), brushSize, brushSize);
        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        painterPath.addRect(event->pos().x(), event->pos().y(), brushSize, brushSize);
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    QVector<QPointF> points;
    for (int i = 0; i < painterPath.elementCount(); ++i) {
        QPainterPath::Element el = painterPath.elementAt(i);
        points.append(QPointF(el.x, el.y));
    }
    emit pathChanged(points);
}
