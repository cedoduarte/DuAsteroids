/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef TEXT_H
#define TEXT_H

#include "DuAsteroidsAbstractShape.h"

namespace DuarteCorporation
{
class DuAsteroidsTextItem;

class DuAsteroidsText : public DuAsteroidsAbstractShape
{
public:
    DuAsteroidsText(QObject *parent = nullptr);
    void setText(const QString &text);
    QString describe() const;
    void draw();
private:
    DuAsteroidsTextItem *mText;
};
} // end namespace DuarteCorporation

#endif // TEXT_H
