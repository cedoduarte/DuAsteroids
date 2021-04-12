/**
 * @author: Carlos Enrique Duarte Ortiz <carlosduarte.1@hotmail.com>
 */

#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

namespace DuarteCorporation
{
class DuAsteroidsThread : public QThread
{
    Q_OBJECT
public:
    DuAsteroidsThread(QObject *parent = nullptr);
    void start(int msec, Priority p);
signals:
    void already();
protected:
    void run();
private:
    bool mRunning;
    int mMsec;
};
} // end namespace DuarteCorporation

#endif // MYTHREAD_H
