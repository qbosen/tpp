#include <stdio.h>

#define ARG 1
#define NO_ARG 0
#define ARRAY_SIZE(A) (sizeof(A) / sizeof(A[0]))

typedef struct
{
    char cmd;               /* command letter */
    int hasArg;             /* 是否有参数 */
    void (*func)(int, int); /* 带有两个参数、返回值为空类型的函数指针变量 */
} Command;

void doSelectPen(int cmd, int arg) { printf("P %d\n", arg); }
void doPenUp(int cmd, int arg) { printf("U\n"); }
void doPenDown(int cmd, int arg) { printf("D\n"); }
void doPenDir(int cmd, int arg) { printf("%c %d\n", cmd, arg); }

// 表驱动
static Command cmds[] = {
    {'P', ARG, doSelectPen},
    {'U', NO_ARG, doPenUp},
    {'D', NO_ARG, doPenDown},
    {'N', ARG, doPenDir},
    {'E', ARG, doPenDir},
    {'S', ARG, doPenDir},
    {'W', ARG, doPenDir}};

// 查找command 返回其指针, 没找到返回空指针
Command *findCommand(int cmd)
{
    // int i;
    for (int i = 0; i < ARRAY_SIZE(cmds); i++)
    {
        if (cmds[i].cmd == cmd)
        {
            return cmds + i;
        }
    }

    fprintf(stderr, "Unkonwn command '%c'\n", cmd);
    return 0;
}

// true: 扫描到1个数字，并赋值给 result
int getArg(const char *buff, int *result)
{
    return sscanf(buff, "%d", result) == 1;
}

int main(int argc, char **argv)
{
    char buff[100];

    // 读入一行
    while (fgets(buff, sizeof(buff), stdin))
    {
        Command *cmd = findCommand(*buff);
        // 找到cmd
        if (cmd)
        {
            int arg = 0;
            if (cmd->hasArg && !getArg(buff + 1, &arg))
            {
                fprintf(stderr, "'%c' needs an argument\n", *buff);
                continue;
            }

            cmd->func(*buff, arg);
        }
    }
}