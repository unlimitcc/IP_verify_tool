grammar contract;               	//parser and lexer	

file: (ltl NEWLINE)+ EOF //contract Assumptions
	;

ltl: TOP? '('? '(' ltl (LOP ltl)* ')' ')'?			//ltl property
	| TOP? '('? '(' propos (LOP propos)+ ')' ')'?
	| TOP? '('? propos ')'?
	;	
	
propos: quan+ '('? '(' com (LOP com)* ')' (LOP '(' com* (LOP com)* ')')? ')'?
	| '('? com ')'?		
	;	

com: expr op=COMP expr
	;	

quan: QUAN '(' VAR COLON RANGE ')'   	// QUANTIFIER
	| QUAN '(' VAR (COMMA VAR)* ')'
	; 

expr: '(' expr op=POW expr ')'					
	| expr op=(MUL | DIV | MOD) expr	
	| expr op=(ADD | SUB) expr		
	| VAR ('(' VAR COLON RANGE')')+ '(' expr ')'
	| VAR expr (COMMA expr)*	
	| '(' expr (COMMA expr)* ')'
	| '-' VALUE    	
	| VALUE
	| ARRAY						
	| VAR
	| '(' expr ')'								
	;

LOP: '&' | '|' | '->' | 'U'; 				//logical operator
TOP: 'G' | 'F' | 'X';						//temporal operator
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
