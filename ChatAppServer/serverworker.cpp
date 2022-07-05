#include "serverworker.h"
#include <QWebSocket>

ServerWorker::ServerWorker(QWebSocket *client, QObject *parent)
    : QObject{parent}, m_client(client)
{
    connect(m_client, &QWebSocket::textMessageReceived,
            this, &ServerWorker::receiveMessage);
    connect(m_client, &QWebSocket::disconnected,
            this, &ServerWorker::deleteLater);
}

ServerWorker::~ServerWorker()
{

}

QString ServerWorker::getUserName()
{
    return m_userName;
}

void ServerWorker::setUserName(const QString& name)
{
    m_userName = name;
}

void ServerWorker::sendMessageToClient(const QString& message)
{
    qDebug() << "Send message to client";
    m_client->sendTextMessage(message);
}

void ServerWorker::receiveMessage(const QString& message)
{
    qDebug() << "Send message to server";
    emit sendMessageToSever(message);
}

void ServerWorker::onDisconnected()
{
    qDebug() << "Client Disconnected";
    emit disconnectFromClient();
}
