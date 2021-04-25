# 时间解析器

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

## 流程

1. `npm install pegjs` 使用 `pegjs` PEG(parser generator)库
2. `npm install tape` 使用 `tape` 测试库
3. `npm init` 生成描述
4. `vscode` 可以安装 `PEG.js Language` 插件
5. `node run test` 执行测试


## 参考链接

1. [pegjs 语法](https://pegjs.org/documentation#using-the-parser)
2. [tape 文档](https://www.npmjs.com/package/tape)