#include "wordpresspost.h"

WordpressPost::WordpressPost()
{
}

void WordpressPost::setPostAuthor(int post_author)
{
    this->post_author = post_author;
}

void WordpressPost::setPostDate(QDate post_date)
{
    this->post_date = post_date;
}

void WordpressPost::setPostDateGmt(QDate post_date_gmt)
{
    this->post_date = post_date_gmt;
}

void WordpressPost::setPostContent(QString content)
{
    this->content = content;
}

void WordpressPost::setPostTitle(QString title)
{
    this->title = title;
}

void WordpressPost::setPostExcerpt(QString post_excerpt)
{
    this->post_excerpt = post_excerpt;
}

void WordpressPost::setPostStatus(QString post_status)
{
    this->post_status = post_status;
}

void WordpressPost::setCommentStatus(QString comment_status)
{
    this->comment_status = comment_status;
}

void WordpressPost::setPingStatus(QString ping_status)
{
    this->ping_status = ping_status;
}

void WordpressPost::setPostPassword(QString post_password)
{
    this->post_password = post_password;
}

void WordpressPost::setPostName(QString post_name)
{
    this->post_name = post_name;
}

void WordpressPost::setToPing(QString to_ping)
{
    this->to_ping = to_ping;
}

void WordpressPost::setPinged(QString pinged)
{
    this->pinged = pinged;
}

void WordpressPost::setPostModified(QDate post_modified)
{
    this->post_modified = post_modified;
}

void WordpressPost::setPostModifiedGmt(QDate post_modified_gmt)
{
    this->post_modified_gmt = post_modified_gmt;
}

void WordpressPost::setPostContentFiltered(QString post_content_filtered)
{
    this->post_content_filtered = post_content_filtered;
}

void WordpressPost::setPostParent(int post_parent)
{
    this->post_parent = post_parent;
}

void WordpressPost::setGuid(QString guid)
{
    this->guid = guid;
}

void WordpressPost::setMenuOrder(int menu_order)
{
    this->menu_order = menu_order;
}

void WordpressPost::setPostType(int post_type)
{
    this->post_type = post_type;
}

void WordpressPost::setPostMineType(QString post_mine_type)
{
    this->post_mine_type = post_mine_type;
}

void WordpressPost::setCommentCount(int comment_count)
{
    this->comment_count = comment_count;
}

int WordpressPost::getPostAuthor()
{
    return this->post_author;
}

QDate WordpressPost::getPostDate()
{
    return this->post_date;
}

QDate WordpressPost::getPostDateGmt()
{
    return this->post_date_gmt;
}

QString WordpressPost::getPostContent()
{
    return this->content;
}

QString WordpressPost::getPostTitle()
{
    return this->title;
}

QString WordpressPost::getPostExcerpt()
{
    return this->post_excerpt;
}

QString WordpressPost::getPostStatus()
{
    return this->post_status;
}

QString WordpressPost::getCommentStatus()
{
    return this->comment_status;
}

QString WordpressPost::getPingStatus()
{
    return this->ping_status;
}

QString WordpressPost::getPostPassword()
{
    return this->post_password;
}

QString WordpressPost::getPostName()
{
    return this->post_name;
}

QString WordpressPost::getToPing()
{
    return this->to_ping;
}

QString WordpressPost::getPinged()
{
    return this->pinged;
}

QDate WordpressPost::getPostModified()
{
    return this->post_modified;
}

QDate WordpressPost::getPostModifiedGmt()
{
    return this->post_modified_gmt;
}

QString WordpressPost::getPostContentFiltered()
{
    return this->post_content_filtered;
}

int WordpressPost::getPostParent()
{
   return this->post_parent;
}

QString WordpressPost::getGuid()
{
    return this->guid;
}

int WordpressPost::getMenuOrder()
{
    return this->menu_order;
}

QString WordpressPost::getPostType()
{
    return this->post_type;
}

QString WordpressPost::getPostMineType()
{
    return this->post_mine_type;
}

int WordpressPost::getCommentCount()
{
    return this->comment_count;
}
