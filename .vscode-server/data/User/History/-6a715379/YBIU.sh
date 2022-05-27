make
golden_scanner < ./scoring_testcase/comment.txt > golden_ans.txt
./scanner < ./scoring_testcase/comment.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/comprehensive.txt > golden_ans.txt
./scanner < ./scoring_testcase/comprehensive.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/int_float_char.txt > golden_ans.txt
./scanner < ./scoring_testcase/int_float_char.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/key_ident.txt > golden_ans.txt
./scanner < ./scoring_testcase/key_ident.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/macro.txt > golden_ans.txt
./scanner < ./scoring_testcase/macro.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/op_punc.txt > golden_ans.txt
./scanner < ./scoring_testcase/op_punc.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/pragma.txt > golden_ans.txt
./scanner < ./scoring_testcase/pragma.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/string.txt > golden_ans.txt
./scanner < ./scoring_testcase/string.txt > ans.txt
diff golden_ans.txt ans.txt
golden_scanner < ./scoring_testcase/sample_testcase.txt > golden_ans.txt
./scanner < ./scoring_testcase/sample_testcase.txt > ans.txt
diff golden_ans.txt ans.txt
make clean