#include "zbuffer.h"
#include <limits>

ZBuffer::ZBuffer(const QSize &size) {
    int width = size.width();
    int height = size.height();

    buffer = QVector<QVector<float>>(width, QVector<float>(height, std::numeric_limits<float>::infinity()));
    image = QImage(size, QImage::Format_Grayscale8);
    image.fill(255);
}

void ZBuffer::setPoint(int x, int y, float z, int color) {
    if (x < 0 || x >= image.width() || y < 0 || y >= image.height())
        return;

    if (z >= buffer[x][y])
        return;

    buffer[x][y] = z;
    image.setPixelColor(x, y, QColor(color, color, color));
}

QImage ZBuffer::toImage() const {
    return image;
}
