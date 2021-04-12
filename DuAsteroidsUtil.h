/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef UTIL_H
#define UTIL_H

class QGraphicsItem;

namespace DuarteCorporation
{
void rotaAngulo(float &x, float &y, float cx, float cy, float da);
bool collides(const QGraphicsItem *a, const QGraphicsItem *b);
void limits(float &val, float max);
float random(float max);
} // end namespace DuarteCorporation

#endif // UTIL_H
