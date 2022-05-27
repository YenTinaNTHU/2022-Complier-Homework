make
golden_scanner < ./scoring_testcase/macro.txt > golden_ans.txt
./scanner < ./scoring_testcase/macro.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean