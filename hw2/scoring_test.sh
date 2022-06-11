make
file=array_decl_wo_init.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=expr_2.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=func_decl.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=func_def.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=scalar_decl_wo_init.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=stmt.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=var_decl.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=expr_1.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=expr_3.txt
golden_parser < ./scoring_testcase/$file > ./answer/golden_ans.txt
./parser < ./scoring_testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

make clean