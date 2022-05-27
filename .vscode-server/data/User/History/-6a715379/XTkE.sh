make
golden_scanner < ./scoring_testcase/op_punc.txt > golden_ans.txt
./scanner < ./scoring_testcase/op_punc.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean