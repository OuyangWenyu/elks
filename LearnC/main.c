#include <stdio.h>
#include <stdlib.h>

/**
 * @param string 文件路径
 * @return 成功返回0
 */
int write_a_file(char string[]) {
    // 文件流
    FILE *fp;
    fp = fopen(string, "w+");
    // fprintf：发送格式化输出到流stream中
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2019);
    fclose(fp);
    return 0;
}

/**
 * 读取文件，打印文件内容
 * @param string  文件路径
 * @return  成功放回0
 */
int read_a_file(char string[]) {
    FILE *fp;
    int c;

    fp = fopen(string, "r");
    while (1) {
        // fgetc从指定的流中获取下一个字符（一个无符号字符），并把位置标识符往前移动。
        c = fgetc(fp);
        // feof测试给定流的文件结束标识符。
        if (feof(fp)) {
            break;
        }
        printf("%c", c);
    }
    fclose(fp);
    return (0);
}

/**
 * 读取nc文件
 * @return
 */
int read_nc() {

}

int main() {
    printf("Hello, World!\n");
    // ubuntu下绝对路径从/home开始
    char file_loc[] = "/home/dutwr/owenyy/file.txt";
    //调用读文件函数
    printf("读取一个其他位置的文件\n");
    int read_success = read_a_file(file_loc);
    return read_success;
}