#ifndef WORDPRESSUSER_H
#define WORDPRESSUSER_H

#include <QString>
#include <QDate>

class WordpressUser
{
public:
    WordpressUser();
    void setUserLogin(QString user_login);
    void setUserPass(QString user_pass);
    void setUserNiceName(QString user_nicename);
    void setUserEmail(QString user_email);
    void setUserUrl(QString user_url);
    void setUserRegistered(QDate user_registered);
    void setUserActivationKey(QString user_activation_key);
    void setUserSecretKey(QString user_secret_key);
    void setUserStatus(int user_status);
    void setDisplayName(QString display_name);

    QString getUserLogin();
    QString getUserPass();
    QString getUserNiceName();
    QString getUserEmail();
    QString getUserUrl();
    QDate getUserRegistered();
    QString getUserActivationKey();
    QString getUserSecretKey();
    int getUserStatus();
    QString getDisplayName();


private:
    QString user_login;
    QString user_pass;
    QString user_nicename;
    QString user_email;
    QString user_url;
    QDate user_registered;
    QString user_activation_key;
    QString user_secret_key;
    int user_status;
    QString display_name;
};

#endif // WORDPRESSUSER_H
