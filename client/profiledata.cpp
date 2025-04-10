#include "profiledata.h"

ProfileData& ProfileData::instance()
{
    static ProfileData instance;
    return instance;
}

ProfileData::ProfileData(QObject *parent) : QObject(parent) {}

// Деструктор (добавлено!)
ProfileData::~ProfileData() = default;

void ProfileData::setLogin(const QString &login) {
    m_login = login;
}

QString ProfileData::getLogin() const {
    return m_login;
}

void ProfileData::setPassword(const QString &password) {
    m_password = password;
}

QString ProfileData::getPassword() const {
    return m_password;
}

void ProfileData::setLoginPassword(const QString& login, const QString& password) {
    m_login = login;
    m_password = password;
}
