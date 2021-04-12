/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef MYTEXTITEM_H
#define MYTEXTITEM_H

#include <QGraphicsItem>
#include <QPointF>

namespace DuarteCorporation
{
class DuAsteroidsTextItem : public QGraphicsItem
{
public:
    DuAsteroidsTextItem(QGraphicsItem *parent = nullptr);

    void setPosition(const QPointF &pos)
    {
        mPos = pos;
    }

    void setString(const QString &str)
    {
        mStr = str;
    }
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
private:
    QPointF mPos;
    QString mStr;
};
} // end namespace DuarteCorporation

#endif // MYTEXTITEM_H
