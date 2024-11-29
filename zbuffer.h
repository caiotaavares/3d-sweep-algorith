#ifndef ZBUFFER_H
#define ZBUFFER_H

#include <QVector>
#include <QImage>
#include <QSize>

class ZBuffer {
public:
    explicit ZBuffer(const QSize &size);
    void setPoint(int x, int y, float z, int color);
    QImage toImage() const;

private:
    QVector<QVector<float>> buffer;
    QImage image;
};

#endif // ZBUFFER_H
