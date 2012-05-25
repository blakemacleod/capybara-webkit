#include "Authenticate.h"
#include "WebPage.h"
#include "NetworkAccessManager.h"

Authenticate::Authenticate(WebPage *page, QStringList &arguments, QObject *parent) : Command(page, arguments, parent) {
}

void Authenticate::start() {
  QString username = arguments()[0];
  QString password = arguments()[1];

  NetworkAccessManager* networkAccessManager = qobject_cast<NetworkAccessManager*>(page()->networkAccessManager());
  networkAccessManager->setUserName(username);
  networkAccessManager->setPassword(password);

  emit finished(new Response(true));
}

