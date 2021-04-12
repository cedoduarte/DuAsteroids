/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef NAVE_H
#define NAVE_H

#include "DuAsteroidsAbstractShape.h"

namespace DuarteCorporation
{
class DuAsteroidsLineItem;
class DuAsteroidsAsteroid;
class DuAsteroidsMissile;

class DuAsteroidsStarship : public DuAsteroidsAbstractShape
{
public:
    DuAsteroidsStarship(float x, float y, QObject *parent = nullptr);
    bool collidesWith(const DuAsteroidsAsteroid *A) const;

    DuAsteroidsLineItem *line1() const
    {
        return mL1;
    }

    DuAsteroidsLineItem *line2() const
    {
        return mL2;
    }

    DuAsteroidsLineItem *line3() const
    {
        return mL3;
    }

    QString describe() const;
    DuAsteroidsMissile *shoot();
    void draw();
private:
    DuAsteroidsLineItem *mL1; // línea 1
    DuAsteroidsLineItem *mL2; // línea 2
    DuAsteroidsLineItem *mL3; // línea 3

    void vertices(float &x1, float &y1,
                  float &x2, float &y2,
                  float &x3, float &y3) const;
};
} // end namespace DuarteCorporation

#endif // NAVE_H
