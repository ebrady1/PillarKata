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

clean:
	rm -rf bin
	rm -rf obj

tests:
	$(ECHO) Building all tests
	cd test; $MAKE
