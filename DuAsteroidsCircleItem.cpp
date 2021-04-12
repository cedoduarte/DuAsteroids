/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsCircleItem.h"
#include "DuAsteroidsUtil.h"
#include <QPainter>

namespace DuarteCorporation
{
DuAsteroidsCircleItem::DuAsteroidsCircleItem(float r, QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    mR = r;
    const int count = 12;
    for (int i = 0; i < count; ++i) {
        float x = 0.0;
        float y = mR + random(mR*0.5) - mR*0.25;
        rotaAngulo(x, y, 0.0, 0.0, 30.0*i);
        mPoints.append(QPointF(x, y));
    }
}

void DuAsteroidsCircleItem::setCenter(float x, float y)
{
    mC.setX(x);
    mC.setY(y);
}

QRectF DuAsteroidsCircleItem::boundingRect() const
{
    return QRectF(QPointF(mC.x()-mR,mC.y()-mR), QSizeF(mR*2,mR*2));
}

void DuAsteroidsCircleItem::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *,
                                  QWidget *)
{
    const int count = mPoints.size();
    QPointF vertices[count];
    for (int i = 0; i < count; ++i) {
        float x = mPoints.at(i).x() + mC.x();
        float y = mPoints.at(i).y() + mC.y();
        vertices[i] = QPointF(x, y);
    }
    painter->drawPolygon(vertices, count);
    //painter->drawEllipse(mC, mR, mR);
}
} // end namespace DuarteCorporation
