/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsCircleItem.h"
#include "DuAsteroidsLineItem.h"
#include "DuAsteroidsAsteroid.h"
#include "DuAsteroidsStarship.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsDefines.h"
#include "DuAsteroidsUtil.h"
#include <QtMath>

namespace DuarteCorporation
{
DuAsteroidsAsteroid::DuAsteroidsAsteroid(QObject *parent)
    : DuAsteroidsAbstractShape(parent)
{
    mX = random(WIDTH);
    mY = random(HEIGHT);

    while (mX > WIDTH*0.3 && mX < WIDTH*0.7) {
        mX = random(WIDTH);
    }
    while (mY > HEIGHT*0.3 && mY < HEIGHT*0.7) {
        mY = random(HEIGHT);
    }

    mVx = random(0.5) - 0.5;
    mVy = random(0.5) - 0.5;
    mTam = 10.0;
    mCircle = new DuAsteroidsCircleItem(mTam);
    mScene->addItem(mCircle);
}

DuAsteroidsAsteroid::DuAsteroidsAsteroid(float x, float y, float tam,
                                         float vx, float vy,
                   QObject *parent)
    : DuAsteroidsAbstractShape(parent)
{
    mX = x;
    mY = y;
    mVx = vx;
    mVy = vy;
    mTam = tam;
    mCircle = new DuAsteroidsCircleItem(tam);
    mScene->addItem(mCircle);
}

void DuAsteroidsAsteroid::draw()
{
    mCircle->setCenter(mX, mY);
}

QString DuAsteroidsAsteroid::describe() const
{
    return "asteroid";
}

void DuAsteroidsAsteroid::explode
    (QList<DuAsteroidsAsteroid *> &asteroids) const
{
    if (mTam > 9.0) {
        for (int i = 0; i < 4; ++i) {
            float vx = mVx + random(1.0) - 0.5;
            float vy = mVy + random(1.0) - 0.5;
            asteroids.append(new DuAsteroidsAsteroid(mX, mY, 5.0, vx, vy,
                                                     mScene));
        }
    }
}

bool DuAsteroidsAsteroid::collidesWith(const DuAsteroidsAsteroid *A) const
{
    return collides(mCircle, A->mCircle);
}

bool DuAsteroidsAsteroid::collidesWith(const DuAsteroidsStarship *S) const
{
    return collides(S->line1(), mCircle) || collides(S->line2(), mCircle)
            || collides(S->line3(), mCircle);
}
} // end namespace DuarteCorporation
