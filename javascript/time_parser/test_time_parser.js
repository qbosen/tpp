// 测试框架
let test = require('tape');
// 测试过程中，解析 pegjs 生成的 js 文件
let time_parser = require('./time_parser.js');

// 解析器 对应的 处理逻辑：返回分钟数
const h = (val) => val * 60;
const m = (val) => val;
const am = (val) => val;
const pm = (val) => val + h(12);


let tests = {
    "4pm": pm(h(4)),
    "7:38pm": pm(h(7) + m(38)),
    "23:42": h(23) + m(42),
    "3:16": h(3) + m(16),
    "3:16am": am(h(3) + m(16)),
}

test('test time parse', function (t) {
    for (const time_str in tests) {
        let result = time_parser.parse(time_str);
        // t.equal(actual, expected, msg)
        t.equal(result, tests[time_str], time_str)
    }
    t.end()
})