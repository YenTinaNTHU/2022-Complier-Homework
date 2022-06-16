make
file=array_decl_input.txt
golden_parser < ./testcase/$file > ./answer/golden_ans.txt
./parser < ./testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=expr_input.txt
golden_parser < ./testcase/$file > ./answer/golden_ans.txt
./parser < ./testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=func_input.txt
golden_parser < ./testcase/$file > ./answer/golden_ans.txt
./parser < ./testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=scalar_decl_input.txt
golden_parser < ./testcase/$file > ./answer/golden_ans.txt
./parser < ./testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=stmt_input.txt
golden_parser < ./testcase/$file > ./answer/golden_ans.txt
./parser < ./testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

file=type_input.txt
golden_parser < ./testcase/$file > ./answer/golden_ans.txt
./parser < ./testcase/$file > ./answer/ans.txt
diff ./answer/golden_ans.txt ./answer/ans.txt

#file=bonus_input.txt
#golden_parser < ./testcase/$file > ./answer/golden_ans.txt
#./parser < ./testcase/$file > ./answer/ans.txt
#diff ./answer/golden_ans.txt ./answer/ans.txt

make clean