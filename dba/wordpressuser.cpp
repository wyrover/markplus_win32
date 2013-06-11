#include "wordpressuser.h"

WordpressUser::WordpressUser()
{
}

void WordpressUser::setUserLogin(QString user_login)
{
    this->user_login = user_login;
}

void WordpressUser::setUserPass(QString user_pass)
{
    this->user_pass = user_pass;
}

void WordpressUser::setUserNiceName(QString user_nicename)
{
    this->user_nicename = user_nicename;
}

void WordpressUser::setUserEmail(QString user_email)
{
    this->user_email = user_email;
}

void WordpressUser::setUserUrl(QString user_url)
{
    this->user_url = user_url;
}

void WordpressUser::setUserRegistered(QDate user_registered)
{
    this->user_registered = user_registered;
}

void WordpressUser::setUserActivationKey(QString user_activation_key)
{
    this->user_activation_key = user_activation_key;
}

void WordpressUser::setUserSecretKey(QString user_secret_key)
{
    this->user_secret_key = user_secret_key;
}

void WordpressUser::setUserStatus(int user_status)
{
    this->user_status = user_status;
}

void WordpressUser::setDisplayName(QString display_name)
{
    this->display_name = display_name;
}

QString WordpressUser::getUserLogin()
{
    return this->user_login;
}

QString WordpressUser::getUserPass()
{
    return this->user_pass;
}

QString WordpressUser::getUserNiceName()
{
    return this->user_nicename;
}

QString WordpressUser::getUserEmail()
{
    return this->user_email;
}

QString WordpressUser::getUserUrl()
{
    return this->user_url;
}

QDate WordpressUser::getUserRegistered()
{
    return this->user_registered;
}

QString WordpressUser::getUserActivationKey()
{
    return this->user_activation_key;
}

QString WordpressUser::getUserSecretKey()
{
    return this->user_secret_key;
}

int WordpressUser::getUserStatus()
{
    return this->user_status;
}

QString WordpressUser::getDisplayName()
{
    return this->display_name;
}


