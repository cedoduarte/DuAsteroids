/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef ASTEROID_H
#define ASTEROID_H

#include "DuAsteroidsAbstractShape.h"

namespace DuarteCorporation
{
class DuAsteroidsCircleItem;
class DuAsteroidsStarship;

class DuAsteroidsAsteroid : public DuAsteroidsAbstractShape
{
public:
    DuAsteroidsAsteroid(QObject *parent = nullptr);
    DuAsteroidsAsteroid(float x, float y, float tam, float vx, float vy,
             QObject *parent = nullptr);

    void draw();
    QString describe() const;
    void explode(QList<DuAsteroidsAsteroid *> &asteroids) const;
    bool collidesWith(const DuAsteroidsAsteroid *A) const;
    bool collidesWith(const DuAsteroidsStarship *S) const;

    DuAsteroidsCircleItem *circle() const
    {
        return mCircle;
    }
private:
    DuAsteroidsCircleItem *mCircle;
    float mTam;
};

} // end namespace DuarteCorporation

#endif // ASTEROID_H
