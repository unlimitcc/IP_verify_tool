grammar NC;
/*开启Visitor模式 根据不同 # Label 会自动生成对应的方法*/
prog:   stat+;
stat:   expr NEWLINE                    # printExpr        
    |   ID '=' expr NEWLINE             # assign
    |   NEWLINE                         # blank
    ;
expr:	'(' expr op=POW expr ')'   		# Pow
	|	expr op=(MUL | DIV | MOD) expr  # MulDivMod
    |   expr op=(ADD | SUB) expr        # AddSub
    |   NUM                             # Num
    |	'('SUB NUM ')'					# MinusVal
    |   ID                              # id
    |   '(' expr ')'                    # parens
    ;
    
ID : [a-zA-Z]+;
NUM: [0-9]+('.'[0-9]+)?;
NEWLINE : '\r'?'\n' ;
WS : [ \t]+ ->skip;
MUL : '*';
DIV : '/';
MOD : '%';
ADD : '+';
SUB : '-';
POW : '^';     
