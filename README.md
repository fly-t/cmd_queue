# 项目介绍

一个简单的命令解析队列


参考: 大彩 stm32 驱动代码

# 嵌入式移植

将push入队操作放到串口中断中, 在中断中进行数据入队.


# 编译项目

``` c
gcc app_mian.c cmd_queue.c
```

运行

``` bashe
./a.out
```