/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsTextItem.h"
#include <QPainter>

namespace DuarteCorporation
{
DuAsteroidsTextItem::DuAsteroidsTextItem(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
}

QRectF DuAsteroidsTextItem::boundingRect() const
{
    return QRectF(mPos, QSizeF(mStr.size(), 10.0));
}

void DuAsteroidsTextItem::paint(QPainter *painter,
                                const QStyleOptionGraphicsItem *,
                                QWidget *)
{
    painter->drawText(mPos, mStr);
}
} // end namespace DuarteCorporation
