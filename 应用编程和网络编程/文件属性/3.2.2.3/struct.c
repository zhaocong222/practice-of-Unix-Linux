#include <stdio.h>
#include <stdlib.h>

//复习-结构体定义变量的三种方法

//1.先定义结构体，然后在定义结构体变量
struct stu{ /*定义学生结构体类型*/
    char name[20]; //学生姓名
    char sex; //性别
    long num; //学号
    float score[3]; //三科考试成绩
}
struct stu student1,student2; //定义结构体类型变量
struct stu student3,student4;
//用此结构体类型，可以定义更多的该结构体类型变量。

//2.定义结构体类型同时定义结构体类型变量：
struct data{
    int day;
    int month;
    int year;
} time1,time2;
//也可以在定义如下变量:
struct data time3,time4;
//用此结构体类型，同样可以定义更多的该结构体类型变量。

//3.直接定义结构体类型变量:
struct{
    char name[20]; //学生姓名
    char sex; //性别
    long num; //学号
    float score[3]; //三科考试成绩
} person1,person2; //定义该结构体类型变量
//该定义方法由于无法记录该结构体类型，所以除直接定义外，不能再定义该结构体类型变量。

//4. 在C中定义一个结构体类型要用typedef:
typedef struct Student{
    int a;
}Stu;
//于是在声明变量的时候就可： Stu stu1;
/*
如果没有typedef就必须用struct Student stu1;来声明
这里的Stu, 实际上就是 struct Student的别名
另外这里也可以不写Student（于是也不能struct Student stu1;了）

typedef struct{
    int a;
}Stu;
*/
