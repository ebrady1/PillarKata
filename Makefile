DIRS = src test
ECHO = echo

.PHONY:	all
.PHONY: src
.PHONY: tests

all: tests src

src:
	@$(ECHO)
	@$(ECHO) ---------- Building Sources ----------
	@$(ECHO)
	@cd src; $(MAKE)


tests: src 
	@$(ECHO)
	@$(ECHO) ---------- Building Tests ----------
	@$(ECHO)
	@cd test; $(MAKE)

run_test: src tests
	@$(ECHO)
	@$(ECHO) ---------- Running Tests ----------
	@$(ECHO)
	@bin/RomanNumeralCalcTests

run: src
	@bin/RomanNumeralCalc

clean:
	rm -rf bin
	rm -rf obj
	rm -rf lib

