/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsCircleItem.h"
#include "DuAsteroidsLineItem.h"
#include "DuAsteroidsStarship.h"
#include "DuAsteroidsAsteroid.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsDefines.h"
#include "DuAsteroidsMissile.h"
#include "DuAsteroidsText.h"
#include <QMediaPlayer>
#include <QDir>

namespace DuarteCorporation
{
DuAsteroidsScene::DuAsteroidsScene(QObject *parent)
    : QGraphicsScene(XPOS, YPOS, WIDTH, HEIGHT, parent)
{
    QGraphicsRectItem *background = addRect(XPOS, YPOS, WIDTH, HEIGHT,
                                            QPen(Qt::black));
    background->setBrush(QBrush(Qt::white));
    setBackgroundBrush(QBrush(Qt::black));

    mStarship = new DuAsteroidsStarship(WIDTH/2, HEIGHT/2, this);
    mText = new DuAsteroidsText(this);
    mGameOver = false;
    for (int i = 0; i < 10; ++i) {
        mAsteroids.append(new DuAsteroidsAsteroid(this));
    }
    mMedia = new QMediaPlayer(this);
    mMedia->setMedia(QUrl::fromLocalFile(QDir::currentPath()
                                         + "/dingodile.mp3"));

    connect(mMedia, &QMediaPlayer::stateChanged, [&](int s) {
        if (s == QMediaPlayer::StoppedState)
            mMedia->play();
    });

    mMedia->play();
}

void DuAsteroidsScene::onUpdate()
{
    if (mGameOver) {
        update();
        return;
    }

    // pinta texto
    mText->draw();
    mText->setText(QString("%1 %2").arg(mAsteroids.size()).
                   arg(mMissiles.size()));

    // pinta nave
    mStarship->move();
    mStarship->draw();

    // pinta asteroides
    for (const auto &i : mAsteroids) {
        i->move();
        i->draw();
    }

    // pinta misiles
    for (const auto &i : mMissiles) {
        i->move();
        i->draw();
    }

    // detecta game over
    for (const auto &i : mAsteroids) {
        if (mStarship->collidesWith(i)) {
            mGameOver = true;
            return;
        }
    }

    // destruye asteroides
    for (const auto &i : mMissiles) {
        for (const auto &j : mAsteroids) {
            if (i->collidesWith(j)) {
                removeItem(i->line());
                mMissiles.removeOne(i);
                delete i;
                j->explode(mAsteroids);
                removeItem(j->circle());
                mAsteroids.removeOne(j);
                delete j;
                break;
            }
        }
    }

    // actualiza
    update();
}

void DuAsteroidsScene::onKeyPressed(int k)
{
    // esto se ejecuta cuando se presiona una tecla
    if (k == Qt::Key_A) {
        mStarship->rotate(10);
    } else if (k == Qt::Key_D) {
        mStarship->rotate(-10);
    } else if (k == Qt::Key_W) {
        mStarship->accelerates();
    } else if (k == Qt::Key_Space) {
        // disparar
        mMissiles.append(mStarship->shoot());
    }
}
} // end namespace DuarteCorporation


