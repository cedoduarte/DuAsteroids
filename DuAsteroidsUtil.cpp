/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsUtil.h"
#include <QGraphicsItem>
#include <QtMath>

namespace DuarteCorporation
{
void limits(float &val, float max)
{
    if (val > max) {
        val -= max;
    } else if (val < 0.0) {
        val += max;
    }
}

void rotaAngulo(float &x, float &y, float cx, float cy, float da)
{
    float dx = x - cx;
    float dy = y - cy;
    float r = qSqrt(dx*dx + dy*dy);
    float a = qAtan2(dy, dx);
    a -= da / 180.0 * M_PI;
    x = cx + r*qCos(a);
    y = cy + r*qSin(a);
}

float random(float max)
{
    return max * (float(qrand()) / float(RAND_MAX));
}

bool collides(const QGraphicsItem *a, const QGraphicsItem *b)
{
    return a->collidesWithItem(b);
}
} // end namespace DuarteCorporation
