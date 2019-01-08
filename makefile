all:
	@$(MAKE) clear
	@mkdir -p bin
	@$(MAKE) grammar
	@$(MAKE) lex
	@$(MAKE) compiler
	@$(MAKE) run/test/test2.lit

compiler:
	@g++ -std=c++17  bin/grammar.tab.c bin/lex.yy.c src/main.cpp -o bin/a.out

grammar:
	@echo
	@echo "\033[4m\033[1mBuilding grammar\033[0m"
	@echo
	bison -d src/grammar.y -o bin/grammar.tab.c

lex:
	@echo
	@echo "\033[4m\033[1mBuilding parser\033[0m"
	@echo
	flex -o bin/lex.yy.c src/lex.l 

run/%.lit: %.lit
	@./bin/a.out < $<
	@-node out.js
	@rm out.js

clear:
	@rm -rf bin