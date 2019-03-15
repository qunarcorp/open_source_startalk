//
// Created by may on 2018/5/4.
//

#ifndef WIDGET_JID_H
#define WIDGET_JID_H

#include <string>

using namespace std;

namespace qtalk {
    class JID {

    public:
        static JID *jidWithString(std::string *str);

        JID(std::string *jid);

        JID(std::string *node, std::string *domain, std::string *resource);

    public:
        std::string fullname(void);

        std::string barename(void);

		std::string resourcestr(void);
    private:
        void init(std::string *node, std::string *domain, std::string *resource);

    private:
        std::string node;
        std::string domain;
        std::string resource;
    };
}


#endif //WIDGET_JID_H
