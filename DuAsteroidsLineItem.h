/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef MYITEM_H
#define MYITEM_H

#include <QGraphicsItem>
#include <QPointF>

namespace DuarteCorporation
{
class DuAsteroidsLineItem : public QGraphicsItem
{
public:
    DuAsteroidsLineItem(QGraphicsItem *parent = nullptr);
    void setPoints(float x1, float y1, float x2, float y2);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
private:
     QPointF mP1;
     QPointF mP2;
};
} // end namespace DuarteCorporation

#endif // MYITEM_H
