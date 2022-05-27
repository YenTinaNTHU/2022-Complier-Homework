make
golden_scanner < ./scoring_testcase/string.txt > golden_ans.txt
./scanner < ./scoring_testcase/string.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean