/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsLineItem.h"
#include <QPainter>

namespace DuarteCorporation
{
DuAsteroidsLineItem::DuAsteroidsLineItem(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
}

void DuAsteroidsLineItem::setPoints(float x1, float y1, float x2, float y2)
{
    mP1.setX(x1);
    mP1.setY(y1);
    mP2.setX(x2);
    mP2.setY(y2);
}

QRectF DuAsteroidsLineItem::boundingRect() const
{
    return QRectF(mP1, mP2);
}

void DuAsteroidsLineItem::paint(QPainter *painter,
                                const QStyleOptionGraphicsItem *,
                                QWidget *)
{
    painter->drawLine(mP1, mP2);
}
} // end namespace DuarteCorporation
