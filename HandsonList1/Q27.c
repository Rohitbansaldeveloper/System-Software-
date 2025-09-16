/*
============================================================================
Name : Q27.c
Author : Rohit Bansal
Description :Write a program to execute ls -Rl by the following system calls
             a. execl
             b. execlp
             c. execle
             d. execv
             e. execvp
Date: 30th Aug, 2025.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main(int argc,char *env[])
{
    char *path = "/bin/ls";
    execl(path, path, "-Rl", NULL);//a
    char *path2 = "ls";
    execlp(path2, path2, "-Rl", NULL);//b
    execle(path, path, "-Rl" ,"27c_example/",NULL, env);//c
    char *argv[] = {path,"-Rl",NULL};
    execv(path, argv);//d
    char *buf[] = {path2, "-Rl", NULL};
    execvp(path2, buf);//e     
    return 0;
}
/*
Output:
total 188
-rw-rw-rw- 1 rohit-bansal rohit-bansal   563 Aug  30 00:09 01_shell.sh
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16208 Aug  30 14:35 10
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16248 Aug  30 14:36 11
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 14:37 12
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16128 Aug  30 14:38 13
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16160 Aug  30 14:39 14
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16096 Aug  30 14:41 15
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16208 Aug  30 14:58 16a
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16208 Aug  30 14:58 16b
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16296 Aug  30 14:59 17
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16488 Aug  30 15:00 17b
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16120 Aug  30 15:02 18
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16304 Aug  30 15:01 18a
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16344 Aug  30 15:01 18b
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16104 Aug  30 15:02 19
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 14:20 1a
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 14:22 1b
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16152 Aug  30 14:22 1c
-rwxrwxr-x 1 rohit-bansal rohit-bansal 15848 Aug  30 14:23 2
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16168 Aug  30 15:03 20
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 15:03 21
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16288 Aug  30 15:05 22
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16240 Aug  30 15:07 23
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16200 Aug  30 15:08 24
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 15:09 25
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16080 Aug  30 15:09 26
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16248 Aug  30 15:09 27
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16152 Aug  30 15:10 28
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 14:23 3
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16112 Aug  30 14:24 4
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16152 Aug  30 14:26 5
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16160 Aug  30 14:27 6
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16200 Aug  30 14:28 7
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16328 Aug  30 14:30 8
-rwxrwxr-x 1 rohit-bansal rohit-bansal 16208 Aug  30 14:30 9
-rw-rw-rw- 1 rohit-bansal rohit-bansal     0 Aug  30 00:48 creatfile.txt
-rw-rw-rw- 1 rohit-bansal rohit-bansal     0 Aug  30 00:49 file1dup.txt
-rw-rw-rw- 2 rohit-bansal rohit-bansal    35 Aug  30 12:34 file1.txt
-rw-rw-rw- 1 rohit-bansal rohit-bansal    20 Aug  30 00:49 file2.txt
-rw-rw-r-- 1 rohit-bansal rohit-bansal    21 Aug  30 14:29 fileq7a.txt
-rw-r--r-- 1 rohit-bansal rohit-bansal    21 Aug  30 14:29 fileq7b.txt
-rw-r--r-- 1 rohit-bansal rohit-bansal    37 Aug  30 14:30 fileq8.txt
-rw-rw-r-- 2 rohit-bansal rohit-bansal    18 Aug  30 14:21 hardlink
prwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:23 mkfifo
prwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:23 mknod
-rwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:23 newfile
-rw-r--r-- 1 rohit-bansal rohit-bansal    50 Aug  30 15:05 out.txt
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1157 Aug  30 14:35 Q10.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   943 Sep  6 22:57 Q11.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal    24 Aug  30 14:36 Q11sample.txt
-rw-rw-rw- 1 rohit-bansal rohit-bansal   965 Sep  6 23:00 Q12.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   941 Sep  6 23:01 Q13.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1572 Sep  6 23:09 Q14.c
-rw-rw-r-- 1 rohit-bansal rohit-bansal  2890 Aug  30 14:57 Q15.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   900 Aug  30 12:42 Q16a.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1002 Sep  6 23:15 Q16b.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1153 Aug  30 15:00 Q17a.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1510 Sep  6 23:17 Q17b.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1367 Aug  30 12:31 Q18a.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1353 Sep  6 23:24 Q18b.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   971 Sep  6 23:19 Q18.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal    90 Sep  6 23:26 Q18main.txt
-rw-rw-rw- 1 rohit-bansal rohit-bansal   771 Aug  30 15:03 Q19.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   778 Aug  30 00:12 Q1a.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   733 Aug  30 14:22 Q1b.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1121 Aug  30 00:16 Q1c.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   869 Sep  6 23:31 Q20.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   591 Aug  30 15:04 Q21.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   779 Aug  30 15:05 Q22.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   778 Aug  30 15:07 Q23.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   770 Aug  30 15:09 Q24.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   596 Sep  6 23:45 Q25.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   615 Sep  6 23:48 Q26.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  4356 Aug  30 01:06 Q27.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1072 Sep  6 23:53 Q28.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  2508 Aug  30 12:37 Q29.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   448 Aug  30 00:20 Q2.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1033 Aug  30 00:47 Q30.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   864 Aug  30 00:22 Q3.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   800 Aug  30 14:24 Q4.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   906 Aug  30 00:26 Q5.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   715 Aug  30 00:28 Q6.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   596 Aug  30 00:33 Q7.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal   913 Aug  30 00:35 Q8.c
-rw-rw-rw- 1 rohit-bansal rohit-bansal  1811 Aug  30 14:32 Q9.c
lrwxrwxrwx 1 rohit-bansal rohit-bansal    10 Aug  30 14:22 softlink.txt -> source.txt
-rw-rw-r-- 2 rohit-bansal rohit-bansal    18 Aug  30 14:21 source.txt
-rwxrwxr-x 1 rohit-bansal rohit-bansal    30 Aug  30 14:36 temp.txt
-rwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:26 test1.txt
-rwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:26 test2.txt
-rwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:26 test3.txt
-rwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:26 test4.txt
-rwx------ 1 rohit-bansal rohit-bansal     0 Aug  30 14:26 test5.txt
-rw-rw-rw- 1 rohit-bansal rohit-bansal     4 Aug  30 15:00 ticket.txt
*/
