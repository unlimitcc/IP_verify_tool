grammar contract;               	//parser and lexer	

file: (ltl NEWLINE)+ EOF //contract Assumptions
	;
	
ltl: propos
	| ltl '&' ltl
	| ltl '|' ltl
	| ltl '->' ltl
	| ltl '<->' ltl
	| '!' ltl
	| 'X' ltl
	| 'G' ltl
	| 'F' ltl
	| ltl 'U' ltl
	| '(' ltl ')'
	; 
	
propos: atomic_propos
	| propos '&' propos
	| propos '|' propos
	| propos '->' propos
	| propos '<->' propos
	| quan ':' propos	
	| '(' propos ')'
	;

atomic_propos: expr op=COMP expr
	| '(' quan ':' '(' atomic_propos (LOP atomic_propos)* ')' ')'
	;	

quan: (QUAN '(' VAR (COMMA VAR)* ')')+  //example: FORALL(x,y,z)
	| '(' quan ')'
	;

expr: '(' expr op=POW expr ')'					
	| expr op=(MUL | DIV | MOD) expr	
	| expr op=(ADD | SUB) expr		
	| VAR ('(' expr (COMMA expr)* ')')+	//function
	| '(' expr (COMMA expr)* ')'
	| '-' VALUE    	
	| VALUE
	| ARRAY						
	| VAR
	| '(' expr ')'								
	;

LOP: '&' | '|' | '->' | '<->';
QUAN: 'EXIST' | 'FORALL';					//quantifier in contract
fragment INT: [1-9][0-9]* | '0';			//integer
VALUE: INT | INT POINT INT;					//value 
VAR: [A-Za-z0-9_][a-zA-Z_0-9.]*; 			//variable
fragment INDEX: ('[' [0-9a-zA-Z]+ ']');		//array index
ARRAY: VAR (INDEX | '[' ARRAY ']')+;		//array element
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';
POW: '^';
fragment LIMIT: VAR | VALUE | ARRAY | VAR'(' LIMIT (COMMA LIMIT)*')';
fragment TILDE: '~';
RANGE: LIMIT TILDE LIMIT;
COMP: '!=' | '>' | '>=' | '<' | '<=' | '=';
COLON: ':';
COMMA: ',';
fragment POINT: '.';  
SKIP1: [ \t]+ -> skip;
NEWLINE: ('r'?'\n');
