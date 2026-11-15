#ifndef CPP_OS__KERNEL_H
#define CPP_OS__KERNEL_H

#define PANIC(fmt, ...)                                                                     \
    do {                                                                                    \
        printf("PANIC!\nfile: %s\t\tline: %d\t\t" fmt "\n",                                 \ 
             __FILE__, __LINE__, ##__VA_ARGS__);                                            \
        while (1) {}                                                                        \
    } while (0)                                                                             \


struct sbiret
{
    long error;
    long value;
};

#endif