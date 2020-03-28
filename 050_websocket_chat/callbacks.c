#include "main.h"

void cb_on_message(duda_request_t *dr, ws_request_t *wr)
{
    websocket->broadcast(wr, wr->payload, wr->payload_len,
                         WS_OPCODE_TEXT, channel);
}

void cb_handshake(duda_request_t *dr)
{
    websocket->handshake(dr, channel);
}
