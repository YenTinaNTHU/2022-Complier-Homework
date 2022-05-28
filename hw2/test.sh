golden_parser < ./basic_testcase/input.txt > golden_ans.txt
./parser < ./basic_testcase/input.txt > ans.txt
diff golden_ans.txt ans.txt