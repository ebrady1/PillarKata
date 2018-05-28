DIRS = src test
ECHO = echo

all:
	@$(ECHO)
	@$(ECHO) ---------- Building Sources ----------
	@$(ECHO)
	@cd src; $(MAKE)
	@$(ECHO)
	@$(ECHO) ---------- Building Tests ----------
	@$(ECHO)
	@cd test; $(MAKE)
	@$(ECHO)
	@$(ECHO) ---------- Running Tests ----------
	@$(ECHO)
	@bin/RomanNumeralCalcTests
	

clean:
	rm -rf bin
	rm -rf obj
	rm -rf lib

tests:
	$(ECHO) Building all tests
	cd test; $MAKE
