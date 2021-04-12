/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class QMediaPlayer;

namespace DuarteCorporation
{
class DuAsteroidsStarship;
class DuAsteroidsAsteroid;
class DuAsteroidsMissile;
class DuAsteroidsText;

class DuAsteroidsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    DuAsteroidsScene(QObject *parent = nullptr);
public slots:
    void onUpdate();
    void onKeyPressed(int k);
private:
    DuAsteroidsText *mText;
    bool mGameOver;
    DuAsteroidsStarship *mStarship;
    QMediaPlayer *mMedia;
    QList<DuAsteroidsMissile *> mMissiles;
    QList<DuAsteroidsAsteroid *> mAsteroids;
};
} // end namespace DuarteCorporation

#endif // MYSCENE_H
