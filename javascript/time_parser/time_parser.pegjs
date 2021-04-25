/* 

time    ::= hour ampm | hour : minute ampm | hour : minute 
ampm    ::= "am" | "pm"
hour    ::= h-tens digit | digit
minute  ::= m-tens digit | digit
h-tens  ::= 0|1
m-tens  ::= 0|1|2|3|4|5
digit   ::= 0|1|2|3|4|5|6|7|8|9

 */

{
    function parse(str) {
        return parseInt(str, 10);
    }
}

// 最后返回的记过是分钟数
time
 = h:hour offset:ampm               { return h + offset }
 / h:hour ":" m:minute offset:ampm  { return h + m + offset }
 / h:hour ":" m:minute              { return h + m }

ampm
= "am" { return 0 }
/ "pm" { return 12 * 60 }

hour
= h_tens:[01] h_unit:digit  { return (parse(h_tens) * 10 + h_unit) * 60 }
/ h_tens:[2] h_unit:[0-3]   { return (parse(h_tens) * 10 + parse(h_unit)) * 60 }
/ h_unit:digit              { return h_unit * 60 }

minute
= m_tens:[0-5] m_unit:digit { return parse(m_tens) * 10 + m_unit }
/ m_unit:digit              { return m_unit }

digit
= digit:[0-9] { return parse(digit) }
