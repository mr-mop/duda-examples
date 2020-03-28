/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "main.h"

DUDA_REGISTER("Duda I/O Examples", "WebSocket Chat");

int channel;
duda_logger_t logger_context;

int duda_main()
{
  duda_logger_create(&logger_context, "alarm.log");

  /* Load the websocket package */
  duda_load_package(websocket, "websocket");


  /*
   * We will have only one websocket channel identified by
   * number zero
   */
  channel = 0;

  /*
   * Define a callback, on every websocket message received,
   * trigger cb_on_message.
   */
  websocket->set_callback(WS_ON_MESSAGE, cb_on_message);

  /* Associate a static URL with a callback */
  map->static_add("/handshake/", "cb_handshake");

  /* Initialize the broadcaster interface */
  websocket->broadcaster();

  return 0;
}
