/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsTextItem.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsText.h"

namespace DuarteCorporation
{
DuAsteroidsText::DuAsteroidsText(QObject *parent)
    : DuAsteroidsAbstractShape(parent)
{
    mText = new DuAsteroidsTextItem;
    mScene->addItem(mText);
    mX = 5.0;
    mY = 15.0;
}

void DuAsteroidsText::draw()
{
    mText->setPosition(QPointF(mX, mY));
}

QString DuAsteroidsText::describe() const
{
    return "text";
}

void DuAsteroidsText::setText(const QString &text)
{
    mText->setString(text);
}
} // end namespace DuarteCorporation

