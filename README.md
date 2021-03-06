# TPP

`The Pragmatic Programmer: your journey to mastery`

[程序员修炼之道：通向务实的最高境界](https://book.douban.com/subject/35006892/) 的练习代码

1. 练习4，画海龟
    ```
    P 2 # select pen 2
    D   # pen down
    W 2 # draw west 2cm
    N 1 # then north 1
    E 2 # then east 2
    S 1 # then south 1
    U   # pen up
    ```
    [c语言](c/turtle)

2. 练习6, BNF语法解析时间规范
    ```
    4pm, 7:38pm, 23:42, 3:16, 3:16am
    ```
    > Backus-Naur Form 巴科斯范式
    1. `::=`表示定义；
    2. `""` 双引号里的内容表示字符；
    3. `<>` 尖括号里的内容表示必选内容；
    4. `|` 竖线两边的是可选内容，相当于or；

    ```
    time    ::= hour ampm | hour : minute ampm | hour : minute 
    ampm    ::= "am" | "pm"
    hour    ::= h-tens digit | digit
    minute  ::= m-tens digit | digit
    h-tens  ::= 0|1
    m-tens  ::= 0|1|2|3|4|5
    digit   ::= 0|1|2|3|4|5|6|7|8|9
    ```
    
    [javascript with Pegjs](javascript/time_parser)