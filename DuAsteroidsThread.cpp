/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#include "DuAsteroidsThread.h"

namespace DuarteCorporation
{
DuAsteroidsThread::DuAsteroidsThread(QObject *parent)
    : QThread(parent)
{
    mRunning = false;
    mMsec = 0;
}

void DuAsteroidsThread::start(int msec, QThread::Priority p)
{
    mMsec = msec;
    mRunning = true;
    QThread::start(p);
}

void DuAsteroidsThread::run()
{
    while (mRunning) {
        emit already(); // ya = listo
        msleep(mMsec);
    }
}
} // end namespace DuarteCorporation
