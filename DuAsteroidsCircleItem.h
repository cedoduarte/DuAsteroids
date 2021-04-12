/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef MYCIRCLEITEM_H
#define MYCIRCLEITEM_H

#include <QGraphicsItem>

namespace DuarteCorporation
{
class DuAsteroidsCircleItem : public QGraphicsItem
{
public:
    DuAsteroidsCircleItem(float r, QGraphicsItem *parent = nullptr);
    void setCenter(float x, float y);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
private:
    QList<QPointF> mPoints;
    QPointF mC;
    float mR;
};
} // end namespace DuarteCorporation

#endif // MYCIRCLEITEM_H
