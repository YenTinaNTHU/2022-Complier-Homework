make
golden_scanner < ./scoring_testcase/pragma.txt > golden_ans.txt
./scanner < ./scoring_testcase/pragma.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean