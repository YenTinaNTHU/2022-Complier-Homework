make
golden_scanner < /scoring_testcase/comment.txt > golden_ans.txt
./scanner < /scoring_testcase/comment.txt > ans.txt
diff golden_ans.txt ans.txt 
make clean