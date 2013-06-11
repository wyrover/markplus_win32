#ifndef WORDPRESSPOST_H
#define WORDPRESSPOST_H

#include <QString>
#include <QDate>

class WordpressPost
{
public:
    WordpressPost();
    void setPostAuthor(int post_author);
    void setPostDate(QDate post_date);
    void setPostDateGmt(QDate post_date_gmt);
    void setPostTitle(QString title);
    void setPostContent(QString content);
    void setPostExcerpt(QString post_excerpt);
    void setPostStatus(QString post_status);
    void setCommentStatus(QString comment_status);
    void setPingStatus(QString ping_status);
    void setPostPassword(QString post_password);
    void setPostName(QString post_name);
    void setToPing(QString to_ping);
    void setPinged(QString pinged);
    void setPostModified(QDate post_modified);
    void setPostModifiedGmt(QDate post_modified_gmt);
    void setPostContentFiltered(QString post_content_filtered);
    void setPostParent(int post_parent);
    void setGuid(QString guid);
    void setMenuOrder(int menu_order);
    void setPostType(int post_type);
    void setPostMineType(QString post_mine_type);
    void setCommentCount(int comment_count);

    int getPostAuthor();
    QDate getPostDate();
    QDate getPostDateGmt();
    QString getPostTitle();
    QString getPostContent();
    QString getPostExcerpt();
    QString getPostStatus();
    QString getCommentStatus();
    QString getPingStatus();
    QString getPostPassword();
    QString getPostName();
    QString getToPing();
    QString getPinged();
    QDate getPostModified();
    QDate getPostModifiedGmt();
    QString getPostContentFiltered();
    int getPostParent();
    QString getGuid();
    int getMenuOrder();
    QString getPostType();
    QString getPostMineType();
    int getCommentCount();

private:
    int post_author;
    QDate post_date;
    QDate post_date_gmt;
    QString title;
    QString content;
    QString post_excerpt;
    QString post_status;
    QString comment_status;
    QString ping_status;
    QString post_password;
    QString post_name;
    QString to_ping;
    QString pinged;
    QDate post_modified;
    QDate post_modified_gmt;
    QString post_content_filtered;
    int post_parent;
    QString guid;
    int menu_order;
    QString post_type;
    QString post_mine_type;
    int comment_count;
};

#endif // WORDPRESSPOST_H
