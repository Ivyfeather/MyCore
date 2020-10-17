.PHONY: test

test:
	@echo
	@echo "-- GENERATING .v -------------------"

#	sbt "test:runMain MyCore.MyCoreGen"
# done in IntellJ


# add dumpfile to the end of .v
# may modify chisel code to do this
	@sed -i '1i /* verilator lint_off UNUSED */' Top.v && sed -i '$$d' Top.v && cat >> Top.v <./test/dumpfile.txt
	cd ./test && make run
