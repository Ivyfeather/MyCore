	// verilator_coverage annotation
	/* verilator lint_off UNUSED */
	module ALU(
 000041	  input  [5:0]  io_opcode,
 000116	  input  [63:0] io_in1,
 000256	  input  [63:0] io_in2,
 000134	  output [63:0] io_out,
 000023	  output        io_zero
	);
	  wire [63:0] _T_1 = ~io_in2; // @[ALU.scala 19:54]
	  wire [63:0] _T_3 = _T_1 + 64'h1; // @[ALU.scala 19:62]
	  wire [63:0] _T_4 = io_opcode[4] ? _T_3 : io_in2; // @[ALU.scala 19:35]
 000134	  wire [64:0] add_result = io_in1 + _T_4; // @[ALU.scala 19:29]
 000276	  wire [63:0] xor_result = io_in1 ^ io_in2; // @[ALU.scala 20:29]
 000324	  wire [63:0] or_result = io_in1 | io_in2; // @[ALU.scala 21:29]
 000048	  wire [63:0] and_result = io_in1 & io_in2; // @[ALU.scala 22:29]
%000001	  wire  sltu_result = ~add_result[64]; // @[ALU.scala 24:30]
%000001	  wire  slt_result = xor_result[63] ^ sltu_result; // @[ALU.scala 25:51]
 000030	  wire [4:0] shamt = io_in2[4:0]; // @[ALU.scala 28:23]
	  wire [94:0] _GEN_0 = {{31'd0}, io_in1}; // @[ALU.scala 29:30]
	  wire [94:0] _T_7 = _GEN_0 << shamt; // @[ALU.scala 29:30]
 000116	  wire [63:0] sll_result = _T_7[63:0]; // @[ALU.scala 29:39]
%000044	  wire [63:0] sra_result = $signed(io_in1) >>> shamt; // @[ALU.scala 30:55]
%000044	  wire [63:0] srl_result = io_in1 >> shamt; // @[ALU.scala 31:29]
 000134	  wire [63:0] io_out_res = add_result[63:0]; // @[ALU.scala 33:33]
	  wire  _io_out_T = io_opcode == 6'h12; // @[ALU.scala 34:20]
	  wire [63:0] _io_out_T_1 = {63'h0,sltu_result}; // @[Cat.scala 29:58]
	  wire  _io_out_T_2 = io_opcode == 6'h11; // @[ALU.scala 35:20]
	  wire [63:0] _io_out_T_3 = {63'h0,slt_result}; // @[Cat.scala 29:58]
	  wire  _io_out_T_4 = io_opcode == 6'h1; // @[ALU.scala 36:20]
	  wire  _io_out_T_5 = io_opcode == 6'h2; // @[ALU.scala 37:20]
	  wire  _io_out_T_6 = io_opcode == 6'h3; // @[ALU.scala 38:20]
	  wire  _io_out_T_7 = io_opcode == 6'h4; // @[ALU.scala 39:20]
	  wire  _io_out_T_8 = io_opcode == 6'h6; // @[ALU.scala 40:20]
	  wire  _io_out_T_9 = io_opcode == 6'h5; // @[ALU.scala 41:20]
	  wire  _io_out_T_10 = io_opcode == 6'h8; // @[ALU.scala 42:20]
	  wire [63:0] _io_out_T_11 = _io_out_T_10 ? io_in1 : io_out_res; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_12 = _io_out_T_9 ? srl_result : _io_out_T_11; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_13 = _io_out_T_8 ? sra_result : _io_out_T_12; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_14 = _io_out_T_7 ? sll_result : _io_out_T_13; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_15 = _io_out_T_6 ? and_result : _io_out_T_14; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_16 = _io_out_T_5 ? or_result : _io_out_T_15; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_17 = _io_out_T_4 ? xor_result : _io_out_T_16; // @[Mux.scala 98:16]
	  wire [63:0] _io_out_T_18 = _io_out_T_2 ? _io_out_T_3 : _io_out_T_17; // @[Mux.scala 98:16]
	  assign io_out = _io_out_T ? _io_out_T_1 : _io_out_T_18; // @[Mux.scala 98:16]
	  assign io_zero = io_out == 64'h0; // @[ALU.scala 45:27]
	endmodule
	module IDU(
 000359	  input  [31:0] io_inst,
%000028	  output [3:0]  io_br_type,
%000006	  output [1:0]  io_op1_sel,
 000032	  output [1:0]  io_op2_sel,
 000041	  output [5:0]  io_alu_op,
 000012	  output [1:0]  io_wb_sel,
%000007	  output        io_rf_wen,
%000000	  output        io_mem_en,
%000000	  output        io_mem_fcn,
%000000	  output [2:0]  io_mem_msk
	);
	  wire [31:0] _T = io_inst & 32'h707f; // @[Lookup.scala 31:38]
	  wire  _T_1 = 32'h2003 == _T; // @[Lookup.scala 31:38]
	  wire  _T_3 = 32'h3 == _T; // @[Lookup.scala 31:38]
	  wire  _T_5 = 32'h4003 == _T; // @[Lookup.scala 31:38]
	  wire  _T_7 = 32'h5003 == _T; // @[Lookup.scala 31:38]
	  wire  _T_9 = 32'h2023 == _T; // @[Lookup.scala 31:38]
	  wire  _T_11 = 32'h23 == _T; // @[Lookup.scala 31:38]
	  wire  _T_13 = 32'h1023 == _T; // @[Lookup.scala 31:38]
	  wire [31:0] _T_14 = io_inst & 32'h7f; // @[Lookup.scala 31:38]
	  wire  _T_15 = 32'h17 == _T_14; // @[Lookup.scala 31:38]
	  wire  _T_17 = 32'h37 == _T_14; // @[Lookup.scala 31:38]
	  wire  _T_19 = 32'h13 == _T; // @[Lookup.scala 31:38]
	  wire  _T_21 = 32'h7013 == _T; // @[Lookup.scala 31:38]
	  wire  _T_23 = 32'h6013 == _T; // @[Lookup.scala 31:38]
	  wire  _T_25 = 32'h4013 == _T; // @[Lookup.scala 31:38]
	  wire  _T_27 = 32'h2013 == _T; // @[Lookup.scala 31:38]
	  wire  _T_29 = 32'h3013 == _T; // @[Lookup.scala 31:38]
	  wire [31:0] _T_30 = io_inst & 32'hfc00707f; // @[Lookup.scala 31:38]
	  wire  _T_31 = 32'h1013 == _T_30; // @[Lookup.scala 31:38]
	  wire  _T_33 = 32'h40005013 == _T_30; // @[Lookup.scala 31:38]
	  wire  _T_35 = 32'h5013 == _T_30; // @[Lookup.scala 31:38]
	  wire [31:0] _T_36 = io_inst & 32'hfe00707f; // @[Lookup.scala 31:38]
	  wire  _T_37 = 32'h1033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_39 = 32'h33 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_41 = 32'h40000033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_43 = 32'h2033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_45 = 32'h3033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_47 = 32'h7033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_49 = 32'h6033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_51 = 32'h4033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_53 = 32'h40005033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_55 = 32'h5033 == _T_36; // @[Lookup.scala 31:38]
	  wire  _T_57 = 32'h6f == _T_14; // @[Lookup.scala 31:38]
	  wire  _T_59 = 32'h67 == _T; // @[Lookup.scala 31:38]
	  wire  _T_61 = 32'h63 == _T; // @[Lookup.scala 31:38]
	  wire  _T_63 = 32'h1063 == _T; // @[Lookup.scala 31:38]
	  wire  _T_65 = 32'h5063 == _T; // @[Lookup.scala 31:38]
	  wire  _T_67 = 32'h7063 == _T; // @[Lookup.scala 31:38]
	  wire  _T_69 = 32'h4063 == _T; // @[Lookup.scala 31:38]
	  wire  _T_71 = 32'h6063 == _T; // @[Lookup.scala 31:38]
	  wire  _T_73 = 32'h5073 == _T; // @[Lookup.scala 31:38]
	  wire  _T_75 = 32'h6073 == _T; // @[Lookup.scala 31:38]
	  wire  _T_77 = 32'h7073 == _T; // @[Lookup.scala 31:38]
	  wire  _T_79 = 32'h1073 == _T; // @[Lookup.scala 31:38]
	  wire  _T_81 = 32'h2073 == _T; // @[Lookup.scala 31:38]
	  wire  _T_83 = 32'h3073 == _T; // @[Lookup.scala 31:38]
	  wire  _T_85 = 32'h73 == io_inst; // @[Lookup.scala 31:38]
	  wire  _T_87 = 32'h30200073 == io_inst; // @[Lookup.scala 31:38]
	  wire  _T_89 = 32'h7b200073 == io_inst; // @[Lookup.scala 31:38]
	  wire  _T_91 = 32'h100073 == io_inst; // @[Lookup.scala 31:38]
	  wire  _T_93 = 32'h10500073 == io_inst; // @[Lookup.scala 31:38]
	  wire  _T_95 = 32'h100f == _T; // @[Lookup.scala 31:38]
	  wire  _T_97 = 32'hf == _T; // @[Lookup.scala 31:38]
	  wire [3:0] _T_159 = _T_71 ? 4'h6 : 4'h0; // @[Lookup.scala 33:37]
	  wire [3:0] _T_160 = _T_69 ? 4'h5 : _T_159; // @[Lookup.scala 33:37]
	  wire [3:0] _T_161 = _T_67 ? 4'h4 : _T_160; // @[Lookup.scala 33:37]
	  wire [3:0] _T_162 = _T_65 ? 4'h3 : _T_161; // @[Lookup.scala 33:37]
	  wire [3:0] _T_163 = _T_63 ? 4'h1 : _T_162; // @[Lookup.scala 33:37]
	  wire [3:0] _T_164 = _T_61 ? 4'h2 : _T_163; // @[Lookup.scala 33:37]
	  wire [3:0] _T_165 = _T_59 ? 4'h8 : _T_164; // @[Lookup.scala 33:37]
	  wire [3:0] _T_166 = _T_57 ? 4'h7 : _T_165; // @[Lookup.scala 33:37]
	  wire [3:0] _T_167 = _T_55 ? 4'h0 : _T_166; // @[Lookup.scala 33:37]
	  wire [3:0] _T_168 = _T_53 ? 4'h0 : _T_167; // @[Lookup.scala 33:37]
	  wire [3:0] _T_169 = _T_51 ? 4'h0 : _T_168; // @[Lookup.scala 33:37]
	  wire [3:0] _T_170 = _T_49 ? 4'h0 : _T_169; // @[Lookup.scala 33:37]
	  wire [3:0] _T_171 = _T_47 ? 4'h0 : _T_170; // @[Lookup.scala 33:37]
	  wire [3:0] _T_172 = _T_45 ? 4'h0 : _T_171; // @[Lookup.scala 33:37]
	  wire [3:0] _T_173 = _T_43 ? 4'h0 : _T_172; // @[Lookup.scala 33:37]
	  wire [3:0] _T_174 = _T_41 ? 4'h0 : _T_173; // @[Lookup.scala 33:37]
	  wire [3:0] _T_175 = _T_39 ? 4'h0 : _T_174; // @[Lookup.scala 33:37]
	  wire [3:0] _T_176 = _T_37 ? 4'h0 : _T_175; // @[Lookup.scala 33:37]
	  wire [3:0] _T_177 = _T_35 ? 4'h0 : _T_176; // @[Lookup.scala 33:37]
	  wire [3:0] _T_178 = _T_33 ? 4'h0 : _T_177; // @[Lookup.scala 33:37]
	  wire [3:0] _T_179 = _T_31 ? 4'h0 : _T_178; // @[Lookup.scala 33:37]
	  wire [3:0] _T_180 = _T_29 ? 4'h0 : _T_179; // @[Lookup.scala 33:37]
	  wire [3:0] _T_181 = _T_27 ? 4'h0 : _T_180; // @[Lookup.scala 33:37]
	  wire [3:0] _T_182 = _T_25 ? 4'h0 : _T_181; // @[Lookup.scala 33:37]
	  wire [3:0] _T_183 = _T_23 ? 4'h0 : _T_182; // @[Lookup.scala 33:37]
	  wire [3:0] _T_184 = _T_21 ? 4'h0 : _T_183; // @[Lookup.scala 33:37]
	  wire [3:0] _T_185 = _T_19 ? 4'h0 : _T_184; // @[Lookup.scala 33:37]
	  wire [3:0] _T_186 = _T_17 ? 4'h0 : _T_185; // @[Lookup.scala 33:37]
	  wire [3:0] _T_187 = _T_15 ? 4'h0 : _T_186; // @[Lookup.scala 33:37]
	  wire [3:0] _T_188 = _T_13 ? 4'h0 : _T_187; // @[Lookup.scala 33:37]
	  wire [3:0] _T_189 = _T_11 ? 4'h0 : _T_188; // @[Lookup.scala 33:37]
	  wire [3:0] _T_190 = _T_9 ? 4'h0 : _T_189; // @[Lookup.scala 33:37]
	  wire [3:0] _T_191 = _T_7 ? 4'h0 : _T_190; // @[Lookup.scala 33:37]
	  wire [3:0] _T_192 = _T_5 ? 4'h0 : _T_191; // @[Lookup.scala 33:37]
	  wire [3:0] _T_193 = _T_3 ? 4'h0 : _T_192; // @[Lookup.scala 33:37]
	  wire [1:0] _T_204 = _T_77 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
	  wire [1:0] _T_205 = _T_75 ? 2'h2 : _T_204; // @[Lookup.scala 33:37]
	  wire [1:0] _T_206 = _T_73 ? 2'h2 : _T_205; // @[Lookup.scala 33:37]
	  wire [1:0] _T_207 = _T_71 ? 2'h0 : _T_206; // @[Lookup.scala 33:37]
	  wire [1:0] _T_208 = _T_69 ? 2'h0 : _T_207; // @[Lookup.scala 33:37]
	  wire [1:0] _T_209 = _T_67 ? 2'h0 : _T_208; // @[Lookup.scala 33:37]
	  wire [1:0] _T_210 = _T_65 ? 2'h0 : _T_209; // @[Lookup.scala 33:37]
	  wire [1:0] _T_211 = _T_63 ? 2'h0 : _T_210; // @[Lookup.scala 33:37]
	  wire [1:0] _T_212 = _T_61 ? 2'h0 : _T_211; // @[Lookup.scala 33:37]
	  wire [1:0] _T_213 = _T_59 ? 2'h0 : _T_212; // @[Lookup.scala 33:37]
	  wire [1:0] _T_214 = _T_57 ? 2'h0 : _T_213; // @[Lookup.scala 33:37]
	  wire [1:0] _T_215 = _T_55 ? 2'h0 : _T_214; // @[Lookup.scala 33:37]
	  wire [1:0] _T_216 = _T_53 ? 2'h0 : _T_215; // @[Lookup.scala 33:37]
	  wire [1:0] _T_217 = _T_51 ? 2'h0 : _T_216; // @[Lookup.scala 33:37]
	  wire [1:0] _T_218 = _T_49 ? 2'h0 : _T_217; // @[Lookup.scala 33:37]
	  wire [1:0] _T_219 = _T_47 ? 2'h0 : _T_218; // @[Lookup.scala 33:37]
	  wire [1:0] _T_220 = _T_45 ? 2'h0 : _T_219; // @[Lookup.scala 33:37]
	  wire [1:0] _T_221 = _T_43 ? 2'h0 : _T_220; // @[Lookup.scala 33:37]
	  wire [1:0] _T_222 = _T_41 ? 2'h0 : _T_221; // @[Lookup.scala 33:37]
	  wire [1:0] _T_223 = _T_39 ? 2'h0 : _T_222; // @[Lookup.scala 33:37]
	  wire [1:0] _T_224 = _T_37 ? 2'h0 : _T_223; // @[Lookup.scala 33:37]
	  wire [1:0] _T_225 = _T_35 ? 2'h0 : _T_224; // @[Lookup.scala 33:37]
	  wire [1:0] _T_226 = _T_33 ? 2'h0 : _T_225; // @[Lookup.scala 33:37]
	  wire [1:0] _T_227 = _T_31 ? 2'h0 : _T_226; // @[Lookup.scala 33:37]
	  wire [1:0] _T_228 = _T_29 ? 2'h0 : _T_227; // @[Lookup.scala 33:37]
	  wire [1:0] _T_229 = _T_27 ? 2'h0 : _T_228; // @[Lookup.scala 33:37]
	  wire [1:0] _T_230 = _T_25 ? 2'h0 : _T_229; // @[Lookup.scala 33:37]
	  wire [1:0] _T_231 = _T_23 ? 2'h0 : _T_230; // @[Lookup.scala 33:37]
	  wire [1:0] _T_232 = _T_21 ? 2'h0 : _T_231; // @[Lookup.scala 33:37]
	  wire [1:0] _T_233 = _T_19 ? 2'h0 : _T_232; // @[Lookup.scala 33:37]
	  wire [1:0] _T_234 = _T_17 ? 2'h1 : _T_233; // @[Lookup.scala 33:37]
	  wire [1:0] _T_235 = _T_15 ? 2'h1 : _T_234; // @[Lookup.scala 33:37]
	  wire [1:0] _T_236 = _T_13 ? 2'h0 : _T_235; // @[Lookup.scala 33:37]
	  wire [1:0] _T_237 = _T_11 ? 2'h0 : _T_236; // @[Lookup.scala 33:37]
	  wire [1:0] _T_238 = _T_9 ? 2'h0 : _T_237; // @[Lookup.scala 33:37]
	  wire [1:0] _T_239 = _T_7 ? 2'h0 : _T_238; // @[Lookup.scala 33:37]
	  wire [1:0] _T_240 = _T_5 ? 2'h0 : _T_239; // @[Lookup.scala 33:37]
	  wire [1:0] _T_241 = _T_3 ? 2'h0 : _T_240; // @[Lookup.scala 33:37]
	  wire [1:0] _T_261 = _T_59 ? 2'h1 : 2'h0; // @[Lookup.scala 33:37]
	  wire [1:0] _T_262 = _T_57 ? 2'h0 : _T_261; // @[Lookup.scala 33:37]
	  wire [1:0] _T_263 = _T_55 ? 2'h0 : _T_262; // @[Lookup.scala 33:37]
	  wire [1:0] _T_264 = _T_53 ? 2'h0 : _T_263; // @[Lookup.scala 33:37]
	  wire [1:0] _T_265 = _T_51 ? 2'h0 : _T_264; // @[Lookup.scala 33:37]
	  wire [1:0] _T_266 = _T_49 ? 2'h0 : _T_265; // @[Lookup.scala 33:37]
	  wire [1:0] _T_267 = _T_47 ? 2'h0 : _T_266; // @[Lookup.scala 33:37]
	  wire [1:0] _T_268 = _T_45 ? 2'h0 : _T_267; // @[Lookup.scala 33:37]
	  wire [1:0] _T_269 = _T_43 ? 2'h0 : _T_268; // @[Lookup.scala 33:37]
	  wire [1:0] _T_270 = _T_41 ? 2'h0 : _T_269; // @[Lookup.scala 33:37]
	  wire [1:0] _T_271 = _T_39 ? 2'h0 : _T_270; // @[Lookup.scala 33:37]
	  wire [1:0] _T_272 = _T_37 ? 2'h0 : _T_271; // @[Lookup.scala 33:37]
	  wire [1:0] _T_273 = _T_35 ? 2'h1 : _T_272; // @[Lookup.scala 33:37]
	  wire [1:0] _T_274 = _T_33 ? 2'h1 : _T_273; // @[Lookup.scala 33:37]
	  wire [1:0] _T_275 = _T_31 ? 2'h1 : _T_274; // @[Lookup.scala 33:37]
	  wire [1:0] _T_276 = _T_29 ? 2'h1 : _T_275; // @[Lookup.scala 33:37]
	  wire [1:0] _T_277 = _T_27 ? 2'h1 : _T_276; // @[Lookup.scala 33:37]
	  wire [1:0] _T_278 = _T_25 ? 2'h1 : _T_277; // @[Lookup.scala 33:37]
	  wire [1:0] _T_279 = _T_23 ? 2'h1 : _T_278; // @[Lookup.scala 33:37]
	  wire [1:0] _T_280 = _T_21 ? 2'h1 : _T_279; // @[Lookup.scala 33:37]
	  wire [1:0] _T_281 = _T_19 ? 2'h1 : _T_280; // @[Lookup.scala 33:37]
	  wire [1:0] _T_282 = _T_17 ? 2'h0 : _T_281; // @[Lookup.scala 33:37]
	  wire [1:0] _T_283 = _T_15 ? 2'h3 : _T_282; // @[Lookup.scala 33:37]
	  wire [1:0] _T_284 = _T_13 ? 2'h2 : _T_283; // @[Lookup.scala 33:37]
	  wire [1:0] _T_285 = _T_11 ? 2'h2 : _T_284; // @[Lookup.scala 33:37]
	  wire [1:0] _T_286 = _T_9 ? 2'h2 : _T_285; // @[Lookup.scala 33:37]
	  wire [1:0] _T_287 = _T_7 ? 2'h1 : _T_286; // @[Lookup.scala 33:37]
	  wire [1:0] _T_288 = _T_5 ? 2'h1 : _T_287; // @[Lookup.scala 33:37]
	  wire [1:0] _T_289 = _T_3 ? 2'h1 : _T_288; // @[Lookup.scala 33:37]
	  wire [3:0] _T_297 = _T_83 ? 4'h8 : 4'h0; // @[Lookup.scala 33:37]
	  wire [3:0] _T_298 = _T_81 ? 4'h8 : _T_297; // @[Lookup.scala 33:37]
	  wire [3:0] _T_299 = _T_79 ? 4'h8 : _T_298; // @[Lookup.scala 33:37]
	  wire [3:0] _T_300 = _T_77 ? 4'h8 : _T_299; // @[Lookup.scala 33:37]
	  wire [3:0] _T_301 = _T_75 ? 4'h8 : _T_300; // @[Lookup.scala 33:37]
	  wire [3:0] _T_302 = _T_73 ? 4'h8 : _T_301; // @[Lookup.scala 33:37]
	  wire [4:0] _T_303 = _T_71 ? 5'h12 : {{1'd0}, _T_302}; // @[Lookup.scala 33:37]
	  wire [4:0] _T_304 = _T_69 ? 5'h11 : _T_303; // @[Lookup.scala 33:37]
	  wire [4:0] _T_305 = _T_67 ? 5'h12 : _T_304; // @[Lookup.scala 33:37]
	  wire [4:0] _T_306 = _T_65 ? 5'h11 : _T_305; // @[Lookup.scala 33:37]
	  wire [4:0] _T_307 = _T_63 ? 5'h10 : _T_306; // @[Lookup.scala 33:37]
	  wire [4:0] _T_308 = _T_61 ? 5'h10 : _T_307; // @[Lookup.scala 33:37]
	  wire [4:0] _T_309 = _T_59 ? 5'h0 : _T_308; // @[Lookup.scala 33:37]
	  wire [4:0] _T_310 = _T_57 ? 5'h0 : _T_309; // @[Lookup.scala 33:37]
	  wire [4:0] _T_311 = _T_55 ? 5'h5 : _T_310; // @[Lookup.scala 33:37]
	  wire [4:0] _T_312 = _T_53 ? 5'h6 : _T_311; // @[Lookup.scala 33:37]
	  wire [4:0] _T_313 = _T_51 ? 5'h1 : _T_312; // @[Lookup.scala 33:37]
	  wire [4:0] _T_314 = _T_49 ? 5'h2 : _T_313; // @[Lookup.scala 33:37]
	  wire [4:0] _T_315 = _T_47 ? 5'h3 : _T_314; // @[Lookup.scala 33:37]
	  wire [4:0] _T_316 = _T_45 ? 5'h12 : _T_315; // @[Lookup.scala 33:37]
	  wire [4:0] _T_317 = _T_43 ? 5'h11 : _T_316; // @[Lookup.scala 33:37]
	  wire [4:0] _T_318 = _T_41 ? 5'h10 : _T_317; // @[Lookup.scala 33:37]
	  wire [4:0] _T_319 = _T_39 ? 5'h0 : _T_318; // @[Lookup.scala 33:37]
	  wire [4:0] _T_320 = _T_37 ? 5'h4 : _T_319; // @[Lookup.scala 33:37]
	  wire [4:0] _T_321 = _T_35 ? 5'h5 : _T_320; // @[Lookup.scala 33:37]
	  wire [4:0] _T_322 = _T_33 ? 5'h6 : _T_321; // @[Lookup.scala 33:37]
	  wire [4:0] _T_323 = _T_31 ? 5'h4 : _T_322; // @[Lookup.scala 33:37]
	  wire [4:0] _T_324 = _T_29 ? 5'h12 : _T_323; // @[Lookup.scala 33:37]
	  wire [4:0] _T_325 = _T_27 ? 5'h11 : _T_324; // @[Lookup.scala 33:37]
	  wire [4:0] _T_326 = _T_25 ? 5'h1 : _T_325; // @[Lookup.scala 33:37]
	  wire [4:0] _T_327 = _T_23 ? 5'h2 : _T_326; // @[Lookup.scala 33:37]
	  wire [4:0] _T_328 = _T_21 ? 5'h3 : _T_327; // @[Lookup.scala 33:37]
	  wire [4:0] _T_329 = _T_19 ? 5'h0 : _T_328; // @[Lookup.scala 33:37]
	  wire [4:0] _T_330 = _T_17 ? 5'h8 : _T_329; // @[Lookup.scala 33:37]
	  wire [4:0] _T_331 = _T_15 ? 5'h0 : _T_330; // @[Lookup.scala 33:37]
	  wire [4:0] _T_332 = _T_13 ? 5'h0 : _T_331; // @[Lookup.scala 33:37]
	  wire [4:0] _T_333 = _T_11 ? 5'h0 : _T_332; // @[Lookup.scala 33:37]
	  wire [4:0] _T_334 = _T_9 ? 5'h0 : _T_333; // @[Lookup.scala 33:37]
	  wire [4:0] _T_335 = _T_7 ? 5'h0 : _T_334; // @[Lookup.scala 33:37]
	  wire [4:0] _T_336 = _T_5 ? 5'h0 : _T_335; // @[Lookup.scala 33:37]
	  wire [4:0] _T_337 = _T_3 ? 5'h0 : _T_336; // @[Lookup.scala 33:37]
 000041	  wire [4:0] csignals_4 = _T_1 ? 5'h0 : _T_337; // @[Lookup.scala 33:37]
	  wire [1:0] _T_345 = _T_83 ? 2'h3 : 2'h0; // @[Lookup.scala 33:37]
	  wire [1:0] _T_346 = _T_81 ? 2'h3 : _T_345; // @[Lookup.scala 33:37]
	  wire [1:0] _T_347 = _T_79 ? 2'h3 : _T_346; // @[Lookup.scala 33:37]
	  wire [1:0] _T_348 = _T_77 ? 2'h3 : _T_347; // @[Lookup.scala 33:37]
	  wire [1:0] _T_349 = _T_75 ? 2'h3 : _T_348; // @[Lookup.scala 33:37]
	  wire [1:0] _T_350 = _T_73 ? 2'h3 : _T_349; // @[Lookup.scala 33:37]
	  wire [1:0] _T_351 = _T_71 ? 2'h0 : _T_350; // @[Lookup.scala 33:37]
	  wire [1:0] _T_352 = _T_69 ? 2'h0 : _T_351; // @[Lookup.scala 33:37]
	  wire [1:0] _T_353 = _T_67 ? 2'h0 : _T_352; // @[Lookup.scala 33:37]
	  wire [1:0] _T_354 = _T_65 ? 2'h0 : _T_353; // @[Lookup.scala 33:37]
	  wire [1:0] _T_355 = _T_63 ? 2'h0 : _T_354; // @[Lookup.scala 33:37]
	  wire [1:0] _T_356 = _T_61 ? 2'h0 : _T_355; // @[Lookup.scala 33:37]
	  wire [1:0] _T_357 = _T_59 ? 2'h2 : _T_356; // @[Lookup.scala 33:37]
	  wire [1:0] _T_358 = _T_57 ? 2'h2 : _T_357; // @[Lookup.scala 33:37]
	  wire [1:0] _T_359 = _T_55 ? 2'h0 : _T_358; // @[Lookup.scala 33:37]
	  wire [1:0] _T_360 = _T_53 ? 2'h0 : _T_359; // @[Lookup.scala 33:37]
	  wire [1:0] _T_361 = _T_51 ? 2'h0 : _T_360; // @[Lookup.scala 33:37]
	  wire [1:0] _T_362 = _T_49 ? 2'h0 : _T_361; // @[Lookup.scala 33:37]
	  wire [1:0] _T_363 = _T_47 ? 2'h0 : _T_362; // @[Lookup.scala 33:37]
	  wire [1:0] _T_364 = _T_45 ? 2'h0 : _T_363; // @[Lookup.scala 33:37]
	  wire [1:0] _T_365 = _T_43 ? 2'h0 : _T_364; // @[Lookup.scala 33:37]
	  wire [1:0] _T_366 = _T_41 ? 2'h0 : _T_365; // @[Lookup.scala 33:37]
	  wire [1:0] _T_367 = _T_39 ? 2'h0 : _T_366; // @[Lookup.scala 33:37]
	  wire [1:0] _T_368 = _T_37 ? 2'h0 : _T_367; // @[Lookup.scala 33:37]
	  wire [1:0] _T_369 = _T_35 ? 2'h0 : _T_368; // @[Lookup.scala 33:37]
	  wire [1:0] _T_370 = _T_33 ? 2'h0 : _T_369; // @[Lookup.scala 33:37]
	  wire [1:0] _T_371 = _T_31 ? 2'h0 : _T_370; // @[Lookup.scala 33:37]
	  wire [1:0] _T_372 = _T_29 ? 2'h0 : _T_371; // @[Lookup.scala 33:37]
	  wire [1:0] _T_373 = _T_27 ? 2'h0 : _T_372; // @[Lookup.scala 33:37]
	  wire [1:0] _T_374 = _T_25 ? 2'h0 : _T_373; // @[Lookup.scala 33:37]
	  wire [1:0] _T_375 = _T_23 ? 2'h0 : _T_374; // @[Lookup.scala 33:37]
	  wire [1:0] _T_376 = _T_21 ? 2'h0 : _T_375; // @[Lookup.scala 33:37]
	  wire [1:0] _T_377 = _T_19 ? 2'h0 : _T_376; // @[Lookup.scala 33:37]
	  wire [1:0] _T_378 = _T_17 ? 2'h0 : _T_377; // @[Lookup.scala 33:37]
	  wire [1:0] _T_379 = _T_15 ? 2'h0 : _T_378; // @[Lookup.scala 33:37]
	  wire [1:0] _T_380 = _T_13 ? 2'h0 : _T_379; // @[Lookup.scala 33:37]
	  wire [1:0] _T_381 = _T_11 ? 2'h0 : _T_380; // @[Lookup.scala 33:37]
	  wire [1:0] _T_382 = _T_9 ? 2'h0 : _T_381; // @[Lookup.scala 33:37]
	  wire [1:0] _T_383 = _T_7 ? 2'h1 : _T_382; // @[Lookup.scala 33:37]
	  wire [1:0] _T_384 = _T_5 ? 2'h1 : _T_383; // @[Lookup.scala 33:37]
	  wire [1:0] _T_385 = _T_3 ? 2'h1 : _T_384; // @[Lookup.scala 33:37]
	  wire  _T_399 = _T_71 ? 1'h0 : _T_73 | (_T_75 | (_T_77 | (_T_79 | (_T_81 | _T_83)))); // @[Lookup.scala 33:37]
	  wire  _T_400 = _T_69 ? 1'h0 : _T_399; // @[Lookup.scala 33:37]
	  wire  _T_401 = _T_67 ? 1'h0 : _T_400; // @[Lookup.scala 33:37]
	  wire  _T_402 = _T_65 ? 1'h0 : _T_401; // @[Lookup.scala 33:37]
	  wire  _T_403 = _T_63 ? 1'h0 : _T_402; // @[Lookup.scala 33:37]
	  wire  _T_404 = _T_61 ? 1'h0 : _T_403; // @[Lookup.scala 33:37]
	  wire  _T_428 = _T_13 ? 1'h0 : _T_15 | (_T_17 | (_T_19 | (_T_21 | (_T_23 | (_T_25 | (_T_27 | (_T_29 | (_T_31 | (_T_33
	     | (_T_35 | (_T_37 | (_T_39 | (_T_41 | (_T_43 | (_T_45 | (_T_47 | (_T_49 | (_T_51 | (_T_53 | (_T_55 | (_T_57 | (
	    _T_59 | _T_404)))))))))))))))))))))); // @[Lookup.scala 33:37]
	  wire  _T_429 = _T_11 ? 1'h0 : _T_428; // @[Lookup.scala 33:37]
	  wire  _T_430 = _T_9 ? 1'h0 : _T_429; // @[Lookup.scala 33:37]
	  wire  _T_435 = _T_95 ? 1'h0 : _T_97; // @[Lookup.scala 33:37]
	  wire  _T_436 = _T_93 ? 1'h0 : _T_435; // @[Lookup.scala 33:37]
	  wire  _T_437 = _T_91 ? 1'h0 : _T_436; // @[Lookup.scala 33:37]
	  wire  _T_438 = _T_89 ? 1'h0 : _T_437; // @[Lookup.scala 33:37]
	  wire  _T_439 = _T_87 ? 1'h0 : _T_438; // @[Lookup.scala 33:37]
	  wire  _T_440 = _T_85 ? 1'h0 : _T_439; // @[Lookup.scala 33:37]
	  wire  _T_441 = _T_83 ? 1'h0 : _T_440; // @[Lookup.scala 33:37]
	  wire  _T_442 = _T_81 ? 1'h0 : _T_441; // @[Lookup.scala 33:37]
	  wire  _T_443 = _T_79 ? 1'h0 : _T_442; // @[Lookup.scala 33:37]
	  wire  _T_444 = _T_77 ? 1'h0 : _T_443; // @[Lookup.scala 33:37]
	  wire  _T_445 = _T_75 ? 1'h0 : _T_444; // @[Lookup.scala 33:37]
	  wire  _T_446 = _T_73 ? 1'h0 : _T_445; // @[Lookup.scala 33:37]
	  wire  _T_447 = _T_71 ? 1'h0 : _T_446; // @[Lookup.scala 33:37]
	  wire  _T_448 = _T_69 ? 1'h0 : _T_447; // @[Lookup.scala 33:37]
	  wire  _T_449 = _T_67 ? 1'h0 : _T_448; // @[Lookup.scala 33:37]
	  wire  _T_450 = _T_65 ? 1'h0 : _T_449; // @[Lookup.scala 33:37]
	  wire  _T_451 = _T_63 ? 1'h0 : _T_450; // @[Lookup.scala 33:37]
	  wire  _T_452 = _T_61 ? 1'h0 : _T_451; // @[Lookup.scala 33:37]
	  wire  _T_453 = _T_59 ? 1'h0 : _T_452; // @[Lookup.scala 33:37]
	  wire  _T_454 = _T_57 ? 1'h0 : _T_453; // @[Lookup.scala 33:37]
	  wire  _T_455 = _T_55 ? 1'h0 : _T_454; // @[Lookup.scala 33:37]
	  wire  _T_456 = _T_53 ? 1'h0 : _T_455; // @[Lookup.scala 33:37]
	  wire  _T_457 = _T_51 ? 1'h0 : _T_456; // @[Lookup.scala 33:37]
	  wire  _T_458 = _T_49 ? 1'h0 : _T_457; // @[Lookup.scala 33:37]
	  wire  _T_459 = _T_47 ? 1'h0 : _T_458; // @[Lookup.scala 33:37]
	  wire  _T_460 = _T_45 ? 1'h0 : _T_459; // @[Lookup.scala 33:37]
	  wire  _T_461 = _T_43 ? 1'h0 : _T_460; // @[Lookup.scala 33:37]
	  wire  _T_462 = _T_41 ? 1'h0 : _T_461; // @[Lookup.scala 33:37]
	  wire  _T_463 = _T_39 ? 1'h0 : _T_462; // @[Lookup.scala 33:37]
	  wire  _T_464 = _T_37 ? 1'h0 : _T_463; // @[Lookup.scala 33:37]
	  wire  _T_465 = _T_35 ? 1'h0 : _T_464; // @[Lookup.scala 33:37]
	  wire  _T_466 = _T_33 ? 1'h0 : _T_465; // @[Lookup.scala 33:37]
	  wire  _T_467 = _T_31 ? 1'h0 : _T_466; // @[Lookup.scala 33:37]
	  wire  _T_468 = _T_29 ? 1'h0 : _T_467; // @[Lookup.scala 33:37]
	  wire  _T_469 = _T_27 ? 1'h0 : _T_468; // @[Lookup.scala 33:37]
	  wire  _T_470 = _T_25 ? 1'h0 : _T_469; // @[Lookup.scala 33:37]
	  wire  _T_471 = _T_23 ? 1'h0 : _T_470; // @[Lookup.scala 33:37]
	  wire  _T_472 = _T_21 ? 1'h0 : _T_471; // @[Lookup.scala 33:37]
	  wire  _T_473 = _T_19 ? 1'h0 : _T_472; // @[Lookup.scala 33:37]
	  wire  _T_474 = _T_17 ? 1'h0 : _T_473; // @[Lookup.scala 33:37]
	  wire  _T_475 = _T_15 ? 1'h0 : _T_474; // @[Lookup.scala 33:37]
	  wire  _T_527 = _T_7 ? 1'h0 : _T_9 | (_T_11 | _T_13); // @[Lookup.scala 33:37]
	  wire  _T_528 = _T_5 ? 1'h0 : _T_527; // @[Lookup.scala 33:37]
	  wire  _T_529 = _T_3 ? 1'h0 : _T_528; // @[Lookup.scala 33:37]
	  wire [2:0] _T_572 = _T_13 ? 3'h2 : 3'h0; // @[Lookup.scala 33:37]
	  wire [2:0] _T_573 = _T_11 ? 3'h1 : _T_572; // @[Lookup.scala 33:37]
	  wire [2:0] _T_574 = _T_9 ? 3'h3 : _T_573; // @[Lookup.scala 33:37]
	  wire [2:0] _T_575 = _T_7 ? 3'h6 : _T_574; // @[Lookup.scala 33:37]
	  wire [2:0] _T_576 = _T_5 ? 3'h5 : _T_575; // @[Lookup.scala 33:37]
	  wire [2:0] _T_577 = _T_3 ? 3'h1 : _T_576; // @[Lookup.scala 33:37]
	  assign io_br_type = _T_1 ? 4'h0 : _T_193; // @[Lookup.scala 33:37]
	  assign io_op1_sel = _T_1 ? 2'h0 : _T_241; // @[Lookup.scala 33:37]
	  assign io_op2_sel = _T_1 ? 2'h1 : _T_289; // @[Lookup.scala 33:37]
	  assign io_alu_op = {{1'd0}, csignals_4}; // @[Lookup.scala 33:37]
	  assign io_wb_sel = _T_1 ? 2'h1 : _T_385; // @[Lookup.scala 33:37]
	  assign io_rf_wen = _T_1 | (_T_3 | (_T_5 | (_T_7 | _T_430))); // @[Lookup.scala 33:37]
	  assign io_mem_en = _T_1 | (_T_3 | (_T_5 | (_T_7 | (_T_9 | (_T_11 | (_T_13 | _T_475)))))); // @[Lookup.scala 33:37]
	  assign io_mem_fcn = _T_1 ? 1'h0 : _T_529; // @[Lookup.scala 33:37]
	  assign io_mem_msk = _T_1 ? 3'h3 : _T_577; // @[Lookup.scala 33:37]
	endmodule
	module RegFile(
 000126	  input         clock,
 000052	  input  [4:0]  io_rs1_addr,
 000108	  output [63:0] io_rs1_data,
 000038	  input  [4:0]  io_rs2_addr,
%000014	  output [63:0] io_rs2_data,
 000048	  input  [4:0]  io_waddr,
 000160	  input  [63:0] io_wdata,
%000007	  input         io_wen,
	  output [63:0] _WIRE_0_0,
	  output [63:0] _WIRE_0_1,
	  output [63:0] _WIRE_0_2,
	  output [63:0] _WIRE_0_3,
	  output [63:0] _WIRE_0_4,
	  output [63:0] _WIRE_0_5,
	  output [63:0] _WIRE_0_6,
	  output [63:0] _WIRE_0_7,
	  output [63:0] _WIRE_0_8,
	  output [63:0] _WIRE_0_9,
	  output [63:0] _WIRE_0_10,
	  output [63:0] _WIRE_0_11,
	  output [63:0] _WIRE_0_12,
	  output [63:0] _WIRE_0_13,
	  output [63:0] _WIRE_0_14,
	  output [63:0] _WIRE_0_15,
	  output [63:0] _WIRE_0_16,
	  output [63:0] _WIRE_0_17,
	  output [63:0] _WIRE_0_18,
	  output [63:0] _WIRE_0_19,
	  output [63:0] _WIRE_0_20,
	  output [63:0] _WIRE_0_21,
	  output [63:0] _WIRE_0_22,
	  output [63:0] _WIRE_0_23,
	  output [63:0] _WIRE_0_24,
	  output [63:0] _WIRE_0_25,
	  output [63:0] _WIRE_0_26,
	  output [63:0] _WIRE_0_27,
	  output [63:0] _WIRE_0_28,
	  output [63:0] _WIRE_0_29,
	  output [63:0] _WIRE_0_30,
	  output [63:0] _WIRE_0_31
	);
	`ifdef RANDOMIZE_MEM_INIT
	  reg [63:0] _RAND_0;
	`endif // RANDOMIZE_MEM_INIT
	  reg [63:0] regfile [0:31]; // @[RegFile.scala 20:22]
 000110	  wire [63:0] regfile_io_rs1_data_MPORT_data; // @[RegFile.scala 20:22]
 000052	  wire [4:0] regfile_io_rs1_data_MPORT_addr; // @[RegFile.scala 20:22]
%000026	  wire [63:0] regfile_io_rs2_data_MPORT_data; // @[RegFile.scala 20:22]
 000038	  wire [4:0] regfile_io_rs2_data_MPORT_addr; // @[RegFile.scala 20:22]
%000012	  wire [63:0] regfile_MPORT_1_data; // @[RegFile.scala 20:22]
%000000	  wire [4:0] regfile_MPORT_1_addr; // @[RegFile.scala 20:22]
%000009	  wire [63:0] regfile_MPORT_2_data; // @[RegFile.scala 20:22]
%000001	  wire [4:0] regfile_MPORT_2_addr; // @[RegFile.scala 20:22]
%000019	  wire [63:0] regfile_MPORT_3_data; // @[RegFile.scala 20:22]
%000001	  wire [4:0] regfile_MPORT_3_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_4_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_4_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_5_data; // @[RegFile.scala 20:22]
%000001	  wire [4:0] regfile_MPORT_5_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_6_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_6_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_7_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_7_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_8_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_8_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_9_data; // @[RegFile.scala 20:22]
%000001	  wire [4:0] regfile_MPORT_9_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_10_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_10_addr; // @[RegFile.scala 20:22]
%000026	  wire [63:0] regfile_MPORT_11_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_11_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_12_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_12_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_13_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_13_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_14_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_14_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_15_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_15_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_16_data; // @[RegFile.scala 20:22]
%000004	  wire [4:0] regfile_MPORT_16_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_17_data; // @[RegFile.scala 20:22]
%000001	  wire [4:0] regfile_MPORT_17_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_18_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_18_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_19_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_19_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_20_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_20_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_21_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_21_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_22_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_22_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_23_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_23_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_24_data; // @[RegFile.scala 20:22]
%000004	  wire [4:0] regfile_MPORT_24_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_25_data; // @[RegFile.scala 20:22]
%000002	  wire [4:0] regfile_MPORT_25_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_26_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_26_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_27_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_27_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_28_data; // @[RegFile.scala 20:22]
%000004	  wire [4:0] regfile_MPORT_28_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_29_data; // @[RegFile.scala 20:22]
%000003	  wire [4:0] regfile_MPORT_29_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_30_data; // @[RegFile.scala 20:22]
%000004	  wire [4:0] regfile_MPORT_30_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_31_data; // @[RegFile.scala 20:22]
%000004	  wire [4:0] regfile_MPORT_31_addr; // @[RegFile.scala 20:22]
%000000	  wire [63:0] regfile_MPORT_32_data; // @[RegFile.scala 20:22]
%000005	  wire [4:0] regfile_MPORT_32_addr; // @[RegFile.scala 20:22]
 000160	  wire [63:0] regfile_MPORT_data; // @[RegFile.scala 20:22]
 000048	  wire [4:0] regfile_MPORT_addr; // @[RegFile.scala 20:22]
%000001	  wire  regfile_MPORT_mask; // @[RegFile.scala 20:22]
%000007	  wire  regfile_MPORT_en; // @[RegFile.scala 20:22]
	  wire [63:0] _WIRE_0 = regfile_MPORT_1_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_1 = regfile_MPORT_2_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_2 = regfile_MPORT_3_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_3 = regfile_MPORT_4_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_4 = regfile_MPORT_5_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_5 = regfile_MPORT_6_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_6 = regfile_MPORT_7_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_7 = regfile_MPORT_8_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_8 = regfile_MPORT_9_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_9 = regfile_MPORT_10_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_10 = regfile_MPORT_11_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_11 = regfile_MPORT_12_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_12 = regfile_MPORT_13_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_13 = regfile_MPORT_14_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_14 = regfile_MPORT_15_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_15 = regfile_MPORT_16_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_16 = regfile_MPORT_17_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_17 = regfile_MPORT_18_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_18 = regfile_MPORT_19_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_19 = regfile_MPORT_20_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_20 = regfile_MPORT_21_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_21 = regfile_MPORT_22_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_22 = regfile_MPORT_23_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_23 = regfile_MPORT_24_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_24 = regfile_MPORT_25_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_25 = regfile_MPORT_26_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_26 = regfile_MPORT_27_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_27 = regfile_MPORT_28_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_28 = regfile_MPORT_29_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_29 = regfile_MPORT_30_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_30 = regfile_MPORT_31_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  wire [63:0] _WIRE_31 = regfile_MPORT_32_data; // @[RegFile.scala 26:33 RegFile.scala 26:33]
	  assign regfile_io_rs1_data_MPORT_addr = io_rs1_addr;
	  assign regfile_io_rs1_data_MPORT_data = regfile[regfile_io_rs1_data_MPORT_addr]; // @[RegFile.scala 20:22]
	  assign regfile_io_rs2_data_MPORT_addr = io_rs2_addr;
	  assign regfile_io_rs2_data_MPORT_data = regfile[regfile_io_rs2_data_MPORT_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_1_addr = 5'h0;
	  assign regfile_MPORT_1_data = regfile[regfile_MPORT_1_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_2_addr = 5'h1;
	  assign regfile_MPORT_2_data = regfile[regfile_MPORT_2_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_3_addr = 5'h2;
	  assign regfile_MPORT_3_data = regfile[regfile_MPORT_3_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_4_addr = 5'h3;
	  assign regfile_MPORT_4_data = regfile[regfile_MPORT_4_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_5_addr = 5'h4;
	  assign regfile_MPORT_5_data = regfile[regfile_MPORT_5_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_6_addr = 5'h5;
	  assign regfile_MPORT_6_data = regfile[regfile_MPORT_6_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_7_addr = 5'h6;
	  assign regfile_MPORT_7_data = regfile[regfile_MPORT_7_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_8_addr = 5'h7;
	  assign regfile_MPORT_8_data = regfile[regfile_MPORT_8_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_9_addr = 5'h8;
	  assign regfile_MPORT_9_data = regfile[regfile_MPORT_9_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_10_addr = 5'h9;
	  assign regfile_MPORT_10_data = regfile[regfile_MPORT_10_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_11_addr = 5'ha;
	  assign regfile_MPORT_11_data = regfile[regfile_MPORT_11_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_12_addr = 5'hb;
	  assign regfile_MPORT_12_data = regfile[regfile_MPORT_12_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_13_addr = 5'hc;
	  assign regfile_MPORT_13_data = regfile[regfile_MPORT_13_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_14_addr = 5'hd;
	  assign regfile_MPORT_14_data = regfile[regfile_MPORT_14_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_15_addr = 5'he;
	  assign regfile_MPORT_15_data = regfile[regfile_MPORT_15_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_16_addr = 5'hf;
	  assign regfile_MPORT_16_data = regfile[regfile_MPORT_16_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_17_addr = 5'h10;
	  assign regfile_MPORT_17_data = regfile[regfile_MPORT_17_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_18_addr = 5'h11;
	  assign regfile_MPORT_18_data = regfile[regfile_MPORT_18_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_19_addr = 5'h12;
	  assign regfile_MPORT_19_data = regfile[regfile_MPORT_19_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_20_addr = 5'h13;
	  assign regfile_MPORT_20_data = regfile[regfile_MPORT_20_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_21_addr = 5'h14;
	  assign regfile_MPORT_21_data = regfile[regfile_MPORT_21_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_22_addr = 5'h15;
	  assign regfile_MPORT_22_data = regfile[regfile_MPORT_22_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_23_addr = 5'h16;
	  assign regfile_MPORT_23_data = regfile[regfile_MPORT_23_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_24_addr = 5'h17;
	  assign regfile_MPORT_24_data = regfile[regfile_MPORT_24_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_25_addr = 5'h18;
	  assign regfile_MPORT_25_data = regfile[regfile_MPORT_25_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_26_addr = 5'h19;
	  assign regfile_MPORT_26_data = regfile[regfile_MPORT_26_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_27_addr = 5'h1a;
	  assign regfile_MPORT_27_data = regfile[regfile_MPORT_27_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_28_addr = 5'h1b;
	  assign regfile_MPORT_28_data = regfile[regfile_MPORT_28_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_29_addr = 5'h1c;
	  assign regfile_MPORT_29_data = regfile[regfile_MPORT_29_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_30_addr = 5'h1d;
	  assign regfile_MPORT_30_data = regfile[regfile_MPORT_30_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_31_addr = 5'h1e;
	  assign regfile_MPORT_31_data = regfile[regfile_MPORT_31_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_32_addr = 5'h1f;
	  assign regfile_MPORT_32_data = regfile[regfile_MPORT_32_addr]; // @[RegFile.scala 20:22]
	  assign regfile_MPORT_data = io_wdata;
	  assign regfile_MPORT_addr = io_waddr;
	  assign regfile_MPORT_mask = 1'h1;
	  assign regfile_MPORT_en = io_wen;
	  assign io_rs1_data = io_rs1_addr != 5'h0 ? regfile_io_rs1_data_MPORT_data : 64'h0; // @[RegFile.scala 23:23]
	  assign io_rs2_data = io_rs2_addr != 5'h0 ? regfile_io_rs2_data_MPORT_data : 64'h0; // @[RegFile.scala 24:23]
	  assign _WIRE_0_0 = _WIRE_0;
	  assign _WIRE_0_1 = _WIRE_1;
	  assign _WIRE_0_2 = _WIRE_2;
	  assign _WIRE_0_3 = _WIRE_3;
	  assign _WIRE_0_4 = _WIRE_4;
	  assign _WIRE_0_5 = _WIRE_5;
	  assign _WIRE_0_6 = _WIRE_6;
	  assign _WIRE_0_7 = _WIRE_7;
	  assign _WIRE_0_8 = _WIRE_8;
	  assign _WIRE_0_9 = _WIRE_9;
	  assign _WIRE_0_10 = _WIRE_10;
	  assign _WIRE_0_11 = _WIRE_11;
	  assign _WIRE_0_12 = _WIRE_12;
	  assign _WIRE_0_13 = _WIRE_13;
	  assign _WIRE_0_14 = _WIRE_14;
	  assign _WIRE_0_15 = _WIRE_15;
	  assign _WIRE_0_16 = _WIRE_16;
	  assign _WIRE_0_17 = _WIRE_17;
	  assign _WIRE_0_18 = _WIRE_18;
	  assign _WIRE_0_19 = _WIRE_19;
	  assign _WIRE_0_20 = _WIRE_20;
	  assign _WIRE_0_21 = _WIRE_21;
	  assign _WIRE_0_22 = _WIRE_22;
	  assign _WIRE_0_23 = _WIRE_23;
	  assign _WIRE_0_24 = _WIRE_24;
	  assign _WIRE_0_25 = _WIRE_25;
	  assign _WIRE_0_26 = _WIRE_26;
	  assign _WIRE_0_27 = _WIRE_27;
	  assign _WIRE_0_28 = _WIRE_28;
	  assign _WIRE_0_29 = _WIRE_29;
	  assign _WIRE_0_30 = _WIRE_30;
	  assign _WIRE_0_31 = _WIRE_31;
 000124	  always @(posedge clock) begin
 000118	    if(regfile_MPORT_en & regfile_MPORT_mask) begin
%000003	    verilator_coverage: (next point on previous line)

 000059	      regfile[regfile_MPORT_addr] <= regfile_MPORT_data; // @[RegFile.scala 20:22]
	    end
	  end
	// Register and memory initialization
	`ifdef RANDOMIZE_GARBAGE_ASSIGN
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_INVALID_ASSIGN
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_REG_INIT
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_MEM_INIT
	`define RANDOMIZE
	`endif
	`ifndef RANDOM
	`define RANDOM $random
	`endif
	`ifdef RANDOMIZE_MEM_INIT
	  integer initvar;
	`endif
	`ifndef SYNTHESIS
	`ifdef FIRRTL_BEFORE_INITIAL
	`FIRRTL_BEFORE_INITIAL
	`endif
%000002	initial begin
	  `ifdef RANDOMIZE
	    `ifdef INIT_RANDOM
	      `INIT_RANDOM
	    `endif
	    `ifndef VERILATOR
	      `ifdef RANDOMIZE_DELAY
	        #`RANDOMIZE_DELAY begin end
	      `else
	        #0.002 begin end
	      `endif
	    `endif
	`ifdef RANDOMIZE_MEM_INIT
	  _RAND_0 = {2{`RANDOM}};
	  for (initvar = 0; initvar < 32; initvar = initvar+1)
	    regfile[initvar] = _RAND_0[63:0];
	`endif // RANDOMIZE_MEM_INIT
	  `endif // RANDOMIZE
	end // initial
	`ifdef FIRRTL_AFTER_INITIAL
	`FIRRTL_AFTER_INITIAL
	`endif
	`endif // SYNTHESIS
	endmodule
	module Top(
 000126	  input         clock,
%000002	  input         reset,
 000040	  input         io_imem_req_ready,
 000041	  output        io_imem_req_valid,
 000038	  output [31:0] io_imem_req_bits_addr,
%000000	  output [31:0] io_imem_req_bits_data,
%000000	  output        io_imem_req_bits_fcn,
%000003	  output [2:0]  io_imem_req_bits_msk,
%000001	  output        io_imem_resp_ready,
 000040	  input         io_imem_resp_valid,
 000229	  input  [31:0] io_imem_resp_bits_data,
%000000	  input         io_dmem_req_ready,
%000000	  output        io_dmem_req_valid,
 000118	  output [31:0] io_dmem_req_bits_addr,
%000014	  output [63:0] io_dmem_req_bits_data,
%000000	  output        io_dmem_req_bits_fcn,
%000000	  output [2:0]  io_dmem_req_bits_msk,
%000001	  output        io_dmem_resp_ready,
%000000	  input         io_dmem_resp_valid,
%000000	  input  [63:0] io_dmem_resp_bits_data,
%000012	  output [63:0] io_debug_rf_0,
%000009	  output [63:0] io_debug_rf_1,
%000019	  output [63:0] io_debug_rf_2,
%000000	  output [63:0] io_debug_rf_3,
%000000	  output [63:0] io_debug_rf_4,
%000000	  output [63:0] io_debug_rf_5,
%000000	  output [63:0] io_debug_rf_6,
%000000	  output [63:0] io_debug_rf_7,
%000000	  output [63:0] io_debug_rf_8,
%000000	  output [63:0] io_debug_rf_9,
%000026	  output [63:0] io_debug_rf_10,
%000000	  output [63:0] io_debug_rf_11,
%000000	  output [63:0] io_debug_rf_12,
%000000	  output [63:0] io_debug_rf_13,
%000000	  output [63:0] io_debug_rf_14,
%000000	  output [63:0] io_debug_rf_15,
%000000	  output [63:0] io_debug_rf_16,
%000000	  output [63:0] io_debug_rf_17,
%000000	  output [63:0] io_debug_rf_18,
%000000	  output [63:0] io_debug_rf_19,
%000000	  output [63:0] io_debug_rf_20,
%000000	  output [63:0] io_debug_rf_21,
%000000	  output [63:0] io_debug_rf_22,
%000000	  output [63:0] io_debug_rf_23,
%000000	  output [63:0] io_debug_rf_24,
%000000	  output [63:0] io_debug_rf_25,
%000000	  output [63:0] io_debug_rf_26,
%000000	  output [63:0] io_debug_rf_27,
%000000	  output [63:0] io_debug_rf_28,
%000000	  output [63:0] io_debug_rf_29,
%000000	  output [63:0] io_debug_rf_30,
%000000	  output [63:0] io_debug_rf_31,
 000038	  output [63:0] io_debug_PC,
 000041	  output        io_debug_stall
	);
	`ifdef RANDOMIZE_REG_INIT
	  reg [63:0] _RAND_0;
	  reg [31:0] _RAND_1;
	`endif // RANDOMIZE_REG_INIT
 000041	  wire [5:0] alu_io_opcode; // @[core.scala 17:21]
 000116	  wire [63:0] alu_io_in1; // @[core.scala 17:21]
 000256	  wire [63:0] alu_io_in2; // @[core.scala 17:21]
 000134	  wire [63:0] alu_io_out; // @[core.scala 17:21]
 000023	  wire  alu_io_zero; // @[core.scala 17:21]
 000359	  wire [31:0] idu_io_inst; // @[core.scala 18:21]
%000028	  wire [3:0] idu_io_br_type; // @[core.scala 18:21]
%000006	  wire [1:0] idu_io_op1_sel; // @[core.scala 18:21]
 000032	  wire [1:0] idu_io_op2_sel; // @[core.scala 18:21]
 000041	  wire [5:0] idu_io_alu_op; // @[core.scala 18:21]
 000012	  wire [1:0] idu_io_wb_sel; // @[core.scala 18:21]
%000007	  wire  idu_io_rf_wen; // @[core.scala 18:21]
%000000	  wire  idu_io_mem_en; // @[core.scala 18:21]
%000000	  wire  idu_io_mem_fcn; // @[core.scala 18:21]
%000000	  wire [2:0] idu_io_mem_msk; // @[core.scala 18:21]
 000126	  wire  rf_clock; // @[core.scala 19:21]
 000052	  wire [4:0] rf_io_rs1_addr; // @[core.scala 19:21]
 000108	  wire [63:0] rf_io_rs1_data; // @[core.scala 19:21]
 000038	  wire [4:0] rf_io_rs2_addr; // @[core.scala 19:21]
%000014	  wire [63:0] rf_io_rs2_data; // @[core.scala 19:21]
 000048	  wire [4:0] rf_io_waddr; // @[core.scala 19:21]
 000160	  wire [63:0] rf_io_wdata; // @[core.scala 19:21]
%000007	  wire  rf_io_wen; // @[core.scala 19:21]
%000012	  wire [63:0] rf__WIRE_0_0; // @[core.scala 19:21]
%000009	  wire [63:0] rf__WIRE_0_1; // @[core.scala 19:21]
%000019	  wire [63:0] rf__WIRE_0_2; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_3; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_4; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_5; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_6; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_7; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_8; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_9; // @[core.scala 19:21]
%000026	  wire [63:0] rf__WIRE_0_10; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_11; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_12; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_13; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_14; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_15; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_16; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_17; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_18; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_19; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_20; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_21; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_22; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_23; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_24; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_25; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_26; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_27; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_28; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_29; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_30; // @[core.scala 19:21]
%000000	  wire [63:0] rf__WIRE_0_31; // @[core.scala 19:21]
 000038	  reg [63:0] pc_reg; // @[core.scala 22:26]
	  wire [63:0] _pc_4_T_1 = pc_reg + 64'h4; // @[core.scala 25:23]
 000041	  wire  stall = ~io_imem_resp_valid | ~(idu_io_mem_en & io_dmem_resp_valid | ~idu_io_mem_en); // @[core.scala 28:37]
 000041	  reg  imem_req_r; // @[core.scala 37:29]
	  wire  _T_5 = ~stall; // @[core.scala 39:15]
	  wire  _GEN_0 = ~stall | imem_req_r; // @[core.scala 39:29 core.scala 39:42 core.scala 37:29]
	  wire  _GEN_1 = io_imem_req_ready ? 1'h0 : _GEN_0; // @[core.scala 38:29 core.scala 38:42]
 000359	  wire [31:0] inst = io_imem_resp_valid ? io_imem_resp_bits_data : 32'h4033; // @[core.scala 45:15]
 000114	  wire [11:0] imm_i = inst[31:20]; // @[core.scala 52:21]
 000076	  wire [6:0] right = inst[31:25]; // @[core.scala 53:25]
 000048	  wire [4:0] left = inst[11:7]; // @[core.scala 53:39]
 000124	  wire [11:0] imm_s = {right,left}; // @[Cat.scala 29:58]
 000012	  wire  right_right = inst[31]; // @[core.scala 54:25]
 000010	  wire  right_left = inst[7]; // @[core.scala 54:35]
 000064	  wire [5:0] left_right = inst[30:25]; // @[core.scala 54:44]
 000038	  wire [3:0] left_left = inst[11:8]; // @[core.scala 54:57]
 000124	  wire [11:0] imm_b = {right_right,right_left,left_right,left_left}; // @[Cat.scala 29:58]
 000225	  wire [19:0] imm_u = inst[31:12]; // @[core.scala 55:21]
 000111	  wire [7:0] right_left_1 = inst[19:12]; // @[core.scala 56:35]
 000010	  wire  left_right_1 = inst[20]; // @[core.scala 56:48]
 000092	  wire [9:0] left_left_1 = inst[30:21]; // @[core.scala 56:58]
 000225	  wire [19:0] imm_j = {right_right,right_left_1,left_right_1,left_left_1}; // @[Cat.scala 29:58]
 000052	  wire [4:0] left_3 = inst[19:15]; // @[core.scala 57:39]
 000052	  wire [31:0] imm_z = {27'h0,left_3}; // @[Cat.scala 29:58]
 000240	  wire [19:0] right_4 = imm_i[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 72:12]
 000354	  wire [31:0] imm_i_sext = {right_4,imm_i}; // @[Cat.scala 29:58]
 000240	  wire [19:0] right_5 = imm_s[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 72:12]
 000364	  wire [31:0] imm_s_sext = {right_5,right,left}; // @[Cat.scala 29:58]
 000228	  wire [18:0] right_right_2 = imm_b[11] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 72:12]
 000352	  wire [31:0] imm_b_sext = {right_right_2,right_right,right_left,left_right,left_left,1'h0}; // @[Cat.scala 29:58]
 000225	  wire [31:0] imm_u_sext = {imm_u,12'h0}; // @[Cat.scala 29:58]
 000132	  wire [10:0] right_right_3 = imm_j[19] ? 11'h7ff : 11'h0; // @[Bitwise.scala 72:12]
 000357	  wire [31:0] imm_j_sext = {right_right_3,right_right,right_left_1,left_right_1,left_left_1,1'h0}; // @[Cat.scala 29:58]
	  wire  _rf_io_wdata_T = idu_io_wb_sel == 2'h0; // @[core.scala 71:24]
	  wire  _rf_io_wdata_T_1 = idu_io_wb_sel == 2'h1; // @[core.scala 72:24]
	  wire  _rf_io_wdata_T_2 = idu_io_wb_sel == 2'h2; // @[core.scala 73:24]
 000044	  wire [31:0] pc_4 = _pc_4_T_1[31:0]; // @[core.scala 24:23 core.scala 25:13]
	  wire [63:0] _rf_io_wdata_T_3 = _rf_io_wdata_T_2 ? {{32'd0}, pc_4} : alu_io_out; // @[Mux.scala 98:16]
	  wire [63:0] _rf_io_wdata_T_4 = _rf_io_wdata_T_1 ? io_dmem_resp_bits_data : _rf_io_wdata_T_3; // @[Mux.scala 98:16]
	  wire  _alu_io_in1_T = idu_io_op1_sel == 2'h0; // @[core.scala 80:25]
	  wire  _alu_io_in1_T_1 = idu_io_op1_sel == 2'h1; // @[core.scala 81:25]
	  wire  _alu_io_in1_T_2 = idu_io_op1_sel == 2'h2; // @[core.scala 82:25]
	  wire [63:0] _alu_io_in1_T_3 = _alu_io_in1_T_2 ? {{32'd0}, imm_z} : rf_io_rs1_data; // @[Mux.scala 98:16]
	  wire [63:0] _alu_io_in1_T_4 = _alu_io_in1_T_1 ? {{32'd0}, imm_u_sext} : _alu_io_in1_T_3; // @[Mux.scala 98:16]
	  wire  _alu_io_in2_T = idu_io_op2_sel == 2'h0; // @[core.scala 86:25]
	  wire  _alu_io_in2_T_1 = idu_io_op2_sel == 2'h1; // @[core.scala 87:25]
	  wire  _alu_io_in2_T_2 = idu_io_op2_sel == 2'h2; // @[core.scala 88:25]
	  wire  _alu_io_in2_T_3 = idu_io_op2_sel == 2'h3; // @[core.scala 89:25]
	  wire [63:0] _alu_io_in2_T_4 = _alu_io_in2_T_3 ? pc_reg : rf_io_rs2_data; // @[Mux.scala 98:16]
	  wire [63:0] _alu_io_in2_T_5 = _alu_io_in2_T_2 ? {{32'd0}, imm_s_sext} : _alu_io_in2_T_4; // @[Mux.scala 98:16]
	  wire [63:0] _alu_io_in2_T_6 = _alu_io_in2_T_1 ? {{32'd0}, imm_i_sext} : _alu_io_in2_T_5; // @[Mux.scala 98:16]
	  wire [63:0] _GEN_3 = {{32'd0}, imm_b_sext}; // @[core.scala 102:29]
 000338	  wire [63:0] br_target = pc_reg + _GEN_3; // @[core.scala 102:29]
	  wire [63:0] _GEN_4 = {{32'd0}, imm_j_sext}; // @[core.scala 103:29]
 000263	  wire [63:0] jmp_target = pc_reg + _GEN_4; // @[core.scala 103:29]
	  wire [63:0] _GEN_5 = {{32'd0}, imm_i_sext}; // @[core.scala 104:37]
 000260	  wire [63:0] jr_target = rf_io_rs1_data + _GEN_5; // @[core.scala 104:37]
	  wire  _T_18 = idu_io_br_type == 4'h2 & alu_io_zero; // @[core.scala 107:36]
	  wire  _T_21 = idu_io_br_type == 4'h1 & ~alu_io_zero; // @[core.scala 108:36]
	  wire  _T_24 = ~alu_io_out[0]; // @[core.scala 109:39]
	  wire  _T_25 = idu_io_br_type == 4'h3 & ~alu_io_out[0]; // @[core.scala 109:36]
	  wire  _T_29 = idu_io_br_type == 4'h4 & _T_24; // @[core.scala 110:36]
	  wire  _T_32 = idu_io_br_type == 4'h5 & alu_io_out[0]; // @[core.scala 111:36]
	  wire  _T_35 = idu_io_br_type == 4'h6 & alu_io_out[0]; // @[core.scala 112:36]
%000000	  wire  br_taken = _T_18 | (_T_21 | (_T_25 | (_T_29 | (_T_32 | _T_35)))); // @[Mux.scala 98:16]
	  wire  _pc_next_T_1 = idu_io_br_type == 4'h7; // @[core.scala 118:25]
	  wire  _pc_next_T_2 = idu_io_br_type == 4'h8; // @[core.scala 119:25]
	  wire [63:0] _pc_next_T_3 = _pc_next_T_2 ? jr_target : {{32'd0}, pc_4}; // @[Mux.scala 98:16]
	  wire [63:0] _pc_next_T_4 = _pc_next_T_1 ? jmp_target : _pc_next_T_3; // @[Mux.scala 98:16]
	  wire [63:0] _pc_next_T_5 = br_taken ? br_target : _pc_next_T_4; // @[Mux.scala 98:16]
 000050	  wire [31:0] pc_next = _pc_next_T_5[31:0]; // @[core.scala 23:23 core.scala 116:13]
	  ALU alu ( // @[core.scala 17:21]
	    .io_opcode(alu_io_opcode),
	    .io_in1(alu_io_in1),
	    .io_in2(alu_io_in2),
	    .io_out(alu_io_out),
	    .io_zero(alu_io_zero)
	  );
	  IDU idu ( // @[core.scala 18:21]
	    .io_inst(idu_io_inst),
	    .io_br_type(idu_io_br_type),
	    .io_op1_sel(idu_io_op1_sel),
	    .io_op2_sel(idu_io_op2_sel),
	    .io_alu_op(idu_io_alu_op),
	    .io_wb_sel(idu_io_wb_sel),
	    .io_rf_wen(idu_io_rf_wen),
	    .io_mem_en(idu_io_mem_en),
	    .io_mem_fcn(idu_io_mem_fcn),
	    .io_mem_msk(idu_io_mem_msk)
	  );
	  RegFile rf ( // @[core.scala 19:21]
	    .clock(rf_clock),
	    .io_rs1_addr(rf_io_rs1_addr),
	    .io_rs1_data(rf_io_rs1_data),
	    .io_rs2_addr(rf_io_rs2_addr),
	    .io_rs2_data(rf_io_rs2_data),
	    .io_waddr(rf_io_waddr),
	    .io_wdata(rf_io_wdata),
	    .io_wen(rf_io_wen),
	    ._WIRE_0_0(rf__WIRE_0_0),
	    ._WIRE_0_1(rf__WIRE_0_1),
	    ._WIRE_0_2(rf__WIRE_0_2),
	    ._WIRE_0_3(rf__WIRE_0_3),
	    ._WIRE_0_4(rf__WIRE_0_4),
	    ._WIRE_0_5(rf__WIRE_0_5),
	    ._WIRE_0_6(rf__WIRE_0_6),
	    ._WIRE_0_7(rf__WIRE_0_7),
	    ._WIRE_0_8(rf__WIRE_0_8),
	    ._WIRE_0_9(rf__WIRE_0_9),
	    ._WIRE_0_10(rf__WIRE_0_10),
	    ._WIRE_0_11(rf__WIRE_0_11),
	    ._WIRE_0_12(rf__WIRE_0_12),
	    ._WIRE_0_13(rf__WIRE_0_13),
	    ._WIRE_0_14(rf__WIRE_0_14),
	    ._WIRE_0_15(rf__WIRE_0_15),
	    ._WIRE_0_16(rf__WIRE_0_16),
	    ._WIRE_0_17(rf__WIRE_0_17),
	    ._WIRE_0_18(rf__WIRE_0_18),
	    ._WIRE_0_19(rf__WIRE_0_19),
	    ._WIRE_0_20(rf__WIRE_0_20),
	    ._WIRE_0_21(rf__WIRE_0_21),
	    ._WIRE_0_22(rf__WIRE_0_22),
	    ._WIRE_0_23(rf__WIRE_0_23),
	    ._WIRE_0_24(rf__WIRE_0_24),
	    ._WIRE_0_25(rf__WIRE_0_25),
	    ._WIRE_0_26(rf__WIRE_0_26),
	    ._WIRE_0_27(rf__WIRE_0_27),
	    ._WIRE_0_28(rf__WIRE_0_28),
	    ._WIRE_0_29(rf__WIRE_0_29),
	    ._WIRE_0_30(rf__WIRE_0_30),
	    ._WIRE_0_31(rf__WIRE_0_31)
	  );
	  assign io_imem_req_valid = imem_req_r; // @[core.scala 41:29]
	  assign io_imem_req_bits_addr = pc_reg[31:0]; // @[core.scala 32:29]
	  assign io_imem_req_bits_data = 32'h0; // @[core.scala 31:29]
	  assign io_imem_req_bits_fcn = 1'h0; // @[core.scala 33:29]
	  assign io_imem_req_bits_msk = 3'h7; // @[core.scala 34:29]
	  assign io_imem_resp_ready = 1'h1; // @[core.scala 47:24]
	  assign io_dmem_req_valid = idu_io_mem_en; // @[core.scala 95:27]
	  assign io_dmem_req_bits_addr = alu_io_out[31:0]; // @[core.scala 93:27]
	  assign io_dmem_req_bits_data = rf_io_rs2_data; // @[core.scala 94:27]
	  assign io_dmem_req_bits_fcn = idu_io_mem_fcn; // @[core.scala 96:27]
	  assign io_dmem_req_bits_msk = idu_io_mem_msk; // @[core.scala 97:27]
	  assign io_dmem_resp_ready = 1'h1; // @[core.scala 99:24]
	  assign io_debug_rf_0 = rf__WIRE_0_0; // @[core.scala 132:22]
	  assign io_debug_rf_1 = rf__WIRE_0_1; // @[core.scala 132:22]
	  assign io_debug_rf_2 = rf__WIRE_0_2; // @[core.scala 132:22]
	  assign io_debug_rf_3 = rf__WIRE_0_3; // @[core.scala 132:22]
	  assign io_debug_rf_4 = rf__WIRE_0_4; // @[core.scala 132:22]
	  assign io_debug_rf_5 = rf__WIRE_0_5; // @[core.scala 132:22]
	  assign io_debug_rf_6 = rf__WIRE_0_6; // @[core.scala 132:22]
	  assign io_debug_rf_7 = rf__WIRE_0_7; // @[core.scala 132:22]
	  assign io_debug_rf_8 = rf__WIRE_0_8; // @[core.scala 132:22]
	  assign io_debug_rf_9 = rf__WIRE_0_9; // @[core.scala 132:22]
	  assign io_debug_rf_10 = rf__WIRE_0_10; // @[core.scala 132:22]
	  assign io_debug_rf_11 = rf__WIRE_0_11; // @[core.scala 132:22]
	  assign io_debug_rf_12 = rf__WIRE_0_12; // @[core.scala 132:22]
	  assign io_debug_rf_13 = rf__WIRE_0_13; // @[core.scala 132:22]
	  assign io_debug_rf_14 = rf__WIRE_0_14; // @[core.scala 132:22]
	  assign io_debug_rf_15 = rf__WIRE_0_15; // @[core.scala 132:22]
	  assign io_debug_rf_16 = rf__WIRE_0_16; // @[core.scala 132:22]
	  assign io_debug_rf_17 = rf__WIRE_0_17; // @[core.scala 132:22]
	  assign io_debug_rf_18 = rf__WIRE_0_18; // @[core.scala 132:22]
	  assign io_debug_rf_19 = rf__WIRE_0_19; // @[core.scala 132:22]
	  assign io_debug_rf_20 = rf__WIRE_0_20; // @[core.scala 132:22]
	  assign io_debug_rf_21 = rf__WIRE_0_21; // @[core.scala 132:22]
	  assign io_debug_rf_22 = rf__WIRE_0_22; // @[core.scala 132:22]
	  assign io_debug_rf_23 = rf__WIRE_0_23; // @[core.scala 132:22]
	  assign io_debug_rf_24 = rf__WIRE_0_24; // @[core.scala 132:22]
	  assign io_debug_rf_25 = rf__WIRE_0_25; // @[core.scala 132:22]
	  assign io_debug_rf_26 = rf__WIRE_0_26; // @[core.scala 132:22]
	  assign io_debug_rf_27 = rf__WIRE_0_27; // @[core.scala 132:22]
	  assign io_debug_rf_28 = rf__WIRE_0_28; // @[core.scala 132:22]
	  assign io_debug_rf_29 = rf__WIRE_0_29; // @[core.scala 132:22]
	  assign io_debug_rf_30 = rf__WIRE_0_30; // @[core.scala 132:22]
	  assign io_debug_rf_31 = rf__WIRE_0_31; // @[core.scala 132:22]
	  assign io_debug_PC = pc_reg; // @[core.scala 127:22]
	  assign io_debug_stall = ~io_imem_resp_valid | ~(idu_io_mem_en & io_dmem_resp_valid | ~idu_io_mem_en); // @[core.scala 28:37]
	  assign alu_io_opcode = idu_io_alu_op; // @[core.scala 78:20]
	  assign alu_io_in1 = _alu_io_in1_T ? rf_io_rs1_data : _alu_io_in1_T_4; // @[Mux.scala 98:16]
	  assign alu_io_in2 = _alu_io_in2_T ? rf_io_rs2_data : _alu_io_in2_T_6; // @[Mux.scala 98:16]
	  assign idu_io_inst = io_imem_resp_valid ? io_imem_resp_bits_data : 32'h4033; // @[core.scala 45:15]
	  assign rf_clock = clock;
	  assign rf_io_rs1_addr = inst[19:15]; // @[core.scala 67:27]
	  assign rf_io_rs2_addr = inst[24:20]; // @[core.scala 68:27]
	  assign rf_io_waddr = inst[11:7]; // @[core.scala 69:27]
	  assign rf_io_wdata = _rf_io_wdata_T ? alu_io_out : _rf_io_wdata_T_4; // @[Mux.scala 98:16]
	  assign rf_io_wen = idu_io_rf_wen; // @[core.scala 75:20]
 000124	  always @(posedge clock) begin
%000004	    if (reset) begin // @[core.scala 22:26]
%000002	      pc_reg <= 64'h80000000; // @[core.scala 22:26]
 000040	    end else if (_T_5) begin // @[core.scala 121:17]
 000040	    verilator_coverage: (next point on previous line)

 000020	      pc_reg <= {{32'd0}, pc_next}; // @[core.scala 122:16]
	    end
 000062	    imem_req_r <= reset | _GEN_1; // @[core.scala 37:29 core.scala 37:29]
	  end
	// Register and memory initialization
	`ifdef RANDOMIZE_GARBAGE_ASSIGN
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_INVALID_ASSIGN
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_REG_INIT
	`define RANDOMIZE
	`endif
	`ifdef RANDOMIZE_MEM_INIT
	`define RANDOMIZE
	`endif
	`ifndef RANDOM
	`define RANDOM $random
	`endif
	`ifdef RANDOMIZE_MEM_INIT
	  integer initvar;
	`endif
	`ifndef SYNTHESIS
	`ifdef FIRRTL_BEFORE_INITIAL
	`FIRRTL_BEFORE_INITIAL
	`endif
%000002	initial begin
	  `ifdef RANDOMIZE
	    `ifdef INIT_RANDOM
	      `INIT_RANDOM
	    `endif
	    `ifndef VERILATOR
	      `ifdef RANDOMIZE_DELAY
	        #`RANDOMIZE_DELAY begin end
	      `else
	        #0.002 begin end
	      `endif
	    `endif
	`ifdef RANDOMIZE_REG_INIT
	  _RAND_0 = {2{`RANDOM}};
	  pc_reg = _RAND_0[63:0];
	  _RAND_1 = {1{`RANDOM}};
	  imem_req_r = _RAND_1[0:0];
	`endif // RANDOMIZE_REG_INIT
	  `endif // RANDOMIZE
	end // initial
	`ifdef FIRRTL_AFTER_INITIAL
	`FIRRTL_AFTER_INITIAL
	`endif
	`endif // SYNTHESIS
%000002	   initial begin
%000002	      if ($test$plusargs("trace") != 0) begin
%000000	      verilator_coverage: (next point on previous line)

%000001	         $display("[%0t] Tracing to logs/vlt_dump.vcd...\n", $time);
%000001	         $dumpfile("logs/vlt_dump.vcd");
%000001	         $dumpvars();
	      end
%000001	      $display("[%0t] Model running...\n", $time);
	   end
	endmodule
	
