.SUFFIXES: .jj .java
.phony:	all run dot clean

PROG=SimpleLex

all:
	javacc ${PROG}.jj
	javac  ${PROG}.java

run:	all
	java ${PROG} abcd-fab-cd ab-abc-abcd < test.rules

dot:
	dot -Tpdf nfa.dot -o nfa.pdf
	dot -Tpdf dfa.dot -o dfa.pdf

clean:
	-rm regexp/*.class *.class *.java *.dot *.pdf

