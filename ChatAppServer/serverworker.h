#ifndef SERVERWORKER_H
#define SERVERWORKER_H

#include <QObject>
#include <QDebug>

class QWebSocket;

class ServerWorker : public QObject
{
    Q_OBJECT
public:
    explicit ServerWorker(QWebSocket* client,QObject *parent = nullptr);
    ~ServerWorker();

    QString getUserName();
    void setUserName(const QString& name);

    void sendMessageToClient(const QString& message);
    void disconnectFromServer();

signals:
    void sendMessageToSever(const QString message);
    void disconnectFromClient();

private slots:
    void receiveMessage(const QString& message);
    void onDisconnected();

private:

    QWebSocket* m_client;
    QString m_userName;
};

#endif // SERVERWORKER_H
