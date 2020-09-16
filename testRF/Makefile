TOP = RegFile
TOP_V = $(TOP).v
SIMTOP = sim_main.cpp
OUT_DIR = ./obj_dir

clean:
	rm -rf $(OUT_DIR)

run:
	$(OUT_DIR)/V$(TOP)

all:
	verilator -Wall --cc $(TOP_V) --exe $(SIMTOP) --trace
	cd $(OUT_DIR) && make -f V$(TOP).mk
