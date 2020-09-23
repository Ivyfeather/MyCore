.PHONY: test

test:
	@echo
	@echo "-- GENERATING .v -------------------"

	sbt "test:runMain MyCore.MyCoreGen" 
# to move generated .v to ./test
# may modify sbt settings to do this
	@mv Top.v Top.fir Top.anno.json ./test/

# add dumpfile to the end of .v
# may modify chisel code to do this
	@cd ./test && sed -i '$$d' Top.v && cat >> Top.v <dumpfile.txt
