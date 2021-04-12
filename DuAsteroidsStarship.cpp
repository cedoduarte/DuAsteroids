/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsCircleItem.h"
#include "DuAsteroidsLineItem.h"
#include "DuAsteroidsStarship.h"
#include "DuAsteroidsAsteroid.h"
#include "DuAsteroidsMissile.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsUtil.h"

namespace DuarteCorporation
{
DuAsteroidsStarship::DuAsteroidsStarship(float x, float y, QObject *parent)
    : DuAsteroidsAbstractShape(parent)
{
    mX = x;
    mY = y;
    // líneas de la nave
    mL1 = new DuAsteroidsLineItem;
    mL2 = new DuAsteroidsLineItem;
    mL3 = new DuAsteroidsLineItem;
    // agregamos la nave a la escena
    mScene->addItem(mL1);
    mScene->addItem(mL2);
    mScene->addItem(mL3);
}

void DuAsteroidsStarship::draw()
{
    float x1, y1, x2, y2, x3, y3;
    vertices(x1, y1, x2, y2, x3, y3);
    mL1->setPoints(x1, y1, x2, y2);
    mL2->setPoints(x2, y2, x3, y3);
    mL3->setPoints(x3, y3, x1, y1);
}

QString DuAsteroidsStarship::describe() const
{
    return "starship";
}

bool DuAsteroidsStarship::collidesWith(const DuAsteroidsAsteroid *A) const
{
    return collides(mL1, A->circle()) || collides(mL2, A->circle())
            || collides(mL3, A->circle());
}

DuAsteroidsMissile *DuAsteroidsStarship::shoot()
{
    float x1, y1, none;
    vertices(x1, y1, none, none, none, none);
    return new DuAsteroidsMissile(x1, y1, mA, mScene);
}

void DuAsteroidsStarship::vertices(float &x1, float &y1,
                        float &x2, float &y2,
                        float &x3, float &y3) const
{
    x1 = mX;
    y1 = mY - 40.0;
    x2 = mX - 15.0;
    y2 = mY + 10.0;
    x3 = mX + 15.0;
    y3 = mY + 10.0;
    rotaAngulo(x1, y1, mX, mY, mA);
    rotaAngulo(x2, y2, mX, mY, mA);
    rotaAngulo(x3, y3, mX, mY, mA);
}
} // end namespace DuarteCorporation


