/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef MISSILE_H
#define MISSILE_H

#include "DuAsteroidsAbstractShape.h"

namespace DuarteCorporation
{
class DuAsteroidsLineItem;
class DuAsteroidsAsteroid;

class DuAsteroidsMissile : public DuAsteroidsAbstractShape
{
public:
    DuAsteroidsMissile(float x, float y, float a, QObject *parent = nullptr);
    bool collidesWith(const DuAsteroidsAsteroid *A) const;

    DuAsteroidsLineItem *line() const
    {
        return mLine;
    }

    QString describe() const;
    bool isOut() const;
    void draw();
    void move();
private:
    DuAsteroidsLineItem *mLine;
};
} // end namespace DuarteCorporation

#endif // MISSILE_H
