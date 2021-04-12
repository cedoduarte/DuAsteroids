/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsCircleItem.h"
#include "DuAsteroidsLineItem.h"
#include "DuAsteroidsAsteroid.h"
#include "DuAsteroidsMissile.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsDefines.h"
#include "DuAsteroidsUtil.h"

namespace DuarteCorporation
{
DuAsteroidsMissile::DuAsteroidsMissile(float x, float y, float a,
                                       QObject *parent)
    : DuAsteroidsAbstractShape(parent)
{
    mA = a;
    mX = x;
    mY = y;
    mVx = 0.0;
    mVy = -5.0;
    rotaAngulo(mVx, mVy, 0.0, 0.0, mA);
    mLine = new DuAsteroidsLineItem;
    mScene->addItem(mLine);
}

void DuAsteroidsMissile::draw()
{
    float x1 = 0.0;
    float y1 = -5.0;
    float x2 = 0.0;
    float y2 = 5.0;
    rotaAngulo(x1, y1, 0.0, 0.0, mA);
    rotaAngulo(x2, y2, 0.0, 0.0, mA);
    mLine->setPoints(mX+x1, mY+y1, mX+x2, mY+y2);
}

void DuAsteroidsMissile::move()
{
    mX += mVx;
    mY += mVy;
}

QString DuAsteroidsMissile::describe() const
{
    return "missile";
}

bool DuAsteroidsMissile::isOut() const
{
    return mX > WIDTH || mX < 0.0 || mY > HEIGHT || mY < 0.0;
}

bool DuAsteroidsMissile::collidesWith(const DuAsteroidsAsteroid *A) const
{
    return mLine->collidesWithItem(A->circle());
}
} // end namespace DuarteCorporation
