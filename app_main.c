#include <stdio.h>
#include <stdint.h>
#include "queue_cmd.h"

uint8_t cmd_buffer[CMD_MAX_SIZE];

typedef struct
{
    uint8_t cmd_head;
    uint8_t ctrl_msg[2];
    uint8_t cmd_tail[4];
} CTRL_MSG, *PCTRL_MSG;

int main(void)
{ // 清空串口接收缓冲区
    queue_reset();

    // -------------------- cmd 1------------------------

    uint8_t data = 0xEE;
    queue_push(data);

    data = 0x11;
    queue_push(data);
    data = 0x22;
    queue_push(data);

    data = 0XFF;
    queue_push(data);
    data = 0XFC;
    queue_push(data);
    data = 0XFF;
    queue_push(data);
    data = 0XFF;
    queue_push(data);
    // -------------------- cmd 2------------------------
    data = 0xEE;
    queue_push(data);

    data = 0x44;
    queue_push(data);
    data = 0x33;
    queue_push(data);
    data = 0x55;
    queue_push(data);
    data = 0x55;
    queue_push(data);

    data = 0XFF;
    queue_push(data);
    data = 0XFC;
    queue_push(data);
    data = 0XFF;
    queue_push(data);
    data = 0XFF;
    queue_push(data);

    // -------------------- 出队列 cmd1 ------------------------

    int size = queue_find_cmd(cmd_buffer, CMD_MAX_SIZE);
    printf("cmd size %d\r\n", size);

    printf("msg %04x\r\n", *((uint16_t *)(((PCTRL_MSG)cmd_buffer)->ctrl_msg)));

    // -------------------- 出队列 cmd2 ------------------------
    int size2 = queue_find_cmd(cmd_buffer, CMD_MAX_SIZE);
    printf("cmd size %d\r\n", size2);

    printf("msg %04x\r\n", *((uint16_t *)(((PCTRL_MSG)cmd_buffer)->ctrl_msg)));
    return 0;
}