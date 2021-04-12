/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

namespace DuarteCorporation
{
class DuAsteroidsScene;
class DuAsteroidsThread;

class DuAsteroidsMainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DuAsteroidsMainWidget(QWidget *parent = nullptr);
    ~DuAsteroidsMainWidget();
signals:
    void update();
    void keyPressed(int);
protected:
    void keyPressEvent(QKeyEvent *e);
private:
    Ui::Widget *ui;
    DuAsteroidsScene *mScene;
    DuAsteroidsThread *mThread;
};
} // end namespace DuarteCorporation

#endif // WIDGET_H
