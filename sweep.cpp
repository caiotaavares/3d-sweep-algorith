#include "sweep.h"
#include "zbuffer.h"
#include <QVector3D>
#include <QMatrix4x4>

Sweep::Sweep(const QSize &canvasSize) : canvasSize(canvasSize) {}

QImage Sweep::applySweep(const QVector<QPointF> &points, float rotationStep, float angleX) {
    ZBuffer zb(canvasSize);

    QVector<QVector3D> processedPoints;
    for (const QPointF &point : points) {
        float adjustedX = qAbs(canvasSize.width() / 2 - point.x());
        processedPoints.append(QVector3D(adjustedX, point.y(), 0));
    }

    QMatrix4x4 Rx;
    Rx.rotate(angleX, 1, 0, 0);

    for (int i = 0; i < processedPoints.size(); i += 4) {
        QVector3D p = processedPoints[i];
        for (float g = 0; g < 360; g += rotationStep) {
            QMatrix4x4 T;
            T.rotate(g, 0, 1, 0);

            QVector3D transformed = T * Rx * p;
            zb.setPoint(transformed.x() + canvasSize.width() / 2, transformed.y(), transformed.z(), 0);
        }
    }

    return zb.toImage();
}
