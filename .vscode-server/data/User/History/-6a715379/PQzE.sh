make
golden_scanner < ./scoring_testcase/int_float_char.txt > golden_ans.txt
./scanner < ./scoring_testcase/int_float_char.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean