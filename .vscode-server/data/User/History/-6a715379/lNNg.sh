make
golden_scanner < ./scoring_testcase/comprehensive.txt > golden_ans.txt
./scanner < ./scoring_testcase/comprehensive.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean