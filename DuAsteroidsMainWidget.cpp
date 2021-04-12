/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "ui_DuAsteroidsMainWidget.h"
#include "DuAsteroidsThread.h"
#include "DuAsteroidsScene.h"
#include "DuAsteroidsMainWidget.h"
#include <QKeyEvent>

#define MSEC 5

namespace DuarteCorporation
{
DuAsteroidsMainWidget::DuAsteroidsMainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mScene = new DuAsteroidsScene(this);
    mThread = new DuAsteroidsThread(this);
    ui->graphicsView->setScene(mScene);
    layout()->setMargin(0);

    connect(mThread, &DuAsteroidsThread::already, [&]() {
        emit update();
    });

    connect(this, &DuAsteroidsMainWidget::update, mScene,
            &DuAsteroidsScene::onUpdate);
    connect(this, &DuAsteroidsMainWidget::keyPressed, mScene,
            &DuAsteroidsScene::onKeyPressed);
    mThread->start(MSEC, QThread::HighestPriority);
}

DuAsteroidsMainWidget::~DuAsteroidsMainWidget()
{
    delete ui;
}

void DuAsteroidsMainWidget::keyPressEvent(QKeyEvent *e)
{
    emit keyPressed(e->key());
}
} // end namespace DuarteCorporation
