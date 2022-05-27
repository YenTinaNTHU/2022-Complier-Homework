make
golden_scanner < /scoring_testcase/sample_testcase.txt > golden_ans.txt
./scanner < /scoring_testcase/sample_testcase.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean