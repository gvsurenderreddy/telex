#ifndef _PROXY_H_
#define _PROXY_H_

#include <event2/event.h>
#include <event2/util.h>
#include <event2/listener.h>

#include "state.h"

#if !defined(LIBEVENT_VERSION_NUMBER) || LIBEVENT_VERSION_NUMBER < 0x02000100
#error "This version of Libevent is not supported; Get 2.0.1-alpha or later."
#endif

// We've accepted a connection for proxying...
// Establish a connection to server specified in conf
// and set up events to relay traffic in both directions.
void proxy_accept_cb(struct evconnlistener *listener, evutil_socket_t fd,
                     struct sockaddr *address, int socklen,
                     struct telex_conf *conf);

#endif//_PROXY_H_
