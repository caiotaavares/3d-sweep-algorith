#ifndef SWEEP_H
#define SWEEP_H

#include <QVector>
#include <QPointF>
#include <QSize>
#include <QImage>

class Sweep {
public:
    explicit Sweep(const QSize &canvasSize);
    QImage applySweep(const QVector<QPointF> &points, float rotationStep = 1.0, float angleX = 30.0);

private:
    QSize canvasSize;
};

#endif // SWEEP_H
