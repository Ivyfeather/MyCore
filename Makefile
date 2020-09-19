.PHONY: test

test:
	@echo
	@echo "-- GENERATING .v -------------------"

	sbt "test:runMain MyCore.MyCoreGen" 
