/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsAbstractShape.h"
#include "DuAsteroidsDefines.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsUtil.h"

namespace DuarteCorporation
{
DuAsteroidsAbstractShape::DuAsteroidsAbstractShape(QObject *parent)
    : QObject(parent)
{
    mScene = static_cast<DuAsteroidsScene *>(parent);
    mVx = 0.0;
    mVy = 0.0;
    mA = 0.0;
    mX = 0.0;
    mY = 0.0;
}

void DuAsteroidsAbstractShape::move()
{
    mX += mVx;
    mY += mVy;
    limits(mX, WIDTH);
    limits(mY, HEIGHT);
}

void DuAsteroidsAbstractShape::accelerates()
{
    float ax = 0.0;
    float ay = -0.5;
    rotaAngulo(ax, ay, 0.0, 0.0, mA);
    mVx += ax;
    mVy += ay;
}

void DuAsteroidsAbstractShape::rotate(int da)
{
    mA += da;
}
} // end namespace DuarteCorporation
