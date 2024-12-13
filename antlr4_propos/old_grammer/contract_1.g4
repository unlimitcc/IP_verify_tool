grammar contract;               	//parser and lexer	

file: (ltl)+ EOF //contract Assumptions
	;

ltl: '(' ltl (LOP ltl)* ')'
	| '(' propos (LOP propos)+ ')'
	| propos
	;	
	
propos: quan+ '('? '(' com (LOP com)* ')' (LOP '(' com* (LOP com)* ')')? ')'?
	| com		
	;	

com: expr op=COMP expr
	;	

quan: QUAN '(' VAR COLON RANGE ')'   	// QUANTIFIER
	| QUAN '(' VAR (COMMA VAR)* ')'
	; 

expr: '(' expr op=POW expr ')'					
	| expr op=(MUL | DIV | MOD) expr	
	| expr op=(ADD | SUB) expr			
	| VAR ('(' VAR COLON RANGE ')')+ '(' expr ')'
	| (VAR expr)	
	| '(' expr (COMMA expr)* ')'    	
	| VALUE						
	| VAR
	| '(' expr ')'								
	;

ASS: 'Assumptions' VALUE? COLON;
GUA: 'Guarantee' VALUE? COLON;
LOP: '&' | '|' | '->'; 						//logical operator
TOP: 'FINALLY' | 'GLOBALLY';				//temporal operator
QUAN: 'EXIST' | 'FORALL';					//quantifier in contract
VALUE: [0-9]+(POINT [0-9]+)? | SUB VALUE;		//digit value in contract 
VAR: [a-zA-Z_0-9-.]+(INDEX | '[' VAR ']')*; 	//var name defined in contract
fragment INDEX: ( '[' [0-9a-zA-Z]+ ']');	//index of var
ADD: '+';
SUB: '-';
MUL: '*';
DIV: '/';
MOD: '%';
POW: '^';
fragment TILDE: '~';
fragment EDGE: (VALUE | VAR | VAR'(' (VAR | VALUE) (COMMA (VAR | VALUE))*')');
RANGE: (EDGE TILDE EDGE);
COMP: '!=' | '>' | '>=' | '<' | '<=' | '=';
COLON: ':';
COMMA: ',';
fragment POINT: '.';  
SKIP1: [ \t\r\n]+ -> skip;
