golden_scanner < sample_testcase.txt > golden_ans.txt
sh script.sh < sample_testcase.txt > ans.txt
diff golden_ans.txt ans.txt 