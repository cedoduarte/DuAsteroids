/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QObject>

namespace DuarteCorporation
{
class DuAsteroidsScene;

class DuAsteroidsAbstractShape : public QObject
{
public:
    DuAsteroidsAbstractShape(QObject *parent = nullptr);
    virtual void move();
    void accelerates();
    void rotate(int da);
    virtual void draw() = 0;
    virtual QString describe() const = 0;
protected:
    float mX; // coordenada x
    float mY; // coordenada y
    float mVx; // velocidad x
    float mVy; // velocidad y
    float mA; // ángulo de rotación
    DuAsteroidsScene *mScene; // escena padre
};
} // end namespace DuarteCorporation

#endif // ABSTRACTSHAPE_H
